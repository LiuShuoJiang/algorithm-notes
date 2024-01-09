/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
再给定k个询问，每个询问包含两个整数x和y，表示查询从点 x到点y的最短距离，
如果路径不存在，则输出impossible。
数据保证图中不存在负权回路。

输入格式
第一行包含三个整数n, m, k。
接下来m行，每行包含三个整数x, y, z，表示存在一条从点x到点y的有向边，边长为z。
接下来k行，每行包含两个整数x, y，表示询问点x到点y的最短距离。

输出格式
共k行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出impossible。

数据范围
1 ≤ n ≤ 200,
1 ≤ k ≤ n^2
1 ≤ m ≤ 20000,
图中涉及边长绝对值均不超过10000。

输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3

输出样例：
impossible
1
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &Q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    while (m--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        d[a][b] = min(d[a][b], w);
    }

    floyd();

    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);

        if (d[a][b] > INF / 2) puts("impossible");
        else printf("%d\n", d[a][b]);
    }

    return 0;
}
