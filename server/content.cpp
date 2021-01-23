#include"content.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

map<int, string>nameMap;

clock_t server_last_time=0;
clock_t client_last_time=0;
clock_t server_big_last_time=0;
clock_t client_big_last_time=0;
int start_s_atk=0;
int start_c_atk=0;
int start_s_big_atk=0;
int start_c_big_atk=0;

int ser_buffered=0;

map<int, string>atkMethodMap;

map<int,string>bigMethodMap;

void INITNAMEMAP::initNameMap() {
    nameMap.insert(pair<int, string>(0, "沙瓦朗"));//power
    nameMap.insert(pair<int, string>(1, "火爆猴"));
    nameMap.insert(pair<int, string>(2, "腕力"));
    nameMap.insert(pair<int, string>(3, "吼鲸王"));//shield
    nameMap.insert(pair<int, string>(4, "果然翁"));
    nameMap.insert(pair<int, string>(5, "卡比兽"));
    nameMap.insert(pair<int, string>(6, "喷火龙"));//defense
    nameMap.insert(pair<int, string>(7, "大钢蛇"));
    nameMap.insert(pair<int, string>(8, "铁甲贝"));
    nameMap.insert(pair<int, string>(9, "狃拉"));//agile
    nameMap.insert(pair<int, string>(10, "敏捷虫"));
    nameMap.insert(pair<int, string>(11, "叉字蝠"));
}

void INITMETHODMAP::initMethodMap() {
    atkMethodMap.insert(pair<int, string>(0, "飞膝踢"));//power
    atkMethodMap.insert(pair<int, string>(1, "过肩摔"));
    atkMethodMap.insert(pair<int, string>(2, "百万拳击"));
    atkMethodMap.insert(pair<int, string>(3, "重磅冲撞"));//shield
    atkMethodMap.insert(pair<int, string>(4, "神秘护身"));
    atkMethodMap.insert(pair<int, string>(5, "防卫卷"));
    atkMethodMap.insert(pair<int, string>(6, "喷射火焰"));//defense
    atkMethodMap.insert(pair<int, string>(7, "岩石封闭"));
    atkMethodMap.insert(pair<int, string>(8, "超音波"));
    atkMethodMap.insert(pair<int, string>(9, "电光石火"));//agile
    atkMethodMap.insert(pair<int, string>(10, "高速星星"));
    atkMethodMap.insert(pair<int, string>(11, "翅膀拍击"));
}

void INITMETHODMAP::initBigMap(){
    bigMethodMap.insert(pair<int, string>(0, "近身打"));//power
    bigMethodMap.insert(pair<int, string>(1, "恶意追击"));
    bigMethodMap.insert(pair<int, string>(2, "山崩地裂"));
    bigMethodMap.insert(pair<int, string>(3, "睡觉"));//shield
    bigMethodMap.insert(pair<int, string>(4, "镜子外衣"));
    bigMethodMap.insert(pair<int, string>(5, "沉重轰炸"));
    bigMethodMap.insert(pair<int, string>(6, "地狱滚动"));//defense
    bigMethodMap.insert(pair<int, string>(7, "流沙地狱"));
    bigMethodMap.insert(pair<int, string>(8, "冰柱坠击"));
    bigMethodMap.insert(pair<int, string>(9, "钢之爪"));//agile
    bigMethodMap.insert(pair<int, string>(10, "酸液炸弹"));
    bigMethodMap.insert(pair<int, string>(11, "英勇之鸟"));
}


pet::pet(int n) {
    petNum = n;
    kind = n / 3;
    map<int, string>::iterator iter;
    iter = nameMap.find(n);
    strncpy(name, iter->second.c_str(), iter->second.length() + 1);
    //name = iter->second;
    atkMethod = n;
    level = 1;
    exp = 0.0;
    if (kind == POWER)
        atk = 100;
    else
        atk = 50;
    if (kind == SHIELD)
        life = 200;
    else
        life = 150;
    if (kind == DEFENSE)
        dfd = 20;
    else
        dfd = 10;
    if (kind == AGILE)
        slot = 1500;
    else
        slot = 2000;
    bigATK = 2.0 * atk;
    bigSLOT = 1.3 * slot;
}

pet::pet(pet& p) {
    this->petNum = p.petNum;
    this->kind = p.kind;
    strcpy(this->name, p.name);
    this->atkMethod = p.atkMethod;
    this->level = p.level;
    this->exp = p.exp;
    this->atk = p.atk;
    this->dfd = p.dfd;
    this->life = p.life;
    this->slot = p.slot;
    this->bigATK = p.bigATK;
    this->bigSLOT = p.bigSLOT;
}
void pet::upper(){
    switch (kind) {
    case POWER:

        level++;
        exp -= 300;
        atk += 50;
        dfd += 3;
        life += 60;
        if(slot>200)
            slot -= 60;

        break;
    case SHIELD:

        level++;
        exp -= 300;
        atk += 30;
        dfd += 3;
        life += 80;
        if(slot>200)
            slot -= 60;

        break;
    case DEFENSE:

        level++;
        exp -= 300;
        atk += 30;
        dfd += 5;
        life += 60;
        if(slot>200)
            slot -= 60;

        break;
    case AGILE:

        level++;
        exp -= 300;
        atk += 30;
        dfd += 3;
        life += 60;
        if(slot>200)
            slot -= 80;

        break;
    }
    bigATK = atk * 2;
    bigSLOT = slot * 1.3;
}
void pet::lifeback(){
    if (kind == SHIELD) {
        life = 200;
        for (int i = 1; i < level; i++) {
            life += 80;
        }
    }
    else {
        life = 150;
        for (int i = 1; i < level; i++) {
            life += 60;
        }
    }
}

