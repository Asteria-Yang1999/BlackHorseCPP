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
    printf("%s 在吃人饭 \n", p->mName);
}

void test01()
{
    struct Person p1;
    strcpy(p1.mName, "刀妹");

    PersonEat(&p1);
}

struct Dog
{
    char mName[64];

    int mAge;
};

void DogEat(struct Dog * dog)
{
    printf("%s 在吃狗粮 \n", dog->mName);
}

void test02()
{
    struct Dog dog1;
    strcpy(dog1.mName, "旺财");

    DogEat(&dog1);

    struct Person p1;
    strcpy(p1.mName, "小王");
    DogEat(&p1);
}

//C语言封装，行为和属性分开处理，，类型检测不够。

int main()
{

    // test01();
    test02();


    system("pause");
    return EXIT_SUCCESS;
}