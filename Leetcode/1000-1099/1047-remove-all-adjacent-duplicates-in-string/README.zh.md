# 删除字符串中的所有相邻重复项

[Leetcode链接](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)。

## 解答

```C++
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto &ch : s) {
            if (res.empty() || res.back() != ch) res.push_back(ch);
            else res.pop_back();
        }
        return res;
    }
};
```
