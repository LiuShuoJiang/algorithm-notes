# Find Common Characters

[Link](https://leetcode.com/problems/find-common-characters/description/)

## Description

Given a string array `words`, return an array of all characters that show up in all strings within the `words` (including duplicates). You may return the answer in any order.

Example 1:

Input: `words = ["bella","label","roller"]`
Output: `["e","l","l"]`

Example 2:

Input: `words = ["cool","lock","cook"]`
Output: `["c","o"]`

Constraints:

`1 <= words.length <= 100`
`1 <= words[i].length <= 100`
`words[i]` consists of lowercase English letters.

## Solution

```C++
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 1e8);
        for (auto word : words) {
            unordered_map<int, int> hash;
            for (auto c : words) hash[c - 'a'] ++;
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], hash[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
```
