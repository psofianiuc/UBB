/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

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

class Ui_taskManagerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *taskManagerClass)
    {
        if (taskManagerClass->objectName().isEmpty())
            taskManagerClass->setObjectName(QStringLiteral("taskManagerClass"));
        taskManagerClass->resize(600, 400);
        menuBar = new QMenuBar(taskManagerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        taskManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(taskManagerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        taskManagerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(taskManagerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        taskManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(taskManagerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        taskManagerClass->setStatusBar(statusBar);

        retranslateUi(taskManagerClass);

        QMetaObject::connectSlotsByName(taskManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *taskManagerClass)
    {
        taskManagerClass->setWindowTitle(QApplication::translate("taskManagerClass", "taskManager", 0));
    } // retranslateUi

};

namespace Ui {
    class taskManagerClass: public Ui_taskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
