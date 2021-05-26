#include <iostream>
#include <memory>
#include "var.hpp"
#include "help.cpp"

int main()
{
    Bar bar;
    std::shared_ptr<Foo> foo= std::make_shared<Foo>();
    auto foofoo= foo;
    bar.on_message(foofoo->x);
    std::cout<<foo->x<<std::endl;
    std::cout<<foofoo->x<<std::endl;
}