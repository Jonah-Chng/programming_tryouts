#ifndef HELPER_HPP
#define HELPER_HPP

class Bar
{
    int y=3;
    public:

    int on_message(int& x)
    {
        return x=y;
    }
};
#endif