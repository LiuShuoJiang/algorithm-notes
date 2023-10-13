/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
请求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出−1。

输入格式
第一行包含整数n和m。
接下来m行每行包含三个整数x,y,z，表示存在一条从点x到点y的有向边，边长为z。

输出格式
输出一个整数，表示1号点到n号点的最短距离。
如果路径不存在，则输出−1。

数据范围
1 ≤ n, m ≤ 1.5 × 10^5,
图中涉及边长均不小于0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过10^9。

输入样例：
3 3
1 2 2
2 3 1
1 3 4

输出样例：
3
*/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        //在pair中把存储距离放在first，节点编号放在second是为了能直接取出小根堆的堆顶元素
        //相当于在朴素算法中第一个for循环中找的最小的j
        auto t = heap.top();
        heap.pop();

        int vertex = t.second, distance = t.first;
        if (st[vertex]) continue;
        st[vertex] = true;

        //朴素版没有对这个循环进行优化，直接遍历了一遍
        //而ver每次都是距离最小的点(堆排序的原理)
        //算法核心就是每次都取距离最小的点，然后用这个点来更新其它点
        for (int i = h[vertex]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
            //上述if block也可以写成：
            //dist数组用于减少堆中部分冗余数据，
            //若不基于dist数组，即不进行判定直接将当前结点的相邻边权值 + 源点到该点的距离均放于堆中，也可以
            /*
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
            */
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //此处无需考虑重边
        add(a, b, c);
    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}
