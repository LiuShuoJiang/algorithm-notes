# 验证二叉搜索树

[Leetcode题目链接](https://leetcode.com/problems/validate-binary-search-tree/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/validate-binary-search-tree/)。

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
    bool traversal(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;
        if (minNode && node->val <= minNode->val) return false;
        if (maxNode && node->val >= maxNode->val) return false;
        return traversal(node->left, minNode, node) && traversal(node->right, node, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return traversal(root, nullptr, nullptr);
    }
};
```
