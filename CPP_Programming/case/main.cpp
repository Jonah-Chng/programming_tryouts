#include <iostream>

enum StatusType
{
    /// Robot status info
    kStatusStatusPub = 0,

    /// move base footprint
    kStatusMoveBaseFootprint,

    /// current completed sub mission status
    kStatusCurrentCompletedSubMission,

    /// amcl pose message
    kStatusAMCLPose,

    /// unknown status type
    kStatusUnknown = 254
} status_id;

std::string sw()
{
    status_id = (StatusType)4;

    switch(status_id)
    {
    case kStatusStatusPub: // Does not have pose
    {
        std::cout<<"kStatusStatusPub"<<std::endl;
        return std::string("kStatusStatusPub");
    }
    case kStatusMoveBaseFootprint: // Cant find message type, will have to see from msg->get_payload()
     {
        std::cout<<"kStatusMoveBaseFootprint"<<std::endl;
        return std::string("kStatusMoveBaseFootprint");
     }
    case kStatusCurrentCompletedSubMission:
    {
        std::cout<<"kStatusCurrentCompletedSubMission"<<std::endl;
        return std::string("kStatusCurrentCompletedSubMission");
    }
    case kStatusAMCLPose:
    {
        std::cout<<"kStatusAMCLPose"<<std::endl;
        return std::string("kStatusAMCLPose");
    }
    case kStatusUnknown:
    {
        std::cout<<"kStatusUnknown"<<std::endl;
        return std::string("kStatusUnknown");
    }
    default:
    {
        std::cout<<"default"<<std::endl;
        return std::string("default");
    }
    }
}

int main()
{
    sw();
}