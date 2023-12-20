# Palindrome Partitioning

[Link](https://leetcode.com/problems/palindrome-partitioning/description/)

## Description

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.

A **substring** is a contiguous non-empty sequence of characters within a string. A **palindrome** is a string that reads the same forward and backward.

Example 1:

- Input: `s = "aab"`
- Output: `[["a","a","b"],["aa","b"]]`

Example 2:

- Input: `s = "a"`
- Output: `[["a"]]`

Constraints:

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

## Solution

### Way 1

```C++
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    
    void backtracking(string &s, int index) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        
        for (int i = index; i < s.length(); i++) {
            if (!isPalindrome(s, index, i)) continue;
            path.push_back(s.substr(index, i - index + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
```

- Time complexity: $O(n\cdot 2^n)$;
- Space complexity: $O(n^2)$.

### Way 2: Optimized Solution

```C++
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> isPalindrome; 

    void backtracking(const string &s, int index) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (!isPalindrome[index][i]) continue;
            path.push_back(s.substr(index, i - index + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    
    void computeMemo(const string &s) {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (j == i) isPalindrome[i][j] = true;
                else if (j - i == 1) isPalindrome[i][j] = (s[i] == s[j]);
                else isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        computeMemo(s);
        backtracking(s, 0);
        return res;
    }
};
```
