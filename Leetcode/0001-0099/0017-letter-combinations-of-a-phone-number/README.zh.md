# 电话号码的字母组合

[Leetcode题目链接](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)。

## 解答

```C++
class Solution {
private:
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz" // 9
};
    vector<string> res;
    string path;
    void backtracking(string& digits, int index) {
        if (digits.length() == index) {
            res.push_back(path);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtracking(digits, 0);
        return res;
    }
};
```
