/*
给定n组数据ai, bi, mi，对于每组数求出一个xi，使其满足ai × xi ≡ bi (mod mi)，如果无解则输出impossible。

输入格式
第一行包含整数n。
接下来n行，每行包含一组数据ai, bi, mi。

输出格式
输出共n行，每组数据输出一个整数表示一个满足条件的xi，如果无解则输出impossible。
每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。
输出答案必须在int范围之内。

数据范围
1 ≤ n ≤ 10^5,
1 ≤ ai, bi, mi ≤ 2 × 10^9

输入样例：
2
2 3 6
4 3 5

输出样例：
impossible
-3
*/

#include <iostream>

using namespace std;

typedef long long LL;

int ex_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);
        
        int x, y;
        int d = ex_gcd(a, m, x, y);
        if (b % d) puts("impossible");
        else printf("%d\n", (LL)x * (b / d) % m);
    }

    return 0;
}
