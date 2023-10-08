/*
给定一个n×m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，
其中0表示可以走的路，1表示不可通过的墙壁。
最初，有一个人位于左上角(1,1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角(n,m)处，至少需要移动多少次。

数据保证(1,1)处和(n,m)处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数n和m。
接下来n行，每行包含m个整数(0或1)，表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1 ≤ n, m ≤ 100

输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出样例：
8
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];  //存放地图
int d[N][N];  //存每一个点到起点的距离

PII q[N * N];  //数组模拟队列

PII previous[N][N];

int bfs() {
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof d);  //距离初始化为-1表示没有走过
    d[0][0] = 0;  //表示起点走过了

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt) {  //队列不空
        auto t = q[hh++];  //取队头元素
        for (int i = 0; i < 4; i++) {  //枚举上下左右4个方向
            int x = t.first + dx[i], y = t.second + dy[i];
            //在边界内并且是空地可以走，且之前没有走过
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;  //到起点的距离
                previous[x][y] = t;
                q[++tt] = {x, y};  //新坐标入队
            }
        }
    }

    int x = n - 1, y = m - 1;
    while (x || y) {
        cout << x << ' ' << y << endl;
        auto t = previous[x][y];
        x = t.first, y = t.second;
    }

    return d[n - 1][m - 1];  //输出右下角点距起点的距离即可
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    }
    cout << bfs() << endl;
    return 0;
}
