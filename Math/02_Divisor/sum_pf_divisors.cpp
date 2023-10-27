/*
给定n个正整数ai，请你输出这些数的乘积的约数之和，答案对10^9 + 7取模。

输入格式
第一行包含整数n。
接下来n行，每行包含一个整数ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数之和，答案需对10^9 + 7取模。

数据范围
1 ≤ n ≤ 100,
1 ≤ ai ≤ 2 × 10^9

输入样例：
3
2
6
8

输出样例：
252
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
    for (auto prime : primes) {
        int p = prime.first, a = prime.second;
        LL t = 1;
        while (a--) t = (t * p + 1) % mod;
        res = res * t % mod;
    }
    
    cout << res << endl;

    return 0;
}

