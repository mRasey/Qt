/********************************************************************************
** Form generated from reading UI file 'udp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDP_H
#define UI_UDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDPClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *dialogBrowser;
    QTextEdit *dialogEdit;
    QPushButton *sendButton;
    QPushButton *flushButton;
    QLabel *MyIpLabel;
    QListWidget *IpListWidget;
    QLabel *chatIpLabel;
    QLabel *label;
    QPushButton *appointIpButton;
    QTextEdit *appointIpEdit;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UDPClass)
    {
        if (UDPClass->objectName().isEmpty())
            UDPClass->setObjectName(QStringLiteral("UDPClass"));
        UDPClass->resize(590, 404);
        UDPClass->setMinimumSize(QSize(590, 404));
        UDPClass->setMaximumSize(QSize(590, 404));
        centralWidget = new QWidget(UDPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dialogBrowser = new QTextBrowser(centralWidget);
        dialogBrowser->setObjectName(QStringLiteral("dialogBrowser"));
        dialogBrowser->setGeometry(QRect(0, 30, 441, 271));
        dialogEdit = new QTextEdit(centralWidget);
        dialogEdit->setObjectName(QStringLiteral("dialogEdit"));
        dialogEdit->setGeometry(QRect(0, 300, 441, 81));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(440, 340, 151, 41));
        flushButton = new QPushButton(centralWidget);
        flushButton->setObjectName(QStringLiteral("flushButton"));
        flushButton->setGeometry(QRect(440, 300, 71, 41));
        MyIpLabel = new QLabel(centralWidget);
        MyIpLabel->setObjectName(QStringLiteral("MyIpLabel"));
        MyIpLabel->setGeometry(QRect(10, 0, 221, 31));
        IpListWidget = new QListWidget(centralWidget);
        IpListWidget->setObjectName(QStringLiteral("IpListWidget"));
        IpListWidget->setGeometry(QRect(440, 50, 151, 251));
        chatIpLabel = new QLabel(centralWidget);
        chatIpLabel->setObjectName(QStringLiteral("chatIpLabel"));
        chatIpLabel->setGeometry(QRect(250, 0, 191, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 10, 91, 20));
        appointIpButton = new QPushButton(centralWidget);
        appointIpButton->setObjectName(QStringLiteral("appointIpButton"));
        appointIpButton->setGeometry(QRect(520, 300, 71, 41));
        appointIpEdit = new QTextEdit(centralWidget);
        appointIpEdit->setObjectName(QStringLiteral("appointIpEdit"));
        appointIpEdit->setGeometry(QRect(440, 30, 171, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(506, 300, 20, 41));
        UDPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UDPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UDPClass->setStatusBar(statusBar);

        retranslateUi(UDPClass);

        QMetaObject::connectSlotsByName(UDPClass);
    } // setupUi

    void retranslateUi(QMainWindow *UDPClass)
    {
        UDPClass->setWindowTitle(QApplication::translate("UDPClass", "UDP", 0));
        sendButton->setText(QApplication::translate("UDPClass", "\345\217\221\351\200\201\346\266\210\346\201\257", 0));
        flushButton->setText(QApplication::translate("UDPClass", "\345\210\267\346\226\260\345\210\227\350\241\250", 0));
        MyIpLabel->setText(QString());
        chatIpLabel->setText(QString());
        label->setText(QApplication::translate("UDPClass", "\350\201\224\347\263\273\344\272\272\345\210\227\350\241\250", 0));
        appointIpButton->setText(QApplication::translate("UDPClass", "\346\214\207\345\256\232IP", 0));
#ifndef QT_NO_TOOLTIP
        appointIpEdit->setToolTip(QApplication::translate("UDPClass", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UDPClass: public Ui_UDPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDP_H
