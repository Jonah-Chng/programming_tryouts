// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset,  std::enable_shared_from_this<Song>
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {std::cout<<"Song Created"<<std::endl;}
    ~Song(){std::cout<<"Song destructor calleld"<<std::endl;}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

std::shared_ptr<Song> keep_alive()
{

}

int main()
{
    // The examples go here, in order:
    {
        Song song(L"Linkin Park", L"In the end");
        std::cout<<"For the beatles song "<<"Im Happy Just to Dance With You"<<std::endl;
        // Use make_shared function when possible.
        auto sp1 = std::make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");
        auto sp2 = sp1;
        const auto& weak_ptr = std::weak_ptr<Song>(sp2);

        {
            std::cout<<"Checking address of objects being held"<<std::endl;
            std::cout<<weak_ptr.lock().get()<<std::endl;
            std::cout<<sp1.get()<<std::endl;
            std::cout<<sp2.get()<<std::endl;
            // std::cout<<<<std::endl;
        }

        {
            std::cout<<"Address of Linkin park title "<<&song.title<<std::endl;
            std::shared_ptr<std::wstring> sp = std::make_shared<std::wstring>(song.title);
            std::cout<<"Address of sp to Linkin park title "<<sp.get()<<std::endl;
            
        }

        std::cout<<"The Beatles has "<<sp1.use_count()<<" shared pointers";
        std::cout<<" and "<<sp1.get()<<" address"<<std::endl;
    }

    // Ok, but slightly less efficient. 
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    std::shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members, 
    // initialize with nullptr to make your programming intent explicit.
    std::shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = std::make_shared<Song>(L"Elton John", L"I'm Still Standing");

    // Example 2
    // Example 3
    // Example 4
    // Example 6
}