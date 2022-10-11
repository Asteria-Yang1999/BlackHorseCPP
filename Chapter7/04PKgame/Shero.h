#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Monster.h"

class Monster;

using namespace std;

class Shero
{
public:
    Shero();

    string m_Name;    //����

    int m_Atk;    //������

    int m_Def;    //������

    int m_Hp;    //Ѫ��

    Weapon * weapon;    //����

    void EquipWeapon(Weapon * weapon);

    void Attack(Monster * monster);
};