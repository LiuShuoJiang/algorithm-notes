# 单词拆分

[Leetcode题目链接](https://leetcode.com/problems/word-break/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/word-break/)。

## 解答

```C++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((wordSet.find(s.substr(j, i - j)) != wordSet.end()) && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
```
