/*
给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数N。
第二行包含N个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1 ≤ N ≤ 100000，
−10^9 ≤ 数列中的数 ≤ 10^9

输入样例：
7
3 1 2 1 8 5 6

输出样例：
4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int len = 0;
    q[0] = -2e9;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    printf("%d\n", len);
    return 0;
}
