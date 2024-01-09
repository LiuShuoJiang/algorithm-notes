#include <iostream>
#include <deque>
using namespace std;

void printObj(const deque<int> &obj) {
    for (auto &num: obj) cout << num << ' ';
    cout << endl;
}

int main() {
    deque<int> dq = {2, 3, 4};
    dq.push_front(1);
    dq.push_back(5);
    printObj(dq);

    deque<int> dq2 = {2, 3, 4};
    dq2.pop_front();
    dq2.pop_back();
    printObj(dq2);

    return 0;
}