
#define Gobang_turn_
#include "Gobang_point.h"
#include "ChessBoard.hpp"
#include <QDebug>
class Nextmove
{
public:
    void Initialize(ChessBoard * const , int a[15][15]);	//�����̽��г�ʼ��������Ϊ1������Ϊ-1������Ϊ0
    int Search_tree(int a[15][15], int count, int const& k);	//��������aΪ��������״̬��count��ʾ������������k(-1/1)��ʾ��ǰ���ӵĺڰ�
    int max0, min0, max1;	//������ȫ�ֱ������ڼ�֦
    int Gobang_turn(ChessBoard * const B, const int BW);	//Nextmove�����ⲿ�Ľӿ�

};