power::power(int n):pet(n){

    petNum = n;
    kind = n / 3;
    map<int, string>::iterator iter;
    iter = nameMap.find(n);
    strncpy(name, iter->second.c_str(), iter->second.length() + 1);
    //name = iter->second;
    atkMethod = n;
    level = 1;
    exp = 0.0;

    atk = 100;
    life = 150;
    dfd = 10;
    slot = 2000;
    bigATK = 2.0 * atk;
    bigSLOT = 1.3 * slot;
}
power::power(const pet& p){
    this->petNum = p.petNum;
    this->kind = p.kind;
    strcpy(this->name, p.name);
    this->atkMethod = p.atkMethod;
    this->level = p.level;
    this->exp = p.exp;
    this->atk = p.atk;
    this->dfd = p.dfd;
    this->life = p.life;
    this->slot = p.slot;
    this->bigATK = p.bigATK;
    this->bigSLOT = p.bigSLOT;
}
void power::doAttack(double p) {
    exp += 50 * 1.0 * p;
    atk+=2;
    bigATK=2.0*atk;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void power::doBIGATK(double p) {
    atk+=3;
    bigATK=2.0*atk;
    exp += 70 * 1.0 * p;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void power::beAtked(pet* p, double possible) {
    if(atk>5)
        atk-=2;
    bigATK=2.0*atk;
    double t = possible * p->atk - dfd;
    if (t > 0.1) {
        life -= 0.3 * t;
    }
}
void power::beBIGATKED(pet* p, double possible) {
    if(atk>10)
        atk-=4;
    bigATK=2.0*atk;
    double t = possible * p->bigATK - dfd;
    if (t >= 0.05) {
        life -= 0.3 * t;
    }
}
shield::shield(int n):pet(n){
    petNum = n;
    kind = n / 3;
    map<int, string>::iterator iter;
    iter = nameMap.find(n);
    strncpy(name, iter->second.c_str(), iter->second.length() + 1);
    //name = iter->second;
    atkMethod = n;
    level = 1;
    exp = 0.0;

    atk = 50;
    life = 200;
    dfd = 10;
    slot = 2000;

    bigATK = 2.0 * atk;
    bigSLOT = 1.3 * slot;
}
shield::shield(const pet& p){
    this->petNum = p.petNum;
    this->kind = p.kind;
    strcpy(this->name, p.name);
    this->atkMethod = p.atkMethod;
    this->level = p.level;
    this->exp = p.exp;
    this->atk = p.atk;
    this->dfd = p.dfd;
    this->life = p.life;
    this->slot = p.slot;
    this->bigATK = p.bigATK;
    this->bigSLOT = p.bigSLOT;
}
void shield::doAttack(double p) {
    exp += 50 * 1.0 * p;
    life+=10;

    if (exp >= 300&&level!=15) {
        upper();
    }
}
void shield::doBIGATK(double p) {
    exp += 70 * 1.0 * p;
    life+=15;

    if (exp >= 300&&level!=15) {
        upper();
    }
}
void shield::beAtked(pet* p, double possible) {
   life-=3;
    double t = possible * p->atk - dfd;
    if (t > 0.1) {
        life -= 0.3 * t;
    }
}
void shield::beBIGATKED(pet* p, double possible) {
   life-=5;
    double t = possible * p->bigATK - dfd;
    if (t >= 0.05) {
        life -= 0.3 * t;
    }
}
defense::defense(int n):pet(n){
    petNum = n;
    kind = n / 3;
    map<int, string>::iterator iter;
    iter = nameMap.find(n);
    strncpy(name, iter->second.c_str(), iter->second.length() + 1);
    //name = iter->second;
    atkMethod = n;
    level = 1;
    exp = 0.0;

    atk = 50;
    life = 150;
    dfd = 20;
    slot = 2000;

    bigATK = 2.0 * atk;
    bigSLOT = 1.3 * slot;
}
defense::defense(const pet& p){
    this->petNum = p.petNum;
    this->kind = p.kind;
    strcpy(this->name, p.name);
    this->atkMethod = p.atkMethod;
    this->level = p.level;
    this->exp = p.exp;
    this->atk = p.atk;
    this->dfd = p.dfd;
    this->life = p.life;
    this->slot = p.slot;
    this->bigATK = p.bigATK;
    this->bigSLOT = p.bigSLOT;
}
void defense::doAttack(double p) {
    exp += 50 * 1.0 * p;
    dfd+=0.5;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void defense::doBIGATK(double p) {
    exp += 70 * 1.0 * p;
    dfd+=1.0;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void defense::beAtked(pet* p, double possible) {
    if(dfd>1.0)
        dfd-=0.5;
    double t = possible * p->atk - dfd;
    if (t > 0.1) {
        life -= 0.3 * t;
    }
}
void defense::beBIGATKED(pet* p, double possible) {
    if(dfd>1.5)
        dfd-=1.0;
    double t = possible * p->bigATK - dfd;
    if (t >= 0.05) {
        life -= 0.3 * t;
    }
}
agile::agile(int n):pet(n){
    petNum = n;
    kind = n / 3;
    map<int, string>::iterator iter;
    iter = nameMap.find(n);
    strncpy(name, iter->second.c_str(), iter->second.length() + 1);
    //name = iter->second;
    atkMethod = n;
    level = 1;
    exp = 0.0;

    atk = 50;
    life = 150;
    dfd = 10;
    slot = 1500;

    bigATK = 2.0 * atk;
    bigSLOT = 1.3 * slot;
}
agile::agile(const pet& p){
    this->petNum = p.petNum;
    this->kind = p.kind;
    strcpy(this->name, p.name);
    this->atkMethod = p.atkMethod;
    this->level = p.level;
    this->exp = p.exp;
    this->atk = p.atk;
    this->dfd = p.dfd;
    this->life = p.life;
    this->slot = p.slot;
    this->bigATK = p.bigATK;
    this->bigSLOT = p.bigSLOT;
}
void agile::doAttack(double p) {
    exp += 50 * 1.0 * p;
    if(slot>100)
        slot-=5;
    bigSLOT=1.3*slot;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void agile::doBIGATK(double p) {
    if(slot>100)
        slot-=7;
    bigSLOT=1.3*slot;
    exp += 70 * 1.0 * p;
    if (exp >= 300&&level!=15) {
        upper();
    }
}
void agile::beAtked(pet* p, double possible) {
    slot+=10;
    bigSLOT=1.3*slot;
    double t = possible * p->atk - dfd;
    if (t > 0.1) {
        life -= 0.3 * t;
    }
}
void agile::beBIGATKED(pet* p, double possible) {
    slot+=20;
    bigSLOT=1.3*slot;
    double t = possible * p->bigATK - dfd;
    if (t >= 0.05) {
        life -= 0.3 * t;
    }
}
CLT clt[101];//clt[100]是服务器
int cltCount = 0;

int stop_server_atk;


int player::upgradeBattle(CLT* cli, CLT* ser, int myChoice, int enemy, int mode,Ui_MainWindow* ui) {
    double p = 1.0 * (rand() % 11 + 90) / 100;
    if (ser->myPet[enemy].life <= 0) {
        return 1;
    }
    if (cli->myPet[myChoice].life <= 0) {
        return -1;
    }

    if (mode == 0) {
        if (clock() - client_last_time >= cli->myPet[myChoice].slot || start_c_atk == 0) {
            if (start_c_atk == 0)
                start_c_atk = 1;
            //客户攻击服务器

            //cli->myPet[myChoice].doAttack(p);
            switch(cli->myPet[myChoice].kind){
            case POWER:
            {
                power ppet(cli->myPet[myChoice]);
                power* ppetp;
                ppetp=&ppet;
                ppetp->doAttack(p);
                cli->myPet[myChoice]=pet(*ppetp);
            }
                break;
            case SHIELD:
            {
                shield spet(cli->myPet[myChoice]);
                shield* spetp;
                spetp=&spet;
                spetp->doAttack(p);
                cli->myPet[myChoice]=pet(*spetp);
            }
                break;
            case DEFENSE:
            {
                defense dpet(cli->myPet[myChoice]);
                defense* dpetp;
                dpetp=&dpet;
                dpetp->doAttack(p);
                cli->myPet[myChoice]=pet(*dpetp);
            }
                break;
            case AGILE:
            {
                agile apet(cli->myPet[myChoice]);
                agile* apetp;
                apetp=&apet;
                apetp->doAttack(p);
                cli->myPet[myChoice]=pet(*apetp);
            }
                break;
            default:
                break;
            }



            client_last_time = clock();

            //ser->myPet[enemy].beAtked(&cli->myPet[myChoice], p);
            switch(ser->myPet[enemy].kind){
            case POWER:
            {
                power ppet(ser->myPet[enemy]);
                power* ppetp;
                ppetp=&ppet;
                ppetp->beAtked(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*ppetp);
            }
                break;
            case SHIELD:
            {
                shield spet(ser->myPet[enemy]);
                shield* spetp;
                spetp=&spet;
                spetp->beAtked(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*spetp);
            }
                break;
            case DEFENSE:
            {
                defense dpet(ser->myPet[enemy]);
                defense* dpetp;
                dpetp=&dpet;
                dpetp->beAtked(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*dpetp);
            }
                break;
            case AGILE:
            {
                agile apet(ser->myPet[enemy]);
                agile* apetp;
                apetp=&apet;
                apetp->beAtked(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*apetp);
            }
                break;
            default:
                break;
            }




            QString s0;
            s0="用户出普攻";
            string ord;
            map<int, string>::iterator iter;
            iter = atkMethodMap.find(cli->myPet[myChoice].petNum);
            ord=iter->second;
            s0=s0+QString::fromStdString(ord);
            ui->cltaction->setText(s0);
            //ui->cltaction->setText("用户出普攻");

            QString s1,s2;
            s1="用户生命值：";
            s1=s1+QString::number(cli->myPet[myChoice].life);
            s1=s1+",等级：";
            s1=s1+QString::number(cli->myPet[myChoice].level);
            s2="服务器生命值：";
            s2=s2+QString::number(clt[100].myPet[enemy].life);
            s2=s2+",等级：";
            s2=s2+QString::number(clt[100].myPet[enemy].level );
            ui->cltlife->setText(s1);
            ui->serlife->setText(s2);

//            cout << "用户出普攻" << endl;
//            cout << "server life: " << clt[100].myPet[enemy].life << ",level: " << clt[100].myPet[enemy].level << endl;
//            cout << "client life: " << cli->myPet[myChoice].life;
//            cout << ",level: " << cli->myPet[myChoice].level << endl;

        }
        else {
            ui->cltaction->setText("冷却中");
//            ugb0.attacktype=-1;
            //cout << "冷却中" << endl;
        }
    }
    else {
        if (clock() - client_big_last_time >= cli->myPet[myChoice].bigSLOT || start_c_big_atk == 0) {
            if (start_c_big_atk == 0)
                start_c_big_atk = 1;
            //客户攻击服务器
            //cli->myPet[myChoice].doBIGATK(p);
            switch(cli->myPet[myChoice].kind){
            case POWER:
            {
                power ppet(cli->myPet[myChoice]);
                power* ppetp;
                ppetp=&ppet;
                ppetp->doBIGATK(p);
                cli->myPet[myChoice]=pet(*ppetp);
            }
                break;
            case SHIELD:
            {
                shield spet(cli->myPet[myChoice]);
                shield* spetp;
                spetp=&spet;
                spetp->doBIGATK(p);
                cli->myPet[myChoice]=pet(*spetp);
            }
                break;
            case DEFENSE:
            {
                defense dpet(cli->myPet[myChoice]);
                defense* dpetp;
                dpetp=&dpet;
                dpetp->doBIGATK(p);
                cli->myPet[myChoice]=pet(*dpetp);
            }
                break;
            case AGILE:
            {
                agile apet(cli->myPet[myChoice]);
                agile* apetp;
                apetp=&apet;
                apetp->doBIGATK(p);
                cli->myPet[myChoice]=pet(*apetp);
            }
                break;
            default:
                break;
            }
            client_big_last_time = clock();
            //ser->myPet[enemy].beBIGATKED(&cli->myPet[myChoice], p);
            switch(ser->myPet[enemy].kind){
            case POWER:
            {
                power ppet(ser->myPet[enemy]);
                power* ppetp;
                ppetp=&ppet;
                ppetp->beBIGATKED(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*ppetp);
            }
                break;
            case SHIELD:
            {
                shield spet(ser->myPet[enemy]);
                shield* spetp;
                spetp=&spet;
                spetp->beBIGATKED(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*spetp);
            }
                break;
            case DEFENSE:
            {
                defense dpet(ser->myPet[enemy]);
                defense* dpetp;
                dpetp=&dpet;
                dpetp->beBIGATKED(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*dpetp);
            }
                break;
            case AGILE:
            {
                agile apet(ser->myPet[enemy]);
                agile* apetp;
                apetp=&apet;
                apetp->beBIGATKED(&cli->myPet[myChoice],p);
                ser->myPet[enemy]=pet(*apetp);
            }
                break;
            default:
                break;
            }


            QString s0;
            s0="用户出大招";
            string big;
            map<int, string>::iterator iter;
            iter = bigMethodMap.find(cli->myPet[myChoice].petNum);
            big=iter->second;
            s0=s0+QString::fromStdString(big);
            ui->cltaction->setText(s0);
            //ui->cltaction->setText("用户放大招");

            QString s1,s2;
            s1="用户生命值：";
            s1=s1+QString::number(cli->myPet[myChoice].life);
            s1=s1+",等级：";
            s1=s1+QString::number(cli->myPet[myChoice].level);
            s2="服务器生命值：";
            s2=s2+QString::number(clt[100].myPet[enemy].life);
            s2=s2+",等级：";
            s2=s2+QString::number(clt[100].myPet[enemy].level );
            ui->cltlife->setText(s1);
            ui->serlife->setText(s2);
//            cout << "用户放大招" << endl;
//            cout << "server life: " << clt[100].myPet[enemy].life << ",level: " << clt[100].myPet[enemy].level << endl;
//            cout << "client life: " << cli->myPet[myChoice].life;
//            cout << ",level: " << cli->myPet[myChoice].level << endl;
        }
        else {
            ui->cltaction->setText("冷却中");
//            ugb0.attacktype=-1;
            //cout << "冷却中" << endl;
        }
    }

//    ugb=&ugb0;
//    CreateThread(NULL,0,&C2S,ugb,0,NULL);
    if (cli->myPet[myChoice].life > 0 && ser->myPet[enemy].life > 0) {
        return 0;
    }
    if (ser->myPet[enemy].life <= 0) {
        return 1;
    }
    if (cli->myPet[myChoice].life <= 0) {
        return -1;
    }

    return 2;
}

DWORD WINAPI MYThread::serverATK(LPVOID lpParameter) {
    struct PMT {
        CLT* myClt;
        int myChoice;
        int enemy;
        Ui_MainWindow* ui;
    };
    PMT* pmt = (PMT*)lpParameter;
    Ui_MainWindow* ui;
    ui=pmt->ui;
    srand((unsigned int)time(NULL));


    while (stop_server_atk != 1) {

        if (clt[100].myPet[pmt->enemy].life <= 0) {
            break;
        }
        if (pmt->myClt->myPet[pmt->myChoice].life <= 0) {
            break;
        }


        int t = rand() % 3;
        double p = 1.0 * (rand() % 31 + 70) / 100;

        if (t == 0 || t == 1) {
            //cout << t << endl;
            if (clock() - server_last_time >= clt[100].myPet[pmt->enemy].slot || start_s_atk == 0) {
                if (start_s_atk == 0)
                    start_s_atk = 1;

                //clt[100].myPet[pmt->enemy].doAttack(p);
                switch(clt[100].myPet[pmt->enemy].kind){
                case POWER:
                {
                    power ppet(clt[100].myPet[pmt->enemy]);
                    power* ppetp;
                    ppetp=&ppet;
                    ppetp->doAttack(p);
                    clt[100].myPet[pmt->enemy]=pet(*ppetp);
                }
                    break;
                case SHIELD:
                {
                    shield spet(clt[100].myPet[pmt->enemy]);
                    shield* spetp;
                    spetp=&spet;
                    spetp->doAttack(p);
                    clt[100].myPet[pmt->enemy]=pet(*spetp);
                }
                    break;
                case DEFENSE:
                {
                    defense dpet(clt[100].myPet[pmt->enemy]);
                    defense* dpetp;
                    dpetp=&dpet;
                    dpetp->doAttack(p);
                    clt[100].myPet[pmt->enemy]=pet(*dpetp);
                }
                    break;
                case AGILE:
                {
                    agile apet(clt[100].myPet[pmt->enemy]);
                    agile* apetp;
                    apetp=&apet;
                    apetp->doAttack(p);
                    clt[100].myPet[pmt->enemy]=pet(*apetp);
                }
                    break;
                default:
                    break;
                }
                server_last_time = clock();
                //pmt->myClt->myPet[pmt->myChoice].beAtked(&clt[100].myPet[pmt->enemy], p);
                switch(pmt->myClt->myPet[pmt->myChoice].kind){
                case POWER:
                {
                    power ppet(pmt->myClt->myPet[pmt->myChoice]);
                    power* ppetp;
                    ppetp=&ppet;
                    ppetp->beAtked(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*ppetp);
                }
                    break;
                case SHIELD:
                {
                    shield spet(pmt->myClt->myPet[pmt->myChoice]);
                    shield* spetp;
                    spetp=&spet;
                    spetp->beAtked(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*spetp);
                }
                    break;
                case DEFENSE:
                {
                    defense dpet(pmt->myClt->myPet[pmt->myChoice]);
                    defense* dpetp;
                    dpetp=&dpet;
                    dpetp->beAtked(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*dpetp);
                }
                    break;
                case AGILE:
                {
                    agile apet(pmt->myClt->myPet[pmt->myChoice]);
                    agile* apetp;
                    apetp=&apet;
                    apetp->beAtked(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*apetp);
                }
                    break;
                default:
                    break;
                }

                QString s0;
                s0="服务器出普攻";
                string ord;
                map<int, string>::iterator iter;
                iter = atkMethodMap.find(clt[100].myPet[pmt->enemy].petNum);
                ord=iter->second;
                s0=s0+QString::fromStdString(ord);
                ui->seraction->setText(s0);
                //ui->cltaction->setText("服务器出普攻");
                QString s1,s2;
                s1="用户生命值：";
                s1=s1+QString::number(pmt->myClt->myPet[pmt->myChoice].life);
                s1=s1+",等级：";
                s1=s1+QString::number(pmt->myClt->myPet[pmt->myChoice].level);
                s2="服务器生命值：";
                s2=s2+QString::number(clt[100].myPet[pmt->enemy].life);
                s2=s2+",等级：";
                s2=s2+QString::number(clt[100].myPet[pmt->enemy].level);
                ui->cltlife->setText(s1);
                ui->serlife->setText(s2);
//                cout << "服务器出普攻" << endl;
//                cout << "server life: " << clt[100].myPet[pmt->enemy].life << ",level: " << clt[100].myPet[pmt->enemy].level << endl;
//                cout << "client life: " << pmt->myClt->myPet[pmt->myChoice].life;
//                cout << ",level: " << pmt->myClt->myPet[pmt->myChoice].level << endl;

            }
        }
        else {
            if (clock() - server_big_last_time >= clt[100].myPet[pmt->enemy].bigSLOT || start_s_big_atk == 0) {
                if (start_s_big_atk == 0)
                    start_s_big_atk = 1;
                //clt[100].myPet[pmt->enemy].doBIGATK(p);
                switch(clt[100].myPet[pmt->enemy].kind){
                case POWER:
                {
                    power ppet(clt[100].myPet[pmt->enemy]);
                    power* ppetp;
                    ppetp=&ppet;
                    ppetp->doBIGATK(p);
                    clt[100].myPet[pmt->enemy]=pet(*ppetp);
                }
                    break;
                case SHIELD:
                {
                    shield spet(clt[100].myPet[pmt->enemy]);
                    shield* spetp;
                    spetp=&spet;
                    spetp->doBIGATK(p);
                    clt[100].myPet[pmt->enemy]=pet(*spetp);
                }
                    break;
                case DEFENSE:
                {
                    defense dpet(clt[100].myPet[pmt->enemy]);
                    defense* dpetp;
                    dpetp=&dpet;
                    dpetp->doBIGATK(p);
                    clt[100].myPet[pmt->enemy]=pet(*dpetp);
                }
                    break;
                case AGILE:
                {
                    agile apet(clt[100].myPet[pmt->enemy]);
                    agile* apetp;
                    apetp=&apet;
                    apetp->doBIGATK(p);
                    clt[100].myPet[pmt->enemy]=pet(*apetp);
                }
                    break;
                default:
                    break;
                }
                server_big_last_time = clock();
                //clt->myPet[pmt->myChoice].beBIGATKED(&clt[100].myPet[pmt->enemy], p);
                switch(pmt->myClt->myPet[pmt->myChoice].kind){
                case POWER:
                {
                    power ppet(pmt->myClt->myPet[pmt->myChoice]);
                    power* ppetp;
                    ppetp=&ppet;
                    ppetp->beBIGATKED(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*ppetp);
                }
                    break;
                case SHIELD:
                {
                    shield spet(pmt->myClt->myPet[pmt->myChoice]);
                    shield* spetp;
                    spetp=&spet;
                    spetp->beBIGATKED(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*spetp);
                }
                    break;
                case DEFENSE:
                {
                    defense dpet(pmt->myClt->myPet[pmt->myChoice]);
                    defense* dpetp;
                    dpetp=&dpet;
                    dpetp->beBIGATKED(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*dpetp);
                }
                    break;
                case AGILE:
                {
                    agile apet(pmt->myClt->myPet[pmt->myChoice]);
                    agile* apetp;
                    apetp=&apet;
                    apetp->beBIGATKED(&clt[100].myPet[pmt->enemy],p);
                    pmt->myClt->myPet[pmt->myChoice]=pet(*apetp);
                }
                    break;
                default:
                    break;
                }


                QString s0;
                s0="服务器出大招";
                string big;
                map<int, string>::iterator iter;
                iter = bigMethodMap.find(clt[100].myPet[pmt->enemy].petNum);
                big=iter->second;
                s0=s0+QString::fromStdString(big);
                ui->seraction->setText(s0);
                //ui->cltaction->setText("服务器放大招");
                QString s1,s2;
                s1="用户生命值：";
                s1=s1+QString::number(pmt->myClt->myPet[pmt->myChoice].life);
                s1=s1+",等级：";
                s1=s1+QString::number(pmt->myClt->myPet[pmt->myChoice].level);
                s2="服务器生命值：";
                s2=s2+QString::number(clt[100].myPet[pmt->enemy].life);
                s2=s2+",等级：";
                s2=s2+QString::number(clt[100].myPet[pmt->enemy].level);
                ui->cltlife->setText(s1);
                ui->serlife->setText(s2);
//                cout << "服务器放大招" << endl;
//                cout << "server life: " << clt[100].myPet[pmt->enemy].life << ",level: " << clt[100].myPet[pmt->enemy].level << endl;
//                cout << "client life: " << pmt->myClt->myPet[pmt->myChoice].life;
//                cout << ",level: " << pmt->myClt->myPet[pmt->myChoice].level << endl;
            }
        }
    }
    return 0;
}

void Action::signup(msg* M, msg* N) {

    //cout << M->name << endl;
    //cout << M->pwd << endl;

    //用户名是否被占用
    int no_flag = 1;
    for (int i = 0; i < cltCount; i++) {
        if (strcmp(M->name, clt[i].cltName) == 0) {
            no_flag = 0;
            break;
        }
    }
    if (no_flag == 1) {
        strcpy(clt[cltCount].cltName, M->name);
        strcpy(clt[cltCount].password, M->pwd);

        //随机分配三个宠物
        srand((unsigned int)time(NULL));
        int have[3];
        for (int i = 0; i < 3; i++)
            have[i] = 0;
        for (int i = 0; i < 3; i++) {
            int t = rand() % 12;
            if (have[t] == 0) {
                clt[cltCount].myPet[i] = pet(t);
                clt[cltCount].petCount++;
                have[t] = 1;
            }
            else {
                i--;
            }
        }

        cltCount++;
        N->kind = 0;
        strcpy(N->feedback, "注册成功");
        //写入文件
        int k=cltCount-1;

        ofstream outFile("clients.txt",ios::app);

        outFile<<"第"<<k<<"号用户："<<endl;
        outFile<<"用户名："<<clt[k].cltName<<endl;
        outFile<<"宠物数量："<<clt[k].petCount<<endl;
        for(int i=0;i<clt[k].petCount;i++){
            outFile<<"("<<i<<")"<<clt[k].myPet[i].name;
            outFile<<"等级："<<clt[k].myPet[i].level<<" 经验值："<<clt[k].myPet[i].exp<<endl;
            outFile<<"atk:"<<clt[k].myPet[i].atk<<" dfd:"<<clt[k].myPet[i].dfd<<" life:"<<clt[k].myPet[i].life<<" slot:"<<clt[k].myPet[i].slot<<endl;
        }
        outFile.close();
    }
    else {
        N->kind = 0;
        strcpy(N->feedback, "用户重名，注册失败");
    }
}

int Action::login(msg* M, msg* N, SOCKET* recvClientSocket, int myChoice, int enemy) {
    int already = 0;
    int k = -1;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket) {
            k = i;
            N->kind = -1;
            strcpy(N->name, clt[i].cltName);
            strcpy(N->feedback, "本客户端已有账号登录");
            already = 1;
            break;
        }
    }
    if (already == 1) {
        N->kind = -1;
        N->myClt = clt[k];
        N->myChoice = myChoice;
        N->enemy = enemy;
        int sLen = send(*recvClientSocket, (char*)N, sizeof(*N), 0);
        memset(N->feedback, 0, sizeof(N->feedback));
        if (SOCKET_ERROR == sLen) {
            //cout << "服务端发送数据失败" << endl;
        }
        else {
            //cout << "服务端发送数据成功 " << endl;
        }
        return 1;
    }
//    cout << "服务器输入的账号密码为" << endl;
//    cout << M->name << endl;
//    cout << M->pwd << endl;
    int flag = -1;
    for (int i = 0; i < cltCount; i++) {
        if (strcmp(clt[i].cltName, M->name) == 0) {
            flag = i;
            break;
        }
    }
    if (strcmp(clt[flag].password, M->pwd) == 0) {


        if (clt[flag].online == 0) {
            N->kind = 1;
            clt[flag].socketnum = *recvClientSocket;
            strcpy(N->feedback, "登录成功");
            clt[flag].online = 1;
        }
        else if (clt[flag].online == 1) {
            N->kind = 111;
            strcpy(N->feedback, "该账号以在线，请勿重复登录");
        }
    }
    else {
        //qDebug()<<"flag:"<<flag<<"clt[flag].password:"<<clt[flag].password<<"M->pwd:"<<M->pwd;
        N->kind = 1111;
        if (flag == -1) {
            strcpy(N->feedback, "用户不存在");
        }
        else {
            strcpy(N->feedback, "密码错误");
        }
    }
    return 0;
}

void Action::logout(msg* M, msg* N, SOCKET* recvClientSocket) {
    int findflag = 0;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket) {

            clt[i].socketnum = 0;
            clt[i].online = 0;

            N->kind = 2;
            strcpy(N->name, clt[i].cltName);
            strcpy(N->feedback, "退出登录成功");
            findflag = 1;
            break;
        }
    }
    if (findflag == 0) {
        N->kind = -2;
        strcpy(N->feedback, "未登录，无法退出");
    }
}

void Action::joinBattle(msg* M, msg* N, SOCKET* recvClientSocket, int* battleKind, int* myChoice, int* enemy, Ui_MainWindow* ui) {
    if(ser_buffered==1){
        N->kind=-3;
        strcpy(N->feedback,"有其他用户在对战中，请稍后重试");
        return ;
    }
    int flag = -1;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket)
            flag = i;
    }
    if (flag == -1) {
        N->kind = -3;
        strcpy(N->feedback, "用户未登录");
    }
    else {
        N->kind = 3;

        ser_buffered=1;

        N->server = clt[100];
        N->myClt = clt[flag];

        strcpy(N->name, clt[flag].cltName);
        strcpy(N->feedback, "加入战斗成功");
        N->myChoice = *myChoice;
        N->enemy = *enemy;
        int sLen = send(*recvClientSocket, (char*)N, sizeof(*N), 0);

        recv(*recvClientSocket, (char*)M, sizeof(*M), 0);//收到对战双方

        strcpy(N->feedback, "战斗开始");

        *battleKind = M->battleKind;
        *myChoice = M->myChoice;
        *enemy = M->enemy;

        //ui->notification->setText("hi");
        //找到用户
        int num = -1;
        for (int i = 0; i < cltCount; i++) {
            if (clt[i].socketnum == *recvClientSocket) {
                num = i;
                break;
            }
        }



        //ui
        QString s;
        s="客户：";
        s=s+QString::number(*myChoice);
        s=s+QString::fromLocal8Bit(clt[flag].myPet[*myChoice].name,strlen(clt[flag].myPet[*myChoice].name));
        switch(clt[flag].myPet[*myChoice].kind){
        case 0:
            s=s+"，力量型";
            break;
        case 1:
            s=s+"，肉盾型";
            break;
        case 2:
            s=s+"，防御型";
            break;
        case 3:
            s=s+"，敏捷型";
            break;
        default:
            break;
        }

        s=s+",服务器：";
        s=s+QString::number(*enemy);
        s=s+QString::fromLocal8Bit(clt[100].myPet[*enemy].name,strlen(clt[100].myPet[*enemy].name));
        switch(clt[100].myPet[*enemy].kind){
        case 0:
            s=s+"，力量型";
            break;
        case 1:
            s=s+"，肉盾型";
            break;
        case 2:
            s=s+"，防御型";
            break;
        case 3:
            s=s+"，敏捷型";
            break;
        default:
            break;
        }
        ui->notification->setText(s);
//        cout << "服务器：" << clt[100].myPet[*enemy].name << endl;
//        cout << "用户：" << clt[flag].myPet[*myChoice].name << endl;

        server_last_time = clock();
        client_last_time = clock();
        server_big_last_time = clock();
        client_big_last_time = clock();
        start_s_atk = 0;
        start_c_atk = 0;
        start_s_big_atk = 0;
        start_c_big_atk = 0;

    }
}

