# 分割回文串

[Leetcode题目链接](https://leetcode.com/problems/palindrome-partitioning/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/palindrome-partitioning/)。

## 解答

```C++
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    
    void backtracking(string &s, int index) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        
        for (int i = index; i < s.length(); i++) {
            if (!isPalindrome(s, index, i)) continue;
            path.push_back(s.substr(index, i - index + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
```
