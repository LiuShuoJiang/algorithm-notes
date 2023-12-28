# 目标和

[Leetcode题目链接](https://leetcode.com/problems/target-sum/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/target-sum/)。

## 解答

```C++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto x : nums) sum += x;
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;
        int m = (sum + target) / 2;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = m; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[m];
    }
};
```
