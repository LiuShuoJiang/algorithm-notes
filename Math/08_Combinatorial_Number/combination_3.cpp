/*
给定n组询问，每组询问给定两个整数a，b，p，其中p为质数，
请输出C(a,b) mod p的值。

输入格式
第一行包含整数n。

接下来n行，每行包含一组a，b，p。

输出格式
共n行，每行输出一个询问的解。

数据范围
1 ≤ n ≤ 20,
1 ≤ b ≤ a ≤ 10^18,
1 ≤ p ≤ 10^5,

输入样例：
3
5 3 7
3 1 5
6 4 13

输出样例：
3
3
2
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int p;

int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int comb(int a, int b) {
    int res = 1;
    //C(n, m) = n * (n - 1) * ... * (n - m + 1) * inv(m) * inv(m - 1) * ... * inv(1);
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }
    return res;
}

int lucas(LL a, LL b) {
    if (a < p && b < p) return comb(a, b);
    return (LL)comb(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
    return 0;
}
