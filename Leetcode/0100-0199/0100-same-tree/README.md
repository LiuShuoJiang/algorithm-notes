# Same Tree

[Link](https://leetcode.com/problems/same-tree/description/)

## Description

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

- Input: `p = [1,2,3], q = [1,2,3]`
- Output: `true`

Example 2:

- Input: `p = [1,2], q = [1,null,2]`
- Output: `false`

Example 3:

- Input: `p = [1,2,1], q = [1,1,2]`
- Output: `false`

Constraints:

- The number of nodes in both trees is in the range `[0, 100]`.
- `-10^4 <= Node.val <= 10^4`

## Solution

### Iterative Method

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both trees are null, they are identical
        if (!p && !q) return true;
        // If only one tree is null or the values are different, they are not identical
        if (!p || !q || p->val != q->val) return false;
        // Recursively check if the left and right subtrees are identical
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

- Time complexity: $O\left( \min \left( n,m \right) \right)$, where $n$ and $m$ are the number of nodes in the two trees, respectively. This is because we need to visit each node once in order to compare their values. In the worst case, where both trees have the same number of nodes, the time complexity would be $O(n)$;
- Space complexity: $O\left( \min \left( h_1,h_2 \right) \right)$, where $h_1$ and $h_2$ are the heights of the two trees, respectively. This is because the space used by the recursive stack is determined by the height of the smaller tree. In the worst case, where one tree is significantly larger than the other, the space complexity would be closer to $O(n)$ or $O(m)$, depending on which tree is larger.

### Tree Hashing

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
    string computeHash(TreeNode* node) {
        if (!node) return "NULL";
        string leftHash = computeHash(node->left);
        string rightHash = computeHash(node->right);
        return "(" + to_string(node->val) + leftHash + rightHash + ")";
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return computeHash(p) == computeHash(q);
    }
};
```
