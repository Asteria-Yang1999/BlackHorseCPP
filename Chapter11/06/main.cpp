#include <iostream>
#include <string>
using namespace std;

//��������
void test01()
{
    //��һ��
    pair<string, int> p(string("Tom"), 100);

    //ȡֵ
    cout << "������ " << p.first << endl;
    cout << "���䣺 " << p.second << endl;

    //�ڶ��ִ���
    pair<string, int> p2 = make_pair("Jerry", 200);

    //ȡֵ
    cout << "������ " << p2.first << endl;
    cout << "���䣺 " << p2.second << endl;
}



int main() {
    test01();
    return 0;
}
