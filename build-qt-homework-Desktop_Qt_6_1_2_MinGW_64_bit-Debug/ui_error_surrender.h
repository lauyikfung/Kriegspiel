/********************************************************************************
** Form generated from reading UI file 'error_surrender.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_SURRENDER_H
#define UI_ERROR_SURRENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Error_surrender
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Error_surrender)
    {
        if (Error_surrender->objectName().isEmpty())
            Error_surrender->setObjectName(QString::fromUtf8("Error_surrender"));
        Error_surrender->resize(337, 184);
        label = new QLabel(Error_surrender);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 341, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(Error_surrender);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 110, 101, 31));

        retranslateUi(Error_surrender);
        QObject::connect(pushButton, &QPushButton::clicked, Error_surrender, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Error_surrender);
    } // setupUi

    void retranslateUi(QWidget *Error_surrender)
    {
        Error_surrender->setWindowTitle(QCoreApplication::translate("Error_surrender", "Form", nullptr));
        label->setText(QCoreApplication::translate("Error_surrender", "\345\257\271\344\270\215\350\265\267\357\274\214 \344\275\240\350\277\230\344\270\215\350\203\275\346\212\225\351\231\215\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Error_surrender", "go on\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Error_surrender: public Ui_Error_surrender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_SURRENDER_H
