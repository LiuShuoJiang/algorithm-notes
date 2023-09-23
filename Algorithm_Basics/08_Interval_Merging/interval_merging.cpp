/*
给定n个区间 [l_i,r_i]，要求合并所有有交集的区间。
注意如果在端点处相交，也算有交集。
输出合并完成后的区间个数。

例如：[1,3]和[2,6]可以合并为一个区间[1,6]。

输入格式
第一行包含整数n。
接下来n行，每行包含两个整数l和r。

输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围
1 ≤ n ≤ 100000,
−10^9 ≤ l_i ≤ r_i ≤ 10^9
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge_intervals(vector<PII> &segs) {
    vector<PII> res;
    //sort默认按pair的first元素排序
    sort(segs.begin(), segs.end());  //按左端点排序

    int st = -2e9, ed = -2e9;  //ed代表区间结尾，st代表区间开头
    for (auto seg: segs) {
        if (ed < seg.first) {  //情况1：两个区间无法合并
            if (st != -2e9) res.push_back({st, ed});  //区间1放进res
            st = seg.first, ed = seg.second;  //维护区间2
        } else {  //情况2：两个区间可以合并，要么区间1不包含区间2，区间2不包含区间1，要么区间1包含区间2
            ed = max(ed, seg.second);
        }
    }

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge_intervals(segs);
    cout << segs.size() << endl;
}
