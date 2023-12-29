# 零钱兑换II

[Leetcode题目链接](https://leetcode.com/problems/coin-change-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/coin-change-ii/)。

## 解答

```C++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = coins[i - 1]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }
        return dp[amount];
    }
};
```
