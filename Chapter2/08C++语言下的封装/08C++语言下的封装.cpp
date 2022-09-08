#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Person
{
    char mName[64];

    int mAge;

    void PersonEat()
    {
        cout << mName << "���˷�"  << endl;
    }
};

struct Dog
{
    char mName[64];

    int mAge;

    void DogEat()
    {
        cout << mName << "�Թ���"  << endl;
    }
};

//C++�еķ�װ �ϸ�����ת����⣬ �����Ժ���Ϊ�󶨵�һ��
//���Ժ���Ϊ��Ϊһ����������ʾ�����е�����
//����Ȩ�� public����Ȩ�� protected����Ȩ�� private˽��Ȩ��

void test01()
{
    Person p1;
    strcpy(p1.mName, "����");
    p1.PersonEat();
    // p1.DogEat();
}

//struct��class��һ����˼��Ψһ��ͬ��Ĭ��Ȩ�ޣ�struct��publi������classĬ��Ȩ����private
class Animal
{
private:
    int mAge;
    //����Ҳ�����Ȩ�ޣ�Ĭ��private
    void eat(){mAge = 100;};

public:
    int mHeight;

protected:
    int mWeight;  //����Ȩ�� ���ڶ����Է��ʣ���ǰ���������Է��ʣ� ���ⲿ�����Է���
    void setWeight(){mWeight = 100;};
};

//��ν˽��Ȩ�� ����˽�г�Ա�����ԡ������� �����ڲ����Է��ʣ����ⲿ�����Է���
//����Ȩ�ޣ� �����ڲ������ⲿ�����Է���

void test02()
{
    Animal an;
    // an.eat();
    // an.mAge;
    an.mHeight = 100;  //����Ȩ�������ⲿ���Է��ʵ�
    // an.mWeight = 100;  //����Ȩ�������ⲻ�ɷ���
}

//public �������ⶼ���Է���
//protected ���ڿ��� ���ⲻ���� ��������ԣ�
//private ���ڿ��� ���ⲻ����  �����಻���ԣ�

int main()
{


    test01();
    return EXIT_SUCCESS;
}