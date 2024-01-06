# 单词接龙

[Leetcode题目链接](https://leetcode.com/problems/word-ladder/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/word-ladder/description/)。

## 解答

```C++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        unordered_map<string, int> visitMap;
        queue<string> que;
        que.push(beginWord);
        visitMap[beginWord] = 1;

        while (!que.empty()) {
            string word = que.front();
            que.pop();

            int path = visitMap[word];
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1;
                    if (wordSet.count(newWord) && !visitMap.count(newWord)) {
                        visitMap[newWord] = path + 1;
                        que.push(newWord);
                    }
                }
            }
        }

        return 0;
    }
};
```
