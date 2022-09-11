#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:

    Person()
    {

    }
    //初始化属性
    Person(char * name, int age)
    {
        m_Name = (char *)malloc(strlen(name) + 1);
        strcpy(m_Name, name);

        m_age = age;
    }
    //拷贝构造  系统会提供默认拷贝构造，而且是简单的值拷贝
    //自己提供拷贝构造，原因：简单的浅拷贝会释放堆区空间两次，导致挂掉
    //深拷贝
    Person(const Person &p)
    {
        m_age = p.m_age;
        m_Name = (char *)malloc(strlen(p.m_Name) + 1);
        strcpy(m_Name, p.m_Name);
    }

    ~Person()
    {
        cout << "析构函数调用" << endl;
        if (m_Name != NULL)
        {
            free(m_Name);
            m_Name = NULL;
        }
    }



    //姓名
    char * m_Name;
    //年龄
    int m_age;
};

void test01()
{
    Person p1("敌方法师", 10);
    Person p2(p1);  //调用拷贝构造
}

int main()
{


    test01();

    system("pause");
    return 0;
}



//如果属性里有指向堆区空间的数据，那么简单的浅拷贝会导致重复释放内存的异常
//这种情况需要自己提供拷贝构造函数
