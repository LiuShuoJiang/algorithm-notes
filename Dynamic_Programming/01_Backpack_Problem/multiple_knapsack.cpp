/*
有N种物品和一个容量是V的背包。
第i种物品最多有si件，每件体积是vi，价值是wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有N行，每行三个整数vi, wi, si，用空格隔开，分别表示第i种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N, V ≤ 100
0 < vi, wi, si ≤ 100

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2

输出样例：
10
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main() {
    cin >> n >> m;

    //朴素解法：时间复杂度 O(NVS)

    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
