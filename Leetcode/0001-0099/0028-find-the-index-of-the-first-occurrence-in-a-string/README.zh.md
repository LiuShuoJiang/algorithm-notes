# 找出字符串中第一个匹配项的下标

[Leetcode题目链接](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)。

## 解答

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        haystack = ' ' + haystack;
        needle = ' ' + needle;
        vector<int> ne(m + 1);
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && needle[i] != needle[j + 1]) j = ne[j];
            if (needle[i] == needle[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = 1, j = 0; i <= n; i++) {
            while (j && haystack[i] != needle[j + 1]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == m) return i - m;
        }
        return -1;
    }
};
```
