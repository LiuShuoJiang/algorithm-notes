/*
给定n对正整数ai,bi，对于每对数，求出一组xi,yi，使其满足
ai * xi + bi * yi = gcd(ai, bi)。

输入格式
第一行包含整数n。
接下来n行，每行包含两个整数ai, bi。

输出格式
输出共n行，对于每组ai, bi，求出一组满足条件的xi, yi，每组结果占一行。
本题答案不唯一，输出任意满足条件的xi, yi均可。

数据范围
1 ≤ n ≤ 10^5,
1 ≤ ai, bi ≤ 2 × 10^9

输入样例：
2
4 6
8 18

输出样例：
-1 1
-2 1
*/

#include <iostream>

using namespace std;

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
        int a, b, x, y;
        scanf("%d%d", &a, &b);

        ex_gcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    return 0;
}
