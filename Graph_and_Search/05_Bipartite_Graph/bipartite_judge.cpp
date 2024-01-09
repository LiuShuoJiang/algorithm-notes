/*
给定一个n个点m条边的无向图，图中可能存在重边和自环。
请判断这个图是否是二分图。

输入格式
第一行包含两个整数n和m。
接下来m行，每行包含两个整数u和v，表示点u和点v之间存在一条边。

输出格式
如果给定图是二分图，则输出Yes，否则输出No。

数据范围
1 ≤ n, m ≤ 10^5

输入样例：
4 4
1 3
1 4
2 3
2 4

输出样例：
Yes
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;  //点数和边数
int h[N], e[M], ne[M], idx;  //邻接表存储图
int color[N];  //保存各个点的颜色，0是未染色，1是红色，2是黑色

void add(int a, int b) {  //邻接表插入点和边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {  //深度优先遍历
    color[u] = c;  //u的点染成c颜色

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {  //若相邻的点还没有颜色,则递归处理这个相邻点
            //3 - 1 = 2， 如果u的颜色是2，则和u相邻的染成1
            //3 - 2 = 1， 如果u的颜色是1，则和u相邻的染成2
            if (!dfs(j, 3 - c)) 
                return false;
        } else if (color[j] == c) {  //如果已经染色，判断颜色是否为c
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);

        //无向图
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {  //如果该点没染色
            //染色该点，并递归处理和它相邻的点
            if (!dfs(i, 1)) {  //有矛盾发生
                flag = false;
                break;
            }
        }
    }

    //全部染色完成，没有矛盾，输出YES
    if (flag) puts("Yes");
    else puts("No");

    return 0;
}
