/********************************************************************************
** Form generated from reading UI file 'Create_the_connection.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_THE_CONNECTION_H
#define UI_CREATE_THE_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_creating_connection
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *creating_connection)
    {
        if (creating_connection->objectName().isEmpty())
            creating_connection->setObjectName(QString::fromUtf8("creating_connection"));
        creating_connection->resize(308, 159);
        label = new QLabel(creating_connection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(creating_connection);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 50, 171, 21));
        label_2->setFont(font);
        pushButton = new QPushButton(creating_connection);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 100, 101, 31));
        pushButton_2 = new QPushButton(creating_connection);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 100, 111, 31));

        retranslateUi(creating_connection);
        QObject::connect(pushButton, &QPushButton::clicked, creating_connection, qOverload<>(&QWidget::close));
        QObject::connect(pushButton_2, &QPushButton::clicked, creating_connection, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(creating_connection);
    } // setupUi

    void retranslateUi(QWidget *creating_connection)
    {
        creating_connection->setWindowTitle(QCoreApplication::translate("creating_connection", "Form", nullptr));
        label->setText(QCoreApplication::translate("creating_connection", "Host IP:", nullptr));
        label_2->setText(QCoreApplication::translate("creating_connection", "192.168.3.181", nullptr));
        pushButton->setText(QCoreApplication::translate("creating_connection", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("creating_connection", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class creating_connection: public Ui_creating_connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_THE_CONNECTION_H
