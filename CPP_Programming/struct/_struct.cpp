#include <iostream>
// #include <thread>

using std::cout;
using std::endl;

// struct foo :  public std::enable_shared_from_this<foo>
// {
//     std::shared_ptr<int> a;
// };

// static int a;

struct A
{
    int a=0;
    A(int _a):a(_a){ func();};
    void func(){cout<<a<<endl;}
};

struct B : public A
{
    int b=0;
    B(int _a, int _b):A(_a), b(_b){func();}
    void func(){cout<<a<<' '<<b<<endl;}
} ;

int main()
{
    A bar(1);
    B foo(1,3);
    return 0;
}