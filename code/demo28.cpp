#include <iostream>
using namespace std;
/*
多态案例二 - 制作饮品
制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料
利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
//抽象制作饮品
class AbsDrinking
{
public:
    //烧水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //规范流程
    void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }

};


//制作咖啡
class Coffee: public AbsDrinking
{
public:
    //烧水
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "将咖啡倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "倒入牛奶" << endl;
    }
};

class Tea: public AbsDrinking
{
public:
    //烧水
    virtual void Boil()
    {
        cout << "煮自来水" << endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout << "将茶水倒入杯中" << endl;
    }
    //加入辅料
    virtual void PutSomething()
    {
        cout << "加入枸杞" << endl;
    }

};


//业务函数
void Dowork(AbsDrinking* drink)
{
    drink->MakeDrink();
    delete drink;
}

void test01()
{
    Dowork(new Coffee);
    cout << "-----" << endl;
    Dowork(new Tea);
}

int main()
{
    test01();
    system("pause");
    return 0;
}