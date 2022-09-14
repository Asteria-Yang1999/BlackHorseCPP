#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        cout << "默认构造调用" << endl;
    }

    Person(int a)
    {
        cout << "有参构造调用" <<endl;
    }

    ~Person()
    {
        cout << "析构函数调用" << endl;
    }

};

void test01()
{
//    Person p1;    //栈区开辟
    Person * p2 = new Person;     //堆区开辟

    //所有new出来的对象都会返回该类型的指针
    //malloc 返回void* 还要强制转换
    //malloc会调用构造吗？ 不会   new会调用构造
    //new运算符  malloc函数
    //释放堆区的空间
    //delete也是运算符 配合new用 malloc配合free用
    delete p2;
}

void test02()
{
    void *p = new Person;
    //当用void*接受new出来的指针，会出现释放的问题
    delete p;
    //无法释放p，所以要避免这种写法

}

void test03()
{
    //通过new来开辟数组
    //一定会调用默认构造函数，所以一定要提供默认构造函数
    Person * pArray = new Person[10];
//    Person pArray2[2] = {Person(1), Person(2)};    //在栈上开辟数组，可以指定有参构造

    //释放数组 delete []
    delete [] pArray;
}

int main()
{

//    test01();
//    test02();
    test03();
    return 0;
}
