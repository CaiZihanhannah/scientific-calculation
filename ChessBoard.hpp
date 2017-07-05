#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include "Gobang.h"

using namespace std;

class ChessBoard{
private:

    int lastx, lasty, lastBW;   //双方最后一步落子的坐标和颜色，这个子最好用不同的颜色表示出来
public:
    char board[ROW][COL];       //棋盘
    ChessBoard();
    ~ChessBoard(){}
    void PrintBoard()const;     //打印棋盘的函数
    void Set(const int x, const int y, const int Chess);//将某个坐标的值置为某个颜色的函数，Chess是函数
    void SetLast(const int x, const int y, const int BW);//更改lastx, lasty, BW3个值的函数
    int GetlastW()const;        //返回相应属性的3个函数
    int Getlastx()const;
    int Getlasty()const;
    bool LegalStep(const int x, const int y)const;  //判断某一落子是否合法的函数
    bool InBoard(const int x, const int y)const;    //判断某个坐标是否在棋盘内的函数
    bool VerticalCheck()const;      //对最后一步落子判断垂直方向有没有因为这个子形成连珠
    bool HorizontalCheck()const;    //....水平方向.....
    bool DiagonalCheck()const;      //....2个对角线方向....
};

#endif
