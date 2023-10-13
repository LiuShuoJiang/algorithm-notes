/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
请求出从1号点到n号点的最多经过k条边的最短距离，
如果无法从1号点走到n号点，输出impossible。
注意：图中可能存在负权回路。

输入格式
第一行包含三个整数n, m, k。
接下来m行，每行包含三个整数x, y, z，表示存在一条从点x到点y的有向边，边长为z。
点的编号为1∼n。

输出格式
输出一个整数，表示从1号点到n号点的最多经过k条边的最短距离。
如果不存在满足条件的路径，则输出impossible。

数据范围
1 ≤ n, k ≤ 500,
1 ≤ m ≤ 10000,
1 ≤ x, y ≤ n，
任意边长的绝对值不超过10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3

输出样例：
3
*/

//注意：本题只能用Bellman-Ford算法

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N];
int backup[N];

struct edge {
    int a, b, w;
} edges[M];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++) {
        //存储上一次迭代的结果(防止出现串联结果)
        memcpy(backup, dist, sizeof dist);

        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    bellman_ford();

    //注意不能写dist[n] == 0x3f3f3f3f
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}
