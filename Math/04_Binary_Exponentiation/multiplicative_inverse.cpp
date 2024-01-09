/*
给定n组ai, pi，其中pi是质数，求ai模pi的乘法逆元，若逆元不存在则输出impossible。
注意：请返回在0∼p−1之间的逆元。

输入格式
第一行包含整数n。

接下来n行，每行包含一个数组ai, pi，数据保证pi是质数。

输出格式
输出共n行，每组数据输出一个结果，每个结果占一行。
若ai模pi的乘法逆元存在，则输出一个整数，表示逆元，否则输出impossible。

数据范围
1 ≤ n ≤ 10^5,
1 ≤ ai, pi ≤ 2 ∗ 10^9

输入样例：
3
4 3
8 5
6 3

输出样例：
1
2
impossible
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, p;
        scanf("%d%d", &a, &p);
        int res = qmi(a, p - 2, p);
        // 若a和p互质，则a的逆元存在
        if (a % p) printf("%d\n", res);
        else puts("impossible");
    }

    return 0;
}
