# Sum of Left Leaves

[Link](https://leetcode.com/problems/sum-of-left-leaves/description/)

## Description

Given the `root` of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `24`
- Explanation: There are two left leaves in the binary tree, with values `9` and `15` respectively.

Example 2:

- Input: `root = [1]`
- Output: `0`

Constraints:

- The number of nodes in the tree is in the range `[1, 1000]`.
- `-1000 <= Node.val <= 1000`

## Solution

### Recursive Solution (Post-order)

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

### Iterative Solution

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
        stack<TreeNode*> stk;
        auto curr = root;
        int res = 0;
        while (curr || !stk.empty()) {
            if (curr) {
                if (curr->left && !curr->left->left && !curr->left->right) res += curr->left->val;
                stk.push(curr);
                curr = curr->left;
            } else {
                auto t = stk.top();
                stk.pop();
                curr = t->right;
            }
        }
        return res;
    }
};
```
