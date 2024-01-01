# Repeated Substring Pattern

[Link](https://leetcode.com/problems/repeated-substring-pattern/description/)

## Description

Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

- Input: `s = "abab"`
- Output: `true`
- Explanation: `It is the substring "ab" twice.`

Example 2:

- Input: `s = "aba"`
- Output: `false`

Example 3:

- Input: `s = "abcabcabcabc"`
- Output: `true`
- Explanation: `It is the substring "abc" four times or the substring "abcabc" twice.`

Constraints:

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.

## Solution

### Moving Match

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

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.

Easier way of writing:

```C++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
```

### KMP

```C++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> ne(n + 1, 0);
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        int t = n - ne[n];
        return t < n && n % t == 0;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.
