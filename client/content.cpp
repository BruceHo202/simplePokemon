#include"content.h"

map<int, string>nameMap;

map<int, string>atkMethodMap;

map<int ,string>bigMethodMap;

int req=100;
char g_name[20], g_pwd[20];
int enteringflag=0;


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

void showfeedback::output_feedback(char *feedback,Ui_MainWindow* ui){
    QString s=QString::fromLocal8Bit(feedback,strlen(feedback));
    ui->feedback->setText(s);

}

DWORD WINAPI MYThread::timerthread(LPVOID lpParameter){
    Ui_MainWindow* ui=(Ui_MainWindow*)lpParameter;
    Sleep(2000);
    ui->notification_timer->setText("");
    return 0;
}

void socketEvent::initCltInfo(Ui_MainWindow* ui) {
    //cout << "-----------客户端-----------" << endl;

//    QTimer* timer_out = new QTimer();
    //	1	初始化
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);


    //	2	创建套接字
    SOCKET clientSocket = {};
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (SOCKET_ERROR == clientSocket) {
        //cout << "套接字创建失败" << endl;
    }
    else {
        //ui->startinfo->setText("套接字创建成功");
        //cout << "套接字创建成功" << endl;
    }


    //	3	绑定套接字	指定绑定的IP地址和端口号
    sockaddr_in socketAddr;
    socketAddr.sin_family = PF_INET;
    socketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    socketAddr.sin_port = htons(1234);
    int cRes = connect(clientSocket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));
    if (SOCKET_ERROR == cRes) {
        //cout << "客户端:与服务器连接失败" << endl;
    }
    else {
        //cout << "客户端:与服务器连接成功" << endl;
    }


//    struct RST{
//        Ui_MainWindow* ui;
//    };
//    RST rst0;
//    RST* rst;
//    rst0.ui=ui;
//    rst=&rst0;

//    req=100;
//    enteringflag=1;
//    CreateThread(NULL,0,&enterreq,rst,0,NULL);

//    while(enteringflag==1){

//    }
    //enter req
    enteringflag=1;
    ui->notification_firm->setText("选择你的请求：");
    QObject::connect(ui->confirm_req,&QToolButton::clicked,[=](){

        if(ui->req->currentIndex()-1 < 4)
            req=ui->req->currentIndex()-1;
        else if(ui->req->currentIndex()-1 == 4)
            req=6;
        else if(ui->req->currentIndex()-1 == 5)
            req=12;
        else if(ui->req->currentIndex()-1 == 6)
            req=13;
        else if(ui->req->currentIndex()-1 == 7)
            req=20;
        else if(ui->req->currentIndex()-1 == 8)
            req=-1;
        ui->notification_firm->setText("");
        ui->onlinecltcombo->clear();
        ui->onlinecltlabel->setText("");
        enteringflag=0;
    });
    while(enteringflag==1){

    }


