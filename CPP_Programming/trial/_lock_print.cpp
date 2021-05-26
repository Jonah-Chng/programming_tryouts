// unique_lock example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

// std::mutex mtx;           // mutex for critical section

void print_block (int n, char c, std::string s) {
  std::string name = s;
  // critical section (exclusive access to std::cout signaled by lifetime of lck):
  // std::unique_lock<std::mutex> lck (mtx);
  for (int i=0; i<n; ++i) { std::cout << c; }  
  std::cout << '\n';
}

// int main ()
// {
//   std::thread th1 (print_block,1000,'*',"th1");
//   std::thread th2 (print_block,1000,'$',"th2");

//   th1.join();
//   th2.join();

//   return 0;
// }

// std::unique_lock<std::mutex> _lock()
// {
//   std::unique_lock<std::mutex> lock(_mutex, std::defer_lock);
// Function check if locked. If able to lock mutex, return false, breaks and return lock. If unable to lock mutex reutrns true, and tries to lock mutex again
//   while (!lock.try_lock()) 
//   {
//     // Intentionally busy wait
//   }

//   return lock;
// }