# Balanced Binary Tree

[Link](https://leetcode.com/problems/balanced-binary-tree/description/)

## Description

Given a binary tree, determine if it is **height-balanced**.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `true`

Example 2:

- Input: `root = [1,2,2,3,3,null,null,4,4]`
- Output: `false`

Example 3:

- Input: `root = []`
- Output: `true`

Constraints:

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`

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
    int depth(TreeNode* node) {
        if (!node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return (abs(depth(root->left) - depth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
```

- Time complexity: $O(N\log N)$;
- Space complexity: $O(N)$.

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
public:
    bool ans;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int lDepth = dfs(root->left), rDepth = dfs(root->right);
        if (abs(lDepth - rDepth) > 1) ans = false;
        return max(lDepth, rDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        dfs(root);
        return ans;
    }
};
```

***Analysis***:

Depth Calculation and Balance Check (`dfs` Function):

- **Functionality**: The `dfs` function calculates the depth of the tree and simultaneously checks if the tree is balanced.
- **Implementation**:
    - If the current node is null, it returns 0 (base case of recursion).
    - It recursively calculates the depth of the left (`lDepth`) and right (`rDepth`) subtrees.
    - The balance condition is checked by comparing the absolute difference between `lDepth` and `rDepth`. If this difference is greater than 1 at any node, `ans` is set to `false`, indicating that the tree is not balanced.
    - The function returns the maximum depth of either subtree plus 1 (to include the current node).

Overall Check (`isBalanced` Function):

- **Functionality**: This function initiates the DFS and returns the final answer.
- **Implementation**:
    - It initializes `ans` to `true`.
    - It calls `dfs(root)` to perform the depth calculation and balance check.
    - It returns the value of `ans`, which indicates whether the tree is balanced.

***Complexity***:

- **Time Complexity**: $O(N)$, as each node is visited only once.
- **Space Complexity**: $O(N)$ due to the recursion stack. In a skewed tree, the recursion depth could be as deep as the tree.

### Way 3

We use post-order traversal and pruning (bottom to top).

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
    int depth(TreeNode* root) {
        if (!root) return 0;
        int lDepth = depth(root->left);
        if (lDepth == -1) return -1;
        int rDepth = depth(root->right);
        if (rDepth == -1) return -1;
        return (abs(lDepth - rDepth) <= 1) ? (max(lDepth, rDepth) + 1) : -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};
```

Code with comments:

```C++
class Solution {
private:
    // Helper function to compute the depth of the tree.
    // It returns -1 if the tree is not balanced.
    int depth(TreeNode* root) {
        // Base case: an empty node has a depth of 0.
        if (!root) return 0;

        // Compute the depth of the left subtree.
        int lDepth = depth(root->left);
        // If the left subtree is not balanced, propagate -1 upwards.
        if (lDepth == -1) return -1;

        // Compute the depth of the right subtree.
        int rDepth = depth(root->right);
        // If the right subtree is not balanced, propagate -1 upwards.
        if (rDepth == -1) return -1;

        // Check if the current node is balanced.
        // If not balanced, return -1, otherwise return the depth of this node.
        return (abs(lDepth - rDepth) <= 1) ? (max(lDepth, rDepth) + 1) : -1;
    }

public:
    // Main function to check if the tree is balanced.
    bool isBalanced(TreeNode* root) {
        // The tree is balanced if the depth function does not return -1.
        return depth(root) != -1;
    }
};
```

***Explanation***:

- This approach optimizes the process of checking tree balance by integrating the balance check directly into the depth calculation.
- If at any point the tree is found to be unbalanced (i.e., the difference in depth between the left and right subtrees of any node is greater than 1), the function immediately returns -1.
- This early termination prevents unnecessary calculations once an imbalance is detected.

***Comparison***:

- **Compared to the First Solution**: The first solution separately calculated the depth for each node and then checked for balance, leading to a less efficient time complexity. In contrast, this solution combines these steps and uses early termination for efficiency, bringing the complexity down to $O(N)$.
- **Compared to the Second Solution**: The second solution also combined the depth calculation and balance check in one pass but did not use early termination. This current solution improves upon that by immediately stopping further depth calculations once an imbalance is detected, which can potentially reduce the number of recursive calls in certain scenarios.
