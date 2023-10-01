/*
给定一个长度为n的整数序列，
请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数n。
第二行包含n个整数（均在0∼10^5范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

数据范围
1 ≤ n ≤ 10^5

输入样例：
5
1 2 2 3 5

输出样例：
3
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n;
int a[N], s[N];  //s[N]是当前j到i区间内每一个数出现次数

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}

