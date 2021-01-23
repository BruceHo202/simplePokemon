#ifndef CONTENT_H
#define CONTENT_H

#include<QTextCodec>
#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolButton>
#include<QDebug>
#include<QTimer>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdlib.h>
#include<iostream>
#include<time.h>
#include<string>
#include<cstring>
#include<conio.h>
#include<WS2tcpip.h>
#include <WinSock2.h>//一般情况下,这个头文件位于windows.h之前,避免发生某些错误
#include<Windows.h>
#include<map>
#include<fstream>
//#pragma warning(disable:4996)
//#pragma comment(lib, "ws2_32.lib")
using namespace std;
#define POWER 0//力量型
#define SHIELD 1//肉盾型
#define DEFENSE 2//防御型
#define AGILE 3//敏捷型

extern map<int, string>nameMap;

extern clock_t server_last_time;
extern clock_t client_last_time;
extern clock_t server_big_last_time;
extern clock_t client_big_last_time;
extern int start_s_atk;
extern int start_c_atk;
extern int start_s_big_atk;
extern int start_c_big_atk;

extern map<int, string>atkMethodMap;

extern map<int,string>bigMethodMap;

class INITNAMEMAP {
public:
    void initNameMap();
};

class INITMETHODMAP {
public:
    void initMethodMap();
    void initBigMap();
};


class pet {
public:
    int petNum;
    int kind;
    char name[50];
    int atkMethod;//攻击方式
    int level;//等级
    double exp;//经验值
    double atk;//攻击力
    double dfd;//防御力
    double life;//生命值
    double slot;//攻击间隔

    double bigATK;
    double bigSLOT;

    pet(){}
    pet(int n);
    pet(pet& p);
    ~pet() {}

    virtual void doAttack(double p){}
    virtual void doBIGATK(double p){}
    virtual void beAtked(pet *p, double possible){}
    virtual void beBIGATKED(pet *p, double possible){}
    void upper();
    void lifeback();
};
class power:public pet{
public:
    power(int n);
    power(const pet& p);
    virtual void doAttack(double p);
    virtual void doBIGATK(double p);
    virtual void beAtked(pet* p, double possible);
    virtual void beBIGATKED(pet* p, double possible);
};
class shield:public pet{
public:
    shield(int n);
    shield(const pet& p);
    virtual void doAttack(double p);
    virtual void doBIGATK(double p);
    virtual void beAtked(pet* p, double possible);
    virtual void beBIGATKED(pet* p, double possible);
};
class defense:public pet{
public:
    defense(int n);
    defense(const pet& p);
    virtual void doAttack(double p) ;
    virtual void doBIGATK(double p) ;
    virtual void beAtked(pet* p, double possible);
    virtual void beBIGATKED(pet* p, double possible);
};
class agile:public pet{
public:
    agile(int n);
    agile(const pet& p);
    virtual void doAttack(double p);
    virtual void doBIGATK(double p);
    virtual void beAtked(pet* p, double possible);
    virtual void beBIGATKED(pet* p, double possible);
};
struct CLT {
    char cltName[20];
    char password[20];
    pet myPet[50];
    int petCount;
    int socketnum;
    int online;
    int in_war;
    int war_time;
    int win_time;
    double win_rate;
    int pet_count_medal;//0金 1银 2铜
    int high_pet_count;
    int high_level_pet_medal;//0金 1银 2铜
};
extern CLT clt[101];//clt[100]是服务器
extern int cltCount;

class player {
public:
    player() {}
    ~player() {}
    int upgradeBattle(CLT* cli, CLT* ser, int myChoice, int enemy, int mode,Ui_MainWindow* ui);
};

class socketEvent {
public:
    void initCltInfo(Ui_MainWindow *ui);

};

struct msg {
    int kind;
    char name[20];
    char pwd[20];
    char feedback[100];
    int atk;
    int beAtk;
    int onlinecount;
    char allname[100][20];
    int battleKind;
    int myChoice;
    int enemy;
    int win;
    CLT myClt;
    CLT server;
    CLT medalclt;//kind=20
    CLT petclt;//kind=12
    int bigATK;
    int choose[3];
    int giveup;
    int allpet[100];
    int petCount;
};

extern int stop_server_atk;

class Action {
public:
    void signup(msg* M, msg* N);
    int login(msg* M, msg* N, SOCKET* recvClientSocket, int myChoice, int enemy);
    void logout(msg* M, msg* N, SOCKET* recvClientSocket);
    void joinBattle(msg* M, msg* N, SOCKET* recvClientSocket, int* battleKind, int* myChoice, int* enemy,Ui_MainWindow* ui);
    void battling(msg* M, msg* N, SOCKET* recvClientSocket, int* battleKind, int* myChoice, int* enemy,Ui_MainWindow* ui);
    void exitBattle(msg* M, msg* N, SOCKET* recvClientSocket, int* myChoice, int* enemy, Ui_MainWindow* ui);
    void queryOnlineCLT(msg* M, msg* N);
    void showBattleResult(msg* M, msg* N);
    void queryCltPet(msg* M, msg* N);
    void querySerPet(msg* M, msg* N);
    void queryMedal(msg* M, msg* N);
};

class MYThread{
public:
    static DWORD WINAPI mythread(LPVOID lpParameter);
    static DWORD WINAPI ServerThread(LPVOID lpParameter);
    static DWORD WINAPI serverATK(LPVOID lpParameter);
    static DWORD WINAPI timerthread(LPVOID lpParameter);
    static DWORD WINAPI medalthread(LPVOID lpParameter);
    static DWORD WINAPI medalthread_2(LPVOID lpParameter);
};

extern int ser_buffered;

#endif
