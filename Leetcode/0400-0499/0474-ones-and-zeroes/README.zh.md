# 一和零

[Leetcode题目链接](https://leetcode.com/problems/ones-and-zeroes/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/ones-and-zeroes/)。

## 解答

```C++
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (string str : strs) {
            int one = 0, zero = 0;
            for (char c : str) {
                (c == '0') ? zero++ : one++;
            }
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
```
