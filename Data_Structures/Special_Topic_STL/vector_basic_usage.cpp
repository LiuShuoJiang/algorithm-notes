#include <iostream>
#include <vector>
using namespace std;

int main() {
    // declaration
    vector<int> arr1;
    vector<int> arr2(5, 20);  // [20, 20, 20, 20, 20]
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> arr4{1, 2, 3, 4, 5};

    arr2[3] = -7;
    // arr2[5] = -8;  // (BAD BEHAVIOR) doesn't get any error output!
    arr2[4] = -10;
    for (auto a : arr2) {
        cout << a << ' ';
    }
    cout << endl;
    cout << "=========================================" << endl;

    for (int i = 0; i < 32; i++) {
        arr1.push_back(i);
        cout << arr1.size() << ' ' << arr1.capacity() << endl;
    }
    cout << "=========================================" << endl;

    vector<int> arr5;
    arr5.reserve(31);
    for (int i = 0; i < 32; i++) {
        arr5.push_back(i);
        cout << arr5.size() << ' ' << arr5.capacity() << endl;
    }
    return 0;
}