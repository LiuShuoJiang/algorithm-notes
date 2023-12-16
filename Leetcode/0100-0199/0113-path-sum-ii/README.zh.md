# 路径总和 II

[Leetcode题目链接](https://leetcode.com/problems/path-sum-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/path-sum-ii/description/)。

## 解答

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void findPaths(TreeNode* root, vector<int> path, int sum) {
        if (!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
            return;
        }
        findPaths(root->left, path, sum);
        findPaths(root->right, path, sum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        findPaths(root, path, targetSum);
        return res;
    }
};
```
