#ifndef Computer_hpp
#define Computer_hpp

#include "Gobang.h"
#include "Player.hpp"

using namespace std;

class Computer:public Player{       //继承Player类
public:
    Computer(ChessBoard * const B, const int BW);   //默认Computer的名字就是Computer
    ~Computer(){}
    virtual void NextChess(int& x, int& y);           //AI的部分，电脑下一步落子的函数
};

#endif /* Computer_hpp */
