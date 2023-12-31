/*
给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图G = (V, E)，
其中V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|。

由V中的全部n个顶点和E中n − 1条边构成的无向连通子图被称为G的一棵生成树，
其中边的权值之和最小的生成树被称为无向图G的最小生成树。

输入格式
第一行包含两个整数n和m。
接下来m行，每行包含三个整数u, v, w，表示点u和点v之间存在一条权值为w的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

数据范围
1 ≤ n ≤ 10^5,
1 ≤ m ≤ 2 ∗ 10^5,
图中涉及边的边权的绝对值均不超过1000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4

输出样例：
6
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];  //并查集中的p数组

struct Edge {
    int a, b, w;

    bool operator< (const Edge &W) const {
        return w < W.w;
    }
} edges[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    //res存最小生成树中所有树边的权重之和
    //cnt存当前加了多少条边
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);

        if (a != b) {
            p[a] = b;  //集合合并
            res += w;
            cnt++;
        }
    }

    if (cnt < n - 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}
