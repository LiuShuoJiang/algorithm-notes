/*
给定一个长度为n的数列，请你求出数列中每个数的二进制表示中1的个数。

输入格式
第一行包含整数n。
第二行包含n个整数，表示整个数列。

输出格式
共一行，包含n个整数，其中的第i个数表示数列中的第i个数的二进制表示中1的个数。

数据范围
1 ≤ n ≤ 100000,
0 ≤ 数列中元素的值 ≤ 10^9

输入样例：
5
1 2 3 4 5

输出样例：
1 1 2 1 2
*/

#include <iostream>
using namespace std;

/*
根据计算机负数表示的特点，如一个数字原码是10001000，他的负数表示形式是补码，就是反码+1，
反码是01110111，加一则是01111000，二者按位与得到了1000，
就是我们想要的low_bit操作
*/
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

    //注：也可(一行)使用系统自带函数
    //cout << __builtin_popcount(x) << ' ';

    return 0;
}
