#include <QApplication>
#include "ui_mainwindow2.h"

QSqlDatabase db;

void Window::LoadDirPressed()
{
    LoadFileDir=QFileDialog::getOpenFileName(nullptr, "Select a file");
    LoadFile=LoadFileDir.mid(LoadFileDir.lastIndexOf("/", -1)+1, -1);
    LoadLineEdit->setText(LoadFileDir);
    return;
}

void Window::LoadPressed()
{
    if(LoadFileDir.isEmpty())
    {
        QMessageBox::warning(nullptr, "Error", "No file diretory has been choosen!");
        return;
    }
    Window::textEdit->append("Loading a file to the server from the directory:\r\n"+Window::LoadFileDir);

    QSqlQuery query(db);
    query.prepare("INSERT INTO Files (FileName, FileDir, Time) VALUES (:a1, :a2, CURRENT_TIMESTAMP);");
    query.bindValue(":a1", LoadFile);
    query.bindValue(":a2", LoadFileDir);
    if(!query.exec())
    {
        textEdit->append(">> Failed to send a query!");
        return;
    }
    int fuid=query.lastInsertId().toInt();
    LoadFileThread *ld = new LoadFileThread(fuid, &LoadFileDir);
    ld->start();
    return;
}
void Window::DownloadDirPressed()
{
    DownloadFileDir=QFileDialog::getExistingDirectory(nullptr, "Select a directory!");
    DownloadLineEdit->setText(DownloadFileDir);
    return;
}
void Window::DownloadPressed()
{
    if(DownloadFileDir.isEmpty())
    {
        QMessageBox::warning(nullptr, "Error", "No file diretory has been choosen!");
        return;
    }

    QString text=fuidLineEdit->text();
    int fuid=text.toInt();

    QSqlQuery query(db);
    query.prepare("SELECT FileName FROM Files WHERE FUID=:a1;");
    query.bindValue(":a1", fuid);
    if(!query.exec())
    {
        textEdit->append(">> Failed to send a query!");
        return;
    }
    if(!query.next())
    {
        textEdit->append(">> File is not found in database!");
        return;
    }

    textEdit->append("Loading a file from the server to the directory: "+Window::DownloadFileDir);
    textEdit->append("Fuid: "+fuidLineEdit->text()+"\tFileName: "+query.value(0).toString());

    QString *TotalDir=new QString;
    *TotalDir=DownloadFileDir+"/copy_"+query.value(0).toString();

    DownloadFileThread *ld = new DownloadFileThread(fuid, TotalDir);

    ld->start();
    return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    Window ui;
    ui.setupUi(&window);

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Client.db");
    if(!db.open())
    {
        ui.textEdit->append(">> Failed to open the database!");
    }

    Server *serv=new Server;
    serv->start();

    window.show();
    return a.exec();
}

void Window::GetTable()
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Files");
    if(!query.exec())
    {
        textEdit->append(">> Failed to send a query!");
        return;
    }
    while(query.next())
    {
        textEdit->append("File UID: " + query.value(0).toString() + "\tTime: " + query.value(3).toString()
        + "\tFile Name: " + query.value(1).toString() + "\r\nFile Dir: " + query.value(2).toString()
        +"\r\n");
    }
    return;
}



