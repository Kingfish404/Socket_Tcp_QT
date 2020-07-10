/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelGet;
    QTextEdit *textGet;
    QLabel *labelSend;
    QTextEdit *textSend;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pBtnSendToAll;
    QPushButton *pBtnSend;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 531);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelGet = new QLabel(centralwidget);
        labelGet->setObjectName(QString::fromUtf8("labelGet"));

        verticalLayout->addWidget(labelGet);

        textGet = new QTextEdit(centralwidget);
        textGet->setObjectName(QString::fromUtf8("textGet"));

        verticalLayout->addWidget(textGet);

        labelSend = new QLabel(centralwidget);
        labelSend->setObjectName(QString::fromUtf8("labelSend"));

        verticalLayout->addWidget(labelSend);

        textSend = new QTextEdit(centralwidget);
        textSend->setObjectName(QString::fromUtf8("textSend"));
        textSend->setMaximumSize(QSize(16777215, 200));

        verticalLayout->addWidget(textSend);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pBtnSendToAll = new QPushButton(widget);
        pBtnSendToAll->setObjectName(QString::fromUtf8("pBtnSendToAll"));

        horizontalLayout->addWidget(pBtnSendToAll);

        pBtnSend = new QPushButton(widget);
        pBtnSend->setObjectName(QString::fromUtf8("pBtnSend"));

        horizontalLayout->addWidget(pBtnSend);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelGet->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\216\245\346\224\266\344\277\241\346\201\257", nullptr));
        labelSend->setText(QCoreApplication::translate("MainWindow", "\345\276\205\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pBtnSendToAll->setText(QCoreApplication::translate("MainWindow", "\347\276\244\345\217\221", nullptr));
        pBtnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
