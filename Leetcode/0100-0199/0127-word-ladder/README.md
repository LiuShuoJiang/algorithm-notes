# Word Ladder

[Link](https://leetcode.com/problems/word-ladder/description/)

## Description

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary wordList is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the number of words in the shortest transformation sequence from `beginWord` to `endWord`, or `0` if no such sequence exists.

Example 1:

- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]`
- Output: `5`
- Explanation: `One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.`

Example 2:

- Input: `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]`
- Output: `0`
- Explanation: `The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.`

Constraints:

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
- `beginWord != endWord`
- All the words in `wordList` are unique.

## Solution

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

Code with Comments:

```C++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList into a set for O(1) access
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If the endWord is not in the wordSet, no solution exists
        if (!wordSet.count(endWord)) return 0;

        // Map to keep track of visited words and their path lengths
        unordered_map<string, int> visitMap;

        // Queue for BFS
        queue<string> que;
        que.push(beginWord); // Start from the beginWord
        visitMap[beginWord] = 1; // Starting word has path length 1

        // BFS
        while (!que.empty()) {
            string word = que.front(); // Current word
            que.pop();

            int path = visitMap[word]; // Current path length
            // Try changing each letter of the word
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                // Try replacing the i-th character with every possible lowercase letter
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a'; // Replace with the j-th letter
                    // If the new word is the endWord, return the path length + 1
                    if (newWord == endWord) return path + 1;
                    // If newWord is in the wordSet and not visited, add to queue and mark as visited
                    if (wordSet.count(newWord) && !visitMap.count(newWord)) {
                        visitMap[newWord] = path + 1; // Increment path length
                        que.push(newWord); // Add to BFS queue
                    }
                }
            }
        }

        // If no path is found
        return 0;
    }
};
```

***Algorithm***:

1. **Initialization**: Convert the `wordList` into an `unordered_set` for $O(1)$ access. This helps in quickly checking if a word exists in the word list. Additionally, a queue for BFS and a map to track visited words are initialized.
2. **Breadth-First Search (BFS)**: The algorithm uses BFS to find the shortest path from `beginWord` to `endWord`. For each word, it iteratively changes each letter to all possible 26 letters and checks if the new word is in the word set.
3. **Path Tracking**: The `visitMap` keeps track of each word and the length of the shortest path to reach it from `beginWord`.
4. **Termination**: If `endWord` is reached, the shortest path length is returned. If BFS completes without finding `endWord`, return 0.

***Complexity Analysis***:

1. **Time Complexity**:
   - The main contributing factor to time complexity is the double loop inside the BFS, where we iterate over each letter of the word and then over 26 possible replacements.
   - For a word of length `L` and a total of `N` words in the word list, the worst-case time complexity is $O(26NL)$. This is because we potentially explore $26$ different transformations for each of the $L$ characters in each of the $N$ words.
2. **Space Complexity**:
   - The space complexity is primarily dictated by the storage of the word set and the visit map.
   - Both the `unordered_set` and the `unordered_map` store a number of elements equal to the size of the `wordList`, giving a space complexity of $O(N)$.
   - Additionally, the queue in the worst case might store a significant number of words, but this also will not exceed $O(N)$.
