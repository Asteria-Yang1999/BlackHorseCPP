#include <iostream>
using namespace std;

void test01()
{
    // int &ref = 10; //�����˲��Ϸ����ڴ�,������
    const int &ref = 10; //����const��,����������ʽΪint tmp = 10; const int & ref = tmp

    //ref = 10;

    int * p = (int *) &ref;
    *p = 1000;

    cout << "ref = " << ref << endl;
}

//��������ʹ�ó���: ���������β�
void showValue(const int &val)
{
    // val += 1000;  //���ֻ������ʾ����,�����޸�����,��ô����const��������β�
    cout << "val = " << val << endl;
}

void test02()
{
    int a = 10;
    showValue(a);
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}