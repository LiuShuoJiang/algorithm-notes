/*
给定一颗树，树中包含n个结点(编号1∼n)和n−1条无向边。
请找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数n，表示树的结点数。

接下来n−1行，每行包含两个整数a和b，表示点a和点b之间存在一条边。

输出格式
输出一个整数m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1 ≤ n ≤ 10^5

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

输出样例：
4
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;  //邻接表
bool st[N];  //标记点是否被搜过

int ans = N;  //ans记录剩余各个连通块中的点数的最大值

//插入一条从a指向b的边
void add(int a, int b) {
    //相当于在a所对应的邻接表里插入节点b
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 以u为根的子树中的点的数量
int dfs(int u) {
    st[u] = true;  //标记u这个点已经被搜过了

    //sum记录以u为根的子树的节点数
    //res记录u的最大子树的节点数
    //那么n-sum就是u上面的部分的节点数
    //我们有ans=max(res, n - sum);
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {  //i是边的编号
        int j = e[i];  //j是u的邻接点
        if (!st[j]) {  //避免向上查找
            int s = dfs(j);  //s是以j为根的子树的节点数
            res = max(res, s); //记录u的最大子树的节点数
            sum += s;  //累加u的各个子树的节点数
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);  //更新答案
    return sum;  //返回以u为根的子树的节点数
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;
}
