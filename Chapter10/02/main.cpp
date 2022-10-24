#include <iostream>
#include <string>
using namespace std;

void test01()
{
    string str = "helloworld";    //默认构造
    string str2(str);    //拷贝构造
    string str3 = str;

    string str4 = "abcd";
    string str5(10, 'a');

    cout << str4 << endl;
    cout << str5 << endl;

    //基本赋值
    str = "hello";
    str2 = str4;

    str3.assign("abcdef", 4);
    cout << str3 << endl;

    string str6;
    str6.assign(str, 1, 3);
    cout << str6 << endl;
}




int main() {
    test01();
    return 0;
}
