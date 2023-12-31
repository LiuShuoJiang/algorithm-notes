/*
给定n个正整数ai，请你输出这些数的乘积的约数个数，答案对10^9 + 7取模。

输入格式
第一行包含整数n。
接下来n行，每行包含一个整数ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对10^9 + 7取模。

数据范围
1 ≤ n ≤ 100,
1 ≤ ai ≤ 2 × 10^9

输入样例：
3
2
6
8

输出样例：
12
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> primes;

    while (n--) {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }

        if (x > 1) primes[x]++;
    }

    LL res = 1;
    for (auto prime : primes)
        //res = (x1 + 1)(x2 + 1)(x3 + 1)…(xk + 1)
        res = res * (prime.second + 1) % mod;
    
    cout << res << endl;

    return 0;
}
