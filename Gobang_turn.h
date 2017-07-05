
#define Gobang_turn_
#include "Gobang_point.h"
#include "ChessBoard.hpp"
#include <QDebug>
class Nextmove
{
public:
    void Initialize(ChessBoard * const , int a[15][15]);	//对棋盘进行初始化，黑子为1，白子为-1，无子为0
    int Search_tree(int a[15][15], int count, int const& k);	//搜索树，a为传入棋盘状态，count表示搜索树层数，k(-1/1)表示当前落子的黑白
    int max0, min0, max1;	//这三个全局变量用于剪枝
    int Gobang_turn(ChessBoard * const B, const int BW);	//Nextmove类与外部的接口

};