//    cout << "Enter request: (0 to sign up and 1 to log in)" << endl;
//    cin >> req;
    while (1) {

        MYThread m;
        //	4	发送
        msg M, N;
        char name[20], pwd[20];


        //sign up
        if (req == 20) {//查看胜率和奖牌榜
            M.kind = 20;

            //enter namepwd
            ui->notification_firm->setText("输入用户名和密码：");
            enteringflag=1;
            QObject::connect(ui->confirm_userpwd,&QToolButton::clicked,[=](){

//                char* ptr;
//                QByteArray ba,bb;
//                //QString str = ui->username->text();
//                ba = ui->username->text().toLatin1();
//                bb=ui->pwd->text().toLatin1();
//                ptr = ba.data();
//                memcpy(g_name,ptr,20);        //就是这一句，必须加，不然不只是把指针指向了值，并没有赋值
//                ptr=bb.data();
//                memcpy(g_pwd,ptr,20);
                string s1,s2;
                s1=ui->username->text().toStdString();
                s2=ui->pwd->text().toStdString();
                for(int i=0;i<s1.length();i++){
                    g_name[i]=s1[i];
                }
                g_name[s1.length()]='\0';
                for(int i=0;i<s2.length();i++)
                    g_pwd[i]=s2[i];
                g_pwd[s2.length()]='\0';

                ui->notification_firm->setText("");
                ui->username->setText("");
                ui->pwd->setText("");
                enteringflag=0;
            });
            while(enteringflag==1){

            }

            strcpy(M.name, g_name);
            strcpy(M.pwd, g_pwd);
            send(clientSocket, (char*)&M, sizeof(M), 0);

        }
        if (req == 0) {
            //strcpy(sendBuf, "sign up");

            //enter namepwd
            ui->notification_firm->setText("输入用户名和密码：");
            enteringflag=1;
            QObject::connect(ui->confirm_userpwd,&QToolButton::clicked,[=](){

//                char* ptr;
//                QByteArray ba,bb;
//                //QString str = ui->username->text();
//                ba = ui->username->text().toLatin1();
//                bb=ui->pwd->text().toLatin1();
//                ptr = ba.data();
//                memcpy(g_name,ptr,20);        //就是这一句，必须加，不然不只是把指针指向了值，并没有赋值
//                ptr=bb.data();
//                memcpy(g_pwd,ptr,20);
                string s1,s2;
                s1=ui->username->text().toStdString();
                s2=ui->pwd->text().toStdString();
                for(int i=0;i<s1.length();i++){
                    g_name[i]=s1[i];
                }
                g_name[s1.length()]='\0';
                for(int i=0;i<s2.length();i++)
                    g_pwd[i]=s2[i];
                g_pwd[s2.length()]='\0';

                ui->notification_firm->setText("");
                ui->username->setText("");
                ui->pwd->setText("");
                enteringflag=0;
            });
            while(enteringflag==1){

            }

//            strcpy(name,g_name);
//            strcpy(pwd,g_pwd);

//            cout << "输入要查询的用户名：" << endl;
//            cin >> name;
//            cout << "输入密码：" << endl;
//            cin >> pwd;


            M.kind = 0;

            strcpy(M.name, g_name);
            strcpy(M.pwd, g_pwd);

            send(clientSocket, (char*)&M, sizeof(M), 0);
        }
        //log in
        else if (req == 1) {
            //strcpy(sendBuf, "log in");

            //enter namepwd
            ui->notification_firm->setText("输入用户名和密码：");
            enteringflag=1;
            QObject::connect(ui->confirm_userpwd,&QToolButton::clicked,[=](){

                string s1,s2;
                s1=ui->username->text().toStdString();
                s2=ui->pwd->text().toStdString();
                for(int i=0;i<s1.length();i++){
                    g_name[i]=s1[i];
                }
                g_name[s1.length()]='\0';
                for(int i=0;i<s2.length();i++)
                    g_pwd[i]=s2[i];
                g_pwd[s2.length()]='\0';

                ui->notification_firm->setText("");
                ui->username->setText("");
                ui->pwd->setText("");
                enteringflag=0;
            });
            while(enteringflag==1){

            }

            strcpy(M.name, g_name);
            strcpy(M.pwd, g_pwd);
//            cout << "输入要查询的用户名：" << endl;
//            cin >> name;
//            cout << "输入密码：" << endl;
//            cin >> pwd;

            M.kind = 1;


            send(clientSocket, (char*)&M, sizeof(M), 0);

        }
        else if (req == 2) {
            M.kind = 2;
            send(clientSocket, (char*)&M, sizeof(M), 0);

        }
        else if (req == 3) {//加入战斗
            M.kind = 3;


            send(clientSocket, (char*)&M, sizeof(M), 0);
            recv(clientSocket, (char*)&N, sizeof(N), 0);
            A.clt = N.myClt;
            A.myChoice = N.myChoice;
            A.enemy = N.enemy;

            if (N.kind != -3) {
//                QTimer* timer0 = new QTimer();
//                timer0->start(3000);
                QString s;
                s=QString::fromLocal8Bit(N.name,strlen(N.name));
                s=s+"加入战斗成功";
                ui->notification_timer->setText(s);


                CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
//                QObject::connect(timer0,QTimer::timeout,[=](){
//                    ui->notification_timer->setText("");
//                    timer0->stop();
//                });
//                cout << N.name << " ";
//                cout << N.feedback << endl << endl;//feedback为"加入战斗成功"
                req = 4;


                int battleKind;
                int *bkd=&battleKind;
                ui->notification_firm->setText("选择战斗类型");
                enteringflag=1;
                QObject::connect(ui->confirm_battlekind,QToolButton::clicked,[=](){

                    *bkd=ui->battlekind->currentIndex()-1;
                    ui->notification_firm->setText("");
                    ui->onlinecltcombo->clear();
                    ui->onlinecltlabel->setText("");
                    enteringflag=0;
                });
                while(enteringflag==1){

                }
//                cout << "0 go upgrade and 1 to duel" << endl;
//                cin >> battleKind;//0->upgrade 1->duel
                battleKind=*bkd;
                M.battleKind = battleKind;


                ui->mypet->clear();
                //cout << "你可选的宠物有：" << endl;
                for (int i = -1; i < N.myClt.petCount; i++) {
                    if(i==-1){
                        ui->mypet->addItem("你的可选宠物有：");
                    }
                    else{
                        QString s;
                        s=QString::number(i)+QString::fromLocal8Bit(N.myClt.myPet[i].name,strlen(N.myClt.myPet[i].name));

                        switch(N.myClt.myPet[i].kind){
                        case 0:
                            s=s+" 力量型";
                            break;
                        case 1:
                            s=s+" 肉盾型";
                            break;
                        case 2:
                            s=s+" 防御型";
                            break;
                        case 3:
                            s=s+" 敏捷型";
                            break;
                        default:
                            break;
                        }

                        s=s+" 等级：";
                        s=s+QString::number(N.myClt.myPet[i].level);
                        s=s+" 经验值：";
                        s=s+QString::number(N.myClt.myPet[i].exp);
                        ui->mypet->addItem(s);
                    }
                    //cout << i << ": " << N.myClt.myPet[i].name << " level: " << N.myClt.myPet[i].level << " exp: " << N.myClt.myPet[i].exp << endl;
                }

                int myChoice;
                int *mce=&myChoice;
                ui->notification_firm->setText("你选择哪个宠物与服务器对战");
                enteringflag=1;
                QObject::connect(ui->confirm_myChoice,QToolButton::clicked,[=](){

                    *mce=ui->getmychoice->text().toInt();
                    //*mce=ui->mypet->currentIndex()-1;
                    ui->notification_firm->setText("");
                    ui->getmychoice->setText("");
                    ui->mypet->clear();
                    enteringflag=0;
                });
                while(enteringflag==1){

                }
//                cout << "Enter the pet you choose to fight with server" << endl;
//                cin >> myChoice;
                myChoice=*mce;
                M.myChoice = myChoice;

                ui->serpet->clear();
                for (int i = -1; i < N.server.petCount; i++) {
                    if(i==-1){
                        ui->serpet->addItem("服务器的可选宠物有：");
                    }
                    else{
                        QString s;
                        s=QString::number(i)+QString::fromLocal8Bit(N.server.myPet[i].name,strlen(N.server.myPet[i].name));

                        switch(N.server.myPet[i].kind){
                        case 0:
                            s=s+" 力量型";
                            break;
                        case 1:
                            s=s+" 肉盾型";
                            break;
                        case 2:
                            s=s+" 防御型";
                            break;
                        case 3:
                            s=s+" 敏捷型";
                            break;
                        default:
                            break;
                        }

                        s=s+" level: ";
                        s=s+QString::number(N.server.myPet[i].level);
                        s=s+" exp: ";
                        s=s+QString::number(N.server.myPet[i].exp);
                        ui->serpet->addItem(s);
                    }
                    //cout << i << ": " << N.server.myPet[i].name << " level: " << N.server.myPet[i].level << " exp: " << N.server.myPet[i].exp << endl;
                }

                int enemy;
                int *enm=&enemy;
                ui->notification_firm->setText("选择你要对战的服务器的宠物");
                enteringflag=1;
                QObject::connect(ui->confirm_enemy,QToolButton::clicked,[=](){

                    *enm=ui->getenemy->text().toInt();
                    //*enm=ui->serpet->currentIndex()-1;
                    ui->notification_firm->setText("");
                    ui->getenemy->setText("");
                    ui->serpet->clear();
                    enteringflag=0;
                });
                while(enteringflag==1){

                }
//                cout << "Enter which pet you want to fight with" << endl;
//                cin >> enemy;
                enemy=*enm;
                M.enemy = enemy;
                send(clientSocket, (char*)&M, sizeof(M), 0);
                recv(clientSocket, (char*)&N, sizeof(N), 0);
                A.clt = N.myClt;
                A.myChoice = N.myChoice;
                A.enemy = N.enemy;

                showfeedback K;
//                timer_out->start(3000);
                K.output_feedback(N.feedback,ui);
//                QObject::connect(timer_out,QTimer::timeout,[=](){
//                    ui->feedback->setText("");
//                    timer_out->stop();
//                });
                //cout << N.feedback << endl;

                continue;
            }
            else {

                showfeedback K;
//                timer_out->start(3000);
                K.output_feedback(N.feedback,ui);
//                QObject::connect(timer_out,QTimer::timeout,[=](){
//                    ui->feedback->setText("");
//                    timer_out->stop();
//                });
                //cout << N.feedback << endl;

                //enter req
                enteringflag=1;
                ui->notification_firm->setText("选择你的请求：");
                QObject::connect(ui->confirm_req,&QToolButton::clicked,[=](){

                    if(ui->req->currentIndex()-1 < 4)
                        req=ui->req->currentIndex()-1;
                    else if(ui->req->currentIndex()-1 == 4)
                        req=6;
                    else if(ui->req->currentIndex()-1 == 5)
                        req=12;
                    else if(ui->req->currentIndex()-1 == 6)
                        req=13;
                    else if(ui->req->currentIndex()-1 == 7)
                        req=20;
                    else if(ui->req->currentIndex()-1 == 8)
                        req=-1;
                    ui->notification_firm->setText("");
                    ui->onlinecltcombo->clear();
                    ui->onlinecltlabel->setText("");
                    enteringflag=0;
                });
                while(enteringflag==1){

                }
//                cout << "Enter request: (0 to sign up and 1 to log in)" << endl;
//                cin >> req;
                continue;
            }
        }
        else if (req == 4) {//出招
            M.kind = 4;
            int opr=2;
            int *oprp=&opr;
            //cout << "do something\n";

            M.atk = 0;
            M.bigATK = 0;

            string ord,big;
            map<int, string>::iterator iter;
            iter = atkMethodMap.find(N.myClt.myPet[N.myChoice].petNum);
            ord=iter->second;
            ui->opr0->setText(QString::fromStdString(ord));

            iter=bigMethodMap.find(N.myClt.myPet[N.myChoice].petNum);
            big=iter->second;
            ui->opr1->setText(QString::fromStdString(big));

            enteringflag=1;
            QObject::connect(ui->opr0,QToolButton::clicked,[=](){
                *oprp=0;
                enteringflag=0;
            });
            QObject::connect(ui->opr1,QToolButton::clicked,[=](){
                *oprp=1;
                enteringflag=0;
            });
            QObject::connect(ui->quit,QToolButton::clicked,[=](){
                *oprp=-1;
                enteringflag=0;
            });
            while(enteringflag==1){

            }


            opr=*oprp;
            //以下注释部分使opr有值
//            while (1) {
//                if (_kbhit()) {
//                    int ch = _getch();
//                    if (ch == 65 || ch == 97) {//按下A或a以出招
//                        opr = 0;
//                        break;
//                    }
//                    if (ch == 69 || ch == 101) {//按下E或e以出大招
//                        opr = 1;
//                        break;
//                    }
//                    if (ch == 81 || ch == 113) {//按下Q或q以退出战斗
//                        opr = -1;
//                        break;
//                    }
//                }
//            }
            if (opr == 0 || opr == 1) {
                if (opr == 0) {
                    M.atk = 1;
                }
                else if (opr == 1) {
                    M.bigATK = 1;
                }
                send(clientSocket, (char*)&M, sizeof(M), 0);
                recv(clientSocket, (char*)&N, sizeof(N), 0);
                A.clt = N.myClt;
                A.myChoice = N.myChoice;
                A.enemy = N.enemy;

                QString ser_life,clt_life;

                ser_life=QString::fromLocal8Bit(N.server.myPet[N.enemy].name,strlen(N.server.myPet[N.enemy].name));
                ser_life=ser_life+"生命值：";
                ser_life=ser_life+QString::number(N.server.myPet[N.enemy].life);
                ser_life=ser_life+"经验值：";
                ser_life=ser_life+QString::number(N.server.myPet[N.enemy].exp);

                clt_life=QString::fromLocal8Bit(N.myClt.myPet[N.myChoice].name,strlen(N.myClt.myPet[N.myChoice].name));
                clt_life=clt_life+"生命值：";
                clt_life=clt_life+QString::number(N.myClt.myPet[N.myChoice].life);
                clt_life=clt_life+"经验值：";
                clt_life=clt_life+QString::number(N.myClt.myPet[N.myChoice].exp);

                ui->serlife->setText(ser_life);
                ui->cltlife->setText(clt_life);

                if(N.win!=0){
                    ui->cltlife->setText("");
                    ui->serlife->setText("");
                }

                if (N.kind == 9) {

                    QObject::disconnect(ui->opr0,QToolButton::clicked,0,0);
                    QObject::disconnect(ui->opr1,QToolButton::clicked,0,0);
                    QObject::disconnect(ui->quit,QToolButton::clicked,0,0);
                    ui->opr0->setText("普通攻击");
                    ui->opr1->setText("大招");

                    ui->notification_firm->setText("你输了，请送出一个宠物");
                    ui->send_list_note->setText("有以下宠物可选：");
                    ui->choose_note->setText("输入你选择送出的宠物编号");
                    //cout << "你输了，请送出一个宠物，有以下宠物可选：" << endl;
                    ui->sendpet->clear();
                    ui->sendpet->addItem("选择你送出的宠物:");
                    for (int i = 0; i < 3; i++) {

                            if (N.choose[i] != -1) {
                                QString s;
                                s=QString::number(N.choose[i]);
                                s=s+":";
                                s=s+QString::fromLocal8Bit(N.myClt.myPet[N.choose[i]].name,strlen(N.myClt.myPet[N.choose[i]].name));

                                switch(N.myClt.myPet[N.choose[i]].kind){
                                case 0:
                                    s=s+" 力量型";
                                    break;
                                case 1:
                                    s=s+" 肉盾型";
                                    break;
                                case 2:
                                    s=s+" 防御型";
                                    break;
                                case 3:
                                    s=s+" 敏捷型";
                                    break;
                                default:
                                    break;
                                }

                                s=s+" 等级：";
                                s=s+QString::number(N.myClt.myPet[N.choose[i]].level);
                                s=s+" 经验值：";
                                s=s+QString::number(N.myClt.myPet[N.choose[i]].exp);
                                ui->sendpet->addItem(s);
//                                cout << N.choose[i] << ": ";
//                                cout << N.myClt.myPet[N.choose[i]].name << ",level: ";
//                                cout << N.myClt.myPet[N.choose[i]].level << ",exp: ";
//                                cout << N.myClt.myPet[N.choose[i]].exp << endl;

                        }
                    }
                    ui->notification_firm->setText("你选择送出的宠物是：（序号）");
                    enteringflag=1;
                    int guptmp;
                    int* gup=&guptmp;
                    QObject::connect(ui->confirm_sendpet,QToolButton::clicked,[=](){

                        *gup=ui->giveup->text().toInt();
                        ui->giveup->setText("");
                        enteringflag=0;
                    });
                    while(enteringflag==1){

                    }
//                    M.giveup=*gup;
//                    ui->notification_firm->setText("");
                    if(*gup!=N.choose[0]&&*gup!=N.choose[1]&&*gup!=N.choose[2]){
                        M.giveup=N.choose[0];
                        ui->notification_timer->setText("选择错误，自动送出选择列表中第一个宠物");
                        ui->notification_firm->setText("");
                        CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
                    }
                    else{
                    M.giveup=*gup;
                    ui->notification_firm->setText("");
                    }
                    ui->send_list_note->setText("");
                    ui->sendpet->clear();
                    ui->choose_note->setText("");
//                    cout << "你选择送出的宠物是：（序号）" << endl;
//                    cin >> M.giveup;
                    M.kind = 9;

                    send(clientSocket, (char*)&M, sizeof(M), 0);
                    recv(clientSocket, (char*)&N, sizeof(N), 0);
                    A.clt = N.myClt;
                    A.myChoice = N.myChoice;
                    A.enemy = N.enemy;
                }

                if (N.kind == -4) {

                    QObject::disconnect(ui->opr0,QToolButton::clicked,0,0);
                    QObject::disconnect(ui->opr1,QToolButton::clicked,0,0);
                    QObject::disconnect(ui->quit,QToolButton::clicked,0,0);
                    ui->opr0->setText("普通攻击");
                    ui->opr1->setText("大招");
                    
                    M.kind = 7;
                    M.win = N.win;

                    showfeedback K;
//                    timer_out->start(3000);
                    K.output_feedback(N.feedback,ui);
//                    QObject::connect(timer_out,QTimer::timeout,[=](){
//                        ui->feedback->setText("");
//                        timer_out->stop();
//                    });
                    //cout << N.feedback << endl;
                    //req = 7;
                    send(clientSocket, (char*)&M, sizeof(M), 0);
                    recv(clientSocket, (char*)&N, sizeof(N), 0);
                    A.clt = N.myClt;
                    A.myChoice = N.myChoice;
                    A.enemy = N.enemy;

                    //showfeedback K;
//                    timer_out->start(3000);
                    K.output_feedback(N.feedback,ui);
//                    QObject::connect(timer_out,QTimer::timeout,[=](){
//                        ui->feedback->setText("");
//                        timer_out->stop();
//                    });
                    //cout << N.feedback << endl;
                    //N.win现在有值

                    //enter req
                    enteringflag=1;
                    ui->notification_firm->setText("选择你的请求：");
                    QObject::connect(ui->confirm_req,&QToolButton::clicked,[=](){

                        if(ui->req->currentIndex()-1 < 4)
                            req=ui->req->currentIndex()-1;
                        else if(ui->req->currentIndex()-1 == 4)
                            req=6;
                        else if(ui->req->currentIndex()-1 == 5)
                            req=12;
                        else if(ui->req->currentIndex()-1 == 6)
                            req=13;
                        else if(ui->req->currentIndex()-1 == 7)
                            req=20;
                        else if(ui->req->currentIndex()-1 == 8)
                            req=-1;
                        ui->notification_firm->setText("");
                        ui->onlinecltcombo->clear();
                        ui->onlinecltlabel->setText("");
                        enteringflag=0;
                    });
                    while(enteringflag==1){

                    }
//                    cout << "Enter request: (0 to sign up and 1 to log in)" << endl;
//                    cin >> req;
                    continue;
                }
                else {
                    showfeedback K;
//                    timer_out->start(3000);
                    K.output_feedback(N.feedback,ui);
//                    QObject::connect(timer_out,QTimer::timeout,[=](){
//                        ui->feedback->setText("");
//                        timer_out->stop();
//                    });
                    //cout << N.feedback << endl;
                    req = 4;
                    continue;
                }
            }
            else if (opr == -1) {//退出战斗
                ui->serlife->setText("");
                ui->cltlife->setText("");
                M.kind = 5;
                send(clientSocket, (char*)&M, sizeof(M), 0);
            }
        }
        else if (req == 6) {//查询所有在线用户
            M.kind = 6;
            send(clientSocket, (char*)&M, sizeof(M), 0);

        }
        else if (req == 7) {

        }
        else if (req == 12) {
            M.kind = 12;

            //enter namepwd
            ui->notification_firm->setText("输入用户名和密码：");
            enteringflag=1;
            QObject::connect(ui->confirm_userpwd,&QToolButton::clicked,[=](){

//                char* ptr;
//                QByteArray ba,bb;
//                //QString str = ui->username->text();
//                ba = ui->username->text().toLatin1();
//                bb=ui->pwd->text().toLatin1();
//                ptr = ba.data();
//                memcpy(g_name,ptr,20);        //就是这一句，必须加，不然不只是把指针指向了值，并没有赋值
//                ptr=bb.data();
//                memcpy(g_pwd,ptr,20);
                string s1,s2;
                s1=ui->username->text().toStdString();
                s2=ui->pwd->text().toStdString();
                for(int i=0;i<s1.length();i++){
                    g_name[i]=s1[i];
                }
                g_name[s1.length()]='\0';
                for(int i=0;i<s2.length();i++)
                    g_pwd[i]=s2[i];
                g_pwd[s2.length()]='\0';

                ui->notification_firm->setText("");
                ui->username->setText("");
                ui->pwd->setText("");
                enteringflag=0;
            });
            while(enteringflag==1){

            }

            strcpy(M.name, g_name);
            strcpy(M.pwd, g_pwd);

            send(clientSocket, (char*)&M, sizeof(M), 0);
        }
        else if (req == 13) {
            M.kind = 13;
            send(clientSocket, (char*)&M, sizeof(M), 0);
        }
        //send(clientSocket, sendBuf, strlen(sendBuf), 0);
        if (req == -1){
            M.kind = -1;
            send(clientSocket, (char*)&M, sizeof(M), 0);
            recv(clientSocket, (char*)&N, sizeof(N), 0);
            break;
        }

        //	5	接受

        recv(clientSocket, (char*)&N, sizeof(N), 0);

        A.clt = N.myClt;
        A.myChoice = N.myChoice;
        A.enemy = N.enemy;

        showfeedback K;

//        timer_out->start(3000);
        K.output_feedback(N.feedback,ui);

//        QObject::connect(timer_out,QTimer::timeout,[=](){
//            ui->feedback->setText("");
//            timer_out->stop();
//        });

        //cout << N.feedback << endl;
        if (N.kind == -1) {
//            QTimer* timer1=new QTimer();
//            timer1->start(5000);
            QString s;
            s="已登录的用户为";
            s=s+QString::fromLocal8Bit(N.name,strlen(N.name));
            ui->notification_timer->setText(s);

            CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
//            QObject::connect(timer1,QTimer::timeout,[=](){
//                ui->notification_timer->setText("");
//                timer1->stop();
//            });
            //cout << "已登录的用户为" << N.name << endl;
        }
        else if (N.kind == 2) {
//            QTimer* timer2=new QTimer();
//            timer2->start(5000);
            QString s;
            s="退出登录的用户为";
            s=s+QString::fromLocal8Bit(N.name,strlen(N.name));
            ui->notification_timer->setText(s);

            CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
//            QObject::connect(timer2,QTimer::timeout,[=](){
//                ui->notification_timer->setText("");
//                timer2->stop();
//            });
            //cout << "退出登录的用户为" << N.name << endl;
        }

        else if (N.kind == 5) {
//            QTimer* timer3=new QTimer();
//            timer3->start(5000);
            QString s;
            s="退出战斗的用户为";
            s=s+QString::fromLocal8Bit(N.name,strlen(N.name));
            ui->notification_timer->setText(s);

            CreateThread(NULL,0,&m.timerthread,ui,0,NULL);
//            QObject::connect(timer3,QTimer::timeout,[=](){
//                ui->notification_timer->setText("");
//                timer3->stop();
//            });
            //cout << "退出战斗的用户为" << N.name << endl;
        }
        else if (N.kind == 6) {
            if (N.onlinecount == 0) {
//                QTimer* timer4=new QTimer();
//                timer4->start(5000);
                QString s;
                s="当前无在线用户";
                ui->onlinecltlabel->setText(s);
//                QObject::connect(timer4,QTimer::timeout,[=](){
//                    ui->notification_timer->setText("");
//                    timer4->stop();
//                });
                //cout << "当前无在线用户" << endl;
            }
            else {
//                QTimer* timer5=new QTimer();
//                timer5->start(5000);
                QString s;
                s="当前在线的用户有：";
                ui->onlinecltlabel->setText(s);
                ui->onlinecltcombo->clear();
                for (int i = 0; i < N.onlinecount; i++) {
                    QString s1;
                    s1=QString::fromLocal8Bit(N.allname[i],strlen(N.allname[i]));
                    ui->onlinecltcombo->addItem(s1);
                    //cout << N.allname[i] << endl;
                }

//                QObject::connect(timer5,QTimer::timeout,[=](){
//                    ui->notification_timer->setText("");
//                    timer5->stop();
//                });
//                cout << "当前在线的用户有：" << endl;

//                for (int i = 0; i < N.onlinecount; i++) {
//                    cout << N.allname[i] << endl;
//                }
            }
        }
        else if (N.kind == 12) {
            ui->showmypet->clear();
            ui->showmypet_label->setText("用户宠物查询结果：");
            for (int i = -1; i < N.petclt.petCount; i++) {
                if(i==-1){
                    ui->showmypet->addItem("用户拥有的宠物有：");
                }
                else{
                    QString s;
                    s=QString::fromLocal8Bit(N.petclt.myPet[i].name,strlen(N.petclt.myPet[i].name));

                    switch(N.petclt.myPet[i].kind){
                    case 0:
                        s=s+" 力量型";
                        break;
                    case 1:
                        s=s+" 肉盾型";
                        break;
                    case 2:
                        s=s+" 防御型";
                        break;
                    case 3:
                        s=s+" 敏捷型";
                        break;
                    default:
                        break;
                    }


                    s=s+" 等级：";
                    s=s+QString::number(N.petclt.myPet[i].level);
                    s=s+" 经验值：";
                    s=s+QString::number(N.petclt.myPet[i].exp);
                    ui->showmypet->addItem(s);
                }

                //cout << N.petclt.myPet[i].name << ",level: " << N.petclt.myPet[i].level << endl;
            }
            //cout << endl;
        }

        else if (N.kind == 13) {
//            qDebug()<<N.server.petCount;
//            for(int i=0;i<N.server.petCount;i++){
//                qDebug()<<N.server.myPet[i].name;
//            }
            ui->showmypet->clear();
            ui->showmypet_label->setText("服务器宠物查询结果：");
            for (int i = -1; i < N.server.petCount; i++) {
                if(i==-1){
                    ui->showmypet->addItem("服务器拥有的宠物有：");
                }
                else{
                    QString s;
                    s=QString::fromLocal8Bit(N.server.myPet[i].name,strlen(N.server.myPet[i].name));

                    switch(N.server.myPet[i].kind){
                    case 0:
                        s=s+" 力量型";
                        break;
                    case 1:
                        s=s+" 肉盾型";
                        break;
                    case 2:
                        s=s+" 防御型";
                        break;
                    case 3:
                        s=s+" 敏捷型";
                        break;
                    default:
                        break;
                    }

                    s=s+" 等级： ";
                    s=s+QString::number(N.server.myPet[i].level);
                    s=s+" 经验值：";
                    s=s+QString::number(N.server.myPet[i].exp);
                    ui->showmypet->addItem(s);
                }

                //cout << N.petclt.myPet[i].name << ",level: " << N.petclt.myPet[i].level << endl;
            }
            //cout << endl;
//            for (int i = 0; i < N.server.petCount; i++) {
//                cout << N.server.myPet[i].name << ",level: " << N.server.myPet[i].level << endl;
//            }
//            cout << endl;
        }
        else if (N.kind == 20) {
            ui->win_rate->setText(QString::number(N.medalclt.win_rate));
            //cout << "胜率： " << N.medalclt.win_rate << endl;
            //cout << "宠物个数徽章： ";
            if (N.medalclt.pet_count_medal == -1)
                ui->count_medal->setText("无");
                //cout << "无" << endl;
            else {
                if (N.medalclt.pet_count_medal == 0)
                    ui->count_medal->setText("金");
                    //cout << "金" << endl;
                if (N.medalclt.pet_count_medal == 1)
                    ui->count_medal->setText("银");
                    //cout << "银" << endl;
                if (N.medalclt.pet_count_medal == 2)
                    ui->count_medal->setText("铜");
                    //cout << "铜" << endl;
            }
            //cout << "高级宠物徽章： ";
            if (N.medalclt.high_level_pet_medal == -1)
                ui->quality_medal->setText("无");
                //cout << "无" << endl;
            else {
                if (N.medalclt.high_level_pet_medal == 0)
                    ui->quality_medal->setText("金");
                    //cout << "金" << endl;
                if (N.medalclt.high_level_pet_medal == 1)
                    ui->quality_medal->setText("银");
                    //cout << "银" << endl;
                if (N.medalclt.high_level_pet_medal == 2)
                    ui->quality_medal->setText("铜");
                    //cout << "铜" << endl;
            }
        }


        //enter req
        enteringflag=1;
        ui->notification_firm->setText("选择你的请求：");
        QObject::connect(ui->confirm_req,&QToolButton::clicked,[=](){

            if(ui->req->currentIndex()-1 < 4)
                req=ui->req->currentIndex()-1;
            else if(ui->req->currentIndex()-1 == 4)
                req=6;
            else if(ui->req->currentIndex()-1 == 5)
                req=12;
            else if(ui->req->currentIndex()-1 == 6)
                req=13;
            else if(ui->req->currentIndex()-1 == 7)
                req=20;
            else if(ui->req->currentIndex()-1 == 8)
                req=-1;
            ui->notification_firm->setText("");
            ui->onlinecltcombo->clear();
            ui->onlinecltlabel->setText("");
            ui->win_rate->setText("");
            ui->quality_medal->setText("");
            ui->count_medal->setText("");
            ui->showmypet->clear();
            enteringflag=0;
        });
        while(enteringflag==1){

        }

//        cout << "Enter request: (0 to sign up and 1 to log in)" << endl;
//        cin >> req;
    }//while(1)

    //	6	关闭socket
    closesocket(clientSocket);


    //	7	终止
    WSACleanup();

    ui->notification_firm->setText("客户端退出，请关闭窗口");
    //cout << "客户端退出" << endl;

}

CLT clt[101];//clt[100]是服务器
int cltCount = 0;

thisclt A;
