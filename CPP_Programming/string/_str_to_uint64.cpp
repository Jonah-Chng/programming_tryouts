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
    // std::cout << "Enter Command: ";
    // std::getline(std::cin, input);
    // std::cout<<"you typed in "<<input<<std::endl;
    
    std::string input="12345";
    std::size_t pos = 0;
    int base = 10;
    uint64_t out = std::stoull(input, &pos, base);

    std::cout<<input<<std::endl;
    std::cout<<pos<<std::endl;
    std::cout<<base<<std::endl;
    std::cout<<out<<std::endl;

    // std::cin.get();
}