#include <iostream>
using namespace std;

void func() throw(int)    //throw(int)ֻ���׳�int�����쳣
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
		cout << "int�����쳣����" << endl;
	}
	catch(...)
	{
		cout << "���������쳣����" << endl;
	}

	return 0;
}