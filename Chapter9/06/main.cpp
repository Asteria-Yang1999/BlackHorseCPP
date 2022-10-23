#include <iostream>
#include <string>
using namespace std;

class MyOutOfRangeException:public exception
{
public:
    MyOutOfRangeException(string errorInfo)
    {
        this->m_errorInfo = errorInfo;
    }

    virtual ~MyOutOfRangeException()
    {

    }
    virtual const char *what() 
    {
        // ���ش�����Ϣ
        //string ת char*    .c_str()
        return this->m_errorInfo.c_str();
    }

    string m_errorInfo;
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		//���������

		if (age < 0 || age > 200)
		{
            throw MyOutOfRangeException(string("���Լ�������Խ���쳣"));
		}

		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	try
	{
		Person p("С��", 300);
	}
	catch (MyOutOfRangeException & e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	test01();
	return 0;
}
