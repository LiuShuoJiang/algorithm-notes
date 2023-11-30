#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    unordered_set<int> uset = {4, 1, 2, 3, 4, 2, 3};

    auto search = uset.find(2);
    if (search != uset.end()) {
        cout << "Found " << (*search) << endl;
    } else {
        cout << "Not found" << endl;
    }
    for (auto &elm : uset) cout << elm << ' ';
    cout << endl;
    cout << "=======================================" << endl;

    string sentence{"cppreference.com"};
    cout << "The sentence: " << sentence << endl;

    unordered_multiset<char> sequence;
    for (char x : sentence)
        sequence.insert(x);

    // { m o c c c p p r r e e e e f n . }
    cout << "The sequence: { ";
    for (char x : sequence)
        cout << x << ' ';

    cout << "}\n" "Symbol:Frequency: ";
    for (auto it = sequence.begin(); it != sequence.end();)
    {
        if (auto [first, last] = sequence.equal_range(*it); first != last)
        {
            cout << *first << ":" << distance(first, last) << "  ";
            it = last;
        }
        else
            ++it;
    }

    return 0;
}