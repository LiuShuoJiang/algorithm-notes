#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> list1 = {5, 4, 6, 2};
    forward_list<int> list2 = {7, 6, 1, 9};
    list1.insert_after(list1.begin(), 8);
    for (auto &elm: list1) cout << elm << endl;
    cout << "===============================" << endl;
    list2.reverse();
    for (auto &elm: list2) cout << elm << endl;
    cout << "===============================" << endl;
    list1.sort();
    list2.sort();
    list1.merge(list2);
    for (auto &elm : list1) cout << elm << endl;
    cout << "===============================" << endl;
    
    forward_list<int> list3 = {5, 4, 6, 2};
    forward_list<int> list4 = {7, 6, 1, 9};
    list3.splice_after(list3.begin(), list4);
    for (auto &elm: list3) cout << elm << endl;
    cout << "===========" << endl;
    for (auto &elm: list4) cout << elm << endl;
    cout << "size of list4: " << distance(list2.begin(), list2.end()) << endl;

    forward_list<int> list5 = {5, 2, 4, 4, 6, 2, 2};
    list5.unique();
    // only remove adjacent duplicates
    for (auto &elm: list5) cout << elm << endl;
    cout << "====" << endl;
    list5.remove(2);
    for (auto &elm: list5) cout << elm << endl;

    cout << "==============================================" << endl;
    forward_list<int> list6 = {5, 2, 4, 6, 2};
    list6.remove_if([] (int n) {
        return n > 4;
    });
    for (auto &elm: list6) cout << elm << endl;

    cout << "================" << endl;
    list6.resize(2);
    for (auto &elm: list6) cout << elm << endl;

    return 0;
}