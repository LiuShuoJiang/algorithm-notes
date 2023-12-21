# 子集

[Leetcode题目链接](https://leetcode.com/problems/subsets/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/subsets/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        // if (startIndex >= nums.size()) return;
        
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```
