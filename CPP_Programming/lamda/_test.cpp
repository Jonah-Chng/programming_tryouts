#include <iostream>
#include <functional>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;
using std::function;

int main()
{
    int i = 0;
    int j = 5;

    function<int (int)> f =[i, &j] (int k ) { return i + j + k;};

    i = 10;

    cout<<f(3)<<endl;
    return 0;


    using namespace std;

    // Create a list of integers with a few initial elements.
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    // Use the find_if function and a lambda expression to find the
    // first even number in the list.
    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(),[](int n) { return (n % 2) == 0; });

    // Print the result.
    if (result != numbers.end()) {
        cout << "The first even number in the list is " << *result << "." << endl;
    } else {
        cout << "The list contains no even numbers." << endl;
    }
}