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
#include <QtWidgets/QLineEdit>
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
    QWidget *widgetSet;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTarget;
    QLineEdit *leTarget;
    QLabel *labGet;
    QTextEdit *textGet;
    QLabel *labSend;
    QTextEdit *textSend;
    QWidget *widgetBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtnConnect;
    QPushButton *pbtnSend;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(388, 514);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetSet = new QWidget(centralwidget);
        widgetSet->setObjectName(QString::fromUtf8("widgetSet"));
        horizontalLayout_2 = new QHBoxLayout(widgetSet);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelTarget = new QLabel(widgetSet);
        labelTarget->setObjectName(QString::fromUtf8("labelTarget"));

        horizontalLayout_2->addWidget(labelTarget);

        leTarget = new QLineEdit(widgetSet);
        leTarget->setObjectName(QString::fromUtf8("leTarget"));

        horizontalLayout_2->addWidget(leTarget);


        verticalLayout->addWidget(widgetSet);

        labGet = new QLabel(centralwidget);
        labGet->setObjectName(QString::fromUtf8("labGet"));

        verticalLayout->addWidget(labGet);

        textGet = new QTextEdit(centralwidget);
        textGet->setObjectName(QString::fromUtf8("textGet"));

        verticalLayout->addWidget(textGet);

        labSend = new QLabel(centralwidget);
        labSend->setObjectName(QString::fromUtf8("labSend"));

        verticalLayout->addWidget(labSend);

        textSend = new QTextEdit(centralwidget);
        textSend->setObjectName(QString::fromUtf8("textSend"));
        textSend->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(textSend);

        widgetBtn = new QWidget(centralwidget);
        widgetBtn->setObjectName(QString::fromUtf8("widgetBtn"));
        horizontalLayout = new QHBoxLayout(widgetBtn);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbtnConnect = new QPushButton(widgetBtn);
        pbtnConnect->setObjectName(QString::fromUtf8("pbtnConnect"));

        horizontalLayout->addWidget(pbtnConnect);

        pbtnSend = new QPushButton(widgetBtn);
        pbtnSend->setObjectName(QString::fromUtf8("pbtnSend"));

        horizontalLayout->addWidget(pbtnSend);


        verticalLayout->addWidget(widgetBtn);

        MainWindow->setCentralWidget(centralwidget);
#if QT_CONFIG(shortcut)
        labelTarget->setBuddy(leTarget);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTarget->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207ip\357\274\232", nullptr));
        leTarget->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        labGet->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\224\266\345\210\260\344\277\241\346\201\257", nullptr));
        labSend->setText(QCoreApplication::translate("MainWindow", "\345\276\205\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pbtnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pbtnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
