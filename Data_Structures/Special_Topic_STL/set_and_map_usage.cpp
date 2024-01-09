#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Person {
public:
    float age;
    string name;
    bool operator < (const Person & rhs) const {return age < rhs.age;}
    bool operator > (const Person & rhs) const {return age > rhs.age;}
};

int main() {
    set<int> S;
    multiset<int> MS;

    map<string, int> a;
    a["abc"] = 1;
    cout << a["abc"] << endl;

    cout << "===========================================" << endl;
    set<int, greater<int>> s1{1, 2, 3, 4, 5, 4, 3, 2, 1, 5};
    for (const auto &e: s1) {
        cout << e << endl;
    }
    cout << "===========================================" << endl;
    set<int, less<int>> s2{1, 2, 3, 4, 5, 4, 3, 2, 1, 5, 6};  //default
    for (const auto &e: s2) {
        cout << e << endl;
    }
    cout << "===========================================" << endl;

    set<Person, greater<Person>> s3 = {{30, "John"}, {25, "Alex"}, {24, "Smith"}};
    for (const auto &e : s3) {
        cout << e.age << ' ' << e.name << endl;
    }
    cout << "===========================================" << endl;

    multiset<int> multiset1 = {5, 2, 4, 3, 2, 5, 8};
    multiset1.insert(6);
    for (const auto &e : multiset1) {
        cout << e << endl;
    }
    cout << "===========================================" << endl;
    multiset<Person, greater<Person>> multiset2 = {{25, "Bob"}, {18, "Alice"}};
    for (const auto &e: multiset2) {
        cout << e.age << ' ' << e.name << endl;
    }

    return 0;
}