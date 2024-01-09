/*
给定n个正整数ai，判定每个数是否是质数。

输入格式
第一行包含整数n。
接下来n行，每行包含一个正整数ai。

输出格式
共n行，其中第i行输出第i个正整数ai是否为质数，是则输出 Yes，否则输出 No。

数据范围
1 ≤ n ≤ 100,
1 ≤ ai ≤ 2^31−1

输入样例：
2
2
6

输出样例：
Yes
No
*/

#include <iostream>
#include <algorithm>

using namespace std;

//时间复杂度O(n)
bool is_prime(int n) {
    if (n < 2) return false;
    //不建议写 i <= sqrt(n)
    //也不建议写 i * i <= n (可能有溢出风险)
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (is_prime(x)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
