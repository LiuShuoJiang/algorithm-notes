/*
给定n对正整数ai,bi，请你求出每对数的最大公约数。

输入格式
第一行包含整数n。
接下来n行，每行包含一个整数对ai,bi。

输出格式
输出共n行，每行输出一个整数对的最大公约数。

数据范围
1 ≤ n ≤ 10^5,
1 ≤ ai, bi ≤ 2 × 10^9

输入样例：
2
3 6
4 6

输出样例：
3
2
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
