/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请求出1号点到n号点的最短距离，如果无法从1号点走到 n号点，则输出−1。

输入格式
第一行包含整数n和m。
接下来m行每行包含三个整数x,y,z，表示存在一条从点x到点y的有向边，边长为z。

输出格式
输出一个整数，表示1号点到n号点的最短距离。
如果路径不存在，则输出−1。

数据范围
1 ≤ n ≤ 500,
1 ≤ m ≤ 10^5,
图中涉及边长均不超过10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4

输出样例：
3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];  //用邻接矩阵存图
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        //t⬅不在当前已确定最短距离的点集中的距离最近的点
        for (int j = 1; j <= n; j++) {
            //在所有st[j]为false的点(尚未确定距离的点)中找出dist最小的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        //把t加到已确定最短距离的点集中
        st[t] = true;

        //用t更新其他点的距离
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        //保留长度最短的那条边(处理重边情况)
        g[a][b] = min(g[a][b], c);
    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;
}
