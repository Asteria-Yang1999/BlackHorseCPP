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
        // 返回错误信息
        //string 转 char*    .c_str()
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
		//年龄做检测

		if (age < 0 || age > 200)
		{
            throw MyOutOfRangeException(string("我自己的年龄越界异常"));
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
		Person p("小红", 300);
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
