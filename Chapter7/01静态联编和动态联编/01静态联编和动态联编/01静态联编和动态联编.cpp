#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

	virtual void eat()
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()    //��д�ɲ�дvirtual
	{
		cout << "Сè��˵��" << endl;
	}

	virtual void eat()
	{
		cout << "Сè�ڳ���" << endl;
	}
};

//����doSpeak speak�����ĵ�ַ��Ͱ󶨺��ˣ���󶨣���̬���࣬����׶ξ�ȷ�����˵�ַ
//��������cat��speak���Ͳ�����ǰ�󶨺ú����ĵ�ַ��������Ҫ������ʱ����ȥȷ�������ĵ�ַ
//��̬���࣬д����DoSpeak������Ϊ�麯������ĸ�������麯���������˶�̬
//ĸ������û���ָ�� ָ�� �������
void doSpeak(Animal & animal)   //Animal & animal = cat
{
	animal.speak();
}

//��������˼̳еĹ�ϵ�������������������ת��
void test01()
{
	Cat cat;
	doSpeak(cat);
}

void test02()
{
	//    cout << sizeof(Animal) << endl;
	//ĸ��ָ��ָ��������� ��̬
	Animal * animal = new Cat; 

	//    animal->speak();

	//*(int *)*(int *)animal ������ַ
	((void(*)()) (*(int*)*(int*)animal))();

	((void(*)()) (*((int *)*(int *)animal + 1)))();
}


int main()
{
	//    test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}