#include <iostream>
#include "Shero.h"
#include "Monster.h"
#include "Weapon.h"
#include "Knife.h"
#include "DragonSword.h"
#include <ctime>

using namespace std;

void play()
{
    //创建怪物
    Monster *monster = new Monster;
    //创建英雌
    Shero *shero = new Shero;

    //创建武器
    Weapon *knife = new Knife;
    Weapon *dragon = new DragonSword;

    //让用户选择一下武器
    cout << "请选择武器：" << endl;
    cout << "1、赤手空拳" << endl;
    cout << "2、小刀" << endl;
    cout << "3、屠龙刀" << endl;

    int oper;
    cin >> oper;
    switch (oper)
    {
        case 1:
            cout << "你真年轻，超勇的！" << endl;
            break;
        case 2:
            shero->EquipWeapon(knife);
            break;
        case 3:
            shero->EquipWeapon(dragon);
            break;
    }

    getchar();    //输入缓冲区里有个回车，多获取一次值

    int round = 1;

    while(true)
    {
        getchar();
        system("cls");

        cout << "=====当前第" << round << "回合开始=====" << endl;

        if (shero->m_Hp <= 0)
        {
            cout << "英雄" << shero->m_Name << "已挂，游戏结束" << endl;
            break;
        }
        shero->Attack(monster);
        if (monster->m_Hp <= 0)
        {
            cout << "怪物" << monster->m_Name << "已挂，顺利通关" << endl;
            break;
        }
        monster->Attack(shero);
        if (shero->m_Hp <= 0)
        {
            cout << "英雄" << shero->m_Name << "已挂，游戏结束" << endl;
            break;
        }
        cout << "英雄" << shero->m_Name << "剩余血量:" << shero->m_Hp << endl;
        cout << "怪物" << monster->m_Name << "剩余血量:" << monster->m_Hp << endl;
        round++;
    }

    delete monster;
    delete shero;
    delete knife;
    delete dragon;

}

int main() {
    srand((unsigned int) time(NULL));
    play();
    system("pause");
    return 0;
}
