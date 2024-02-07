#include <iostream>
using namespace std;
/*
多态案例三-电脑组装
电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作

*/

//抽象cpu类
class Cpu
{
public:
    //抽象的计算函数
    virtual void calculate() = 0;
};

//抽象显卡类
class VideoCard
{
public:
    //抽象的显示函数
    virtual void display() = 0;
};

class Memory
{
public:
    //抽象的存储函数
    virtual void storage() = 0;
};

//电脑类

class Computer
{
public:
    Computer(Cpu* cpu, VideoCard* vc, Memory* mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    //提供的工作函数
    void work()
    {
        //让零件工作起来
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }
    //提供析构函数，释放三个电脑零件
    ~Computer()
    {
        //释放CPU零件
        if(m_cpu !=  NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        //释放显卡零件
        if(m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        //释放内存条零件
        if(m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    Cpu* m_cpu;
    VideoCard* m_vc;
    Memory* m_mem;

};

//intel厂商
class Intelcpu: public Cpu
{
public:
    virtual void calculate()
    {
        cout << "Intel的cpu开始计算了" << endl;
    }

};

class Intelvideocard: public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel的显卡开始显示了" << endl;
    }

};

class InterlMemory: public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel的内存条开始存储了" << endl;
    }
};

class Lenovocpu: public Cpu
{
public:
    virtual void calculate()
    {
        cout << "Lenovo的cpu开始计算了" << endl;
    }

};

class Lenovovideocard: public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenovo的显卡开始显示了" << endl;
    }

};

class LenovoMemory: public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo的内存条开始存储了" << endl;
    }
};

void test01()
{
    //第一台电脑零件
    Cpu* intelcpu = new Intelcpu;
    VideoCard* intelvc = new Intelvideocard;
    Memory* intelmem = new InterlMemory;

    cout << "第一台 电脑开始工作：" << endl;
    //创建第一台电脑
    Computer* computer1 = new Computer(intelcpu, intelvc, intelmem);
    computer1->work();
    delete computer1;

    cout << "----------" << endl;
    cout << "第二台 电脑开始工作： " << endl;
    Computer* computer2 = new Computer(new Lenovocpu, new Lenovovideocard, new LenovoMemory);
    computer2->work();
    delete computer2;
    
    cout << "----------" << endl;
    cout << "第三台 电脑开始工作" << endl;
    Computer* computer3 = new Computer(new Lenovocpu, new Lenovovideocard, new LenovoMemory);
    computer3->work();
    delete computer3;
}


int main()
{
    test01();
    system("pause");
    return 0;
}