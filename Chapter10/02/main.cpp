#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
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

void test02()
{
    string s = "hello world";
    for (int i = 0; i < s.size(); i++)
    {
//        cout << s[i] << endl;
        cout << s.at(i) << endl;
    }
    // []和at区别？ []访问越界 直接挂掉  at会抛出异常
    try
    {
//        cout << s[100] << endl;
        cout << s.at(100) << endl;
    }
    catch (out_of_range & e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "越界异常" << endl;
    }
}

void test03()
{
    //拼接
    string s1 = "Asteria";
    string s2 = " loves freedom";
    s1 += s2;
    cout << s1 << endl;
    s1.append(" so much");

    cout << s1 << endl;

    //find查找

    string s = "abcdefg";
    int pos = s.find("bcf");    //找不到返回的是-1

    cout << "pos = " << pos << endl;

    int pos2 = s.rfind("bc");    //rfind和find结果一样，查找方式不一样
    cout << "pos2 = " << pos2 << endl;

    //替换
    string s3 = "hello";    //替换从pos开始n个字符为字符串str，n和str.size()可以不相等
    s3.replace(1, 3, "111");
    cout << s3 << endl;    //hello->>>>>>h111o
}

void test04()
{
    string s1 = "abc";
    string s2 = "bbc";
    if (s1.compare(s2) == 0)
    {
        cout << "s1 equals to s2" << endl;
    }
    else if (s1.compare(s2) == 1)
    {
        cout << "s1 is bigger than s2" << endl;
    }
    else
    {
        cout << "s1 is less than s2" << endl;
    }
}

void test05()
{
    string s1 = "abcde";
    string s2 = s1.substr(1, 3);
    cout << "s2 = " << s2 << endl;

    //需求： 查找一个邮件的用户名
    string email = "yangsiyi@sina.com";

    int pos = email.find("@");
    cout << "pos = " << pos << endl;

    string usrName = email.substr(0, pos);
    cout << "User Name Is " << usrName << endl;
}

void test06()
{
    string s1 = "hello";
    s1.insert(1, "111");
    cout << s1 << endl;    //h111ello

    //删除 111
    s1.erase(1, 3);
    cout << s1 << endl;
}

//string和c-style字符串转换
void func(string s)
{
    cout << s << endl;
}

void func2(char * s)
{
    cout << s << endl;
}

void test07()
{
    string s = "abc";
    //string -> const char *
    const char* p = s.c_str();

    func(p);   //const char *隐式类型转换为 string

    //const char * -> string
    string s2(p);

//    func2(s2);      //string不能隐式类型转换为char *
}

void test08()
{
    string s = "abcdefg";
    char& a = s[2];
    char& b = s[3];

    a = '1';
    b = '2';

    cout << s << endl;
    cout << (int*)s.c_str() << endl;

    s = "ppppppppppppppppppppppppp";

//    a = '1';
//    b = '2';

    cout << s << endl;
    cout << (int*)s.c_str() << endl;
    //重新分配内存之后，原有的引用失效
}

void test09()
{
    string s = "abCdEfg";

    for (int i = 0; i < s.size(); i++)
    {
//        s[i] = toupper(s[i]);
        s[i] = tolower(s[i]);
    }

    cout << s << endl;
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
    test09();
    return 0;
}
