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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *notification_firm;
    QComboBox *req;
    QPushButton *confirm_req;
    QLineEdit *username;
    QLineEdit *pwd;
    QLabel *label;
    QLabel *label_2;
    QComboBox *battlekind;
    QPushButton *confirm_battlekind;
    QPushButton *confirm_userpwd;
    QLabel *notification_timer;
    QComboBox *mypet;
    QPushButton *confirm_myChoice;
    QPushButton *confirm_enemy;
    QComboBox *serpet;
    QLabel *feedback;
    QPushButton *confirm_sendpet;
    QComboBox *sendpet;
    QLineEdit *giveup;
    QComboBox *showmypet;
    QLabel *label_3;
    QLabel *win_rate;
    QLabel *label_4;
    QLabel *count_medal;
    QLabel *label_5;
    QLabel *quality_medal;
    QLabel *showmypet_label;
    QLabel *choose_note;
    QLabel *send_list_note;
    QPushButton *quit;
    QPushButton *opr0;
    QPushButton *opr1;
    QLabel *serlife;
    QLabel *cltlife;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *onlinecltlabel;
    QComboBox *onlinecltcombo;
    QLabel *label_8;
    QLineEdit *getmychoice;
    QLineEdit *getenemy;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1764, 875);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        notification_firm = new QLabel(centralWidget);
        notification_firm->setObjectName(QStringLiteral("notification_firm"));
        notification_firm->setGeometry(QRect(30, -10, 651, 61));
        notification_firm->setFrameShape(QFrame::Box);
        req = new QComboBox(centralWidget);
        req->setObjectName(QStringLiteral("req"));
        req->setGeometry(QRect(30, 120, 291, 51));
        confirm_req = new QPushButton(centralWidget);
        confirm_req->setObjectName(QStringLiteral("confirm_req"));
        confirm_req->setGeometry(QRect(60, 190, 221, 41));
        username = new QLineEdit(centralWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(370, 160, 201, 41));
        pwd = new QLineEdit(centralWidget);
        pwd->setObjectName(QStringLiteral("pwd"));
        pwd->setGeometry(QRect(370, 240, 201, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 120, 171, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 200, 171, 31));
        battlekind = new QComboBox(centralWidget);
        battlekind->setObjectName(QStringLiteral("battlekind"));
        battlekind->setGeometry(QRect(50, 380, 281, 41));
        confirm_battlekind = new QPushButton(centralWidget);
        confirm_battlekind->setObjectName(QStringLiteral("confirm_battlekind"));
        confirm_battlekind->setGeometry(QRect(50, 430, 221, 41));
        confirm_userpwd = new QPushButton(centralWidget);
        confirm_userpwd->setObjectName(QStringLiteral("confirm_userpwd"));
        confirm_userpwd->setGeometry(QRect(370, 310, 221, 41));
        notification_timer = new QLabel(centralWidget);
        notification_timer->setObjectName(QStringLiteral("notification_timer"));
        notification_timer->setGeometry(QRect(30, 50, 651, 61));
        notification_timer->setFrameShape(QFrame::Box);
        mypet = new QComboBox(centralWidget);
        mypet->setObjectName(QStringLiteral("mypet"));
        mypet->setGeometry(QRect(50, 500, 521, 41));
        confirm_myChoice = new QPushButton(centralWidget);
        confirm_myChoice->setObjectName(QStringLiteral("confirm_myChoice"));
        confirm_myChoice->setGeometry(QRect(50, 600, 221, 41));
        confirm_enemy = new QPushButton(centralWidget);
        confirm_enemy->setObjectName(QStringLiteral("confirm_enemy"));
        confirm_enemy->setGeometry(QRect(50, 770, 221, 41));
        serpet = new QComboBox(centralWidget);
        serpet->setObjectName(QStringLiteral("serpet"));
        serpet->setGeometry(QRect(50, 670, 521, 41));
        feedback = new QLabel(centralWidget);
        feedback->setObjectName(QStringLiteral("feedback"));
        feedback->setGeometry(QRect(700, 40, 651, 61));
        feedback->setFrameShape(QFrame::Box);
        confirm_sendpet = new QPushButton(centralWidget);
        confirm_sendpet->setObjectName(QStringLiteral("confirm_sendpet"));
        confirm_sendpet->setGeometry(QRect(590, 640, 221, 41));
        sendpet = new QComboBox(centralWidget);
        sendpet->setObjectName(QStringLiteral("sendpet"));
        sendpet->setGeometry(QRect(590, 440, 591, 41));
        giveup = new QLineEdit(centralWidget);
        giveup->setObjectName(QStringLiteral("giveup"));
        giveup->setGeometry(QRect(590, 560, 221, 41));
        showmypet = new QComboBox(centralWidget);
        showmypet->setObjectName(QStringLiteral("showmypet"));
        showmypet->setGeometry(QRect(620, 180, 481, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1590, 200, 161, 41));
        win_rate = new QLabel(centralWidget);
        win_rate->setObjectName(QStringLiteral("win_rate"));
        win_rate->setGeometry(QRect(1590, 240, 151, 41));
        win_rate->setFrameShape(QFrame::Box);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1590, 340, 161, 41));
        count_medal = new QLabel(centralWidget);
        count_medal->setObjectName(QStringLiteral("count_medal"));
        count_medal->setGeometry(QRect(1590, 380, 151, 41));
        count_medal->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1590, 470, 161, 41));
        quality_medal = new QLabel(centralWidget);
        quality_medal->setObjectName(QStringLiteral("quality_medal"));
        quality_medal->setGeometry(QRect(1590, 510, 151, 41));
        quality_medal->setFrameShape(QFrame::Box);
        showmypet_label = new QLabel(centralWidget);
        showmypet_label->setObjectName(QStringLiteral("showmypet_label"));
        showmypet_label->setGeometry(QRect(710, 120, 261, 51));
        choose_note = new QLabel(centralWidget);
        choose_note->setObjectName(QStringLiteral("choose_note"));
        choose_note->setGeometry(QRect(590, 490, 231, 51));
        send_list_note = new QLabel(centralWidget);
        send_list_note->setObjectName(QStringLiteral("send_list_note"));
        send_list_note->setGeometry(QRect(590, 370, 231, 51));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(1380, 290, 191, 51));
        opr0 = new QPushButton(centralWidget);
        opr0->setObjectName(QStringLiteral("opr0"));
        opr0->setGeometry(QRect(1130, 250, 191, 51));
        opr1 = new QPushButton(centralWidget);
        opr1->setObjectName(QStringLiteral("opr1"));
        opr1->setGeometry(QRect(1130, 330, 191, 51));
        serlife = new QLabel(centralWidget);
        serlife->setObjectName(QStringLiteral("serlife"));
        serlife->setGeometry(QRect(910, 630, 581, 41));
        serlife->setFrameShape(QFrame::Box);
        cltlife = new QLabel(centralWidget);
        cltlife->setObjectName(QStringLiteral("cltlife"));
        cltlife->setGeometry(QRect(910, 730, 581, 41));
        cltlife->setFrameShape(QFrame::Box);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(910, 590, 751, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(910, 690, 751, 31));
        onlinecltlabel = new QLabel(centralWidget);
        onlinecltlabel->setObjectName(QStringLiteral("onlinecltlabel"));
        onlinecltlabel->setGeometry(QRect(610, 260, 361, 41));
        onlinecltcombo = new QComboBox(centralWidget);
        onlinecltcombo->setObjectName(QStringLiteral("onlinecltcombo"));
        onlinecltcombo->setGeometry(QRect(610, 320, 471, 41));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(700, 0, 411, 41));
        getmychoice = new QLineEdit(centralWidget);
        getmychoice->setObjectName(QStringLiteral("getmychoice"));
        getmychoice->setGeometry(QRect(50, 550, 211, 41));
        getenemy = new QLineEdit(centralWidget);
        getenemy->setObjectName(QStringLiteral("getenemy"));
        getenemy->setGeometry(QRect(50, 720, 211, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1764, 21));
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
        notification_firm->setText(QString());
        req->clear();
        req->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\257\267\346\261\202\357\274\232", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\212\240\345\205\245\346\210\230\346\226\227", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\211\200\346\234\211\345\234\250\347\272\277\347\224\250\346\210\267", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\345\256\240\347\211\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\234\215\345\212\241\345\231\250\345\256\240\347\211\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\350\203\234\347\216\207\345\222\214\345\245\226\347\211\214\346\246\234", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\351\200\200\345\207\272", Q_NULLPTR)
        );
        confirm_req->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        battlekind->clear();
        battlekind->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\210\230\346\226\227\347\261\273\345\236\213", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\215\207\347\272\247\350\265\233", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\206\263\346\226\227\350\265\233", Q_NULLPTR)
        );
        confirm_battlekind->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        confirm_userpwd->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        notification_timer->setText(QString());
        mypet->clear();
        mypet->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\275\240\347\232\204\345\217\257\351\200\211\345\256\240\347\211\251\346\234\211\357\274\232", Q_NULLPTR)
        );
        confirm_myChoice->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        confirm_enemy->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        serpet->clear();
        serpet->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\347\232\204\345\256\240\347\211\251\346\234\211\357\274\232", Q_NULLPTR)
        );
        feedback->setText(QString());
        confirm_sendpet->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        sendpet->clear();
        sendpet->insertItems(0, QStringList()
         << QString()
        );
        showmypet->clear();
        showmypet->insertItems(0, QStringList()
         << QString()
        );
        label_3->setText(QApplication::translate("MainWindow", "\350\203\234\347\216\207", Q_NULLPTR));
        win_rate->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\345\256\240\347\211\251\344\270\252\346\225\260\345\276\275\347\253\240", Q_NULLPTR));
        count_medal->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\351\253\230\347\272\247\345\256\240\347\211\251\345\276\275\347\253\240", Q_NULLPTR));
        quality_medal->setText(QString());
        showmypet_label->setText(QString());
        choose_note->setText(QString());
        send_list_note->setText(QString());
        quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\345\257\271\346\210\230", Q_NULLPTR));
        opr0->setText(QApplication::translate("MainWindow", "\346\231\256\351\200\232\346\224\273\345\207\273", Q_NULLPTR));
        opr1->setText(QApplication::translate("MainWindow", "\345\244\247\346\213\233", Q_NULLPTR));
        serlife->setText(QString());
        cltlife->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\345\257\271\346\210\230\344\270\255\346\234\215\345\212\241\345\231\250\347\224\237\345\221\275\345\200\274\345\222\214\347\273\217\351\252\214\345\200\274", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\257\271\346\210\230\344\270\255\345\256\242\346\210\267\347\253\257\347\224\237\345\221\275\345\200\274\345\222\214\347\273\217\351\252\214\345\200\274", Q_NULLPTR));
        onlinecltlabel->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\344\273\216\346\234\215\345\212\241\345\231\250\346\224\266\345\210\260\347\232\204\345\217\215\351\246\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
