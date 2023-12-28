# 最后一块石头的重量II

[Leetcode题目链接](https://leetcode.com/problems/last-stone-weight-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/last-stone-weight-ii/)。

## 解答

```C++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int x : stones) sum += x;
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum / 2; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
        return sum - 2 * dp[sum / 2];
    }
};
```
