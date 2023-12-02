# 前K个高频元素

[Leetcode题目链接](https://leetcode.com/problems/top-k-frequent-elements/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/top-k-frequent-elements/)。

## 解答

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashing;
        for (auto elm : nums) hashing[elm]++;
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (auto &p : hashing) count[p.second]++;
        int i = n, t = 0;
        while (t < k) t += count[i--];
        vector<int> res;
        for (auto &p : hashing) {
            if (p.second > i) res.push_back(p.first);
        }
        return res;
    }
};
```
