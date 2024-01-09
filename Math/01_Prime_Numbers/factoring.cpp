/*
给定n个正整数ai，将每个数分解质因数，
并按照质因数从小到大的顺序输出每个质因数的底数和指数。

输入格式
第一行包含整数n。
接下来n行，每行包含一个正整数ai。

输出格式
对于每个正整数ai，按照从小到大的顺序输出其分解质因数后，
每个质因数的底数和指数，每个底数和指数占一行。
每个正整数的质因数全部输出完毕后，输出一个空行。

数据范围
1 ≤ n ≤ 100,
2 ≤ ai ≤ 2 × 10^9

输入样例：
2
6
8

输出样例：
2 1
3 1

2 3
*/

#include <iostream>
#include <algorithm>

using namespace std;

void divide(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
}

void divide_optimize(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }

    if (n > 1) printf("%d %d\n", n, 1);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x;
        scanf("%d", &x);
        //divide(x);
        divide_optimize(x);
        puts("");
    }
    return 0;
}
