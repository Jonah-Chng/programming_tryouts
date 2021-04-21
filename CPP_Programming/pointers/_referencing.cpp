#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Person
{
    public:
    Person(std::string name)
    {
        Name = name;
    }
    std::string Name;

    ~Person()
    {
        cout<<"Destroying "<<Name<<" :C"<<endl;
    }
};

class BestFriend
{
    public:
    BestFriend(std::string bff)
    {
        bestfriend = bff;
    }
    std::string bestfriend;

    ~BestFriend()
    {
        cout<<"Destructing"<<endl;
    }
};

int main()
{
    // const auto& patrick= new BestFriend("Patrick Star");
    // const auto& spongebob= new BestFriend("Spongbob Squarepants");
    // BAD! Because patrick references spongebob,
    // They reference each other and therefore the object's reference
    // count will always be 1, and will never be deallocated
    
    auto p = std::make_shared<Person>("Patrick Star");
    std::shared_ptr<Person> s = std::make_shared<Person>("Spongebob Squarepants");

    cout<<p->Name<<endl;
    p = std::make_shared<Person>("Spongebob Squarepants");

    cout<<p->Name<<endl;
    cout<<s->Name<<endl;

    // delete patrick;
    // delete spongebob;

    // Trying out constness
    const int i = 3;
    auto& j = i;
    // j =4; // FAILS!
    cout<<j<<endl;
    return 0;
}