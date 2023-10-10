#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];  //记录地图信息以及每个顶点到源点的距离

int bfs() {
    queue<PII> q;  //定义一个坐标队列

    q.push({0, 0});  //原点进队

    memset(d, -1, sizeof(d));  //初始化各个点到原点的距离为-1

    d[0][0] = 0;  //原点到自己的距离为0

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    //队列不为空
    while (q.size()) {
        PII t = q.front();  //取队头元素

        q.pop(); //队头元素出队

        for (int i = 0; i < 4; i++) {  //分别向四个方向扩展
            int x = t.first + dx[i], y = t.second + dy[i];  //扩展后的坐标

            //首先(x,y)不能越界, 然后g[x][y] == 0说明可以走(g[x][y] == 1说明是障碍物)
            //最后是只更新未被访问的点到原点的距离(要求d[x][y] == -1)
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;  //当前点到起点的距离
                q.push({x, y});  //将新坐标入队
            }
        }
    }

    return d[n - 1][m -1];  //返回右下角元素到原点的距离
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}