#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c) {
//   critical section (exclusive access to std::cout signaled by lifetime of lck):
  std::unique_lock<std::mutex> lck (mtx);
  for (int i=0; i<n; ++i) { std::cout << c; }  
  std::cout << '\n';
}

class Bar
{
  int c =0;
};

class Foo
{
public:
    Foo(int a) : x{a} {}
    int x;
    int y=0;
    Bar bar;
};

int main()
{
  Foo foo(3);
}