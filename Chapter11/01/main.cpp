#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;    //人名
    int m_Score;    //分数    平均分
};

void createPerson(vector<Person>& v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //对5个人进行打分
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;    //60 ~ 100
            d.push_back(score);
        }

        //先看下打分
//        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//        {
//            cout << (*dit) << " ";
//        }
//        cout << endl;

        //排序
        sort(d.begin(), d.end());

        //去除最高和最低
        d.pop_back();    //去除最高
        d.pop_front();    //去除最低

        int sum = 0;    //总分
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += (*dit);
        }

        //平均分
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}

void showScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << " 最终平均分为： " << it->m_Score << endl;
    }
}

int main() {
    //设置随机数种子
    srand((unsigned int) time (NULL));

    //创建容器 存放选手
    vector<Person> v;

    //创建5名选手
    createPerson(v);

    //打分
    setScore(v);

    //展示平均分
    showScore(v);

//    //测试
//    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << "姓名: " << (*it).m_Name << endl;
//    }
    return 0;
}
