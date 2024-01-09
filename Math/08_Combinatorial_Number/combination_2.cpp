/*
给定n组询问，每组询问给定两个整数a，b，请输出C(a,b) mod(10^9+7)的值。

输入格式
第一行包含整数n。

接下来n行，每行包含一组a和b。

输出格式
共n行，每行输出一个询问的解。

数据范围
1 ≤ n ≤ 10000,
1 ≤ b ≤ a ≤ 10^5

输入样例：
3
3 1
5 3
2 2

输出样例：
3
10
1
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010, mod = 1e9 + 7;

int fact[N], infact[N];

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    //预处理：使时间复杂度由 O(n^2) 降到 O(N*log(N))
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        // fact[i] 为 i!
        fact[i] = (LL)fact[i - 1] * i % mod;
        // infact[i] 为 i! 的逆元
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 防止爆long long
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    return 0;
}
