/*
输入一个n行m列的整数矩阵，再输入q个操作，每个操作包含五个整数 x1,y1,x2,y2,c，
其中(x1,y1)和(x2,y2)表示一个子矩阵的左上角坐标和右下角坐标。
每个操作都要将选中的子矩阵中的每个元素的值加上c。
请将进行完所有操作后的矩阵输出。

输入格式
第一行包含整数n,m,q。
接下来n行，每行包含 m个整数，表示整数矩阵。
接下来q行，每行包含 5个整数 x1,y1,x2,y2,c，表示一个操作。

输出格式
共n行，每行m个整数，表示所有操作进行完毕后的最终矩阵。

数据范围
1≤n,m≤1000,
1≤q≤100000,
1≤x1≤x2≤n,
1≤y1≤y2≤m,
−1000≤c≤1000,
−1000≤矩阵内元素的值≤1000
*/

#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 也可写 a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j]; 然后输出a
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d", b[i][j]);
        puts("");
    }

    return 0;
}
