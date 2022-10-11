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
    //��������
    Monster *monster = new Monster;
    //����Ӣ��
    Shero *shero = new Shero;

    //��������
    Weapon *knife = new Knife;
    Weapon *dragon = new DragonSword;

    //���û�ѡ��һ������
    cout << "��ѡ��������" << endl;
    cout << "1�����ֿ�ȭ" << endl;
    cout << "2��С��" << endl;
    cout << "3��������" << endl;

    int oper;
    cin >> oper;
    switch (oper)
    {
        case 1:
            cout << "�������ᣬ���µģ�" << endl;
            break;
        case 2:
            shero->EquipWeapon(knife);
            break;
        case 3:
            shero->EquipWeapon(dragon);
            break;
    }

    getchar();    //���뻺�������и��س������ȡһ��ֵ

    int round = 1;

    while(true)
    {
        getchar();
        system("cls");

        cout << "=====��ǰ��" << round << "�غϿ�ʼ=====" << endl;

        if (shero->m_Hp <= 0)
        {
            cout << "Ӣ��" << shero->m_Name << "�ѹң���Ϸ����" << endl;
            break;
        }
        shero->Attack(monster);
        if (monster->m_Hp <= 0)
        {
            cout << "����" << monster->m_Name << "�ѹң�˳��ͨ��" << endl;
            break;
        }
        monster->Attack(shero);
        if (shero->m_Hp <= 0)
        {
            cout << "Ӣ��" << shero->m_Name << "�ѹң���Ϸ����" << endl;
            break;
        }
        cout << "Ӣ��" << shero->m_Name << "ʣ��Ѫ��:" << shero->m_Hp << endl;
        cout << "����" << monster->m_Name << "ʣ��Ѫ��:" << monster->m_Hp << endl;
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
