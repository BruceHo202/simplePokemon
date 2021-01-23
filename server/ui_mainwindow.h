/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *startinfo;
    QLabel *cltaction;
    QLabel *seraction;
    QLabel *cltlife;
    QLabel *serlife;
    QLabel *notification;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *user;
    QLabel *pwd;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *medal;
    QLabel *medal_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1314, 791);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startinfo = new QLabel(centralWidget);
        startinfo->setObjectName(QStringLiteral("startinfo"));
        startinfo->setGeometry(QRect(200, 120, 651, 71));
        startinfo->setFrameShape(QFrame::Box);
        cltaction = new QLabel(centralWidget);
        cltaction->setObjectName(QStringLiteral("cltaction"));
        cltaction->setGeometry(QRect(10, 290, 501, 51));
        cltaction->setFrameShape(QFrame::Box);
        seraction = new QLabel(centralWidget);
        seraction->setObjectName(QStringLiteral("seraction"));
        seraction->setGeometry(QRect(10, 380, 501, 51));
        seraction->setFrameShape(QFrame::Box);
        cltlife = new QLabel(centralWidget);
        cltlife->setObjectName(QStringLiteral("cltlife"));
        cltlife->setGeometry(QRect(550, 290, 611, 51));
        cltlife->setFrameShape(QFrame::Box);
        serlife = new QLabel(centralWidget);
        serlife->setObjectName(QStringLiteral("serlife"));
        serlife->setGeometry(QRect(550, 380, 611, 51));
        serlife->setFrameShape(QFrame::Box);
        notification = new QLabel(centralWidget);
        notification->setObjectName(QStringLiteral("notification"));
        notification->setGeometry(QRect(230, 550, 651, 41));
        notification->setFrameShape(QFrame::Box);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 250, 261, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 340, 261, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(480, 10, 681, 111));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);
        user = new QLabel(centralWidget);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(140, 480, 351, 31));
        user->setFrameShape(QFrame::Box);
        pwd = new QLabel(centralWidget);
        pwd->setObjectName(QStringLiteral("pwd"));
        pwd->setGeometry(QRect(540, 480, 351, 31));
        pwd->setFrameShape(QFrame::Box);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 440, 181, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(540, 440, 181, 21));
        medal = new QLabel(centralWidget);
        medal->setObjectName(QStringLiteral("medal"));
        medal->setGeometry(QRect(230, 620, 651, 41));
        medal->setFrameShape(QFrame::NoFrame);
        medal_2 = new QLabel(centralWidget);
        medal_2->setObjectName(QStringLiteral("medal_2"));
        medal_2->setGeometry(QRect(230, 690, 651, 41));
        medal_2->setFrameShape(QFrame::NoFrame);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1314, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        startinfo->setText(QString());
        cltaction->setText(QString());
        seraction->setText(QString());
        cltlife->setText(QString());
        serlife->setText(QString());
        notification->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\350\241\214\344\270\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\350\241\214\344\270\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        user->setText(QString());
        pwd->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\232\204\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\232\204\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        medal->setText(QString());
        medal_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
