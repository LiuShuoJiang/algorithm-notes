#include <iostream>
#include <array>
using namespace std;

int main() {
    // declare
    array<int, 5> my_array_0;

    // initialization
    array<int, 5> my_array = {1, 2, 3, 4, 5};  //initializer list
    array<int, 5> my_array_2{1, 2, 3, 4, 5}; //uniform initialization

    // assign using initializer list
    // traditional C array cannot do this!
    array<int, 5> my_array_3;
    my_array_3 = {2, 4, 6, 8, 10};

    cout << my_array_3.at(2) << endl;
    // cout << my_array_3.at(5) << endl;
    cout << my_array_3.front() << ' ' << my_array_3.back() << endl;
    
    return 0;
}