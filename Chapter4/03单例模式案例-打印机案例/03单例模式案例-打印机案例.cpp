#include <iostream>
#include <string>

using namespace std;

class Printer
{
private:
    Printer(){ m_Count = 0; };
    Printer(const Printer & p);

private:
    static Printer * singlePrinter;
    int m_Count;

public:
    static Printer * getInstance()
    {
        return singlePrinter;
    }

    void printText(string text)
    {
        cout << text << endl;
        m_Count++;
        cout << "打印机已使用次数为" << m_Count << endl;
    }
};

Printer *Printer::singlePrinter = new Printer;

void test01()
{
    //拿到打印机
    Printer * printer = Printer::getInstance();
    printer->printText("离职报告");
    printer->printText("入职报告");
    printer->printText("加薪报告");
    printer->printText("升级报告");
    printer->printText("退休申请");
}

int main()
{
    test01();
    return 0;
}
