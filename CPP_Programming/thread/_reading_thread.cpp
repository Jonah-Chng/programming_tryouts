#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <thread>

void reading_func()
{
    std::ifstream ifs("/home/jh/Dev/barkin_mad_ws/src/mrccc_utils/resource/pose.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    
    std::cout<<obj["header"]["clientname"].asString()<<std::endl;
}

void reading_keystroke()
{
    std::string s;
    std::cin>>s;
    std::cout<<s;
}

int main()
{
    while(true)
    {
        std::thread t1(reading_func);
        std::thread t2(reading_keystroke);
        t1.join();
        t2.join();
    }
}