DWORD WINAPI MYThread::medalthread(LPVOID lpParameter){
    Ui_MainWindow* ui=(Ui_MainWindow*)lpParameter;
    Sleep(2000);
    ui->medal->setText("");
    return 0;
}

DWORD WINAPI MYThread::medalthread_2(LPVOID lpParameter){
    Ui_MainWindow* ui=(Ui_MainWindow*)lpParameter;
    Sleep(2000);
    ui->medal_2->setText("");
    return 0;
}

void Action::battling(msg* M, msg* N, SOCKET* recvClientSocket, int* battleKind, int* myChoice, int* enemy,Ui_MainWindow* ui) {
    MYThread my;
    N->kind = 4;
    strcpy(N->feedback, "用户操作成功");

    //找到出招的用户
    int num = -1;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket) {
            num = i;
            break;
        }
    }


    player p;
    if (*battleKind == 0) {
        int mode = -1;
        if (M->atk == 1) {
            mode = 0;
        }
        else if (M->bigATK == 1) {
            mode = 1;
        }

        int win = p.upgradeBattle(&clt[num], &clt[100], *myChoice, *enemy, mode,ui);

        N->win=win;

        if (win != 0) {

            ser_buffered=0;
            ui->cltaction->setText("");
            ui->seraction->setText("");
            ui->cltlife->setText("");
            ui->serlife->setText("");

            stop_server_atk = 1;
            N->kind = -4;
            N->win = win;

            clt[100].myPet[*enemy].lifeback();

            clt[num].myPet[*myChoice].lifeback();

            strcpy(N->name, clt[num].cltName);
            strcpy(N->feedback, "战斗结束，退出战斗");
            clt[num].war_time++;
            if (win == 1) {
                clt[num].win_time++;
            }
            clt[num].win_rate = 1.0 * clt[num].win_time / clt[num].war_time;
            N->myClt = clt[num];


        }
        else {
            N->kind = 4;
            N->myClt = clt[num];
        }
    }
    else if (*battleKind == 1) {
        int mode = -1;
        if (M->atk == 1) {
            mode = 0;
        }
        else if (M->bigATK == 1) {
            mode = 1;
        }

        int win = p.upgradeBattle(&clt[num], &clt[100], *myChoice, *enemy, mode,ui);

        N->win=win;

        if (win != 0) {
            ser_buffered=0;

            ui->cltaction->setText("");
            ui->seraction->setText("");
            ui->cltlife->setText("");
            ui->serlife->setText("");

            stop_server_atk = 1;
            N->kind = -4;
            N->win = win;


            clt[100].myPet[*enemy].lifeback();

            clt[num].myPet[*myChoice].lifeback();

            N->myChoice = -1;
            N->enemy = -1;

            strcpy(N->name, clt[num].cltName);
            strcpy(N->feedback, "战斗结束，退出战斗");
            clt[num].war_time++;
            if (win == 1) {
                clt[num].win_time++;
            }
            clt[num].win_rate = 1.0 * clt[num].win_time / clt[num].war_time;
            N->myClt = clt[num];


        }
        else {
            N->kind = 4;
            N->myClt = clt[num];
        }


        //赢了则获得服务器的宠物
        if (win == 1) {

            QString s="用户获得宠物";
            s=s+QString::fromLocal8Bit(clt[100].myPet[*enemy].name,strlen(clt[100].myPet[*enemy].name));

            ui->notification->setText(s);

            //cout << "获得了宠物" << endl;
            clt[num].myPet[clt[num].petCount] = pet(clt[100].myPet[*enemy]);
            clt[num].petCount++;

            for (int i = *enemy; i < clt[100].petCount-1; i++) {
                clt[100].myPet[i] = pet(clt[100].myPet[i + 1]);
            }
            clt[100].petCount--;
            //如果服务器没有宠物了就随机分配三个
            if (clt[100].petCount == 0) {
                for (int i = 0; i < 3; i++) {
                    clt[100].myPet[i] = pet(rand() % 12);
                    clt[100].petCount++;
                }
            }
            //写入文件
            ofstream outFile("clients.txt",ios::out);
            for(int i=0;i<cltCount;i++){
                outFile<<"第"<<i<<"号用户："<<endl;
                outFile<<"用户名："<<clt[i].cltName<<endl;
                outFile<<"宠物数量："<<clt[i].petCount<<endl;
                for(int j=0;j<clt[i].petCount;j++){
                    outFile<<"("<<j<<")"<<clt[i].myPet[j].name;
                    outFile<<"等级："<<clt[i].myPet[j].level<<" 经验值："<<clt[i].myPet[j].exp<<endl;
                    outFile<<"atk:"<<clt[i].myPet[j].atk<<" dfd:"<<clt[i].myPet[j].dfd<<" life:"<<clt[i].myPet[j].life<<" slot:"<<clt[i].myPet[j].slot<<endl;
                }
            }
            outFile.close();



            //medal
            if (clt[num].myPet[clt[num].petCount - 1].level == 15) {
                clt[num].high_pet_count++;
                int cnt=clt[num].high_pet_count;
                if(cnt==1){
                    ui->medal->setText("用户获得高级宠物徽章铜牌");
                }
                if(cnt==3){
                    ui->medal->setText("用户获得高级宠物徽章银牌");
                }
                if(cnt==5){
                    ui->medal->setText("用户获得高级宠物徽章金牌");
                }
                CreateThread(NULL,0,&my.medalthread,ui,0,NULL);
            }
            int m = clt[num].high_pet_count;
            if (m < 1) {
                clt[num].high_level_pet_medal = -1;
            }
            if (m >= 1 && m <= 2) {
                clt[num].high_level_pet_medal = 2;
            }
            if (m >= 3 && m <= 4) {
                clt[num].high_level_pet_medal = 1;
            }
            if (m >= 5) {
                clt[num].high_level_pet_medal = 0;
            }

            int n = clt[num].petCount;
            if(n==5){
                ui->medal_2->setText("用户获得宠物数量徽章铜牌");
            }
            if(n==7){
                ui->medal_2->setText("用户获得宠物数量徽章银牌");
            }
            if(n==10){
                ui->medal_2->setText("用户获得宠物数量徽章金牌");
            }
            CreateThread(NULL,0,&my.medalthread_2,ui,0,NULL);
            if (n < 5) {
                clt[num].pet_count_medal = -1;
            }
            if (n >= 5 && n <= 7) {
                clt[num].pet_count_medal = 2;
            }
            if (n > 7 && n <= 9) {
                clt[num].pet_count_medal = 1;
            }
            if (n >= 10) {
                clt[num].pet_count_medal = 0;
            }
        }

        //输了则送出宠物
        if (win == -1) {
            int choose[3];
            if (clt[num].petCount <= 3) {
                for (int i = 0; i < clt[num].petCount; i++) {
                    choose[i] = i;
                }
                for (int i = clt[num].petCount; i < 3; i++) {
                    choose[i] = -1;
                }
            }
            else {
                int visit[100];
                for (int i = 0; i < 100; i++)
                    visit[i] = 0;
                int t;
                srand((unsigned int)time(NULL));
                for (int i = 0; i < 3; i++) {
                    t = rand() % clt[num].petCount;
                    if (visit[t] == 0) {
                        choose[i] = t;
                        visit[t] = 1;
                    }

                    else {
                        i--;
                        continue;
                    }
                }
            }

            N->kind = 9;
            for (int i = 0; i < 3; i++)
                N->choose[i] = choose[i];
            N->myClt = clt[num];
            N->server = clt[100];
            N->myChoice = *myChoice;
            N->enemy = *enemy;
            int sLen = send(*recvClientSocket, (char*)N, sizeof(*N), 0);

            memset(N->feedback, 0, sizeof(N->feedback));
            if (SOCKET_ERROR == sLen) {
                //cout << "服务端发送数据失败" << endl;
            }
            else {
                //cout << "服务端发送数据成功 " << endl;
            }

            int reLen = recv(*recvClientSocket, (char*)M, sizeof(*M), 0);
            int giveup = M->giveup;

            clt[100].myPet[clt[100].petCount] = pet(clt[num].myPet[giveup]);
            clt[100].petCount++;

            for (int i = 0; i < clt[num].petCount-1; i++) {
                if (i < giveup)
                    continue;
                else {
                    clt[num].myPet[i] = pet(clt[num].myPet[i + 1]);
                }
            }
            clt[num].petCount--;
            if (clt[num].petCount == 0) {
                srand((unsigned int)time(NULL));
                clt[num].myPet[0] = pet(rand() % 12);
                clt[num].petCount++;

            }

            //写入文件
            ofstream outFile("clients.txt",ios::out);
            for(int i=0;i<cltCount;i++){
                outFile<<"第"<<i<<"号用户："<<endl;
                outFile<<"用户名："<<clt[i].cltName<<endl;
                outFile<<"宠物数量："<<clt[i].petCount<<endl;
                for(int j=0;j<clt[i].petCount;j++){
                    outFile<<"("<<j<<")"<<clt[i].myPet[j].name;
                    outFile<<"等级："<<clt[i].myPet[j].level<<" 经验值："<<clt[i].myPet[j].exp<<endl;
                    outFile<<"atk:"<<clt[i].myPet[j].atk<<" dfd:"<<clt[i].myPet[j].dfd<<" life:"<<clt[i].myPet[j].life<<" slot:"<<clt[i].myPet[j].slot<<endl;
                }
            }
            outFile.close();

            //medal
            if (clt[100].myPet[clt[100].petCount - 1].level == 15) {
                clt[num].high_pet_count--;
            }
            int m = clt[num].high_pet_count;
            if (m < 1) {
                clt[num].high_level_pet_medal = -1;
            }
            if (m >= 1 && m <= 2) {
                clt[num].high_level_pet_medal = 2;
            }
            if (m >= 3 && m <= 4) {
                clt[num].high_level_pet_medal = 1;
            }
            if (m >= 5) {
                clt[num].high_level_pet_medal = 0;
            }

            int n = clt[num].petCount;
            if (n < 5) {
                clt[num].pet_count_medal = -1;
            }
            if (n >= 5 && n <= 7) {
                clt[num].pet_count_medal = 2;
            }
            if (n > 7 && n <= 9) {
                clt[num].pet_count_medal = 1;
            }
            if (n >= 10) {
                clt[num].pet_count_medal = 0;
            }

        }
        //如果有送出宠物发送msg的值已经变化，在这里改回
        if (win != 0) {
            stop_server_atk = 1;
            N->kind = -4;
            N->win = win;
            strcpy(N->name, clt[num].cltName);
            strcpy(N->feedback, "战斗结束，退出战斗");
            N->myClt = clt[num];


        }
        else {
            N->kind = 4;
            N->myClt = clt[num];
        }

    }
}
void Action::exitBattle(msg* M, msg* N, SOCKET* recvClientSocket, int* myChoice, int* enemy, Ui_MainWindow* ui) {
    ui->cltaction->setText("");
    ui->seraction->setText("");
    ui->cltlife->setText("");
    ui->serlife->setText("");
    stop_server_atk = 1;
    int flag = -1;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket)
            flag = i;
    }

    clt[100].myPet[*enemy].lifeback();
    clt[flag].myPet[*myChoice].lifeback();

    N->myChoice = -1;
    N->enemy = -1;
    *myChoice = -1;
    *enemy = -1;

    N->kind = 5;
    ser_buffered=0;
    strcpy(N->name, clt[flag].cltName);
    strcpy(N->feedback, "退出战斗成功");
}
void Action::queryOnlineCLT(msg* M, msg* N) {
    int k = 0;
    N->kind = 6;
    strcpy(N->feedback, "查询成功");
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].online == 1)
            strcpy(N->allname[k++], clt[i].cltName);
    }
    N->onlinecount = k;
}
void Action::showBattleResult(msg* M, msg* N) {
    N->win = M->win;

    if (N->win == 1) {
        strcpy(N->feedback, "用户获胜");
    }
    else {
        strcpy(N->feedback, "用户失败");
    }
}
void Action::queryCltPet(msg* M, msg* N) {
    /*int num = -1;
    for (int i = 0; i < cltCount; i++) {
        if (clt[i].socketnum == *recvClientSocket) {
            num = i;
            break;
        }
    }
    for (int i = 0; i < clt[num].petCount; i++) {

        N->allpet[i] = clt[num].myPet[i].petNum;
    }
    N->petCount = clt[num].petCount;*/

    int flag = -1;
    for (int i = 0; i < cltCount; i++) {
        if (strcmp(clt[i].cltName, M->name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        N->kind = -12;
        strcpy(N->feedback, "用户不存在");
    }
    else {

        if (strcmp(clt[flag].password, M->pwd) == 0) {
            N->kind = 12;
            strcpy(N->feedback, "查询用户宠物成功");
        }
        else {
            N->kind = -12;
            strcpy(N->feedback, "密码错误");
        }
    }
    N->petclt = clt[flag];
}
void Action::querySerPet(msg* M, msg* N) {
    N->kind = 13;
    N->server = clt[100];

    strcpy(N->feedback, "查询服务器宠物成功");
}
void Action::queryMedal(msg* M, msg* N) {
    //cout << "服务器输入的账号密码为" << endl;
    //cout << M->name << endl;
    //cout << M->pwd << endl;
    int flag = -1;
    for (int i = 0; i < cltCount; i++) {
        if (strcmp(clt[i].cltName, M->name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        N->kind = -20;
        strcpy(N->feedback, "用户不存在");
    }
    else if (strcmp(clt[flag].password, M->pwd) == 0) {
        N->kind = 20;
        strcpy(N->feedback, "查询成功");
        N->medalclt = clt[flag];
    }
    else {
        N->kind = -20;
        strcpy(N->feedback, "密码错误");
    }
}

DWORD WINAPI MYThread::timerthread(LPVOID lpParameter){
    Ui_MainWindow* ui;
    ui=(Ui_MainWindow*)lpParameter;
    Sleep(2000);
    ui->user->setText("");
    ui->pwd->setText("");
    return 0;
}

DWORD WINAPI MYThread::ServerThread(LPVOID lpParameter) {
    struct CS{
        SOCKET* ClientSocket;
        Ui_MainWindow* ui;
    };
    CS* cs=(CS*)lpParameter;
    SOCKET* recvClientSocket = cs->ClientSocket;
    Ui_MainWindow* ui=cs->ui;


    MYThread m;

    while (1) {
        //recv
        msg M;
        msg N;
        Action A;
        int reLen = recv(*recvClientSocket, (char*)&M, sizeof(M), 0);
        if (SOCKET_ERROR == reLen) {
            //cout << "服务端接收数据失败" << endl;
            break;
        }
        else {
            static int battleKind = -1;
            static int myChoice = -1;
            static int enemy = -1;

            if (M.kind == 0) {//注册
                ui->notification->setText("注册");
                A.signup(&M, &N);

            }
            else if (M.kind == 1) {//登录
                ui->notification->setText("登录");
                ui->user->setText(M.name);
                ui->pwd->setText(M.pwd);
                CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
                int flag = A.login(&M, &N, recvClientSocket, myChoice, enemy);
                if (flag == 1) {
                    continue;
                }

            }
            else if (M.kind == 20) {//查奖牌
                ui->notification->setText("查看用户胜率和奖牌榜");
                ui->user->setText(M.name);
                ui->pwd->setText(M.pwd);
                CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
                A.queryMedal(&M, &N);

            }
            else if (M.kind == 2) {//退出登录
                ui->notification->setText("退出登录");
                A.logout(&M, &N, recvClientSocket);


            }
            else if (M.kind == 3) {//加入战斗
                ui->notification->setText("加入战斗");
                A.joinBattle(&M, &N, recvClientSocket, &battleKind, &myChoice, &enemy, ui);

                //    //找到用户
                int num = -1;
                for (int i = 0; i < cltCount; i++) {
                    if (clt[i].socketnum == *recvClientSocket) {
                        num = i;
                        break;
                    }
                }



                struct PMT {
                    CLT* myClt;
                    int myChoice;
                    int enemy;
                    Ui_MainWindow* ui;
                };

                PMT pmt;
                PMT* p;
                pmt.myClt = &clt[num];
                pmt.myChoice = myChoice;
                pmt.enemy = enemy;
                pmt.ui=ui;

                p = &pmt;
                stop_server_atk = 0;
                CreateThread(NULL, 0, &m.serverATK, p, 0, NULL);

            }
            else if (M.kind == 4) {//battling
                A.battling(&M, &N, recvClientSocket, &battleKind, &myChoice, &enemy, ui);

            }

            else if (M.kind == 5) {//结束战斗
                ui->notification->setText("退出战斗");
                A.exitBattle(&M, &N, recvClientSocket, &myChoice, &enemy, ui);

            }
            else if (M.kind == 6) {//all online clients
                ui->notification->setText("查看在线用户");
                A.queryOnlineCLT(&M, &N);

            }
            else if (M.kind == 7) {
                A.showBattleResult(&M, &N);

            }
            else if (M.kind == 12) {//查某一用户宠物
                ui->notification->setText("查看用户宠物");
                ui->user->setText(M.name);
                ui->pwd->setText(M.pwd);
                CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
                A.queryCltPet(&M, &N);

            }
            else if (M.kind == 13) {//查服务器宠物
                ui->notification->setText("查看服务器宠物");
                A.querySerPet(&M, &N);
            }
            else if (M.kind == -1) {

                N.myChoice = myChoice;
                N.enemy = enemy;

                int find = -1;
                for (int i = 0; i < cltCount; i++) {
                    if (clt[i].socketnum == *recvClientSocket) {
                        find = i;
                        break;
                    }
                }
                clt[find].online=0;
                //if (find != -1) {
                N.myClt = clt[find];
                //}

                N.server = clt[100];

                int sLen = send(*recvClientSocket, (char*)&N, sizeof(N), 0);
                memset(N.feedback, 0, sizeof(N.feedback));
                if (SOCKET_ERROR == sLen) {
                    //cout << "服务端发送数据失败" << endl;
                }
                else {
                    //cout << "服务端发送数据成功 " << endl;
                }
                QString s;
                s="socket为";
                s=s+QString::number(*recvClientSocket);
                s=s+"的客户端退出";
                ui->startinfo->setText(s);
                ui->notification->setText("客户端退出");
                break;
            }
            N.myChoice = myChoice;
            N.enemy = enemy;
        }


        //send


        int find = -1;
        for (int i = 0; i < cltCount; i++) {
            if (clt[i].socketnum == *recvClientSocket) {
                find = i;
                break;
            }
        }
        //if (find != -1) {
        N.myClt = clt[find];
        //}

        N.server = clt[100];

        int sLen = send(*recvClientSocket, (char*)&N, sizeof(N), 0);
        memset(N.feedback, 0, sizeof(N.feedback));
        if (SOCKET_ERROR == sLen) {
            //cout << "服务端发送数据失败" << endl;
        }
        else {
            //cout << "服务端发送数据成功 " << endl;
        }
    }

    //    7    关闭socket
    closesocket(*recvClientSocket);
    return 0;
}


void socketEvent::initCltInfo(Ui_MainWindow *ui) {
    //cout << "-----------服务器-----------" << endl;

    MYThread m;
    //    1    初始化

    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);    //make word,你把鼠标移到WSAStartup看看参数列表,是不是就是一个word啊


    //    2    创建服务器的套接字
    SOCKET serviceSocket;
    serviceSocket = socket(AF_INET, SOCK_STREAM, 0);    //socket(协议族,socket数据传输方式,某个协议)    我们默认为0,其实就是一个宏

    if (SOCKET_ERROR == serviceSocket) {
        //ui->startinfo->setText("套接字创建失败");
        //cout << "套接字创建失败" << endl;
    }
    else {

        //ui->startinfo->setText("套接字创建成功");
        //cout << "套接字创建成功" << endl;
    }


    //    3    绑定套接字    指定绑定的IP地址和端口号
    sockaddr_in socketAddr;                                //一个绑定地址:有IP地址,有端口号,有协议族
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");        //代码开头第一行我们定义的宏在这就其作用啦
    socketAddr.sin_port = htons(1234);
    int bRes = bind(serviceSocket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));    //绑定注意的一点就是记得强制类型转换
    if (SOCKET_ERROR == bRes) {
        //ui->startinfo->setText("绑定失败");
        //cout << "绑定失败" << endl;
    }
    else {
        //ui->startinfo->setText("绑定成功");
        //cout << "绑定成功" << endl;
    }

    //    4    服务器监听
    int lLen = listen(serviceSocket, 5);    //监听的第二个参数就是:能存放多少个客户端请求,到并发编程的时候很有用哦
    if (SOCKET_ERROR == lLen) {
        //ui->startinfo->setText("监听失败");
        //cout << "监听失败" << endl;
    }
    else {

        //ui->startinfo->setText("监听成功");
        //cout << "监听成功" << endl;
    }


    srand((unsigned int)time(NULL));
    for (int i = 0; i < 3; i++) {
        clt[100].myPet[i] = pet(rand() % 12);
        clt[100].petCount++;
    }
    for (int i = 0; i < 100; i++) {
        clt[i].petCount = 0;
        clt[i].war_time = 0;
        clt[i].win_time = 0;
        clt[i].win_rate = 1.0;
        clt[i].high_level_pet_medal = -1;
        clt[i].pet_count_medal = -1;
        clt[i].high_pet_count = 0;
    }

    while (1) {
        SOCKET* ClientSocket = new SOCKET;
        ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
        //接收客户端连接请求
        int SockAddrlen = sizeof(sockaddr);


        *ClientSocket = accept(serviceSocket, 0, 0);


        QString s1="socket为";
        s1=s1+QString::number(*ClientSocket);
        s1=s1+"的客户端连接到服务器";
        ui->startinfo->setText(s1);


        //cout<<*ClientSocket;
        //cout << "一个客户端已连接到服务器，socket是：" << *ClientSocket << endl;
        struct CS{
            SOCKET* ClientSocket;
            Ui_MainWindow* ui;
        };
        CS cs0;
        CS* cs;
        cs0.ClientSocket=ClientSocket;
        cs0.ui=ui;
        cs=&cs0;

        CreateThread(NULL, 0, &m.ServerThread, cs, 0, NULL);
    }
    //    6    发送/接受 数据


    closesocket(serviceSocket);

    //    8    终止
    WSACleanup();

    //cout << "服务器停止" << endl;
}
