# 不同路径II

[Leetcode题目链接](https://leetcode.com/problems/unique-paths-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/unique-paths-ii/)。

## 解答

```C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                else continue;
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
