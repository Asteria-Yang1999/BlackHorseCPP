#include <iostream>

using namespace std;

//����һ���ӷ�
#define MyAdd(x, y)  ((x) + (y))

void test01()
{
    int ret = MyAdd(10, 20) *20; //Ԥ�ڽ�� 600   10+20*20

    cout << "ret = " << ret << endl;
}

#define MyCompare(a, b) ((a) < (b) ? (a) : (b))

inline void mycompare(int a, int b)
{
    int ret = a < b ? a : b;
    cout << "ret ::::: " << ret << endl;
}

//1.����������ע������
//���ڲ��ĳ�Ա���� Ĭ��ǰ����inline�ؼ���
inline void func(); //������������
inline void func() {}; //�������ʵ��ʱ��û�м�inline�ؼ��֣���ô���������Ȼ������������

void test02()
{
    int a = 10;
    int b = 20;

    // int ret = MyCompare(++a, b);   // Ԥ�ڽ����11  ((a++) < (b) ? (a++) : (b))
    // cout << "ret = " << ret << endl;

    mycompare(++a, b);
}

int main()
{
    test02();

    return 0;
}


//���������൱���ÿռ任ʱ�䣬ʡȥ���ú�����ջ��ջ����ģ�ֱ��ִ�����������ڲ��Ĵ���

/*���������ﲻ�ܴ����κ���ʽ��ѭ�����
���ܴ��ڹ���������ж����
�����岻�ܹ����Ӵ�
���ܶԺ�������ȡַ����

�������� �����ȱ������

���������Ǹ�������һ�����飬��������һ������
һ���õı�����������С�ġ��򵥵ĺ���
*/
