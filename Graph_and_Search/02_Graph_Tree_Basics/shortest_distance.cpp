/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。
所有边的长度都是1，点的编号为1∼n。
请求出1号点到n号点的最短距离，如果从1号点无法走到n号点，输出−1。

输入格式
第一行包含两个整数n和m。

接下来m行，每行包含两个整数a和b，表示存在一条从a走到b的长度为1的边。

输出格式
输出一个整数，表示1号点到n号点的最短距离。

数据范围
1 ≤ n, m ≤ 10^5

输入样例：
4 5
1 2
2 3
3 4
1 3
1 4

输出样例：
1
*/

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
    int hh = 0, tt = 0;
    q[0] = 1;

    memset(d, -1, sizeof d);

    d[1] = 0;

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}
