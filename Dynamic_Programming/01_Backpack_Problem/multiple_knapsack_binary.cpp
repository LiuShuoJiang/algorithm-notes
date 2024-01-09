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
0 < N ≤ 1000
0 < V ≤ 2000
0 < vi, wi, si ≤ 2000

提示：
本题考查多重背包的二进制优化方法。

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

const int N = 25000;  //1000 * log(2000)
const int M = 2010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;

        while (k <= s) {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }

        if (s > 0) {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}
