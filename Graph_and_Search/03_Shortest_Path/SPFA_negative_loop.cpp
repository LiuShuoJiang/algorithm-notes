/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
请判断图中是否存在负权回路。

输入格式
第一行包含整数n和m。
接下来m行每行包含三个整数x, y, z，表示存在一条从点x到点y的有向边，边长为z。

输出格式
如果图中存在负权回路，则输出Yes，否则输出No。

数据范围
1 ≤ n ≤ 2000,
1 ≤ m ≤ 10000,
图中涉及边长绝对值均不超过10000。

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4

输出样例：
Yes
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool SPFA() {
    queue<int> q;
    
    //该题是判断是否存在负环，并非判断是否存在从1开始的负环
    //因此需要将所有的点都加入队列中，更新周围的点
    for (int i = 1;i <= n; i++) {
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (SPFA()) puts("Yes");
    else puts("No");

    return 0;
}
