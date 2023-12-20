# 复原 IP 地址

[Leetcode题目链接](https://leetcode.com/problems/restore-ip-addresses/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/restore-ip-addresses/)。

## 解答

```C++
class Solution {
private:
    vector<string> res;
    void backtracking(const string &s, int startIndex, int currSize, string path) {
        if (startIndex == s.length()) {
            if (currSize == 4) {
                path.pop_back();  // delete the final "."
                res.push_back(path);
            }
            return;
        }

        if (currSize == 4) return;

        for (int i = startIndex, temp = 0; i < s.length(); i++) {
            if (i > startIndex && s[startIndex] == '0') break;
            temp = temp * 10 + s[i] - '0';
            if (temp <= 255) 
                backtracking(s, i + 1, currSize + 1, path + to_string(temp) + '.');
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0, "");
        return res;
    }
};
```
