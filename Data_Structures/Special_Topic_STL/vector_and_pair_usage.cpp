#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //vector<int> a(10, 3);
    vector <int> a;
    
    for (int i = 0; i < 10; i++) a.push_back(i);

    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
    cout << endl;

    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << endl;
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << endl;

    for (auto x: a) cout << x << ' ';
    cout << endl;

    //size()时间复杂度为O(1)
    cout << a.size() << ' ' << a.empty() << endl;

    vector<int> x(4, 3), y(3, 4);
    if (x < y) cout << "yes" << endl;  //依照字典序进行比较

    pair<int, string> p;
    p = make_pair(10, "lsj");
    p = {20, "abc"};  //C++11
    cout << p.first << ' ' << p.second << endl;

    pair<int, pair<int, int>> p2;
    return 0;
}
