/*
给定n组ai, bi, pi，对于每组数据，求出ai^bi (mod pi)的值。

输入格式
第一行包含整数n。

接下来n行，每行包含三个整数ai, bi, pi。

输出格式
对于每组数据，输出一个结果，表示ai^bi (mod pi)的值。
每个结果占一行。

数据范围
1 ≤ n ≤ 100000,
1 ≤ ai, bi, pi ≤ 2 × 10^9

输入样例：
2
3 2 5
4 3 9

输出样例：
4
1
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

// 返回a^k (mod p)
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {  //对k进行二进制化，从低位到高位
        //如果k的二进制表示的第0位为1，则乘上当前的a
        if (k & 1) res = (LL) res * a % p;
        //k右移一位
        k >>= 1;
        //更新a，a依次为a^{2^0},a^{2^1},a^{2^2},....,a^{2^logb}
        a = (LL) a * a % p;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);

        printf("%d\n", qmi(a, k, p));
    }

    return 0;
}
