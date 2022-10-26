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

    string m_Name;    //����
    int m_Score;    //����    ƽ����
};

void createPerson(vector<Person>& v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "ѡ��";
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
        //��5���˽��д��
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;    //60 ~ 100
            d.push_back(score);
        }

        //�ȿ��´��
//        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
//        {
//            cout << (*dit) << " ";
//        }
//        cout << endl;

        //����
        sort(d.begin(), d.end());

        //ȥ����ߺ����
        d.pop_back();    //ȥ�����
        d.pop_front();    //ȥ�����

        int sum = 0;    //�ܷ�
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += (*dit);
        }

        //ƽ����
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}

void showScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "������" << (*it).m_Name << " ����ƽ����Ϊ�� " << it->m_Score << endl;
    }
}

int main() {
    //�������������
    srand((unsigned int) time (NULL));

    //�������� ���ѡ��
    vector<Person> v;

    //����5��ѡ��
    createPerson(v);

    //���
    setScore(v);

    //չʾƽ����
    showScore(v);

//    //����
//    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << "����: " << (*it).m_Name << endl;
//    }
    return 0;
}
