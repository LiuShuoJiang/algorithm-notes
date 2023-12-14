# 左叶子之和

[Leetcode题目链接](https://leetcode.com/problems/sum-of-left-leaves/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/sum-of-left-leaves/)。

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int leftVal = 0;
        if (root->left && !root->left->left && !root->left->right)
            leftVal = root->left->val;
        return leftVal + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```
