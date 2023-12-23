# Search in a Binary Search Tree

[Link](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)

## Description

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

Example 1:

- Input: `root = [4,2,7,1,3], val = 2`
- Output: `[2,1,3]`

Example 2:

- Input: `root = [4,2,7,1,3], val = 5`
- Output: `[]`

Constraints:

- The number of nodes in the tree is in the range `[1, 5000]`.
- `1 <= Node.val <= 10^7`
- `root` is a binary search tree.
- `1 <= val <= 10^7`

## Solution

### Recursive Solution

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};
```

Another way of writing:

```C++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        TreeNode *res = nullptr;
        if (root->val > val) res = searchBST(root->left, val);
        if (root->val < val) res = searchBST(root->right, val);
        return res;
    }
};
```

- Time complexity (worst): $O(n)$;
- Space complexity (worst): $O(n)$ for recursion stack.

### Iterative Solution

```C++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while (curr && curr->val != val) {
            if (curr->val > val) curr = curr->left;
            else curr = curr->right;
        }
        return curr;
    }
};
```

- Time complexity (worst): $O(n)$;
- Space complexity: $O(1)$.
