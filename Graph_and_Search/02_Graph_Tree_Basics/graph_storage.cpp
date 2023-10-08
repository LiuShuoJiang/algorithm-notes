#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[N], ne[M], idx;
bool st[N];

//插入一条从a指向b的边
void add(int a, int b) {
    //相当于在a所对应的邻接表里插入节点b
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    st[u] = true;  //标记该点已经被搜过了
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

int main() {
    memset(h, -1, sizeof h);

    dfs(1);
}