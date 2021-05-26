#include <iostream>

void goWrong()
{
    bool error1 = false;
    bool error2 = false;
    bool error3 = false;
    bool error4 = true;
    
    int* x;
    *x = 3;

    if (error1) throw 6;
    if (error2) throw std::string("Boo!");
    if (error3) throw "Bar!";
    if (error4) throw x;
}

int main()
{
    try{
        goWrong();
    }
    catch(int e)
    {
        std::cout << "Error detected throwing int value "<< e << std::endl;
    }
    catch(std::string e)
    {
        std::cout << "Error detected throwing string obj value "<< e << std::endl;
    }
    catch(const char * e)
    {
        std::cout << "Error detected throwing string primitive value "<< e << std::endl;
    }
    catch(int* e)
    {
        std::cout << "Error detected throwing int * value "<< *e << std::endl;
    }
    std::cout<<"Still runnning"<<std::endl;
    std::cin.get();

    return 0;
}