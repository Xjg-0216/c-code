#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

//公有继承
class Son1: public Base1
{
public:
    void func()
    {
        m_A;//可访问，public权限
        m_B;//可访问，protected权限
        // m_C;//不可访问，private权限
    }

};


//保护继承
class Son2: protected Base1
{
public:
    void func()
    {
        m_A; //可访问，protected权限
        m_B; //可访问，protected权限
        // m_C;//不可访问，private权限
    }
};


class Son3: private Base1{
public:
    void func()
    {
        m_A;//可访问，protected权限
        m_B;//可访问，protected权限
        // m_C; //不可访问，private权限
    }
};

void myclass()
{
    Son1 s1;
    s1.m_A;//类外只能访问公有权限
    Son2 s2;//类外 都不能访问
    Son3 s3;//类外，都不能访问
}

int main()
{
    return 0;
}