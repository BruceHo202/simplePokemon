#ifndef CONTENT_H
#define CONTENT_H

#include<QTextCodec>
#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolButton>
#include<QDebug>
#include<QTimer>
#include<QThread>
#include<QObject>


#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<conio.h>
#include<WS2tcpip.h>
#include <WinSock2.h>
#include<Windows.h>
#include<map>
//#pragma warning(disable:4996)
//#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

using namespace std;

#define POWER 0//力量型
#define SHIELD 1//肉盾型
#define DEFENSE 2//防御型
#define AGILE 3//敏捷型

extern map<int, string>nameMap;

extern map<int, string>atkMethodMap;

extern map<int ,string>bigMethodMap;

class INITNAMEMAP {
public:
    void initNameMap();
    //void initNameMap() {
    //	nameMap.insert(pair<int, string>(0, "沙瓦朗"));//power
    //	nameMap.insert(pair<int, string>(1, "火爆猴"));
    //	nameMap.insert(pair<int, string>(2, "腕力"));
    //	nameMap.insert(pair<int, string>(3, "吼鲸王"));//shield
    //	nameMap.insert(pair<int, string>(4, "果然翁"));
    //	nameMap.insert(pair<int, string>(5, "卡比兽"));
    //	nameMap.insert(pair<int, string>(6, "喷火龙"));//defense
    //	nameMap.insert(pair<int, string>(7, "大钢蛇"));
    //	nameMap.insert(pair<int, string>(8, "铁甲贝"));
    //	nameMap.insert(pair<int, string>(9, "狃拉"));//agile
    //	nameMap.insert(pair<int, string>(10, "敏捷虫"));
    //	nameMap.insert(pair<int, string>(11, "叉字蝠"));
    //}
};

class INITMETHODMAP {
public:
    void initMethodMap();
    //void initMethodMap() {
    //	atkMethodMap.insert(pair<int, string>(0, "飞膝踢"));//power
    //	atkMethodMap.insert(pair<int, string>(1, "过肩摔"));
    //	atkMethodMap.insert(pair<int, string>(2, "百万拳击"));
    //	atkMethodMap.insert(pair<int, string>(3, "重磅冲撞"));//shield
    //	atkMethodMap.insert(pair<int, string>(4, "神秘护身"));
    //	atkMethodMap.insert(pair<int, string>(5, "防卫卷"));
    //	atkMethodMap.insert(pair<int, string>(6, "喷射火焰"));//defense
    //	atkMethodMap.insert(pair<int, string>(7, "岩石封闭"));
    //	atkMethodMap.insert(pair<int, string>(8, "超音波"));
    //	atkMethodMap.insert(pair<int, string>(9, "电光石火"));//agile
    //	atkMethodMap.insert(pair<int, string>(10, "高速星星"));
    //	atkMethodMap.insert(pair<int, string>(11, "翅膀拍击"));
    //}
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

    pet() {}
    pet(int n);
    pet(pet& p);
    ~pet() {}

    void upper();
    void lifeback();
    virtual void doAttack(double p) {
        exp += 50 * 1.0 * p;
        if (exp >= 500&&level!=15) {
            upper();
        }
    }
    virtual void doBIGATK(double p) {
        exp += 70 * 1.0 * p;
        if (exp >= 500&&level!=15) {
            upper();
        }
    }
    virtual void beAtked(pet* p, double possible) {
        double t = possible * p->atk - dfd;
        if (t > 0.1) {
            life -= 0.3 * t;
        }
    }
    virtual void beBIGATKED(pet* p, double possible) {
        double t = possible * p->bigATK - dfd;
        if (t >= 0.05) {
            life -= 0.3 * t;
        }
    }
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
struct thisclt {
    CLT clt;
    int myChoice;
    int enemy;
};
extern thisclt A;

class socketEvent {
public:
    void initCltInfo(Ui_MainWindow* ui);
};

class showfeedback{
public:
    void output_feedback(char* feedback,Ui_MainWindow* ui);
};

class MYThread{
public:
    static DWORD WINAPI mythread(LPVOID lpParameter);
    static DWORD WINAPI timerthread(LPVOID lpParameter);
};

extern int req;
extern char g_name[20], g_pwd[20];
extern int enteringflag;

#endif
