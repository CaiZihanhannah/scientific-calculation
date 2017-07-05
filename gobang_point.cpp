#include"Gobang_point.h"
#include <Qdebug>
int Gobangpoint::Gobang_point(const int a[15][15], const int& k)	//对当前棋盘的黑子（k=1）或白子（k=-1）进行打分
{
        int ans = 0;
        int count3 = 0, count2 = 0;
        int di[4] = { 1,1,0,-1 };
        int dj[4] = { 0,1,1,1 };	//di，dj代表向下，向右，右下，右上四个不同的方向
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                if (a[i][j] == k)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (i - di[l] < 0 || j - dj[l] < 0 || i - di[l] > 14 || j - dj[l] > 14 || a[i - di[l]][j - dj[l]] != k)
                        {	//仅对连子进行加分，单个子不算分
                            int ii = i + di[l], jj = j + dj[l];
                            while (a[ii][jj] == k && ii < 15 && jj < 15 && ii >= 0 && jj >= 0) { ii += di[l]; jj += dj[l]; }
                            int length;
                            if (ii - i >= jj - j) length = ii - i; else length = jj - j;
                    //        if (j==1&&i==10&&l==0&&k==-1) qDebug()<<"length"<<length<<endl;
                            if (length == 5) ans = WIN;	//成五子
/*                            if (ii == 15) ii--;
                            if (jj == 15) jj--;*/
                            int obstacle = 0;	//obstacle代表障碍数（0、1、2），即一段连珠两端有几个障碍（对方的子或是棋盘边缘）
                            if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] == -k) obstacle++;
                            if (ii > 14 || jj > 14 || a[ii][jj] == -k) obstacle++;
                            if (length == 4)
                            {
                                if (obstacle == 0) ans = WIN;		//活四
                                if (obstacle == 1) { ans += 100; count3++; }		//冲四
                                if (obstacle == 2) ans += 50;		//死四
                            }
                            if (length == 3)
                            {
                                if (obstacle == 0) { ans += 100; count3++; }		//活三
                                if (obstacle == 1) { ans += 20; count2++; }		//眠三
                                if (obstacle == 2) ans += 5;		//死三
                            }
                            if (length == 2)
                            {
                                if (obstacle == 0) { ans += 15; count2++; }		//活二
                                if (obstacle == 1) ans += 6;		//眠二
                                if (obstacle == 2) ans += 3;		//死二
                            }
                        //    if (j==1&&i==10&&l==0&&k==-1) qDebug()<<"obs:"<<obstacle<<endl;
                        }

                    }

                }
        if (count3 >= 2) ans += 1500;	//双三、活三冲四的棋形加较多的加分
        if (count2 >= 2) ans += count2 * 10;	//多个活二也有一定威胁，加适当的奖励分数
        return ans;
}

bool Gobangpoint::Gobang_Havefour(int a[15][15], const int& k)	//判断整个棋盘有无四子连珠
{
    int di[4] = { 1,1,0,-1 };
    int dj[4] = { 0,1,1,1 };
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (a[i][j] == k)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] != k)
                    {
                        int ii = i + di[l], jj = j + dj[l];
                        while (a[ii][jj] == k && ii < 15 && jj < 15) { ii += di[l]; jj += dj[l]; }
                        int length;
                        if (ii - i > jj - j) length = ii - i; else length = jj - j;
                        if (ii == 15) ii--;
                        if (jj == 15) jj--;
                        int obstacle = 0;
                        if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] == -k) obstacle++;
                        if (ii + di[l] > 14 || jj + dj[l] > 14 || a[ii][jj] == -k) obstacle++;
                        if (length == 4 && obstacle < 2)
                        {
                            return true;
                        }
                    }

                }

            }
    return false;
}

bool Gobangpoint::Gobang_Havefive(int a[15][15], const int& k)	//判断整个棋盘有无五子连珠
{
    int di[4] = { 1,1,0,-1 };
    int dj[4] = { 0,1,1,1 };
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (a[i][j] == k)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i - di[l] < 0 || j - dj[l] < 0 || a[i - di[l]][j - dj[l]] != k)
                    {
                        int ii = i + di[l], jj = j + dj[l];
                        while (a[ii][jj] == k && ii < 15 && jj < 15) { ii += di[l]; jj += dj[l]; }
                        int length;
                        if (ii - i > jj - j) length = ii - i; else length = jj - j;
                        if (ii == 15) ii--;
                        if (jj == 15) jj--;
                        if (length == 5)
                        {
                            return true;
                        }
                    }

                }

            }
    return false;
}
