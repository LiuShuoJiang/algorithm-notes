# 实现 Trie (前缀树)

[Leetcode题目链接](https://leetcode.com/problems/implement-trie-prefix-tree/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/implement-trie-prefix-tree/)。

## 解答

```C++
class Trie {
private:
    const static int N = 31010;
    int son[N][26] {0};
    int cnt[N] {0};
    int idx = 0;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        int p = 0;
        for (char ch : word) {
            int u = ch - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        for (char ch : word) {
            int u = ch - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        return cnt[p] > 0;
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for (char ch : prefix) {
            int u = ch - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
