# 单词接龙 II

[Leetcode题目链接](https://leetcode.com/problems/word-ladder-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/word-ladder-ii/description/)。

## 解答

```C++
class Solution {
private:
    vector<vector<string>> res;
    void dfs(string& beginWord, string word, vector<string>& path, unordered_map<string, int>& dist) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for (int i = 0; i < word.size(); i++) {
                string oldWord = word;
                for (int j = 'a'; j <= 'z'; j++) {
                    oldWord[i] = j;
                    if (dist.count(oldWord) && dist[oldWord] + 1 == dist[word]) {
                        path.push_back(oldWord);
                        dfs(beginWord, oldWord, path, dist);
                        path.pop_back();
                    }
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return res;
        
        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        queue<string> que;
        que.push(beginWord);

        while (!que.empty()) {
            string word = que.front();
            que.pop();

            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (char j = 'a'; j <= 'z'; j++) {
                    newWord[i] = j;
                    if (wordSet.count(newWord) && !dist.count(newWord)) {
                        dist[newWord] = dist[word] + 1;
                        if (newWord == endWord) break;
                        que.push(newWord);
                    }
                }
            }
        }

        vector<string> path;
        path.push_back(endWord);
        dfs(beginWord, endWord, path, dist);
        return res;
    }
};
```
