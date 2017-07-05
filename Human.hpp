#ifndef Human_hpp
#define Human_hpp

#include "Gobang.h"
#include "Player.hpp"
using namespace std;

class Human:public Player{          //继承Player类
public:
    Human(const string S, ChessBoard * const B, const int BW);          //S名字，B绑定的棋盘，BW是该玩家棋子的颜色
    ~Human(){}
    virtual void NextChess(int& x, int& y);   //等待人类玩家输入下一步的函数
};

#endif /* Human_hpp */
