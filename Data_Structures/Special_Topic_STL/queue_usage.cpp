#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void printObj(queue<int> que) {
    while (!que.empty()) {
        cout << que.front() << " ";
        que.pop();  // remove from the front
    }
    cout << endl;
}

int main() {
    queue<int> q;
    //相当于清空(clear)操作
    q = queue<int>();
    q.push(2);
    q.push(3);
    q.push(4);
    printObj(q);

    //priority_queue<int> heap1;

    //直接定义小根堆的方法
    priority_queue<int, vector<int>, greater<int>> heap1;

    return 0;
}