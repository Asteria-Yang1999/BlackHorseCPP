#include <iostream>
using namespace std;

void func() throw(int)    //throw(int)只能抛出int类型异常
{
	throw 1;
}

int main()
{

	try
	{
		func();
	}
	catch(int)
	{
		cout << "int类型异常捕获" << endl;
	}
	catch(...)
	{
		cout << "其他类型异常捕获" << endl;
	}

	return 0;
}