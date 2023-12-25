# 不同路径

[Leetcode题目链接](https://leetcode.com/problems/unique-paths/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/unique-paths/)。

## 解答

```C++
class Solution {
public:
    int dp[110][110];
    int uniquePaths(int m, int n) {
        for (int i = 0; i < 110; i++) dp[i][0] = dp[0][i] = 1;
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};
```
