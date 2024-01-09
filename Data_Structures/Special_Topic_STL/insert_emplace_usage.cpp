#include <iostream>
#include <set>
#include <vector>
using namespace std;

class A {
public:
    int x;
    A(int x = 0) : x(x) {cout << "Construct" << endl;}
    A(const A& rhs) {
        x = rhs.x;
        cout << "Copy" << endl;
    }
};

bool operator < (const A& lhs, const A& rhs) {return lhs.x < rhs.x;}

int main() {
    set<A> s;
    s.insert(A(1));
    A b(10);
    s.insert(b);
    cout << "=========================" << endl;
    s.emplace(2);
    for (auto &a : s) cout << a.x << ' ' << endl;
    cout << "====================================" << endl;

    vector<pair<int, string>> myVector;

    // Using insert
    myVector.insert(myVector.end(), make_pair(1, "Apple"));
    // Using emplace
    myVector.emplace_back(2, "Banana");
    // Outputting elements
    for (const auto& element : myVector) {
        cout << element.first << " " << element.second << endl;
    }
    return 0;
}