/*
n−皇后问题是指将n个皇后放在n×n的国际象棋棋盘上，使得皇后不能相互攻击到，
即任意两个皇后都不能处于同一行、同一列或同一斜线上。
现在给定整数n，请你输出所有的满足条件的棋子摆法。

输入格式
共一行，包含整数n。

输出格式
每个解决方案占n行，每行输出一个长度为n的字符串，用来表示完整的棋盘状态。
其中 . 表示某一个位置的方格状态为空，Q表示某一个位置的方格上摆着皇后。
每个方案输出完成后，输出一个空行。
注意：行末不能有多余空格。
输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围
1 ≤ n ≤ 9

输入样例：
4

输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/
#include <iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
//行，对角线，反对角线
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++) {
        //撇对角线的下标：u + i
        //捺对角线的下标：-u + i + n
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
