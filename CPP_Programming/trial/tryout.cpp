#include <iostream>

struct Some
{
    int x=0;
    int y=0;
    int z=0;
}a;

Some foo()
{
    a.x=1;
    a.y=2;
    a.z=3;
    
    std::cout<<"x "<<a.x<<" y "<<a.y<<" z "<<a.z<<std::endl;
    return a;
}

Some someFunc()
{
    int i =4;
    switch(i)
    {
    case 1: // Does not have pose
    {
        Some a;
        std::cout<<'0'<<std::endl;
        return a;
    }
    case 2: // Cant find message type, will have to see from msg->get_payload()
     {
        Some a;
        // std::cout<<"kStatusMoveBaseFootprint"<<std::endl;
        // fs = json_movebasefoot_to_fleetstate(obj);
        return a;
     }
    case 3:
    {
        Some a;
        // std::cout<<"kStatusCurrentCompletedSubMission"<<std::endl;
        return a;
    }
    case 4: // <-- changing the object here
    {
        Some a;
        
        a = foo();

        std::cout<<"x "<<a.x<<" y "<<a.y<<" z "<<a.z<<std::endl;
        return a;
    }
    case 5:
    {
        Some a;
        return a;
    }
    }

}

// int main()
// {
//     someFunc();
// }