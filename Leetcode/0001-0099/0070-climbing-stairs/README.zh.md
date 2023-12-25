# 爬楼梯

[Leetcode题目链接](https://leetcode.com/problems/climbing-stairs/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/climbing-stairs/)。

## 解答

```C++
class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```
