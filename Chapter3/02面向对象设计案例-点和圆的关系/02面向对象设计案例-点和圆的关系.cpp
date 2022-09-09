#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

//设计一个圆形类，和一个点类，计算点和圆的关系，
//假如圆心坐标为x0，y0，半径为r，点的坐标为x1，y1


//利用全局函数来判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
    //获取圆心和点的距离 的平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int rDistance = c.getR() * c.getR();

    if (rDistance == distance)
    {
        cout << "点在圆上" << endl;
    }
    else if (rDistance > distance)
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
}

void test01()
{
    Point p1;
    p1.setX(10);
    p1.setY(9);

    Circle c1;
    Point center;
    center.setX(10);
    center.setY(0);
    c1.setCenter(center);
    c1.setR(10);

    //利用全局函数判断点和圆的关系
    isInCircle(c1, p1);

    //利用成员函数来判断点和圆的关系
    c1.isInCircleByClass(p1);
}

int main()
{
    test01();
    return 0;
}
