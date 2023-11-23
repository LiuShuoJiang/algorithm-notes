# Reverse String

[Link](https://leetcode.com/problems/reverse-string/description/)

## Description

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with $O(1)$ extra memory.

Example 1:

- Input: `s = ["h","e","l","l","o"]`
- Output: `["o","l","l","e","h"]`

Example 2:

- Input: `s = ["H","a","n","n","a","h"]`
- Output: `["h","a","n","n","a","H"]`

Constraints:

- `1 <= s.length <= 10^5`
- `s[i]` is a printable ascii character.

## Solution

### Double Pointer

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++)
            swap(s[i], s[s.size() - i - 1]);
    }
};
```

Another way of writing:

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            // swap(s[i], s[j]);
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
        }
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
