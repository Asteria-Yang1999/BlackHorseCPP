#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
public:
    Student()
    {

    }
    Student(string name, double score[])
    {
        this->m_Name = name;
        for (int i = 0; i < 10; i++)
        {
            this->m_Score[i] = score[i];
        }
    }

    string m_Name;
    double m_Score[10];

};

void test01()
{
    double score[10] = {92.5, 65.3, 54.6, 54.6, 98.5, 96.5, 75.6, 65.8, 68.3, 94.1};
    Student st1 = Student("01", score);
//    cout << *(st1.m_Score) << endl;
    deque<double> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(st1.m_Score[i]);
    }
    sort(d.begin(), d.end());
    d.pop_front();
    d.pop_back();
    double sum = 0;
    for (deque<double>::iterator it = d.begin(); it != d.end(); it++)
    {
        sum += (*it);
    }
    cout << sum/d.size() << endl;
}


int main() {
    test01();
    return 0;
}
