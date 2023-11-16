#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    // map<string, int> map1;
    map<string, int, greater<string>> map1;
    map1["Alex"] = 2944930;
    map1["John"] = 34349054;
    map1.insert(make_pair("Smith", 75721));
    map1.insert(make_pair("Frank", 75721));

    for (auto &e : map1) {
        cout << e.first << ' '<< e.second << endl;
    }
    cout << "=======" << endl;
    map1["John"] = 115;
    cout << map1["John"] << endl;
    cout << "=======================================" << endl;

    multimap<char, int> m1;
    m1.insert(make_pair('e', 7));
    m1.insert(make_pair('b', 2));
    m1.insert(make_pair('b', 4));
    m1.insert(make_pair('b', 5));
    m1.insert(make_pair('a', 1));
    m1.insert(make_pair('a', 2));
    m1.insert(make_pair('a', 3));
    for (auto &e: m1) {
        cout << e.first << ' ' << e.second << endl;
    }
    // cout << m1['a'] << endl;  //error! not supported for multimap!

    cout << "==================================" << endl;
    // get all the pairs of given key
    // pair<multimap<char, int>::iterator, multimap<char, int>::iterator> range = m1.equal_range('a');
    auto range = m1.equal_range('a');  //return a pair of two iterators
    for (auto it = range.first; it != range.second; it++) {
        cout << it->first << ' ' << it->second << endl;
    }

    // only C++ 20 supports this function
    // cout << m1.contains('a') << endl;

    cout << "====================" << endl;
    auto pr = m1.find('a');
    cout << pr->first << ' ' << pr->second << endl;

    cout << "========================" << endl;
    auto lb = m1.lower_bound('b');
    cout << lb->first << ' ' << lb->second << endl;
    auto ub = m1.upper_bound('b');  // NOTE!!!! not "b 5"
    cout << ub->first << ' ' << ub->second << endl;

    return 0;
}