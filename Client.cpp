#include <QApplication>
#include "ui_mainwindow2.h"






void LoadFileThread::run()
{
    QTcpSocket client;
    client.connectToHost("localhost", 27000);
    if (!client.waitForConnected(3000))
    {
        qDebug("[Client Thread] Failed to connect!");
        return;
    }

    QFile file(FileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        client.disconnectFromHost();
        client.waitForDisconnected(-1);
        qDebug("[Client Thread] Failed to open a file!");
        return;
    }

    Protocol proto;
    proto.MessageType=QUERY_SendFile;
    proto.MessageLength=file.size()+sizeof(int);

    QByteArray message=file.readAll();
    file.close();
    message.prepend((char *)&FUID, sizeof(int));
    message.prepend((char *)&proto, sizeof(Protocol));

    client.write(message);
    client.disconnectFromHost();
    client.waitForDisconnected(-1);
    return;
}

DownloadFileThread::DownloadFileThread(int val, QString *fileDir)
{
    FUID=val;
    FileDir=fileDir;
}


void DownloadFileThread::run()
{
    iClient=new QTcpSocket;
    iClient->connectToHost("localhost", 27000);
    if (!iClient->waitForConnected(3000))
    {
        qDebug("[Client Thread] Failed to connect!");
        return;
    }
    QObject::connect(iClient, &QIODevice::readyRead, this, &DownloadFileThread::read, Qt::DirectConnection);

    Protocol proto;
    proto.MessageType=QUERY_GetFile;
    proto.MessageLength=sizeof(int);
    QByteArray message;
    message.append((char *)&proto, sizeof(Protocol));
    message.append((char *)&FUID, sizeof(int));

    iClient->write(message);
    exec();
    //delete FileDir;
    return;
}

void DownloadFileThread::read()
{
    File.append(iClient->readAll());
    unsigned long MsgLength=File.size();
    Protocol *proto=(Protocol *)File.data();
    char *Data=File.data()+sizeof(Protocol);

    if(MsgLength < (sizeof(Protocol)+sizeof(int)))
    {
        iClient->abort();
        this->exit();
        return;
    }
    if(proto->MessageLength != (MsgLength-sizeof(Protocol)))
    {
        return;//Wait for another data;
    }


    Data+=sizeof(int);

    QFile file(*FileDir);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug("[Client Thread] Failed to create a file!");
        iClient->abort();
        this->exit();
        return;
    }

    file.write(Data, proto->MessageLength-sizeof(int));
    file.close();

    {
    QSqlDatabase Downloaded=QSqlDatabase::addDatabase("QSQLITE", "Some");
    Downloaded.setDatabaseName("Downloaded.db");
    if(Downloaded.open())
    {
        QSqlQuery query(Downloaded);
        if(!Downloaded.tables().contains("Files"))
        {
           query.prepare("CREATE TABLE Files(FileName TEXT, Time INTEGER);");
           query.exec();
        }
        query.prepare("INSERT INTO Files (FileName, Time) VALUES (:a1, CURRENT_TIMESTAMP);");
        query.bindValue(":a1", *FileDir);
        query.exec();
    }
    Downloaded.close();
    }
    QSqlDatabase::removeDatabase("Some");

    iClient->disconnectFromHost();
    this->exit();
    return;
}


