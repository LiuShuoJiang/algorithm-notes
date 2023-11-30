# 二叉树的前序遍历

[Leetcode题目链接](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/binary-tree-preorder-traversal/)。

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
public:
    void preOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};
```
