#ifndef PIECE_H
#define PIECE_H

#include <QDebug>

#include <QLabel>
#include <QString>

enum PieceType {white, black};

class Piece;

class PieceList                                                         //棋子链表
{
public:
    PieceList(QWidget *p);                                              //构造函数
    void AddPiece(const PieceType& type, const int& x, const int& y);   //增加一颗棋子
    void ClearBoard();                                                  //清理棋盘
    ~PieceList();                                                       //析构函数
private:
    QWidget *parent;                                                    //父窗口
    Piece *head, *tail;                                                 //链表头尾
};

class Piece                                                             //棋子
{
public:
    Piece(QWidget *p);                                                  //构造函数
    virtual void SetPiece(const int& x, const int& y) = 0;              //设置棋子样式
    void DeletePiece();                                                 //删除棋子
    Piece *next;                                                        //下一个棋子
protected:
    QLabel *label;                                                      //其图形框
};

class BlackPiece : public Piece                                         //黑棋
{
public:
    BlackPiece(QWidget *p=nullptr):Piece(p){}
    void SetPiece(const int& x, const int& y);
};

class WhitePiece : public Piece                                         //白棋
{
public:
    WhitePiece(QWidget *p=nullptr):Piece(p){}
    void SetPiece(const int& x, const int& y);
};

#endif // PIECE_H
