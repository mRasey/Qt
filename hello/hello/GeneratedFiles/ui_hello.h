/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *helloClass)
    {
        if (helloClass->objectName().isEmpty())
            helloClass->setObjectName(QStringLiteral("helloClass"));
        helloClass->resize(600, 400);
        menuBar = new QMenuBar(helloClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        helloClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(helloClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        helloClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(helloClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        helloClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(helloClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        helloClass->setStatusBar(statusBar);

        retranslateUi(helloClass);

        QMetaObject::connectSlotsByName(helloClass);
    } // setupUi

    void retranslateUi(QMainWindow *helloClass)
    {
        helloClass->setWindowTitle(QApplication::translate("helloClass", "hello", 0));
    } // retranslateUi

};

namespace Ui {
    class helloClass: public Ui_helloClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
