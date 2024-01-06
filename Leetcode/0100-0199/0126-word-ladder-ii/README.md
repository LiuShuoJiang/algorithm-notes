# Word Ladder II

[Link](https://leetcode.com/problems/word-ladder-ii/description/)

## Description

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return all the shortest transformation sequences from `beginWord` to `endWord`, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words `[beginWord, s1, s2, ..., sk]`.

Example 1:

- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]`
- Output: `[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]`
- Explanation:

```
There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

Example 2:

- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]`
- Output: `[]`
- Explanation: `The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.`

Constraints:

- `1 <= beginWord.length <= 5`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 500`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are unique.
- The sum of all shortest transformation sequences does not exceed `10^5`.

## Solution

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
