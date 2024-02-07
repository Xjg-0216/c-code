#include <iostream>
using namespace std;

//计算器类
//普通实现
class Calculator
{
public:
    int getResult(string oper)
    {
        if(oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if(oper == "*")
        {
            return m_Num1 * m_Num2;
        }
    }
    int m_Num1;
    int m_Num2;
}; 

void test01()
{
    //普通实现测试
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 20;
    cout << c.getResult("+") << endl;
    cout << c.getResult("-") << endl;
    cout << c.getResult("*") << endl;
}

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }   

//多态实现
class Abscalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;

};
//加法计算器
class Addcalculator: public Abscalculator{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};
//减法计算器
class Subcalculator: public Abscalculator{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};
//乘法计算器
class Mulcalculator: public Abscalculator{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};


void test02()
{
    //多态使用条件：父类的指针或引用指向子类对象
    Abscalculator* abc = new Addcalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;

    //创建减法计算器
    abc = new Subcalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->getResult() << endl;
    delete abc;

    //创建乘法计算器
    abc = new Mulcalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;
    


}


int main()
{
    test02();
    system("pause");
    return 0;
}