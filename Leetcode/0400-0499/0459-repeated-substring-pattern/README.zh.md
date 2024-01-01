# 重复的子字符串

[Leetcode题目链接](https://leetcode.com/problems/repeated-substring-pattern/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/repeated-substring-pattern/)。

## 解答

```C++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin()); t.erase(t.end() - 1);
        if (t.find(s) != string::npos) return true;
        return false;
    }
};
```
