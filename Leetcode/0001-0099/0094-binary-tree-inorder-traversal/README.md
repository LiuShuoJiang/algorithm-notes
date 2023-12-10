# Binary Tree Inorder Traversal

[Link](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

## Description

Given the `root` of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

- Input: `root = [1,null,2,3]`
- Output: `[1,3,2]`

Example 2:

- Input: `root = []`
- Output: `[]`

Example 3:

- Input: `root = [1]`
- Output: `[1]`

Constraints:

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Solution

### Recursive Method

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
    void inOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};
```

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                auto t = stk.top();
                stk.pop();
                res.push_back(t->val);
                root = t->right;
            }
        }
        return res;
    }
};
```

Code with comments:

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // A stack to hold TreeNode pointers during traversal.
        stack<TreeNode*> stk;

        // A vector to store the traversal result.
        vector<int> res;

        // Continue until all nodes are processed.
        while (root || !stk.empty()) {
            if (root) {
                // If the current node (root) is not null, push it onto the stack
                // and move to its left child.
                stk.push(root);
                root = root->left;
            } else {
                // If the current node is null, it means we have reached the leftmost node.
                // Pop the top node from the stack, process it, and move to its right child.
                auto t = stk.top();
                stk.pop();
                res.push_back(t->val);  // Process the node.
                root = t->right;        // Move to the right child.
            }
        }
        return res;
    }
};
```

***Steps***:

1. **Initialize a Stack and Result Vector:** The stack is used to track the nodes, and the result vector is for storing the values in the inorder sequence.
2. **Traversing the Tree:**
      - The algorithm continues until all nodes are processed, indicated by both the current node being null and the stack being empty.
      - If the current node (`root`) is not null, it is pushed onto the stack, and the algorithm moves to its left child. This step is repeated until the leftmost node is reached.
      - If the current node is null, the algorithm backtracks by popping a node from the stack. This node's value is then added to the result vector, as it's the node being "visited" in the inorder sequence. The algorithm then proceeds to the right child of this node.
3. **Inorder Sequence Completion:** The process continues until the stack is empty, ensuring that all nodes are visited in the "left, root, right" sequence.

***Time Complexity Analysis***:

- $O(n)$: The time complexity is $O(n)$ as each node in the tree is visited exactly once.

***Space Complexity Analysis***:

- **Best Case (Balanced Tree):** $O(\log n)$, where $n$ is the number of nodes. In a balanced tree, the stack's size will be proportional to the tree's height.
- **Worst Case (Skewed Tree):** $O(n)$, in the case of a skewed tree, like a linked list, where the stack can potentially hold all the nodes.
- **Average Case:** Generally between $O(\log n)$ and $O(n)$, depending on the tree's structure.
