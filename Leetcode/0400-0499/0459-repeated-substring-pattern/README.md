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

Easier way of writing (see [reference](https://leetcode.com/problems/repeated-substring-pattern/solutions/94360/my-one-line-c-solution/)):

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

The `ne` is essentially the LPS (Longest Proper Prefix which is also Suffix) array used in KMP. It stores the length of the longest proper prefix that is also a proper suffix for every substring of `s`.

- `ne[i]`: The length of the longest proper prefix of the substring `s[1..i]` which is also a proper suffix of `s[1..i]`.

***Code Explanation***:

1. **Initialization**:
   - `n`: Length of the string `s`.
   - `s = ' ' + s`: The string `s` is modified by adding a space at the beginning. This is done to make the string 1-indexed, simplifying the algorithm's logic.
   - `vector<int> ne(n + 1, 0)`: Initializes the `ne` array of size `n+1` with all elements as 0.
2. **Building the `ne` Array**:
   - The loop `for (int i = 2, j = 0; i <= n; i++)` iterates over the string.
   - `while (j && s[i] != s[j + 1]) j = ne[j]`: This line checks if the current character doesn't match the character in the pattern. If they don't match, we fall back to the previous position's `ne` value.
   - `if (s[i] == s[j + 1]) j++`: If the characters match, we increment `j`.
   - `ne[i] = j`: Assign the calculated `ne` value for the position `i`.
3. **Checking for Repeated Substring Pattern**:
   - `int t = n - ne[n]`: This calculates the length of the smallest repeating unit.
   - `return t < n && n % t == 0`: Checks if the length of the repeating unit is less than `n` and if `n` is a multiple of `t`.

***Why "n - ne[n]" is the Length of the Repeated Substring?***:

- `ne[n]` gives the length of the longest proper prefix which is also a suffix for the entire string.
- Subtracting this from the total length (`n - ne[n]`) gives us the smallest segment of the string that, when repeated, could recreate the original string.
- If this segment is smaller than the entire string and the total length of the string is a multiple of this segment's length, it implies that the string is composed of repeated occurrences of this segment.

***Correctness of the Algorithm***:

- The preprocessing part correctly computes the `ne` array which captures the prefix-suffix relationship in the string.
- The check `n % t == 0` ensures that the entire string can be constructed by repeating this smallest segment.
- Since the `ne` array is constructed to reflect the longest repeating prefix-suffix pattern in the string, using `n - ne[n]` to find the smallest repeating unit is logically sound.
