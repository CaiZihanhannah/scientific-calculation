
#include "start.h"
#include "Gobang.h"
#include "ChessBoard.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

#include "piece.h"
#include "gamemain.h"
#include "ui_gamemain.h"
#include <QDebug>
#include <QIcon>
#include <QLabel>
#include <QMouseEvent>
#include <QTime>
#include <QMessageBox>
#include <QPushButton>

QLabelToBeClick::QLabelToBeClick(QWidget *parent):QLabel(parent)        //初始化自定义QLabel类
{
    this->setMouseTracking(true);                                       //将鼠标跟踪置为真
}
void QLabelToBeClick::mousePressEvent(QMouseEvent *event)               //重载鼠标点击事件
{
    int x, y;
    x = event->x()-2;                                                   //根据鼠标点击事件传出clicked(x, y)信号
    y = event->y();
    event->accept();
    emit clicked(x/33, y/33);
}

GameMain::GameMain(QWidget *parent) :                                   //初始化
    QMainWindow(parent),
    ui(new Ui::GameMain),
    list(this)
{
    ui->setupUi(this);
    now=black;                                                          //白子先行
    setWindowIcon(QIcon(":/image/gobang.ico"));
    setWindowTitle("Gobang");
    setFixedSize(800,500);
    QLabelToBeClick *label = new QLabelToBeClick(this);                 //棋盘图形框
    label->setPixmap(QPixmap(":/image/board.jpg"));                     //棋盘图片
    label->resize(500,500);                                             //棋盘大小
    label->show();
    connect(label,&QLabelToBeClick::clicked,this,&GameMain::ExecPlay);  //连接槽与clicked()信号

    QLabelToBeClick *label2 = new QLabelToBeClick(this);                //其它地方的背景框
    label2->setPixmap(QPixmap(":/image/buttonback.jpg"));               //背景图片
    label2->move(500,0);
    label2->resize(300,500);
    label2->show();

    QPushButton *labelS1 = new QPushButton(this);                       //下一局按钮
    labelS1->setText("下一局");
    labelS1->resize(100,50);
    labelS1->move(610,200);
    connect(labelS1,&QPushButton::clicked,this,&GameMain::NextPlay);    //连接槽与信号
    QPushButton *labelS2 = new QPushButton(this);                       //主菜单按钮
    labelS2->setText("主菜单");
    labelS2->resize(100,50);
    labelS2->move(610,300);
    connect(labelS2,&QPushButton::clicked,this,&GameMain::return_start);//连接槽与信号

    QPalette palette=this->palette();                                   //样式
    this->setPalette(palette);
    labelS1->setStyleSheet("QPushButton{background-color:black;\
                           color: white;   border-radius: 10px;  border: 2px groove gray;\
                           border-style: outset;}"
                           "QPushButton:hover{background-color:white; color: black;}"
                           "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                           border-style: inset; }");                   //设置按钮样式
    labelS2->setStyleSheet("QPushButton{background-color:black;\
                            color: white;   border-radius: 10px;  border: 2px groove gray;\
                            border-style: outset;}"
                            "QPushButton:hover{background-color:white; color: black;}"
                            "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                            border-style: inset; }");                   //设置按钮样式
}

GameMain::~GameMain()
{
    delete ui;
}

void GameMain::SetGame(const int& mode,const int& first)                //初始化游戏模式
{
    TheBoard=new ChessBoard();
    Mode=mode;
    First=first;                                                        //先行Player
    string tempname, tempname2;

    switch(Mode){
        case PVC:                                                       //人机对弈
            tempname="PH";
            //first 1 人类先行

            P[first]=new Human(tempname, TheBoard, first==black?Black:White);
            P[1-first]=new Computer(TheBoard, first==white?Black:White);

            break;
        case PVP:                                                       //人人对弈
            tempname="P1";
            tempname2="P2";

            P[black]=new Human(tempname, TheBoard, Black);
            P[white]=new Human(tempname2, TheBoard, White);

            break;
        default:
            break;
    }
    if(P[black]->GetName().compare("Computer")==0)                      //若电脑先行
    {
        int tx, ty;
        P[now]->NextChess(tx,ty);
        list.AddPiece(now,tx,ty);
        now=white;
    }
}

void GameMain::ExecPlay(const int& x, const int& y)                     //走一步
{
    int tx=x, ty=y;
    list.AddPiece(now,tx,ty);                                           //画出棋子
    P[now]->NextChess(tx,ty);                                           //在抽象矩阵棋盘中标出棋子
    if(now==black)
        now=white;
    else
        now=black;
                                                                        //判断是否胜利
    if(TheBoard->DiagonalCheck() || TheBoard->HorizontalCheck() || TheBoard->VerticalCheck()){
        int Winner=TheBoard->GetlastW();
        print_winner(Winner);
        delay();                                                        //延迟后清理棋盘
        NextPlay();
        return;
    }
    if(Mode==PVC)                                                       //人机对弈每当人类走一步，电脑也走一步
    {
        P[now]->NextChess(tx,ty);
        list.AddPiece(now,tx,ty);
        if(now==black)
            now=white;
        else
            now=black;
        if(TheBoard->DiagonalCheck() || TheBoard->HorizontalCheck() || TheBoard->VerticalCheck()){
            int Winner=TheBoard->GetlastW();
            print_winner(Winner);
            delay();
            NextPlay();
            return;
        }
    }
}

void GameMain::NextPlay()                                               //下一局游戏
{
    list.ClearBoard();
    now=black;
    delete TheBoard;
    delete P[0];
    delete P[1];
    SetGame(Mode,First);
}

void GameMain::delay()                                                  //延迟
{
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void GameMain::print_winner(const int& winner)                          //弹出胜利者提示框
{
    char w[2][40]={"The winner is Player Black!","The winner is Player White!"};
    int ret = QMessageBox::question(this,tr("提示"),tr(w[winner-1]),QMessageBox::Yes);
    if(ret == QMessageBox::Yes)
    {
        NextPlay();
    }
}

void GameMain::return_start()                                           //返回主菜单
{
    this->close();
    Start *w=new Start();
    w->show();
}
