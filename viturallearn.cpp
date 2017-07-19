#include <stdio.h>
#include <iostream>
using namespace std;
class A
{
  public:
    A()
    {
        cout << "A contr" << endl;
    }
    virtual ~A()  //析构函数不为虚函数的话在向上转型的时候 删除对象时无法调用子类的析构函数
    {
        cout<<"~A()"<<endl;
    }
    virtual void foo()
    {
        cout << "A:foo()" << endl;
    }
};
class B : public A
{
  public:
    B()
    {
        cout << "B constru" << endl;
    }
    ~B()
    {
        cout<<"~B()"<<endl;
    }
    void foo()
    {
        cout << "B:foo()" << endl;
    }
};
class C    //对齐方式是什么
{
    char s;   
    char s2;
   
};

class manager{

    int *a;
     manager(int *a)
     {
        this.->a=a;
     }
    ~manager
    {
        delete a;
    }

}

int main()
{
    A *a = new B();
    a->foo();
    delete a;
    //测试类的大小


    return 0;
}