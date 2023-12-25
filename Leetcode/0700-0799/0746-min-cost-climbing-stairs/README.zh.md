# 使用最小花费爬楼梯

[Leetcode题目链接](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/min-cost-climbing-stairs/)。

## 解答

```C++
class Solution {
public:
    int dp[1010];
    int minCostClimbingStairs(vector<int>& cost) {
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};
```
