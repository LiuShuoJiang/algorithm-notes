/*
给定一个长度为 n的整数数列，以及一个整数 k，
请用快速选择算法求出数列从小到大排序后的第 k个数。

输入格式
第一行包含两个整数 n和 k。
第二行包含 n个整数（所有整数均在 1∼109范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 k小数。

数据范围
1≤n≤100000,
1≤k≤n
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n, k;
int q[N];

int quick_sort(int l, int r, int k) {
    if (l == r) return q[l];

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    int sl = j - l + 1;  //区间l到j有多少个数
    if (k <= sl) return quick_sort(l, j, k);

    // 整个区间第k小的数是右半边区间第k-sl小的数
    return quick_sort(j + 1, r, k - sl);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i];
    cout << quick_sort(0, n - 1, k) << endl;
    return 0;
}