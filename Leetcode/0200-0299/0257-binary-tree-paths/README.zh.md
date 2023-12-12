# 二叉树的所有路径

[Leetcode题目链接](https://leetcode.com/problems/binary-tree-paths/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/binary-tree-paths/)。

## 解答

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traversal(TreeNode* curr, vector<int>& path, vector<string>& result) {
        path.push_back(curr->val);
        if (!curr->left && !curr->right) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (curr->left) {
            traversal(curr->left, path, result);
            path.pop_back();
        }
        if (curr->right) {
            traversal(curr->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        traversal(root, path, res);
        return res;
    }
};
```
