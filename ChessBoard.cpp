#include "ChessBoard.hpp"

ChessBoard::ChessBoard(){
    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++)
            board[i][j]=Empty;//初始化是棋盘为空
    }
    lastx=lasty=-1;
}

void ChessBoard::PrintBoard()const{
    int i, j;
    for(i=-1;i<ROW;i++){
        for(j=-1;j<COL;j++){
            if(i==-1){
                if(j==-1)
                    cout << "  ";
                else
                    printf("%X ", j);
            }
            else if(j==-1){
                printf("%X ", i);
            }
            else
                cout << int(board[i][j]) << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void ChessBoard::Set(const int x, const int y, const int Chess){
    board[x][y]=Chess;
}

void ChessBoard::SetLast(const int x, const int y, const int BW){
    lastx=x;
    lasty=y;
    lastBW=BW;
}

int ChessBoard::GetlastW()const{
    return lastBW;
}

int ChessBoard::Getlastx()const{
    return lastx;
}

int ChessBoard::Getlasty()const{
    return lasty;
}

bool ChessBoard::InBoard(const int x, const int y)const{
    if(x<ROW && x>-1 && y<COL && y>-1)
        return true;
    else
        return false;
}

bool ChessBoard::LegalStep(const int x, const int y)const{
    if(board[x][y]==Empty && x<ROW && x>-1 && y<COL && y>-1)//在棋盘内且原来为空
        return true;
    else
        return false;
}

bool ChessBoard::HorizontalCheck()const{
    int i, count=0;
    for(i=-4;i<=4;i++){//最后一个落子的左4个到右4个之间遍历判断
        if(!InBoard(lastx, lasty+i))//如果这个子已经超出范围了则没跳过
            continue;
        if(board[lastx][lasty+i]==lastBW){//如果这个子和最后下的一个子同色，计数+1，到5则连5子
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;    //否则重新技术
    }
    return false;
}

bool ChessBoard::VerticalCheck()const{//垂直方向原理同水平方向
    int i, count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty))
            continue;
        if(board[lastx+i][lasty]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    return false;
}

bool ChessBoard::DiagonalCheck()const{//对角线分为2个对角线的方向的检查，原理同前
    int i, count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty+i))
            continue;
        if(board[lastx+i][lasty+i]==lastBW){//但是下一个子的循环条件需要同时修改x和y
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    count=0;
    for(i=-4;i<=4;i++){
        if(!InBoard(lastx+i, lasty-i))
            continue;
        if(board[lastx+i][lasty-i]==lastBW){
            count++;
            if(count==5)
                return true;
        }
        else
            count=0;
    }
    return false;
}













