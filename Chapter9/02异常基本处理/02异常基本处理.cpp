#include <iostream>
using namespace std;

class myException    //自定义异常类
{
public:
	void printError()
	{
		cout << "自定义的异常" << endl;
	}
	
};

class Person
{
public:
	Person()
	{
		cout << "Person构造" << endl;
	}
	~Person()
	{
		cout << "Person析构" << endl;
	}
};

int myDivide(int a, int b)
{
	if (b == 0)
	{
		//如果b是异常 则抛出异常
		//return -1;
		
		//throw -1;  //抛出int类型异常
		//throw 3.14;    //抛出double类型异常 异常必须处理，如果不处理就挂掉了
		//throw 'a';
		
		//栈解旋
		//从try开始，到throw抛出异常之前，所有栈上的对象，都会被释放 这个过程称为栈解旋
		//构造和析构顺序相反
		
		Person p1;
		Person p2;
		
		throw myException();    //匿名对象 
	}
	return a / b;
}

void test01()
{
	int a = 10;
	int b = 0;
	
	//int ret = myDivide(a, b);    //早期如果返回-1  无法区分到底是结果还是异常
	
	//c++中异常处理
	try   //试一试
	{
		myDivide(a, b);
	}
	catch(int)  //捕获异常
	{
		cout << "int类型异常捕获" << endl;
	}
	catch(double)  //捕获异常
	{
		//如果不想处理这个异常，可以继续向上抛出
		throw;
		cout << "double类型异常捕获" << endl;
	}
	catch(myException e)
	{
		e.printError();
	}
	catch(...)
	{
		cout << "其它类型异常捕获" << endl;
	}
}

int main()
{
	try
	{
		test01();
	}
	catch(char)    //如果异常都没有处理，那么调用terminate函数，是程序中断
	{
		cout << "main 函数中的 double类型异常捕获" << endl;
	}
	catch(...)
	{
		cout << "main 函数中的其它类型异常捕获" << endl;
	}
	
	system("pause");
	return EXIT_SUCCESS;
}