#include <iostream>
using namespace std;
//赋值运算符重载

/*
c++编译器至少给一个类添加4个函数
1. 默认构造函数（无参）
2. 默认析构函数（无参）
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符operator=, 对属性进行值拷贝
如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/

class Person{
public:
    Person(int age)
    {
        //将年龄开辟到堆区
        m_Age = new int(age);
    }
    //重载赋值运算符
    Person& operator=(Person& p)
    {
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }   
        //编译器提供的浅拷贝
        // m_Age = p.m_Age;
        m_Age = new int(*p.m_Age);
        return *this;
    }
    ~Person()
    {
        if(m_Age !=NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    //年龄的指针
    int* m_Age;
};


void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2;
    cout <<"p1的年龄为： " << *p1.m_Age << endl;
    cout <<"p2的年龄为：" << *p2.m_Age << endl;
    cout << "p3的年龄为：" << *p3.m_Age << endl;
}


int main()
{
    test01();
    system("pause");
    return 0;
}