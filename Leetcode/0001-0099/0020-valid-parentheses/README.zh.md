# 有效的括号

[Leetcode链接](https://leetcode.com/problems/valid-parentheses/description)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/valid-parentheses/)。

## 解答

```C++
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(')');
            else if (s[i] == '[') stk.push(']');
            else if (s[i] == '{') stk.push('}');
            else if (stk.empty() || stk.top() != s[i]) return false;
            else stk.pop();
        }

        return stk.empty();
    }
};
```
