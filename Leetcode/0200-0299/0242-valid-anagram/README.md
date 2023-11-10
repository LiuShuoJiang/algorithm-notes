# Valid Anagram

[Link](https://leetcode.com/problems/valid-anagram/description/)

## Description

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: `s = "anagram"`, `t = "nagaram"`
Output: `true`

Example 2:

Input: `s = "rat"`, `t = "car"`
Output: `false`

Constraints:

- `1 <= s.length`, `t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## Solution

Hash Map:

- Assuming that the string contains only lowercase letters, use an array of length 26 as a hash table to keep track of the number of times a letter appears.
- For `s`, add the number of letters to the hash table.
- For `t`, reduce the number of corresponding letters in the hash table.
- Finally, from `a` to `z` statistics whether there is not 0 cases, if so, then return false, otherwise return true.

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }
        //If any element of the record array is not 0, the strings s and t must be either more or less characters.
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};
```

Hash Map (Simpler):

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash_s, hash_t;
        for (auto c : s) hash_s[c]++;
        for (auto c : t) hash_t[c]++;
        // unordered_map supports == operator
        return hash_s == hash_t;
    }
};
```

Time complexity: $O(n)$
