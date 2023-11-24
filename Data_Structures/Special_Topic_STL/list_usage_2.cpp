#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> list1 = {5, 2, 4, 6, 2};
    list<int> list2 = {7, 6, 1, 9};

    for (auto &elm: list1) cout << elm << endl;
    cout << "===============================" << endl;
    for (auto &elm: list2) cout << elm << endl;
    cout << "===============================" << endl;
    list1.sort();
    list2.sort();
    list1.merge(list2);
    for (auto &elm: list1) cout << elm << endl;
    cout << "===============================" << endl;
    for (auto &elm: list2) cout << elm << endl;
    cout << "===============================" << endl;

    list<int> list3 = {5, 2, 4, 6, 2};
    list<int> list4 = {7, 6, 1, 9};
    list3.splice(list3.begin(), list4);
    for (auto &elm: list3) cout << elm << endl;
    cout << "===============================" << endl;
    for (auto &elm: list4) cout << elm << endl;
    return 0;
}