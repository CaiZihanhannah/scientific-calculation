#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include "ChessBoard.hpp"
#include "Player.hpp"
#include "piece.h"
#include <QMainWindow>

namespace Ui {
class GameMain;
}

class QLabelToBeClick : public QLabel               //定义自己的QLabel类供棋盘使用，实现对鼠标点击信号的发送
{
    Q_OBJECT
public:
    QLabelToBeClick(QWidget *parent = 0);           //构造函数，由于其父窗口会析构掉它，故该类不需要析构函数
protected:
    void mousePressEvent(QMouseEvent *event);       //重载鼠标点击事件方法
signals:
    void clicked(const int& x, const int& y);       //鼠标点击信号
};

class GameMain : public QMainWindow                 //游戏界面窗口类
{
    Q_OBJECT

public:
    explicit GameMain(QWidget *parent = 0);         //构造函数
    ~GameMain();                                    //析构函数
    void SetGame(const int& mode, const int& first = 0);
                                                    //设置游戏模式
    void delay();                                   //延时方法

private:
    Ui::GameMain *ui;                               //UI
    PieceList list;                                 //棋子链表，维护当前棋子
    PieceType now;                                  //当前玩家棋子颜色
    Player *P[2];                                   //两个玩家
    ChessBoard *TheBoard;                           //棋盘
    int Mode,First;                                 //游戏模式

public slots:
    void ExecPlay(const int& x, const int& y);      //执行一步游戏
    void NextPlay();                                //下一场游戏
    void return_start();                            //返回主菜单
    void print_winner(const int& winner);           //提示赢家
};


#endif // GAMEMAIN_H
