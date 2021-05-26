#include <string>
#include <sstream>
#include <iostream>

std::string input;
bool done = false;
std::string cmd;
int id;
int port;

int main()
{
    std::cout << "Enter Command: ";
    // std::getline(std::cin, input);
    std::cin;
    std::cout<<"you typed in "<<input<<std::endl;
    
    // std::stringstream ss("0 https://mrccc.chart.com.sg:5100 5100");

    // ss >> id >> cmd >>port;
    // // std::getline(ss,reason);

    // std::cout<<cmd<<std::endl;
    // std::cout<<id<<std::endl;
    // std::cout<<port<<std::endl;

    // std::cin.get();
}