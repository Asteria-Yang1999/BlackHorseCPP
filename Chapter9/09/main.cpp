#include <iostream>
#include <cstring>
using namespace std;
//�ļ���дͷ�ļ�
#include <fstream>

//д�ļ�
void test01()
{
    //������ķ�ʽ���ļ�
//    ofstream ofs("./test.txt", ios::out | ios::trunc);
    //����ָ���򿪷�ʽ

    ofstream ofs;
    ofs.open("./test.txt", ios::out | ios::trunc);
    //�ж��Ƿ�򿪳ɹ�
    if (!ofs.is_open())
    {
        cout << "��ʧ��" << endl;
    }
    ofs << "����: abc" << endl;
    ofs << "����: 100" << endl;
    ofs << "�Ա�: Ů" << endl;
}

//���ļ�
void test02()
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    //�ж��Ƿ�򿪳ɹ�
    if (!ifs.is_open())
    {
        cout << "��ʧ��" << endl;
    }

    //��һ�ַ�ʽ
/*    char buf[1024];
    while (ifs >> buf)    //���ж�ȡ
    {
        cout << buf << endl;
    }*/

    //�ڶ��ַ�ʽ
/*    char buf2[1024];
    while (ifs.eof())    //eof�����ļ�β
    {
        ifs.getline(buf2, sizeof(buf2));
        cout << buf2 << endl;
    }*/

    //�����ַ�ʽ  ���Ƽ�   ���յ����ַ���ȡ
    char c;
    while ((c = ifs.get()) != EOF)    //EOF�ļ�β
    {
        cout << c;
    }
}

int main() {
//    test01();
    test02();
    return 0;
}
