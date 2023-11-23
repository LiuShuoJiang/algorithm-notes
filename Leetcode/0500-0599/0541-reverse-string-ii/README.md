# Reverse String II

[Link](https://leetcode.com/problems/reverse-string-ii/description/)

## Description

Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the start of the string.

If there are fewer than `k` characters left, reverse all of them. If there are less than `2k` but greater than or equal to `k` characters, then reverse the first `k` characters and leave the other as original.

Example 1:

- Input: `s = "abcdefg", k = 2`
- Output: `"bacdfeg"`

Example 2:

- Input: `s = "abcd", k = 2`
- Output: `"bacd"`

Constraints:

- `1 <= s.length <= 10^4`
- `s` consists of only lowercase English letters.
- `1 <= k <= 10^4`

## Solution

### Original Solution

```C++
class Solution {
public:
    string reverse(string s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
    string reverseStr(string s, int k) {
        for (int i = 0; ; ) {
            int t = i + 2 * k;
            if (t < s.size()) {
                s.replace(i, k, reverse(s.substr(i, k)));
                i += 2 * k;
            } else if (i + k >= s.size()) {
                s.replace(i, s.size() - i, reverse(s.substr(i, s.size() - i)));
                break;
            } else {
                s.replace(i, k, reverse(s.substr(i, k)));
                break;
            }
        }
        return s;
    }
};
```

### Optimized Solution

```C++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            // 1. the first k characters of every 2k characters are reversed
            // 2. if the remaining characters are less than 2k 
            // but greater than or equal to k, invert the first k characters
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 3. If there are less than k characters left,
                // then reverse all remaining characters
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.

Another way of writing:

```C++
class Solution {
public:
    // Left-closed right-closed interval
    void myReverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                myReverse(s, i, i + k - 1);
            } else {
                myReverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};
```

Easiest way of writing:

```C++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            int l = i, r = min(i + k, (int)s.size());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};
```

Note: `s.size()` returns an unsigned number, which needs to be converted to a signed number when `min()` is called to make the comparison.
