#include <iostream>
#include <set>
#include <string>
using namespace std;

void printSet(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    //����ʽ���� ����key�������� ��С����
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);

    printSet(s1);

    if (s1.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "size = " << s1.size() << endl;
    }

    s1.erase(s1.begin());

    printSet(s1);

    s1.erase(3);

    printSet(s1);
}

void test02()
{
    set<int> s1;
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);
    //����set���ԣ� û��value�� key����value

    set<int>::iterator pos = s1.find(3);
    //�ж��Ƿ��ҵ�
    if (pos != s1.end())
    {
        cout << "�ҵ��ˣ�ֵΪ" << *pos << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }

    //����set���ԣ�count���0��1
    int num = s1.count(1);
    cout << "1�ĸ���Ϊ" << num << endl;

    set<int>::iterator it = s1.lower_bound(3);
    if (it != s1.end())
    {
        cout << "lower_bound��ֵΪ��" << *it << endl;
    }
    else
    {
        cout << "û�ҵ�" << endl;
    }

    set<int>::iterator it2 = s1.upper_bound(3);
    if (it2 != s1.end())
    {
        cout << "upper_bound��ֵΪ��" << *it2 << endl;
    }
    else
    {
        cout << "û�ҵ�" << endl;
    }

    pair<set<int>::iterator, set<int>::iterator> ret = s1.equal_range(3);
    //�����޾���lower_bound, upper_bound
    //��ȡ��һ��ֵ
    if (ret.first != s1.end())
    {
        cout << "�ҵ�equal_range��lower_bound��ֵ��" << *(ret.first) << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
    //��ȡ�ڶ���ֵ
    if (ret.second != s1.end())
    {
        cout << "�ҵ�equal_range��upper_bound��ֵ��" << *(ret.second) << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

//set���� ����������ظ�������
void test03()
{
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if (ret.second)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "�ڶ��β���ɹ�" << endl;
    }
    else
    {
        cout << "�ڶ��β���ʧ��" << endl;
    }

    printSet(s1);

    multiset<int> mul;
    mul.insert(10);
    mul.insert(10);
}

//set��������

//ָ��set������� �Ӵ�С
//�º���
class myCompare
{
public:
    //���� ()
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test04()
{
    set<int, myCompare> s1;
//    set<int,
    s1.insert(5);
    s1.insert(1);
    s1.insert(9);
    s1.insert(3);
    s1.insert(7);

    //printSet(s1);

    //�Ӵ�С����
    //�ڲ���֮ǰ��ָ���������
    for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//�Զ�����������
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class myComparePerson
{
public:
    bool operator()(const Person &p1, const Person& p2)
    {
        if (p1.m_Age > p2.m_Age)  //����
        {
            return true;
        }
        return false;
    }
};

void test05()
{
    set<Person, myComparePerson> s1;
    Person p1("����", 100);
    Person p2("����", 90);
    Person p3("����", 10);
    Person p4("үү", 1000);
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    //�����Զ����������ͣ�������ָ�����������

    //��ʾ
    for (set<Person, myComparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << endl;
    }



}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return 0;
}
