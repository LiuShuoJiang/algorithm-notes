# 子集II

[Leetcode题目链接](https://leetcode.com/problems/subsets-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/subsets-ii/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       backtracking(nums, 0);
       return res; 
    }
};
```
