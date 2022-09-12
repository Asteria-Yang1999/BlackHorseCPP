#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Phone
{
public:

    Phone()
    {
        cout << "手机的默认构造函数调用" << endl;
    }

    Phone(string name)
    {
        m_PhoneName = name;
        cout << "手机的有参构造函数调用" << endl;
    }

    ~Phone()
    {
        cout << "手机的析构函数调用" << endl;
    }

    string m_PhoneName;
};

class Game
{
public:
    Game()
    {
        cout << "Game的默认构造函数调用" << endl;
    }

    Game(string name)
    {
        m_GameName = name;
        cout << "Game的有参构造函数调用" << endl;
    }

    ~Game()
    {
        cout << "Game的析构函数调用" << endl;
    }

    string m_GameName;
};



class Person
{
public:

    Person()
    {
        cout << "Person的默认构造函数" << endl;
    }

    Person(string name, string phoneName, string gameName): m_Name(name), m_Phone(phoneName), m_Game(gameName)
    {
//        m_Name = name;
        cout << "Person的有参构造函数调用" << endl;
    }

    void playGame()
    {
        cout << m_Name << "拿着《" << m_Phone.m_PhoneName << "》牌手机，玩着《" << m_Game.m_GameName << "》游戏。" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    string m_Name;    //姓名
    Phone m_Phone;     //手机
    Game m_Game;     //游戏

};

//类对象作为类成员时候， 构造顺序先将类对象一一构造，然后构造自己，析构的顺序是相反的。

void test01()
{
    Person p("狗蛋", "苹果", "切水果");
    p.playGame();
//    p.m_Phone.m_PhoneName = "三星";
//    p.m_Game.m_GameName = "斗地主";
}

int main()
{

    test01();

    system("pause");
    return 0;
}
