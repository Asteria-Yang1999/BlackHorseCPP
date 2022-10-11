#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "������˵��" << endl;
    }

    //��ͨ�������ǲ����������������ģ����Կ��ܻᵼ���ͷŲ��ɾ�
    //����������������������
    //������������Ӱ��ʵ����
//    virtual ~Animal()
//    {
//        cout << "Animal��������������" << endl;
//    }

    //�������� д������
    //����������Ҫ���� ����Ҫʵ�� �������� ����ʵ��
    virtual ~Animal() = 0;
    //��������г����˴���������������ô�����Ҳ�������
    //�����಻��ʵ��������
};
Animal::~Animal()
{
    //������������ʵ��
    cout << "Animal�Ĵ��������ĵ���" << endl;
}

//��������˴�������������Ҳ������࣬����ʵ����
//void func()
//{
//    Animal * animal = new Animal;
//    Animal an;
//}

class Cat:public Animal
{
public:
    Cat(const char * name)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    virtual void speak()
    {
        cout << "Сè��˵��" << endl;
    }

    ~Cat()
    {
        cout << "Cat��������������" << endl;
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char * m_Name;
};

void test01()
{
    Animal * animal = new Cat("TOM");
    animal->speak();
    delete animal;
}

int main() {
    test01();
    return 0;
}
