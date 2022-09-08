#include <iostream>
#include <string>
using namespace std;

/*
2. 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
*/

class Student
{
public://公共权限


    //设置姓名
    void setName(string name)
    {
        m_Name = name;
    }

    //设置学号
    void setId(int id)
    {
        m_Id = id;
    }

    //打印信息
    void showInfo()
    {
        cout << "姓名：" << m_Name << " 学号：" << m_Id << endl;
    }
    string m_Name; //姓名
    int m_Id; //学号

};

void test01()
{
    //创建一个学生  实例化 通过类来创建对象的过程
    Student st;
    st.setName("张三");
    st.setId(1);

    //通过st的属性打印了 st信息
    cout << "st的姓名为：" << st.m_Name << " st的学号：" << st.m_Id << endl;

    //通过成员函数来打印st的信息
    st.showInfo();
}

int main() 
{
    test01();
    return 0;
}

//类是对象的抽象，对象是类的实例化。