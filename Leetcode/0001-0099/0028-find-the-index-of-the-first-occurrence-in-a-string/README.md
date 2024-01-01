# Find the Index of the First Occurrence in a String

[Link](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## Description

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

Example 1:

- Input: `haystack = "sadbutsad", needle = "sad"`
- Output: `0`
- Explanation: `"sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.`

Example 2:

- Input: `haystack = "leetcode", needle = "leeto"`
- Output: `-1`
- Explanation: `"leeto" did not occur in "leetcode", so we return -1.`

Constraints:

- `1 <= haystack.length, needle.length <= 10^4`
- `haystack` and `needle` consist of only lowercase English characters.

## Solution

### Brute-Force Solution

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            bool flag = true;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};
```

### KMP Solution

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
