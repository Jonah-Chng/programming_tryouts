#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::string previous =" ";
    std::string current;
    while(cin>>current){
        cout<<"Current is "<<current<<endl;
        if(previous == current)
            cout<<"Repeated word: "<<current<<"\n";
        previous = current;
    }
}