/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_the_connection_2;
    QAction *actionStart;
    QAction *actionAdmit_defeat;
    QAction *actionConnect_to_Server;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QMenuBar *menubar;
    QMenu *menuConnect;
    QMenu *menuPlay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(556, 558);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font.setPointSize(16);
        MainWindow->setFont(font);
        actionCreate_the_connection_2 = new QAction(MainWindow);
        actionCreate_the_connection_2->setObjectName(QString::fromUtf8("actionCreate_the_connection_2"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionAdmit_defeat = new QAction(MainWindow);
        actionAdmit_defeat->setObjectName(QString::fromUtf8("actionAdmit_defeat"));
        actionConnect_to_Server = new QAction(MainWindow);
        actionConnect_to_Server->setObjectName(QString::fromUtf8("actionConnect_to_Server"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 21, 381, 491));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/background.jpg")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(23, 21, 361, 491));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/png/board2.png")));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 50, 81, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font1.setPointSize(14);
        label_3->setFont(font1);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(410, 80, 64, 23));
        lcdNumber->setProperty("value", QVariant(20.000000000000000));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 120, 161, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font2.setPointSize(12);
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(410, 150, 61, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font3.setPointSize(14);
        label_5->setFont(font3);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 60, 54, 12));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 190, 91, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font4.setPointSize(14);
        label_7->setFont(font4);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 220, 61, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font5.setPointSize(10);
        label_8->setFont(font5);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(470, 220, 54, 16));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font6.setPointSize(16);
        label_9->setFont(font6);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(400, 250, 61, 16));
        label_10->setFont(font5);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(470, 250, 54, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(400, 0, 151, 21));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font7.setPointSize(12);
        label_12->setFont(font7);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(400, 30, 121, 16));
        label_13->setFont(font7);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 556, 21));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("SimSun-ExtB")});
        font8.setPointSize(12);
        menubar->setFont(font8);
        menuConnect = new QMenu(menubar);
        menuConnect->setObjectName(QString::fromUtf8("menuConnect"));
        menuPlay = new QMenu(menubar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConnect->menuAction());
        menubar->addAction(menuPlay->menuAction());
        menuConnect->addAction(actionCreate_the_connection_2);
        menuConnect->addAction(actionConnect_to_Server);
        menuConnect->addAction(actionDisconnect);
        menuPlay->addAction(actionStart);
        menuPlay->addAction(actionAdmit_defeat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        actionCreate_the_connection_2->setText(QCoreApplication::translate("MainWindow", "Create the connection", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionAdmit_defeat->setText(QCoreApplication::translate("MainWindow", "Admit defeat", nullptr));
        actionConnect_to_Server->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Time left:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "You are:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "---", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\266\205\346\227\266\346\254\241\346\225\260\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Player 1\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Player 2\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273Play->start\345\274\200\345\247\213", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\257\271\346\226\271\345\267\262\345\207\206\345\244\207...", nullptr));
        menuConnect->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
