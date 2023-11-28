# Remove All Adjacent Duplicates In String

[Link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/)

## Description

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make duplicate removals on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is **unique**.

Example 1:

- Input: `s = "abbaca"`
- Output: `"ca"`
- Explanation: For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:

- Input: `s = "azxxzy"`
- Output: `"ay"`

Constraints:

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Solution

### Way 1

```C++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto &ch : s) {
            if (!stk.empty() && stk.top() == ch) stk.pop();
            else stk.push(ch);  // if (stk.empty() || stk.top() != ch)
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.

### Way 2

We can take a string and use it directly as a stack, which eliminates the need for the stack to be converted to a string.

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

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
