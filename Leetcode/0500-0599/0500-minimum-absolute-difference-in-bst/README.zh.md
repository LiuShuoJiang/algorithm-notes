# 二叉搜索树的最小绝对差

[Leetcode题目链接](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)。

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
    TreeNode* pre;
    int res = INT_MAX;
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        if (pre) res = min(res, root->val - pre->val);
        pre = root;
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
```
