#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
    char mName[64];

    int mAge;

};

void PersonEat(struct Person *p)
{
    printf("%s �ڳ��˷� \n", p->mName);
}

void test01()
{
    struct Person p1;
    strcpy(p1.mName, "����");

    PersonEat(&p1);
}

struct Dog
{
    char mName[64];

    int mAge;
};

void DogEat(struct Dog * dog)
{
    printf("%s �ڳԹ��� \n", dog->mName);
}

void test02()
{
    struct Dog dog1;
    strcpy(dog1.mName, "����");

    DogEat(&dog1);

    struct Person p1;
    strcpy(p1.mName, "С��");
    DogEat(&p1);
}

//C���Է�װ����Ϊ�����Էֿ����������ͼ�ⲻ����

int main()
{

    // test01();
    test02();


    system("pause");
    return EXIT_SUCCESS;
}