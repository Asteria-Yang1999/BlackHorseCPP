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

    string m_Name;    //人名

    int m_Atk;    //攻击力

    int m_Def;    //防御力

    int m_Hp;    //血量

    Weapon * weapon;    //武器

    void EquipWeapon(Weapon * weapon);

    void Attack(Monster * monster);
};