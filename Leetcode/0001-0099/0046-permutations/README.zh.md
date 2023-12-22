# 全排列

[Leetcode题目链接](https://leetcode.com/problems/permutations/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/permutations/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
```
