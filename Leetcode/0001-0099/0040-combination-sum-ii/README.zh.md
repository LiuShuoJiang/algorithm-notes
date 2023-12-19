# 组合总和II

[Leetcode题目链接](https://leetcode.com/problems/combination-sum-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/combination-sum-ii/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        // if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum - candidates[i] >= 0; i++) {
            if (i != startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, sum - candidates[i], i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};
```
