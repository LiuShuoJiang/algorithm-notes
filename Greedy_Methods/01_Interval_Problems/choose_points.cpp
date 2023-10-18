/*
给定N个闭区间[ai,bi]，请在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
输出选择的点的最小数量。
位于区间端点上的点也算作区间内。

输入格式
第一行包含整数N，表示区间数。
接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需的点的最小数量。

数据范围
1 ≤ N ≤ 10^5,
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

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator< (const Range &W) const {
        return r < W.r;
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

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++) {
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }
    }

    printf("%d\n", res);

    return 0;
}
