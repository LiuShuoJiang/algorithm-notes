#include <iostream>
#include <stack>
using namespace std;

void printObj(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    stk.push(2);
    stk.push(3);
    stk.push(4);

    printObj(stk);
    return 0;
}