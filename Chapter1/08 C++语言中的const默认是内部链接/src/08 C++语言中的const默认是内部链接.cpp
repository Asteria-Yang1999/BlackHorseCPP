/*
 * 08 C++语言中的const默认是内部链接.cpp
 *
 *  Created on: 2022年8月29日
 *      Author: 22526
 */

#include <iostream>
using namespace std;

int main() {
	extern const int a; //告诉编译器a在外部
	cout << a << endl;
	return 0;
}



