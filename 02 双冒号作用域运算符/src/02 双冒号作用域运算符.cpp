#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //标准输入输出流
using namespace std; //使用命名空间std打开一个叫std的房间

////函数入口地址
//int main()
//{
//	// cout 标准的输出
//	// << 左移运算符
//	// endl 结束换行
//	cout << "Hello World!" << endl;
//	char* a = "a";
//
////	system("pause"); //阻塞功能
//	return EXIT_SUCCESS; //返回正常退出
//}

int atk = 200;
void test01()
{
	int atk = 100;
	cout << "攻击力为：" << atk << endl;
	//双冒号 作用域运算符 ::全局作用域
	cout << "全局攻击力为：" << ::atk << endl;
}

int main()
{
	test01();
	return EXIT_SUCCESS;
}
