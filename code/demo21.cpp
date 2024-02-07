#include <iostream>
using namespace std;

class Person{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(Person& p)
    {
        if(this->name == p.name && this->age == p.age)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool operator!=(Person& p)
    {
        if(this->name == p.name && this->age == p.age)
        {
            return false;
        }
        else{
            return true;
        }
    }

    string name;
    int age;
};

void test01()
{
    Person a("孙悟空", 18);
    Person b("孙悟空", 19);
    if (a == b)
    {
        cout << "a和b相等" << endl;
    }
    else{
        cout << "a和b不相等" << endl;
    }
}

int main()
{
    test01();
    return 0;
}