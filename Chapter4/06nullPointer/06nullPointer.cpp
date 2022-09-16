#include <iostream>
using namespace std;

class Person
{
public:

    void show()    //用不到this指针
    {
        cout << "Person show" << endl;
    }
    void showAge()
    {
        if(this == NULL)
        {
            return;
        }
        cout << this->m_Age << endl;    //NULL -> m_Age
    }

    int m_Age;   //mAge
};

void test01()
{
    Person * p = NULL;
    p->show();
    p->showAge();
}

int main() {
    test01();
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
