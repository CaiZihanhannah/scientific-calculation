#include "piece.h"
#include <QDebug>

PieceList::PieceList(QWidget *p)                                            //初始化棋子链表
{
    head = NULL;
    tail = NULL;
    parent = p;
}
void PieceList::AddPiece(const PieceType& type, const int& x, const int& y)
{
    Piece *temp;
    if(type==white)                                                         //当前棋子颜色
        temp = new WhitePiece(parent);
    else
        temp = new BlackPiece(parent);
    temp->SetPiece(x,y);                                                    //设置棋子样式
    if(head==NULL)                                                          //维护链表
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void PieceList::ClearBoard()
{
    Piece *temp;
    temp = head;
    while(temp!=NULL)                                                       //根据链表清理棋盘
    {
        head = temp;
        temp = temp->next;
        head->DeletePiece();
    }
    head = NULL;
    tail = NULL;
}
PieceList::~PieceList()
{
    ClearBoard();
}

Piece::Piece(QWidget *p)                                                    //初始化棋子
{
    next = NULL;
    label = new QLabel(p);                                                  //label由于有父类 不delete也会自动释放
    label->resize(35,35);
}
void Piece::DeletePiece()
{
    delete label;                                                           //删除棋子图形
}

void BlackPiece::SetPiece(const int& x, const int& y)
{
    label->setPixmap(QPixmap(":/image/black.png"));                         //设置黑棋图片
    label->move(x*33+2,y*33);                                               //设置棋子位置
    label->show();
}
void WhitePiece::SetPiece(const int& x, const int& y)
{
    label->setPixmap(QPixmap(":/image/white.png"));                         //设置白棋图片
    label->move(x*33+2,y*33);                                               //设置棋子位置
    label->show();
}


