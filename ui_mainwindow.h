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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
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
    QPushButton *Download;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *fUIDToDownloadLabel;
    QLineEdit *fuidLineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(618, 494);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
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
        Download = new QPushButton(centralwidget);
        Download->setObjectName(QString::fromUtf8("Download"));
        Download->setGeometry(QRect(520, 410, 93, 29));
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

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fuidLineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 450, 93, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Logs:", nullptr));
        loadFromLabel->setText(QCoreApplication::translate("MainWindow", "Save To:", nullptr));
        saveToLabel->setText(QCoreApplication::translate("MainWindow", "Load From: ", nullptr));
        dirLoad->setText(QCoreApplication::translate("MainWindow", "Select Dir", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        dirDownload->setText(QCoreApplication::translate("MainWindow", "Select Dir", nullptr));
        Download->setText(QCoreApplication::translate("MainWindow", "Get Table", nullptr));
        fUIDToDownloadLabel->setText(QCoreApplication::translate("MainWindow", "FUID To Download: ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
