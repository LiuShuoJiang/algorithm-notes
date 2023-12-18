# 组合总和

[Leetcode题目链接](https://leetcode.com/problems/combination-sum/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/combination-sum/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, sum - candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
};
```
