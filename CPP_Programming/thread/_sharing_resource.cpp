#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>    
#include <thread>

void func_increment(int val)
{
    val += val;
    std::cout<<val<<std::endl;
}

void func_decrement(int val)
{
    val -= val;
    std::cout<<val<<std::endl;
}


int main()
{
    int val = 5;   

    while(true)
    {
        std::thread t1(func_increment, val);
        std::thread t2(func_decrement, val);
        t1.join();
        t2.join();
    }

    return 0;
}