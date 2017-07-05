#include "Computer.hpp"
#include "Gobang_turn.h"
#include <Qdebug>

Computer::Computer(ChessBoard * const B, const int BW){
    name="Computer";
    lastx=lasty=-1;
    PlayerBoard=B;
    BlackWhite=BW;
}

void Computer::NextChess(int& x, int& y){
    int tempx=-1, tempy=-1;
    if(!PlayerBoard->LegalStep(tempx, tempy)){
        Nextmove Mycomputer;
        int result = Mycomputer.Gobang_turn(PlayerBoard, BlackWhite);   //调用Gobang_turn函数取得AI的下一步
        tempx = result / 100;   //以一个四位数返回，低两位为列数，高两位为行数
		tempy = result % 100;
        while (tempx==-1||tempy==-1||PlayerBoard->board[tempx][tempy]!=Empty)   //如果AI的下一步是非法的（AI判断自己已经不可能获胜），则返回一个随机点
		{
			tempx = rand() % ROW;
			tempy = rand() % COL;
        }
    }
    lastx=tempx;
    lasty=tempy;
    PlayerBoard->SetLast(tempx, tempy, BlackWhite);     //维护棋盘
    PlayerBoard->Set(tempx, tempy, BlackWhite);
    x=tempx;    //修改x,y值；使其传到外部
    y=tempy;
}
