# Longest Word in Dictionary

[Link](https://leetcode.com/problems/longest-word-in-dictionary/description/)

## Description

Given an array of strings `words` representing an English Dictionary, return the longest word in `words` that can be built one character at a time by other words in `words`.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word.

Example 1:

- Input: `words = ["w","wo","wor","worl","world"]`
- Output: `"world"`
- Explanation: `The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".`

Example 2:

- Input: `words = ["a","banana","app","appl","ap","apply","apple"]`
- Output: `"apple"`
- Explanation: `Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".`

Constraints:

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 30`
- `words[i]` consists of lowercase English letters.

## Solution

### Way 1

```C++
class Solution {
private:
    vector<vector<int>> son;
    vector<int> cnt;
    int idx;
    void insert(string& word) {
        int p = 0;
        for (char s : word) {
            int u = s - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    int query(string& word) {
        int p = 0;
        for (char s : word) {
            int u = s - 'a';
            p = son[p][u];
            if (!p || cnt[p] == 0) return 0;
        }
        return cnt[p];
    }
public:
    string longestWord(vector<string>& words) {
        son = vector<vector<int>>(30010, vector<int>(26, 0));
        cnt = vector<int>(30010, 0);
        idx = 0;
        set<string> ans;
        for (string word : words) insert(word);
        for (string word : words) {
            if (query(word) > 0) ans.insert(word);
        }
        
        string longest = "";
        for (string word : ans) {
            if (word.length() > longest.length() || ((word.length() == longest.length() && word < longest)))
            longest = word;
        }
        
        return longest;
    }
};
```

### Way 2

```C++
class Solution {
private:
    vector<vector<int>> son;
    vector<int> cnt;
    string res = "";
    int idx = 0;
    int m = 0;

    void insert(const string& word) {
        int p = 0;
        for (auto ch : word) {
            int u = ch - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    void search(int u, int l, string& curr) {
        if (l > m) {
            res = curr;
            m = l;
        }

        for (int i = 0; i < 26; i++) {
            int sub = son[u][i];
            if (sub && cnt[sub] > 0) {
                curr += ('a' + i);
                search(sub, l + 1, curr);
                curr.pop_back();
            }
        }
    }

public:
    string longestWord(vector<string>& words) {
        son = vector<vector<int>>(30010, vector<int>(26, 0));
        cnt = vector<int>(30010, 0);

        for (auto word : words) insert(word);

        string curr = "";
        search(0, 0, curr);
        
        return res;
    }
};
```
