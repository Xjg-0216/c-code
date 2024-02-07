#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    virtual void Speak() = 0;
    // ~Animal()
    // {
    //     cout << "Animal 析构函数调用" << endl;
    // }
    virtual ~Animal()
    {
        cout << "Animal虚析构函数调用" << endl;
    }
    //纯虚析构
    // virtual  ~Animal() = 0;
    
};

// Animal::~Animal()
// {
//     cout << "Animal 纯虚析构函数调用" << endl;
// }

class Cat: public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat 构造函数调用" << endl;
        m_name = new string(name);

    }
    virtual void Speak()
    {
        cout << *m_name << "小猫在说话" << endl;
    }

    ~Cat()
    {
        cout << "Cat 析构函数调用" << endl;
        if(this->m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }
    }
public:
    string* m_name;

};

void test01()
{
    Animal* animal = new Cat("Tom");
    animal->Speak();
    delete animal;

}


int main()
{
    test01();
    system("pause");
    return 0;
}