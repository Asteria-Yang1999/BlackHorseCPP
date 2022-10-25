#include <iostream>
#include <vector>
#include <list>
using namespace std;

void test01()
{
    vector<int> v;
    for ( int i = 0; i < 10; i++)
    {
        v.push_back(i);
        cout << v.capacity() << endl;    //v.capacity()容器的容量
    }
}

void printVector(vector<int> & v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    vector<int> v;
    int arr[] = {2, 3, 4, 1, 9};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> v2(v1.begin(), v1.end());

    printVector(v2);

    vector<int>v3(10, 100);

    printVector(v3);

    //赋值使用
    vector<int>v4;
    v4.assign(v3.begin(), v3.end());
    printVector(v4);

    v4.swap(v2);
    cout << "After Swaping v4 = ";
    printVector(v4);

    cout << "The size of v4 = " << v4.size() << endl;

    if (v4.empty())
    {
        cout << "v4 is empty" << endl;
    }
    else
    {
        cout << "v4 is not empty" << endl;
    }

    v4.resize(10, -1);    //第二个参数是默认的填充值， 默认是0
    printVector(v4);

    v4.resize(3);
    printVector(v4);
}

//巧用swap收缩空间
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }
    cout << "the capacity of v = " << v.capacity() << endl;
    cout << "the size of v = " << v.size() << endl;

    v.resize(3);

    cout << "the capacity of v = " << v.capacity() << endl;
    cout << "the size of v = " << v.size() << endl;

    //巧用swap
    vector<int>(v).swap(v);

    cout << "the capacity of v = " << v.capacity() << endl;
    cout << "the size of v = " << v.size() << endl;
}

void test04()
{
    vector<int> v;

    v.reserve(100000); //预留空间

    int* p = NULL;
    int num = 0;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << num << endl;
    //开辟100000数据用了多少次
}

void test05()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    cout << "the front of v = " << v.front() << endl;
    cout << "the back of v = " << v.back() << endl;

    v.insert(v.begin(), 2, 100);    //参数1：迭代器    参数2：N    参数3：具体插入的内容
    printVector(v);

    v.pop_back();    //尾删
    printVector(v);

    v.erase(v.begin());  //删除
    printVector(v);

//    v.erase(v.begin(), v.end());
    v.clear(); //清空所有数据
    if(v.empty())
    {
        cout << "v is empty" << endl;
    }
}

void test06()
{
    //逆序遍历
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
//    printVector(v);
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //vector迭代器是随机访问迭代器，支持跳跃式访问
    vector<int>::iterator itBegin = v.begin();
    itBegin = itBegin + 3;
    //如果上述写法不报错，则这个迭代器可以支持随机访问

    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    list<int>::iterator  lIt = l.begin();
    lIt++;
//    lIt = lIt + 1;     //不支持随机访问
}

int main() {

//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
    return 0;
}
