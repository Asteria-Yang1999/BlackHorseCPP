#include "Monster.h"

Monster::Monster()
{
    this->m_Hp = 300;

    this->m_Atk = 70;

    this->m_Def = 40;

    this->m_Hold = false;

    this->m_Name = "��ħ��";
}

void Monster::Attack(Shero *shero)
{
    if (this->m_Hold)
    {
        cout << "����" << this->m_Name << "����ס�ˣ����غ��޷�����" << endl;
        return;
    }

    //���㹥���˺�
    int damage = (this->m_Atk - shero->m_Def) > 0 ? this->m_Atk - shero->m_Def : 1;

    shero->m_Hp -= damage;

    cout << "����" << this->m_Name << "������Ӣ�� " << shero->m_Name << "����� �˺� " << damage << endl;
}