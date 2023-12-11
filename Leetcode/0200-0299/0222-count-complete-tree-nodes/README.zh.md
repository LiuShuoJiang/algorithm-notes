# 完全二叉树的节点个数

[Leetcode题目链接](https://leetcode.com/problems/count-complete-tree-nodes/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/count-complete-tree-nodes/)。

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* l = root, * r = root;
        int lDepth = 0, rDepth = 0;
        while (l) { l = l->left; lDepth++; }
        while (r) { r = r->right; rDepth++; }
        if (lDepth == rDepth) return (1 << lDepth) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
