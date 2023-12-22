# 斐波那契数

[Leetcode题目链接](https://leetcode.com/problems/fibonacci-number/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/fibonacci-number/)。

## 解答

```C++
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
```
