#include <iostream>
#include <vector>
using namespace std;

void print_obj(const pair<int, int> &obj) {
    cout << obj.first << " " << obj.second << endl;
}

int main() {
    pair<int, int> obj(10, 20);
    print_obj(obj);

    pair<int, int> obj2 = make_pair(20, 30);
    print_obj(obj2);

    vector<pair<string, int>> list;
    list.push_back(make_pair("Sam", 20));
    list.push_back(make_pair("John", 50));
    list.push_back(pair<string, int>("Smith", 40));
    list.push_back(pair("Frank", 70));
    for (auto &elm: list) cout << elm.first << " " << elm.second << endl;

    return 0;
}