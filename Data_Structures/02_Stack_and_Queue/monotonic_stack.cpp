/*
给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出−1。

输入格式
第一行包含整数N，表示数列长度。

第二行包含N个整数，表示整数数列。

输出格式
共一行，包含N个整数，其中第i个数表示第i个数的左边第一个比它小的数
如果不存在则输出−1。

数据范围
1≤N≤10^5
1≤数列中元素≤10^9
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    //时间复杂度O(n)
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;  //如果栈顶元素大于当前待入栈元素，则出栈
        if (tt) cout << stk[tt] << ' ';  //栈顶元素就是左侧第一个比它小的元素 
        else cout << -1 << ' '; //如果栈空，则没有比该元素小的值

        stk[++tt] = x;
    }

    return 0;
}
