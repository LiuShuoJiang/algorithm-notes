#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<int> q;
    //相当于清空(clear)操作
    q = queue<int>();

    //priority_queue<int> heap1;

    //直接定义小根堆的方法
    priority_queue<int, vector<int>, greater<int>> heap1;

    return 0;
}