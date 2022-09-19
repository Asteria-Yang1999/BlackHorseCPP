#include <iostream>
#include <string>

using namespace std;

class Building
{
    //让全局的好闺蜜函数 变为我的好朋友：友元函数
    friend void goodGirl(Building * building);
public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_Bedroom = "卧室";
    }

    //客厅   卧室
public:
    string m_SittingRoom;    //客厅

private:
    string m_Bedroom;     //卧室
};

//全局函数   好闺蜜
void goodGirl(Building * building)
{
    cout << "好闺蜜正在访问  " << building->m_SittingRoom << endl;
    cout << "好闺蜜正在访问  " << building->m_Bedroom << endl;
}


//友元函数 目的： 访问类中的私有成员属性
void test01()
{
    Building * building = new Building;
    goodGirl(building);
}

int main()
{
    test01();
    return 0;
}
