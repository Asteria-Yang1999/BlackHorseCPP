#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    stack<int>s;
    //�������� push
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(40);

    while (s.size() != 0)
    {
        cout << "ջ��Ϊ�� " << s.top() << endl;    //40 20 30 10
        //����ջ��Ԫ��
        s.pop();
    }
    cout << "size = " << s.size() << endl;
}


int main() {
    test01();
    return 0;
}
