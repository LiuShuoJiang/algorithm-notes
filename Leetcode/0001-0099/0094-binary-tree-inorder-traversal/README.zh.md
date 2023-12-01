# 二叉树的中序遍历

[Leetcode题目链接](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/binary-tree-inorder-traversal/)。

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
    void inOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};
```
