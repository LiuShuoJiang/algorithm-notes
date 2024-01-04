# Implement Trie (Prefix Tree)

[Link](https://leetcode.com/problems/implement-trie-prefix-tree/description/)

## Description

A **trie** (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- `Trie()` Initializes the trie object.
- `void insert(String word)` Inserts the string `word` into the trie.
- `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and false otherwise.
- `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

Example 1:

- Input:

```C++
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
```

- Output:

```C++
[null, null, true, false, true, null, true]
```

- Explanation:

```C++
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

Constraints:

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 10^4` calls in total will be made to `insert`, `search`, and `startsWith`.

## Solution

### Way 1

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

### Way 2

```C++
class Trie {
private:
    struct Node {
        bool is_tail;
        Node *son[26];
        Node() {
            is_tail = false;
            for (int i = 0; i < 26; i++) son[i] = nullptr;
        }
        ~Node() {
            for (int i = 0; i < 26; i++) delete son[i];
        }
    } *root;
public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        auto p = root;
        for (auto ch : word) {
            int u = ch - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_tail = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto ch : word) {
            int u = ch - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return p->is_tail;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto ch : prefix) {
            int u = ch - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
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
