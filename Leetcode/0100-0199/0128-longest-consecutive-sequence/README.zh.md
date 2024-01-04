# 最长连续序列

[Leetcode题目链接](https://leetcode.com/problems/longest-consecutive-sequence/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/longest-consecutive-sequence/)。

## 解答

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            if (s.find(x - 1) == s.end()) {
                int curr = x + 1;
                while (s.find(curr) != s.end()) curr++;
                best = max(best, curr - x);
            }
        }
        return best;
    }
};
```
