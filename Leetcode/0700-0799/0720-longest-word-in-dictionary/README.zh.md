# 词典中最长的单词

[Leetcode题目链接](https://leetcode.com/problems/longest-word-in-dictionary/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/longest-word-in-dictionary/)。

## 解答

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
