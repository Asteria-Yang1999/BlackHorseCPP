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
        cout << "队头： " << q.front() << endl;
        cout << "队尾： " << q.back() << endl;
        //弹出队头元素
        q.pop();
    }
    cout << "size: " << q.size() << endl;
}

int main() {
    test01();
    return 0;
}
