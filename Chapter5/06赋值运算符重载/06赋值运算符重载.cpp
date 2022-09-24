#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//һ����Ĭ�ϴ��� Ĭ�Ϲ��졢�������������졢operator=��ֵ����������м򵥵�ֵ���ݣ�
class Person
{
public:
    Person(int a)
    {
        this->m_A = a;
    }

    int m_A;
};

void test01()
{
    Person p1(10);

    Person p2(0);

    p2 = p1;    //��ֵ

    cout << "p2��m_A: " << p1.m_A << endl;
}

class Person2
{
public:
    Person2(char * name)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
    }

//  ���� = ��ֵ�����
    Person2& operator=(const Person2 & p)
    {
        //�ж����ԭ���Ѿ����������ݣ����ͷ�
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }

        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);

        return *this;
    }

    ~Person2()
    {
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }

    char * pName;
};

void test02()
{
    Person2 p1("С��");

    Person2 p2("С��");

    Person2 p3("");
    p3 = p2 = p1;

    p2 = p1;

    cout << p2.pName << endl;
    cout << p3.pName << endl;

    int a = 10;
    int b = 20;
    int c;
    c = a = b;
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}