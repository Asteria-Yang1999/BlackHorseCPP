#include <iostream>

using namespace std;

//class Calculator
//{
//public:
//    void setv1(int v)
//    {
//        this->val1 = v;
//    }
//    void setv2(int v)
//    {
//        this->val2 = v;
//    }
//
//    int getResult(string oper)
//    {
//        if (oper == "+")
//        {
//            return val1 + val2;
//        }
//        else if (oper == "-")
//        {
//            return val1 - val2;
//        }
//    }
//
//private:
//    int val1;
//    int val2;
//};
//
//void test01()
//{
//    Calculator cal;
//    cal.setv1(10);
//    cal.setv2(10);
//    cout << cal.getResult("+") << endl;
//    cout << cal.getResult("-") << endl;
//}

//真正的开发中，有个开发原则：开闭原则
//对扩展开放，对修改关闭

//利用多态实现计算器
class abstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    void setv1(int v)
    {
        this->val1 = v;
    }
    void setv2(int v)
    {
        this->val2 = v;
    }

public:
    int val1;
    int val2;
};

//加法计算器
class  PlusCalculator :public abstractCalculator
{
public:
    virtual int getResult()
    {
        return val1 + val2;
    }
};

class SubCalculator :public abstractCalculator
{
public:
    virtual int getResult()
    {
        return val1 - val2;
    }
};

class TimesCalculator :public abstractCalculator
{
public:
    virtual int getResult()
    {
        return val1 * val2;
    }
};

void test01()
{
    abstractCalculator * abc;    //加法计算器
    abc = new PlusCalculator;

    abc->setv1(20);
    abc->setv2(10);

    cout << abc->getResult() << endl;

    delete abc;

    abc = new SubCalculator;
    abc->setv1(10);
    abc->setv2(20);
    cout << abc->getResult() << endl;

    delete abc;

    abc = new TimesCalculator;
    abc->setv1(10);
    abc->setv2(20);
    cout << abc->getResult() << endl;
}

int main()
{
    test01();
	system("pause");
    return 0;
}
