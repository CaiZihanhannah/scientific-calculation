#ifndef Player_hpp
#define Player_hpp

#include "Gobang.h"
#include "ChessBoard.hpp"
using namespace std;

class Player{
protected:
    string name;        //名字
    int lastx, lasty;     //前一步,大概可以高亮显示
    ChessBoard *PlayerBoard;    //绑定的棋盘
    int BlackWhite;   //黑子先手
public:
    Player(){}
    virtual ~Player(){}
    virtual void NextChess(int& x, int& y)=0; //computer需要修改x,y值
    string GetName()const;  //返回选手名字
};

#endif /* Player_hpp */
