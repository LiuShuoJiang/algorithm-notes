# Binary Tree Postorder Traversal

[Link](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

## Description

Given the `root` of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

- Input: `root = [1,null,2,3]`
- Output: `[3,2,1]`

Example 2:

- Input: `root = []`
- Output: `[]`

Example 3:

- Input: `root = [1]`
- Output: `[1]`

Constraints:

- The number of the nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Solution

### Recursive Method

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

### Iterative Method
