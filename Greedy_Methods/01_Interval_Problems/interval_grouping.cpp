/*
给定N个闭区间[ai,bi]，请将这些区间分成若干组，
使得每组内部的区间两两之间(包括端点)没有交集，并使得组数尽可能小。
输出最小组数。

输入格式
第一行包含整数N，表示区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

数据范围
1 ≤ N ≤10^5,
−10^9 ≤ ai ≤ bi ≤ 10^9

输入样例：
3
-1 1
2 4
3 5

输出样例：
2
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
} range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    // 小根堆
    priority_queue<int, vector<int>, greater<int> > heap;
    for (int i = 0; i < n; i++) {
        auto t = range[i];
        if (heap.empty() || heap.top() >= t.l) heap.push(t.r);
        else {
            heap.pop();
            heap.push(t.r);
        }
    }
    printf("%d\n", heap.size());
    return 0;
}
