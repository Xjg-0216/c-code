#include <iostream>
using namespace std;

class myPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }

};
void test01()
{
    //仿函数
    myPrint myfunc;
    myfunc("hello world");
}

int main()
{
    test01();
    return 0;
}