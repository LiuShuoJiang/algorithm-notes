# Find Bottom Left Tree Value

[Link](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

## Description

Given the `root` of a binary tree, return the leftmost value in the last row of the tree.

Example 1:

- Input: `root = [2,1,3]`
- Output: `1`

Example 2:

- Input: `root = [1,2,3,4,null,5,6,null,null,7]`
- Output: `7`

Constraints:

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

## Solution

## Recursive Solution

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

## Iterative Solution (Level-order)

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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                if (i == 0) res = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
```
