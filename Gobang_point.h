#ifndef Gobang_point_
#define Gobang_point_

#define WIN 500000;

class Gobangpoint
{
public:
    int Gobang_point(const int a[15][15], const int& k);	//�Ե�ǰ���̵ĺ��ӣ�k=1������ӣ�k=-1�����д��
    bool Gobang_Havefour(int a[15][15], const int& k);		//�ж���������������������
    bool Gobang_Havefive(int a[15][15], const int& k);		//�ж���������������������
};

#endif
