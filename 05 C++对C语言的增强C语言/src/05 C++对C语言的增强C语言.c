/*
 ============================================================================
 Name        : 05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//1.全局变量检测增强
int a;
int a = 10;

//2.函数检测增强
int getRectS(w, h)
{

}
void test02()
{
	getRectS(10, 10, 10);
}

//3.类型转换检测增强
void test03()
{
	char * p = malloc(sizeof(04)); //malloc返回值是void*
}


//4.struct增强
struct Person
{
	int m_Age;
//	void plusAge();  //c语言中struct不可以加函数
};

void test04()
{
	struct Person p1;  //c语言中使用时必须加入struct关键字
}

//5.bool类型增强 C语言中没有bool类型
//bool flag;

//6.三目运算符增强
void test06()
{
	int a = 10;
	int b = 20;

	printf("ret = %d \n", a > b ? a : b);

//	a > b ? a : b = 100;  //20 = 100 C语言返回的是值

	//C语言中想模仿C++写
	*(a > b ? &a : &b) = 100;
	printf("a = %d, b = %d \n", a, b);
}
//7.const增强
const int m_A = 10; //全局区域受到保护，不可以修改
void test07()
{
//	m_A = 100;
	const int m_B = 20; //伪常量
//	m_B = 100;

	int * p = (int *)&m_B;
	*p = 200;
	printf("*p = %d, m_B = %d \n", *p, m_B);

	//int arr[20]; 不可以用const初始化数组
}

//C语言中，const修饰的变量，是伪变量，编译器是会分配内存的。只要分配内存的变量都可以修改
//C++中，const不会分配内存 const int m_B = 20，用类似哈希表的结构存储。
//编译器会临时开辟一块内存空间
/*
 * int tmp = m_B; //tmp有内存
 * int *p = (int *) &tmp; //*p指向的是临时那块空间，临时空间看不到，改的东西并不是m_B，而是临时空间
*/
int main(void) {
//	test06();
	test07();

	return EXIT_SUCCESS;
}
