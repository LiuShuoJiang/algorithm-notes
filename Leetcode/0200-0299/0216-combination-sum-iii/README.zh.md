# 组合总和 III

[Leetcode题目链接](https://leetcode.com/problems/combination-sum-iii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/combination-sum-iii/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int sum, int startIndex) {
        if (sum > n) return;
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(k, n, sum + i, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return res;
    }
};
```
