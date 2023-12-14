# 找树左下角的值

[Leetcode题目链接](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/find-bottom-left-tree-value/)。

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
    int res = 0;
    int maxDepth = 0;
    void traversal(TreeNode* root, int depth) {
        if (!root) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 1);
        return res;
    }
};
```
