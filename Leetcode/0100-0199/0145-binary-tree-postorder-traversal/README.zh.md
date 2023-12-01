# 二叉树的后序遍历

[Leetcode题目链接](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/binary-tree-postorder-traversal/)。

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
    void postOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};
```
