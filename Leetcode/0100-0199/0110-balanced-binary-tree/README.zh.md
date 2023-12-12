# 平衡二叉树

[Leetcode题目链接](https://leetcode.com/problems/balanced-binary-tree/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/balanced-binary-tree/)。

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
    int depth(TreeNode* node) {
        if (!node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return (abs(depth(root->left) - depth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
```
