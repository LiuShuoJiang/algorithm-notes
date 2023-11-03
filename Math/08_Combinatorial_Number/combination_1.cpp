/*
给定n组询问，每组询问给定两个整数a，b，请输出C(a,b) mod(10^9+7)的值。

输入格式
第一行包含整数n。
接下来n行，每行包含一组a和b。

输出格式
共n行，每行输出一个询问的解。

数据范围
1 ≤ n ≤ 10000,
1 ≤ b ≤ a ≤ 2000

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

const int N = 2010, mod = 1e9 + 7;

int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i ; j++) {
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

int main() {
    init();

    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}
