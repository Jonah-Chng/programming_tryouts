#include <iostream>
#include <exception>

class my_exception : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "Something bad happened";
    }
};

class go_wrong
{
    public:
    void went_wrong()
    {
        throw my_exception();
    }
};

int main()
{
    try{
        go_wrong wong;
        wong.went_wrong();
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
    catch(my_exception &e)
    {
        std::cout << "Error my_exception "<< e.what() << std::endl;
    }
    std::cout<<"Still runnning"<<std::endl;
    std::cin.get();

    return 0;
}