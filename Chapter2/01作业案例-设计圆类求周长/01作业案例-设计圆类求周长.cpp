#include <iostream>

using namespace std;

const double pi = 3.14;

//1.���һ���࣬��Բ���ܳ�
//�ܳ���ʽ 2 * pi * r
class Circle  //class��������һ���࣬����������������
{
public:  //����Ȩ��

//��Բ���ܳ�
    //��������д��������Ա����
    double calculateZC()
    {
        return 2*pi*m_R;
    }

    //���ð뾶�ĳ�Ա����
    //��Ա���������޸ĳ�Ա����
    void setR(int r)
    {
        m_R = r;
    }

//�뾶  ��Ա����
    int m_R;

};

void test01()
{
    //ͨ����������һ��?
    Circle c1; //? ������
    // c1.m_R = 10; //��������������а뾶�ĸ�ֵ
    //ͨ����Ա������Ӹ�Բ���ð뾶
    c1.setR(10);
    //���c1���ܳ�

    cout << "c1���ܳ�Ϊ�� " << c1.calculateZC() << endl;

}

int main()
{
    test01();
    return EXIT_SUCCESS;
}