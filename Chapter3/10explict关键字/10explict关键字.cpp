#include <iostream>

using namespace std;

class MyString
{
public:

    MyString(const char * str)
    {

    }

    explicit MyString(int a)
    {
        mSize = a;
    }

    char * mStr;
    int mSize;
};

void test01()
{

    MyString str = "abc";
//    MyString str2 = 10; //做什么用途： str2字符串为“10”字符串的长度10
    //隐式类型转换  MyString str2 = MyString(10)
    //explict 防止隐式类型转换
    MyString str3(10);
}

int main()
{

    test01();

    return 0;
}
