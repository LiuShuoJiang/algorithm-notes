# 对称二叉树

[Leetcode题目链接](https://leetcode.com/problems/symmetric-tree/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/symmetric-tree/)。

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
    bool compare(TreeNode* left, TreeNode* right) {
        if (!left && right) return false;
        if (left && !right) return false;
        if (!left && !right) return true;
        if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};
```
