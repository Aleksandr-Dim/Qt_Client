/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <QIntValidator>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDate>

enum MsgTypes
{
    QUERY_SendFile,
    QUERY_GetFile,
};

struct Protocol
{
  unsigned long MessageLength;
  long MessageType;//QUERY_SendFile; QUERY_GetFile;
};


QT_BEGIN_NAMESPACE

class Server : public QThread
{
Q_OBJECT
private:
    QTcpServer *serv;
public:
    Server();
    void run();
public slots:
    void newConnection();
};

class ServerThread : public QThread
{
Q_OBJECT
private:
    QTcpSocket *Another;
    QByteArray message;
    Protocol *proto;
    char *Data;
    void Exit();
public:
    void run();
    ServerThread(QTcpServer *sock);
public slots:
    void read();
    void close();
};


class LoadFileThread : public QThread
{
private:
int FUID;
QString FileName;
public:
    LoadFileThread(int val, QString *text)
    {
        FUID=val;
        FileName=*text;//No mutex;
    }
    void run();
};

class DownloadFileThread : public QThread
{
Q_OBJECT
private:
int FUID;
QString *FileDir;
QTcpSocket *iClient;
QByteArray File;
public:
    DownloadFileThread(int val, QString *fileDir);
    void run();
public slots:
    void read();
};

class Window : public QObject
{
Q_OBJECT

private:
QString LoadFileDir;
QString LoadFile;
QString DownloadFileDir;

public slots:
void LoadDirPressed();
void LoadPressed();
void DownloadDirPressed();
void DownloadPressed();
void GetTable();

private:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *loadFromLabel;
    QLineEdit *DownloadLineEdit;
    QLabel *saveToLabel;
    QLineEdit *LoadLineEdit;
    QPushButton *dirLoad;
    QPushButton *Load;
    QPushButton *dirDownload;
    QPushButton *getTable;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *fUIDToDownloadLabel;
    QLineEdit *fuidLineEdit;
    QPushButton *Download;
public:
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->setFixedSize(618, 494);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 601, 331));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 62, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 370, 401, 74));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(0, 0, 0, 0);
        loadFromLabel = new QLabel(formLayoutWidget);
        loadFromLabel->setObjectName(QString::fromUtf8("loadFromLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, loadFromLabel);

        DownloadLineEdit = new QLineEdit(formLayoutWidget);
        DownloadLineEdit->setObjectName(QString::fromUtf8("DownloadLineEdit"));
        DownloadLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, DownloadLineEdit);

        saveToLabel = new QLabel(formLayoutWidget);
        saveToLabel->setObjectName(QString::fromUtf8("saveToLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, saveToLabel);

        LoadLineEdit = new QLineEdit(formLayoutWidget);
        LoadLineEdit->setObjectName(QString::fromUtf8("LoadLineEdit"));
        LoadLineEdit->setReadOnly(true);
        LoadLineEdit->setClearButtonEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, LoadLineEdit);

        dirLoad = new QPushButton(centralwidget);
        dirLoad->setObjectName(QString::fromUtf8("dirLoad"));
        dirLoad->setGeometry(QRect(420, 370, 93, 29));
        Load = new QPushButton(centralwidget);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setGeometry(QRect(520, 370, 93, 29));
        dirDownload = new QPushButton(centralwidget);
        dirDownload->setObjectName(QString::fromUtf8("dirDownload"));
        dirDownload->setGeometry(QRect(420, 410, 93, 29));
        getTable = new QPushButton(centralwidget);
        getTable->setObjectName(QString::fromUtf8("Download"));
        getTable->setGeometry(QRect(520, 410, 93, 29));
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 450, 231, 31));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        fUIDToDownloadLabel = new QLabel(formLayoutWidget_2);
        fUIDToDownloadLabel->setObjectName(QString::fromUtf8("fUIDToDownloadLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, fUIDToDownloadLabel);

        fuidLineEdit = new QLineEdit(formLayoutWidget_2);
        fuidLineEdit->setObjectName(QString::fromUtf8("fuidLineEdit"));
        fuidLineEdit->setValidator(new QIntValidator(0, 50000, this));
        formLayout_2->setWidget(0, QFormLayout::FieldRole, fuidLineEdit);
        Download = new QPushButton(centralwidget);
        Download->setObjectName(QString::fromUtf8("pushButton"));
        Download->setGeometry(QRect(250, 446, 93, 29));


        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QObject::connect(dirLoad, &QPushButton::clicked, this, &Window::LoadDirPressed);
        QObject::connect(Load, &QPushButton::clicked, this, &Window::LoadPressed);
        QObject::connect(dirDownload, &QPushButton::clicked, this, &Window::DownloadDirPressed);
        QObject::connect(getTable, &QPushButton::clicked, this, &Window::GetTable);
        QObject::connect(Download, &QPushButton::clicked, this, &Window::DownloadPressed);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUiq
private:
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "File Loader", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Logs:", nullptr));
        loadFromLabel->setText(QCoreApplication::translate("MainWindow", "Save To:", nullptr));
        saveToLabel->setText(QCoreApplication::translate("MainWindow", "Load From: ", nullptr));
        dirLoad->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        dirDownload->setText(QCoreApplication::translate("MainWindow", "Select Dir", nullptr));
        getTable->setText(QCoreApplication::translate("MainWindow", "Get Table", nullptr));
        fUIDToDownloadLabel->setText(QCoreApplication::translate("MainWindow", "FUID To Download: ", nullptr));
        Download->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
