#include <iostream>
using namespace std;
//多态， 虚函数
class Animal
{
public:
    //函数前加virtual, 变为虚函数，那么编译器在编译阶段就不能确定函数调用了
    virtual void speak()
    {
        cout <<"动物在说话" << endl;
    }

};

class Cat: public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }

};

class Dog: public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};

void Dospeak(Animal& animal)
{
    animal.speak();
}

//多态满足条件
//1.有继承条件
//2.子类重写父类中的虚函数
//使用， 父类指针或引用指向子类对象
void test01()
{
    Cat cat;
    Dospeak(cat);
    Dog dog;
    Dospeak(dog);
}

int main()
{
    test01();
    system("pause");
    return 0;
}