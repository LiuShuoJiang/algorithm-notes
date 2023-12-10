# Invert Binary Tree

[Link](https://leetcode.com/problems/invert-binary-tree/description/)

## Description

Given the `root` of a binary tree, invert the tree, and return its root.

Example 1:

- Input: `root = [4,2,7,1,3,6,9]`
- Output: `[4,7,2,9,6,3,1]`

Example 2:

- Input: `root = [2,1,3]`
- Output: `[2,3,1]`

Example 3:

- Input: `root = []`
- Output: `[]`

Constraints:

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

### Iterative Solution

#### Way 1 (Pre-order)

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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *curr = root;

        while (curr || !stk.empty()) {
            if (curr) {
                swap(curr->left, curr->right);
                stk.push(curr);
                curr = curr->left;
            } else {
                auto t = stk.top();
                stk.pop();
                curr = t->right;
            }
        }
        return root;
    }
};
```

#### Way 2 (Level-order)

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            swap(curr->left, curr->right);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return root;
    }
};
```

***Explanation***:

1. **Check for Empty Tree**: If the root is null, the tree is empty, and we return `nullptr`.
2. **Queue Initialization**: We use a queue to keep track of nodes. Initially, it contains only the root.
3. **Tree Traversal**: We use a loop to process nodes until the queue is empty. For each node:
      - Swap its left and right children.
      - Enqueue its non-null children for subsequent processing.

***Complexity Analysis***:

- **Time Complexity**: $O(n)$, where $n$ is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**: $O(m)$, where m is the maximum number of nodes at any level in the input tree. In the worst case, the space complexity can be $O(n)$ (consider a perfectly balanced tree).


