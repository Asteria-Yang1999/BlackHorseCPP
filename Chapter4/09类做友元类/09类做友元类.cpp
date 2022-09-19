#include <iostream>
#include <string>

using namespace std;

class Building;
class goodGirl
{
public:
    goodGirl();

    void visit();
private:
    Building * building;
};

class Building
{
    //让好闺蜜类 作为 Building 的好朋友
    friend class goodGirl;
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

Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_Bedroom = "卧室";
}

int main()
{

    return 0;
}
