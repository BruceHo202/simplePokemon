#include "mainwindow.h"
#include <QApplication>
#include"content.h"

DWORD WINAPI MYThread::mythread(LPVOID lpParameter){
    Ui_MainWindow* ui=(Ui_MainWindow*)lpParameter;
    socketEvent b;
    b.initCltInfo(ui);
    return 0;
}

//DWORD WINAPI mythread(LPVOID lpParameter){
//    Ui_MainWindow* ui=(Ui_MainWindow*)lpParameter;
//    socketEvent b;
//    b.initCltInfo(ui);
//    return 0;
//}

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    Ui_MainWindow *ui;
    ui=w.ui;

    INITNAMEMAP M;
    M.initNameMap();
    INITMETHODMAP N;
    N.initMethodMap();
    N.initBigMap();
    cltCount = 0;
    ui->pwd->setEchoMode(QLineEdit::Password);

//    QObject::connect(ui->start,&QToolButton::clicked,[=](){
//        ui->startinfo->setText("a");
//    });


    MYThread m;
    CreateThread(NULL,0,&m.mythread,ui,0,NULL);


    return a.exec();
}
