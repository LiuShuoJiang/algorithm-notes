/*
给定一个长度为n的数列，请你求出数列中每个数的二进制表示中1的个数。

输入格式
第一行包含整数n。
第二行包含n个整数，表示整个数列。

输出格式
共一行，包含n个整数，其中的第i个数表示数列中的第i个数的二进制表示中1的个数。

数据范围
1≤n≤100000,
0≤数列中元素的值≤10^9
*/

#include <iostream>
using namespace std;

int low_bit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= low_bit(x), res++;  //每次减去x的最后一位1
        cout << res << ' ';
    }
    return 0;
}
