# 从前序与中序遍历序列构造二叉树

[Leetcode题目链接](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)。

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
    unordered_map<int, int> pos;
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) return nullptr;
        auto root = new TreeNode(preorder[preorderLeft]);
        int index = pos[root->val];
        root->left = treeBuilder(preorder, inorder, 
        preorderLeft + 1, preorderLeft + 1 + index - 1 - inorderLeft, 
        inorderLeft, index - 1);
        root->right = treeBuilder(preorder, inorder, 
        preorderLeft + 1 + index - 1 - inorderLeft + 1, preorderRight, 
        index + 1, inorderRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int treeSize = inorder.size();
        for (int i = 0; i < treeSize; i++) pos[inorder[i]] = i;
        return treeBuilder(preorder, inorder, 0, treeSize - 1, 0, treeSize - 1);
    }
};
```
