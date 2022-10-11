#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Shero.h"

using namespace std;

class Shero;

class Monster
{
public:
    Monster();

    string m_Name;

    int m_Hp;

    int m_Atk;

    int m_Def;

    bool m_Hold;

    void Attack(Shero * shero);
};