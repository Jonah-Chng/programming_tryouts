#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
 
// https://en.cppreference.com/w/cpp/thread/mutex

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::string result = "fake content";
 
    // std::lock_guard<std::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}

void func(std::string s)
{
    std::cout<<s<<std::endl;
}

int main() 
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    std::thread t3(save_page, "http://foofoo");
    std::thread t4(save_page, "http://barbar");
    t1.join();
    t2.join();  
    t3.join();
    t4.join();

    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}