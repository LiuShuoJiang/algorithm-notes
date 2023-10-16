/*
有N种物品和一个容量是V的背包，每种物品都有无限件可用。
第i种物品的体积是vi，价值是wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有N行，每行两个整数vi, wi，用空格隔开，分别表示第i种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N, V ≤ 1000
0 < vi, wi ≤ 1000

输入样例
4 5
1 2
2 4
3 4
4 5

输出样例：
10
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    //朴素解法
    //时间复杂度为 O(N*V^2)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
