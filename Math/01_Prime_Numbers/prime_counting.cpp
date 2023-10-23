/*
给定一个正整数n，请你求出1∼n中质数的个数。

输入格式
共一行，包含整数n。

输出格式
共一行，包含一个整数，表示1∼n中质数的个数。

数据范围
1 ≤ n ≤ 10^6

输入样例：
8

输出样例：
4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

//埃氏筛法
void get_prime_optimize_1(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}

//线性筛法
void get_prime_optimize_2(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;  //意味着primes[j]一定是i的最小质因子
        }
    }
}

int main() {
    int n;
    cin >> n;

    //get_prime(n);
    get_prime_optimize_1(n);
    cout << cnt << endl;
    return 0;
}