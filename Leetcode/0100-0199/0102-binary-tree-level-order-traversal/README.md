# Binary Tree Level Order Traversal

[Link](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

## Description

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `[[3],[9,20],[15,7]]`

Example 2:

- Input: `root = [1]`
- Output: `[[1]]`

Example 3:

- Input: `root = []`
- Output: `[]`

Constraints:

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`

## Solution

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            vector<int> level;
            
            while (len--) {
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            res.push_back(level);
        }
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // To store the final result
        queue<TreeNode*> q; // Queue to help in BFS

        // Check if the root is not null
        if (root) q.push(root);
        
        // Loop until the queue is empty
        while (!q.empty()) {
            int len = q.size(); // Current level size
            vector<int> level; // To store nodes at the current level
            
            // Process nodes of the current level
            while (len--) {
                auto t = q.front(); // Get the front node in the queue
                q.pop(); // Remove the node from the queue
                level.push_back(t->val); // Add the node's value to the current level

                // Add child nodes to the queue for next level
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            // Add the current level to the final result
            res.push_back(level);
        }
        return res; // Return the final result
    }
};
```

***Algorithm Analysis***:

1. **Initialize Data Structures**:
      - Create an empty queue (`q`) that will be used to store the nodes of the tree at each level.
      - Create an empty list (`res`) that will eventually hold the level order traversal result. This list will contain sublists, each representing one level of the tree.
2. **Start with the Root Node**:
      - If the root node of the tree is not `nullptr`, add it to the queue. This step initiates the process of level order traversal.
3. **Traverse the Tree Level by Level**:
      - While the queue is not empty, perform the following steps. Each iteration of this loop corresponds to processing one level of the tree:
          - Determine the number of nodes at the current level. This is given by the current size of the queue (`int len = q.size()`).
          - Create an empty list (`level`) that will store the values of the nodes at this current level.
4. **Process Nodes at the Current Level**:
      - Repeat the following steps `len` times (the number of nodes at the current level):
          - Remove the front node from the queue and refer to it as `t`.
          - Add the value of `t` to the `level` list.
          - If `t` has a left child, add the left child to the queue.
          - If `t` has a right child, add the right child to the queue.
      - After processing all nodes at the current level, add the `level` list to the `res` list.
5. **Repeat for All Levels**:
      - The while loop continues until the queue is empty. When the queue is empty, it means that all levels of the tree have been processed.
6. **Return the Result**:
      - After the while loop completes, `res` contains the level order traversal of the tree, and is returned as the result.

***Complexity Analysis***:

- Time Complexity: The time complexity of this algorithm is $O(N)$, where $N$ is the number of nodes in the tree. This is because every node in the tree is processed exactly once.
- Space Complexity: The space complexity of this algorithm is $O(N)$ as well, in the worst case when the tree is completely unbalanced (e.g., every node has only one child), the queue will hold all nodes. For a balanced tree, the maximum size of the queue will be proportional to the width of the tree, which can be $O(N)$ in the worst case.
