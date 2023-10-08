#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int g[N][N];  //存储地图，兼职判重
int d[N][N]; //存储距离
int n, m;

int bfs(int a, int b) {
    queue<PII> q;
    q.push({a, b});

    //初始点的距离为0
    //也可以不要这一句，因为d初始化的时候，各个点就是0
    d[0][0] = 0;

    while (!q.empty()) {
        PII start = q.front();
        q.pop();
        //这一句可以不要，因为入队的时候就置为了1
        g[start.first][start.second] = 1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {  //往四个方向走
            //当前点能走到的点
            int x = start.first + dx[i], y = start.second + dy[i];
            //如果还没有走过
            if (g[x][y] == 0) {
                //走到这个点，并计算距离
                g[x][y] = 1;
                d[x][y] = d[start.first][start.second] + 1; //从当前点走过去，则距离等于当前点的距离+1
                //这个点放入队列，用来走到和它相邻的点。
                q.push({x, y});
            }
        }
    }
    return d[n][m];
}

void bfs_print() {
    int target = d[n][m];
    queue<PII> q;
    q.push({n, m});
    cout << n << " " << m <<endl;

    while (!q.empty()) {
        PII start = q.front();
        q.pop();

        int dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + start.first, y = dy[i] + start.second;
            if (x >= 1 && y >= 1 && x <= n && x <= m && d[x][y] == target - 1) {
                q.push({x, y});
                cout << x << " " << y << endl;
            }
        }
        target--;
    }
}

int main() {
    memset(g, 1, sizeof g);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs(1, 1) << endl;
    bfs_print();
    return 0;
}