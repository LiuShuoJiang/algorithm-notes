/*
给定一个大小为n≤10^6的数组。
有一个大小为k的滑动窗口，它从数组的最左边移动到最右边。
你只能在窗口中看到k个数字。
每次滑动窗口向右移动一个位置。

你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

输入格式
输入包含两行。
第一行包含两个整数n和k，分别代表数组长度和滑动窗口的长度。
第二行有n个整数，代表数组的具体数值。
同行数据之间用空格隔开。

输出格式
输出包含两个。
第一行输出，从左至右，每个位置滑动窗口中的最小值。
第二行输出，从左至右，每个位置滑动窗口中的最大值。

输入样例：
8 3
1 3 -1 -3 5 3 6 7

输出样例：
-1 -3 -3 -3 3 3
3 3 5 5 6 7

注：暴力做法的时间复杂度为O(n*k)
*/

#include <iostream>
#include <deque>
using namespace std;

const int N = 1000010;
int a[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() < i - k + 1) dq.pop_front();
        if (i >= k - 1) printf("%d ", a[dq.front()]);
    }
    puts("");
    
    dq.clear();
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() < i - k + 1) dq.pop_front();
        if (i >= k - 1) printf("%d ", a[dq.front()]);
    }
    puts("");
    
    return 0;
}
