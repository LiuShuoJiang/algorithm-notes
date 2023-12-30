# 组合总和 Ⅳ

[Leetcode题目链接](https://leetcode.com/problems/combination-sum-iv/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/combination-sum-iv/)。

## 解答

```C++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) 
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
```
