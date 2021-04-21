#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include <signal.h>
#include <string>

using std::cout;
using std::endl;

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
    cout << "Caught signal " << signum << endl;
    // Terminate program
    exit(signum);
}

int main(){

    // Register signal and signal handler
    signal(SIGINT, signal_callback_handler);

    std::string input;

    cout<<"Input a long sentence"<<endl;

    std::getline(std::cin, input);

    std::stringstream s(input);
    
    std::string word;

    while (s >> word)
    {   
        [word](){cout<<word<<endl;};
    }
    
    // while(true){
    //     cout << "Program processing..." << endl;
    //     std::cout << "Enter Command: ";
    //     std::getline(std::cin, input);
    //     sleep(1);
    //     cout<<input<<endl;
    // }
   
   return EXIT_SUCCESS;
}