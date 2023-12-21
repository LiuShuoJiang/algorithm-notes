# 递增子序列

[Leetcode题目链接](https://leetcode.com/problems/non-decreasing-subsequences/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/non-decreasing-subsequences/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() > 1) res.push_back(path);

        unordered_set<int> used;
        for (int i = startIndex; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) continue;
            if (!path.empty() && nums[i] < path.back()) continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```
