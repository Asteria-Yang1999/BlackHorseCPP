#include <iostream>
using namespace std;

class MyException
{
public:
	MyException()
	{
		cout << "MyException的默认构造" << endl;
	}
	
	MyException(const MyException & e)
	{
		cout << "MyException的拷贝构造" << endl;
	}
	
	~MyException()
	{
		cout << "MyException的析构函数" << endl;
	}
	
	void printError()
	{
		this->m_A = 100;
		cout << "error" << m_A << endl;
	}
	
	int m_A;
};

void doWork()
{
	throw &MyException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch(MyException *e)     //MyException e, 会多开销一份数据，推荐使用引用
	{
		e->printError();    // 指向非法内存空间，不应该这么做
		cout << "捕获异常" << endl;
	}
}

int main()
{
	test01();
	return 0;
}