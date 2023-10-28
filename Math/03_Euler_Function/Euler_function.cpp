/*
给定n个正整数ai，请你求出每个数的欧拉函数。

输入格式
第一行包含整数n。
接下来n行，每行包含一个正整数ai。

输出格式
输出共n行，每行输出一个正整数ai的欧拉函数。

数据范围
1 ≤ n ≤ 100,
1 ≤ ai ≤ 2 × 10^9

输入样例：
3
3
6
8

输出样例：
2
2
4
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;

        int res = a;
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {
                // 不能写 res = res * (1 - 1 / a);  以防小数
                res = res / i * (i - 1);
                while (a % i == 0) a /= i;
            }
        }
        if (a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    return 0;
}
