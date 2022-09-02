//============================================================================
// Name        : 06.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//1.全局变量检测增强
//int a;
int a = 10;

//2.函数检测增强, 参数类型增强, 返回值检测增强, 函数调用参数检测增强
int getRectS(int w, int h)
{
	return w*h;
}

void test02()
{
	getRectS(10, 10);
}

//3.类型转换检测增强
void test03()
{
	char * p = (char*)malloc(sizeof(04)); //malloc返回值是void*
}

//4.struct增强
struct Person
{
	int m_Age;
	void plusAge(){ m_Age++; };  //c++语言中struct可以加函数
};
void test04()
{
	Person p1;  //c++中使用时可以不加入struct关键字
	p1.m_Age = 10;
	p1.plusAge();
	cout << p1.m_Age << endl;
}

//5.bool类型增强 C语言中没有bool类型
bool flag;  //只有真(true\非0)或假(false\0)
void test05()
{
	cout << sizeof(bool) << endl;
	flag = 100;
	//bool类型非0的值转换为1，0值转换为0
	cout << flag << endl;
}

//6.三目运算符增强
void test06()
{
	int a = 10;
	int b = 20;
	cout << "ret = " << (a > b ? a : b) << endl;
//	printf("ret = %d \n", a > b ? a : b);
	(a > b ? a : b) = 100; //b = 100 C++返回的是变量
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

const int m_A = 10; //全局区域受到保护，不可以修改
void test07()
{
//	m_A = 100;
	const int m_B = 20; //真正的常量
//	m_B = 100;

	int * p = (int *)&m_B;
	*p = 200;
	cout << "*p = " << *p << endl;
	cout << "m_B = " << m_B << endl;


	int arr[m_B]; //不可以用const初始化数组
}

//C语言中，const修饰的变量，是伪变量，编译器是会分配内存的。只要分配内存的变量都可以修改
//C++中，const不会分配内存 const int m_B = 20，用类似哈希表的结构存储。
//编译器会临时开辟一块内存空间
/*
 * int tmp = m_B; //tmp有内存
 * int *p = (int *) &tmp; //*p指向的是临时那块空间，临时空间看不到，改的东西并不是m_B，而是临时空间
*/

int main() {

//	test04();
//	test05();
//	test06();
	test07();
	return 0;
}
