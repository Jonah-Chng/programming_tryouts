#include <iostream>

int func (int x, int* y, int& z)
{
    return x,*y, z;
}

int main()
{
    int x=1;
    int y=2;
    int z=3;

    func(x, &y, z);
}
