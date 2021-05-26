#include <iostream>

class goWrong
{
    public:
    goWrong()
    {
        char * arr = new char [999999999999999999999999999999999999999999];
        delete [] arr;
    }
};

int main()
{
    try{
        goWrong wong;
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
    catch(std::bad_alloc &e)
    {
        std::cout << "Error bad_alloc"<< e.what() << std::endl;
    }
    std::cout<<"Still runnning"<<std::endl;
    std::cin.get();

    return 0;
}