# Merge Two Binary Trees

[Link](https://leetcode.com/problems/merge-two-binary-trees/description/)

## Description

You are given two binary trees `root1` and `root2`.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

Example 1:

- Input: `root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]`
- Output: `[3,4,5,5,4,null,7]`

Example 2:

- Input: `root1 = [1], root2 = [1,2]`
- Output: `[2,2]`

Constraints:

- The number of nodes in both trees is in the range `[0, 2000]`.
- `-10^4 <= Node.val <= 10^4`

## Solution

### Recursive Solution (Pre-order)

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
```

- Time complexity: $O(N)$;
- Space complexity: $O(h)$, where $h$ is the height of the tree.

Another way of writing (without modifying the original tree's structure):

```C++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* node = new TreeNode(0);
        node->val = root1->val + root2->val;
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};
```

### Iterative Solution (Level-order)

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});
        
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            t.first->val += t.second->val;
            
            if (t.first->left && t.second->left) 
                q.push({t.first->left, t.second->left});
            if (t.first->right && t.second->right) 
                q.push({t.first->right, t.second->right});
            
            if (!t.first->left && t.second->left) 
                t.first->left = t.second->left;
            if (!t.first->right && t.second->right) 
                t.first->right = t.second->right;
        }
        return root1;
    }
};
```
