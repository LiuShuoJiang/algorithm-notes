/*
给定两个升序排序的有序数组A和B，以及一个目标值x。
数组下标从0开始。
请求出满足A[i]+B[j]=x的数对(i,j)。
数据保证有唯一解。

输入格式
第一行包含三个整数n,m,x，分别表示A的长度B的长度以及目标值x。
第二行包含n个整数，表示数组A。
第三行包含m个整数，表示数组B。

输出格式
共一行，包含两个整数i和j。

数据范围
数组长度不超过10^5。
同一数组内元素各不相同。
1 ≤ 数组元素 ≤ 10^9

输入样例：
4 5 6
1 2 4 7
3 4 6 8 9

输出样例：
1 1
*/

//注：以下采用双指针算法时间复杂度为O(n + m)
//此处保证了有唯一解才能用双指针算法，如果没有唯一解而需要求所有解的题目则用不了双指针

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, x;
int a[N], b[N];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x) {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}

