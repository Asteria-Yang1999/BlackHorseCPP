#include <iostream>
#include <queue>
using namespace std;

void test01()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while (!q.empty())
    {
        // 10 40 20 40 30 40 40 40
        cout << "��ͷ�� " << q.front() << endl;
        cout << "��β�� " << q.back() << endl;
        //������ͷԪ��
        q.pop();
    }
    cout << "size: " << q.size() << endl;
}

int main() {
    test01();
    return 0;
}
