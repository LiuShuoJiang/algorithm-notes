/*
有N组物品和一个容量是V的背包。每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是vij，价值是wij，其中i是组号，j是组内编号。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行有两个整数N，V，用空格隔开，分别表示物品组数和背包容量。
接下来有N组数据：
每组数据第一行有一个整数Si，表示第i个物品组的物品数量；
每组数据接下来有Si行，每行有两个整数vij,wij，用空格隔开，
分别表示第i个物品组的第j个物品的体积和价值；

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N, V ≤ 100
0 < Si ≤ 100
0 < vij, wij ≤ 100

输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5

输出样例：
8
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N][N];

int main() {
    cin >> n >>m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= s[i]; k++)
                if (j >= v[i][k])
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
