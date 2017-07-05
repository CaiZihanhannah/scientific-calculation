#include"Gobang_turn.h"
#include<QDebug>

int Nextmove::Gobang_turn(ChessBoard * const B, const int BW)
{
    int a[15][15];
    int k = (BW == Black )?1:-1;
    Initialize(B,a);
    int count = 0;
    for (int i = 0; i < 15; i++)	//统计棋盘上棋子的个数，便于初始化判断
        for (int j = 0; j < 15; j++)
        {
            if (a[i][j] != 0) count++;
        }
    if (!count) return 707;		//若执黑，第一步下在棋盘正中
    if (count==1)	//若执白，第一步下在比对方更靠近棋盘正中的地方
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                if (a[i][j] != 0)
                {
                    if (i < 7 && j < 7) return (i + 1) * 100 + (j + 1);
                    if (i < 7 && j >= 7) return (i + 1) * 100 + (j - 1);
                    if (i >= 7 && j < 7) return (i - 1) * 100 + (j + 1);
                    if (i >= 7 && j >= 7) return (i - 1) * 100 + (j - 1);
                }

    max0 = -WIN;
    int maxi = -1, maxj = -1;
    for (int i = 0; i < 15; i++)	//搜索树为第一层，玩家落子的情形判断
        for (int j = 0; j < 15; j++)
        {
            if (a[i][j] == 0)
            {
                Gobangpoint Mybang;
                int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);	//电脑分数减去玩家分数为当前棋盘的分数
                a[i][j] = k;
                if (Mybang.Gobang_Havefive(a, k)) { return i * 100 + j; }
                int point2 = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                if (point == point2) { a[i][j] = 0; continue; }		//如果落子后分数不变则忽略该节点，减少不必要的搜索
                if (!Mybang.Gobang_Havefour(a, -k) && point2 > 400000)  //能够获胜就选择获胜的步骤
                {
                    return i * 100 + j;
                }
                int result = Search_tree(a, 0, k);

                if (result == -500000) { a[i][j] = 0; continue; }	//result为最小，则说明玩家有必胜手，则忽略这一节点
                if (result > max0)
                {
                    max0 = result;
                    maxi = i;
                    maxj = j;
                }
                a[i][j] = 0;
            }
        }
    qDebug()<<max0<<endl;
    return maxi * 100 + maxj;	//用i*100+j的形式坐标，较为方便
}


int Nextmove:: Search_tree(int a[15][15], int count, const int& k)
{
    if (count == 0)		//搜索树为第二层，玩家落子的情形判断
    {
        min0 = WIN;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
            {
                if (a[i][j] == 0)
                {
                    Gobangpoint Mybang;
                    int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    a[i][j] = -k;
                    int point2 = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    if (point == point2) { a[i][j] = 0; continue; }
                    if (Mybang.Gobang_Havefive(a, k)) { a[i][j] = 0; return WIN; }
                    if (Mybang.Gobang_point(a, -k) >= 500000) { a[i][j] = 0; return -WIN; }
                    point = Search_tree(a, count + 1, k);
                    if (min0 > point) min0 = point;
                    if (min0 <= max0) { a[i][j] = 0; continue; }	//剪枝
					//如果该节点的某个孩子已经小于该节点祖先当前最大值，那么我们判断一定不会选择这一步，从而减少搜索量
                    a[i][j] = 0;
                }
            }
        return min0;
    }
    if (count == 1)		//搜索树为第三层，电脑落子的情形判断
    {

        int max = -WIN;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
            {
                if (a[i][j] == 0)
                {
                    Gobangpoint Mybang;
                    a[i][j] = k;
                    int point = Mybang.Gobang_point(a, k) - Mybang.Gobang_point(a, -k);
                    if (Mybang.Gobang_Havefive(a, k)) { a[i][j] = 0; return WIN; }
                    if (Mybang.Gobang_point(a, k) >= 500000) { a[i][j] = 0; return WIN; }
                    if (Mybang.Gobang_Havefour(a, k)) { a[i][j] = 0; continue; }
                    if (max < point) max = point;
                    a[i][j] = 0;
                }
            }
        return max;
    }
    return 0;
}

void Nextmove::Initialize(ChessBoard * const B, int a[15][15])	//初始化
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (B->board[i][j] == Black) a[i][j] = 1; else if (B->board[i][j] == White) a[i][j] = -1; else a[i][j] = 0;
}
