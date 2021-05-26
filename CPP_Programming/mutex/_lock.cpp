#include <iostream>
#include <mutex>
#include <thread>

std::mutex _mutex;

std::unique_lock<std::mutex> _lock()
{
    std::unique_lock<std::mutex> lock(_mutex, std::defer_lock);
    while (!lock.try_lock())
    {
        // Intentionally busy wait
    }
    return lock;
}

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by lifetime of lck):
//   std::unique_lock<std::mutex> lck (_m,.utex);
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
}


int main()
{
    std::thread th1 (print_block,1000,'*');
    std::thread th2 (print_block,1000,'$');

    th1.join();
    th2.join();

    return 0;
    
}