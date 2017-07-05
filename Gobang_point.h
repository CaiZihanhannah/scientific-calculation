#ifndef Gobang_point_
#define Gobang_point_

#define WIN 500000;

class Gobangpoint
{
public:
    int Gobang_point(const int a[15][15], const int& k);	//对当前棋盘的黑子（k=1）或白子（k=-1）进行打分
    bool Gobang_Havefour(int a[15][15], const int& k);		//判断整个棋盘有无四子连珠
    bool Gobang_Havefive(int a[15][15], const int& k);		//判断整个棋盘有无五子连珠
};

#endif
