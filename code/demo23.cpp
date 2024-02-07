#include <iostream>
using namespace std;
//继承
class Base
{
public:
    void header()
    {
        cout << "首页，公开课，登录，注册" << endl;
    }
    void footer()
    {
        cout << "帮助中心，交流合作，站内地图" << endl;
    }
    void left()
    {
        cout << "Java, python, c/c++" << endl;
    }
};
//Java页面
class Java: public Base
{
public:
    void content(){
        cout << "java视频" << endl;
    }

};
//python 页面
class Python: public Base
{
public:
    void content(){
        cout << "python视频" << endl;
    }
};
//c/c++页面
class C: public Base
{
public:
    void content(){
        cout << "c/c++视频" << endl;
    }

};

void test01()
{
    //java页面
    cout << "java视频页面下载：" << endl;
    Java ja;
    ja.header();
    ja.content();
    ja.footer();
    ja.left();

    //python页面
    cout << "python视频页面下载：" << endl;
    Python py;
    py.header();
    py.content();
    py.footer();
    py.left();
    //c/c++页面
    cout << "c/c++视频页面下载：" << endl;
    C c;
    c.header();
    c.footer();
    c.content();
    c.left();
    
 
}


int main()
{
    test01();
    system("pause");
    return 0;
}