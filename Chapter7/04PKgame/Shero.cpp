#include "Shero.h"

Shero::Shero()
{
    this->m_Hp = 500;

    this->m_Atk = 50;

    this->m_Def = 50;

    this->m_Name = "�·�ʦ";

    this->weapon = NULL;
}

//װ������
void Shero::EquipWeapon(Weapon *weapon)
{
    this->weapon = weapon;
    cout << "Ӣ�ۣ�" << this->m_Name << "װ���� " << this->weapon->m_WeaponName << "��" << endl;
}

//����
void Shero::Attack(Monster *monster)
{
    int damage = 0;
    int addHp = 0;
    int isHold = false;
    int isCrit = false;

    if (this->weapon = NULL)    //����Ϊ�� û�мӳ�
    {
        damage = this->m_Atk;
    }
    else
    {
        //�����˺�
        damage = this->m_Atk + this->weapon->getBaseDamage();
        //������Ѫ
        addHp = this->weapon->getSuckBlood();
        //���㶨��
        isHold = this->weapon->getHold();
        //���㱩��
        isCrit = this->weapon->getCrit();
    }
    if (isCrit)
    {
        damage = damage * 2;
        cout << "Ӣ�۵����������˱���Ч���������ܵ���˫�����˺��� �˺�ֵ��" << damage << endl;
    }
    if (isHold)
    {
        cout << "Ӣ�۵����������˶���Ч��������ֹͣ����һ�غ�" << endl;
    }
    if (addHp > 0)
    {
        cout << "Ӣ�۵�������������ѪЧ����Ӣ�����ӵ�Ѫ��Ϊ" << addHp << endl;
    }

    //���ù��ﶨ��
    monster->m_Hold = isHold;

    //������ʵ�˺�
    int trueDamage = (damage - monster->m_Def) > 0 ? damage - monster->m_Def : 1;

    monster->m_Hp -= trueDamage;

    this->m_Hp += addHp;

    cout << "Ӣ��" << this->m_Name << "�����˵��� " << monster->m_Name << "����� �˺� " << trueDamage << endl;
}