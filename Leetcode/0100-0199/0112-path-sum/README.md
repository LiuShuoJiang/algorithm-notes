# Path Sum

[Link](https://leetcode.com/problems/path-sum/description/)

## Description

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A leaf is a node with no children.

Example 1:

- Input: `root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22`
- Output: `true`
- Explanation: The root-to-leaf path with the target sum is shown.

![example 1](./pathsum1.jpg)

Example 2:

- Input: `root = [1,2,3], targetSum = 5`
- Output: `false`
- Explanation:
    - There two root-to-leaf paths in the tree:
        - `(1 --> 2)`: The sum is `3`.
        - `(1 --> 3)`: The sum is `4`.
    - There is no root-to-leaf path with `sum = 5`.

Example 3:

- Input: `root = [], targetSum = 0`
- Output: `false`
- Explanation: Since the tree is empty, there are no root-to-leaf paths.

Constraints:

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Solution

### Way 1 (Recursion)

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right && targetSum == root->val) return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
```

- Time complexity: $O(N)$, where $N$ is the number of nodes in the tree;
- Space complexity: $O(H)$, where $H$ is the height of the tree (Worst: $O(N)$; Best: $O(\log N)$ ).

### Way 2 (Pre-order)

```C++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, root->val));
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (!(node.first)->left && !(node.first)->right && targetSum == node.second) return true;
            if ((node.first)->right)
                stk.push(make_pair((node.first)->right, node.second + (node.first)->right->val));
            if ((node.first)->left)
                stk.push(make_pair((node.first)->left, node.second + (node.first)->left->val));
        }
        return false;
    }
};
```

### Way 3 (Level-order)

```C++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (!t.first->left && !t.first->right && t.second == targetSum) return true;
            if (t.first->left) q.push(make_pair(t.first->left, t.first->left->val + t.second));
            if (t.first->right) q.push(make_pair(t.first->right, t.first->right->val + t.second));
        }
        return false;
    }
};
```

- Time complexity: $O(N)$;
- Space complexity: $O(N)$.
