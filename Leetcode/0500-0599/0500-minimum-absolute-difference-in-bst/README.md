# Minimum Absolute Difference in BST

[Link](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

## Description

Given the `root` of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

- Input: `root = [4,2,6,1,3]`
- Output: `1`

Example 2:

- Input: `root = [1,0,48,null,null,12,49]`
- Output: `1`

Constraints:

- The number of nodes in the tree is in the range `[2, 10^4]`.
- `0 <= Node.val <= 10^5`

## Solution

### Way 1

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
    vector<int> inorder;
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int minVal = INT_MAX;
        for (int i = 1; i < inorder.size(); i++) {
            minVal = min(minVal, inorder[i] - inorder[i - 1]);
        }
        return minVal;
    }
};
```

### Way 2

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

- Time complexity: $O(n)$;
- Space complexity (worst): $O(n)$.
