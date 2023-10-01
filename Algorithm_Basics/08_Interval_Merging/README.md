# 区间合并

## 问题描述

给定 $n$ 个区间 $[l_i,r_i]$ ，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如： $[1,3]$ 和 $[2,6]$ 可以合并为一个区间 $[1,6]$

> 例题：[区间合并](./interval_merging.cpp)

## 思路与模板

思路(类似于“贪心”)：

- 按区间左端点排序
- 扫描整个区间，将可能有交集的区间进行合并
  - 维护一个“当前区间”
  - 比较当前区间`[st,ed]`与现在扫到区间的关系
    - 包含：`st`和`ed`不变
    - 相交：`ed`更新(即维护区间和当前区间的并集)
    - 无交集：当前维护的区间可作为最终答案之一，更新当前维护区间为新的扫到区间

```C++
// 将所有存在交集的区间合并
void merge(vector<PII> &segs) {
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
```
