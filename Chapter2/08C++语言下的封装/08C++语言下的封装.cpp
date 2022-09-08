#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Person
{
    char mName[64];

    int mAge;

    void PersonEat()
    {
        cout << mName << "吃人饭"  << endl;
    }
};

struct Dog
{
    char mName[64];

    int mAge;

    void DogEat()
    {
        cout << mName << "吃狗粮"  << endl;
    }
};

//C++中的封装 严格类型转换检测， 让属性和行为绑定到一起
//属性和行为作为一个整体来表示生活中的事物
//控制权限 public公有权限 protected保护权限 private私有权限

void test01()
{
    Person p1;
    strcpy(p1.mName, "老王");
    p1.PersonEat();
    // p1.DogEat();
}

//struct和class是一个意思，唯一不同是默认权限，struct是publi，但是class默认权限是private
class Animal
{
private:
    int mAge;
    //如果我不声明权限，默认private
    void eat(){mAge = 100;};

public:
    int mHeight;

protected:
    int mWeight;  //保护权限 类内都可以访问，当前类的子类可以访问， 类外部不可以访问
    void setWeight(){mWeight = 100;};
};

//所谓私有权限 就是私有成员（属性、函数） 在类内部可以访问，类外部不可以访问
//公共权限， 在类内部和类外部都可以访问

void test02()
{
    Animal an;
    // an.eat();
    // an.mAge;
    an.mHeight = 100;  //公有权限在类外部可以访问到
    // an.mWeight = 100;  //保护权限在类外不可访问
}

//public 类内类外都可以访问
//protected 类内可以 类外不可以 （子类可以）
//private 类内可以 类外不可以  （子类不可以）

int main()
{


    test01();
    return EXIT_SUCCESS;
}