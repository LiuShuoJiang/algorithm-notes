# 整数拆分

[Leetcode题目链接](https://leetcode.com/problems/integer-break/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/integer-break/)。

## 解答

```C++
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
        return dp[n];
    }
};
```
