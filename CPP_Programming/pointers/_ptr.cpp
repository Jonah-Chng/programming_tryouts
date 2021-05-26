#include <iostream>

using namespace std;

void test(int * const &x){

    *x = 1000;
}

int main(){
    int Byte = 100;
    int* nKByte = &Byte;
    test(nKByte);
    cout << nKByte << " megabytes" << endl;
    cin.get();
}