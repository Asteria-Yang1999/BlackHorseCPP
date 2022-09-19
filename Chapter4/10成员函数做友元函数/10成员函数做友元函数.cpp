#include <iostream>
#include <string>
using namespace std;

//只让visit可以做Building的好朋友  visit2不可以访问私有属性
class Building;
class goodGirl
{
public:
    goodGirl();

    void visit();
    void visit2();
private:
    Building * building;
};

class Building
{
    //让成员函数 visit 作为友元函数
    friend void goodGirl::visit();

public:
    Building();
public:
    string m_SittingRoom;   //客厅
private:
    string m_Bedroom;    //卧室
};

goodGirl::goodGirl()
{
    building = new Building;
}

void goodGirl::visit()
{
    cout << "好闺蜜正在访问  " << this->building->m_SittingRoom << endl;
    cout << "好闺蜜正在访问  " << this->building->m_Bedroom << endl;
}

void goodGirl::visit2()
{
    cout << "好闺蜜正在访问  " << this->building->m_SittingRoom << endl;
//    cout << "好闺蜜正在访问  " << this->building->m_Bedroom << endl;
}

Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_Bedroom = "卧室";
}

void test01()
{
    goodGirl gg;
    gg.visit();
//    gg.visit2();
}

int main()
{
    test01();
}
