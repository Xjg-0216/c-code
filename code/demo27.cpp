#include <iostream>
using namespace std;
//抽象类

class Base
{
public:
    virtual void func() = 0;

};

class Son: public Base{
public:
    void func()
    {
        cout << "func()调用" << endl;
    }
};

void test01()
{
    Base* base = NULL;
    // base = new base; // error, 抽象类无法实例化
    base = new Son; //父类指针或对象指向子类对象
    base->func();
    delete base;
}

int main()
{
    test01();
    system("pause");
    return 0;
}   