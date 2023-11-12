# Ransom Note

[Link](https://leetcode.com/problems/ransom-note/description/)

## Description

Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise.

Each letter in `magazine` can only be used once in `ransomNote`.

Example 1:

- Input: `ransomNote = "a", magazine = "b"`
- Output: `false`

Example 2:

- Input: `ransomNote = "aa", magazine = "ab"`
- Output: `false`

Example 3:

- Input: `ransomNote = "aa", magazine = "aab"`
- Output: `true`

Constraints:

- `1 <= ransomNote.length, magazine.length <= 10^5`
- `ransomNote` and `magazine` consist of lowercase English letters.

## Solution

### Hash Map

We can check if the count of each character in the `ransomNote` is less than or equal to the count of that character in the `magazine`. If it's greater, it means there aren't enough characters in the `magazine` to form the `ransomNote`.

```C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mapping;
        for (auto c : magazine) {
            //Record the number of occurrences of each character in the "magazine" through "mapping"
            mapping[c - 'a']++;
        }
        // Traverse "randomNote" and do the -- operation on the corresponding number of characters in the "mapping"
        for (auto c : ransomNote) {
            // If it is less than zero, it means that the characters appearing in "randomNote" are not in the "magazine"
            if (--mapping[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
```

Another way of writing:

```C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (auto c : magazine) hash[c]++;
        for (auto c : ransomNote) {
            if (!hash[c]) return false;
            else hash[c]--;
        }
        return true;
    }
};
```

Time complexity: $O(n)$
