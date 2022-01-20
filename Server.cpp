#include <QApplication>
#include "ui_mainwindow2.h"

#include <iostream>
#include <string>



Server::Server()
{
    serv=new QTcpServer;
    if(!serv->listen(QHostAddress::LocalHost, 27000))
    {
        qDebug("[Server] Failed to listen!");
        return;
    }

    connect(serv, &QTcpServer::newConnection, this, &Server::newConnection);
}

void Server::run()
{
    exec();
}


void Server::newConnection()
{
    ServerThread *thread = new ServerThread(serv);
    connect(thread, &ServerThread::finished, thread, &ServerThread::deleteLater);
    thread->start();
}


ServerThread::ServerThread(QTcpServer *sock)
{

    Another=sock->nextPendingConnection();
    QObject::connect(Another, &QIODevice::readyRead, this, &ServerThread::read, Qt::DirectConnection);
    QObject::connect(Another, &QAbstractSocket::disconnected, this, &ServerThread::close, Qt::DirectConnection);

}

void ServerThread::run()
{
    exec();
}

void ServerThread::close()
{
    this->exit();
    return;
}

void ServerThread::read()
{
    message.append(Another->readAll());
    unsigned long MsgLength=message.size();
    proto=(Protocol *)message.data();
    Data=message.data()+sizeof(Protocol);

    if(MsgLength < (sizeof(Protocol)+sizeof(int)))
    {
        Exit();
        return;
    }
    if(proto->MessageLength != (MsgLength-sizeof(Protocol)))
    {
        return;//Wait for another data;
    }

    if(proto->MessageType == QUERY_SendFile)//I am getting a file;
    {
        int *fuid=(int *)Data;
        Data+=sizeof(int);

        QString FileName;
        FileName.setNum(*fuid);
        FileName.append(".bin");

        QFile file(FileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            qDebug("[Server Thread] Failed to create a file!");
            Exit();
            return;
        }

        file.write(Data, proto->MessageLength-sizeof(int));
        file.close();
    }
    else if(proto->MessageType == QUERY_GetFile)//Send a file
    {
        if(MsgLength != (sizeof(Protocol)+sizeof(int)))
        {
            Exit();
            return;
        }

        int *fuid=(int *)Data;

        QString FileName;
        FileName.setNum(*fuid);
        FileName.append(".bin");

        QFile file(FileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug("[Server Thread] File not found!");
            Exit();
            return;
        }

        proto->MessageLength=file.size()+sizeof(int);
        message.append(file.readAll());
        file.close();

        Another->write(message);
    }
    return;
}

void ServerThread::Exit()
{
    Another->abort();
    this->exit();
    return;
}

