# Binary Tree Preorder Traversal

[Link](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

## Description

Given the `root` of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

- Input: `root = [1,null,2,3]`
- Output: `[1,2,3]`

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
    void preOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};
```

### Iterative Method

#### Way 1

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res{};
        if (root == nullptr) return res;
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return res;
    }
};
```

The right child is pushed before the left child. This is crucial because stacks are LIFO (Last In, First Out) structures, meaning the left child will be popped and processed first in the next iteration, maintaining the correct order for preorder traversal: root, left, right.

#### Way 2 (Preferred)

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root || !stk.empty()) {
            if (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            } else {
                auto t = stk.top();
                stk.pop();
                root = t->right;
            }
        }
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // A stack to hold the TreeNode pointers during traversal.
        stack<TreeNode*> stk;

        // A vector to store the result of the preorder traversal.
        vector<int> res;

        // The loop continues as long as there are nodes to process. This is determined
        // by checking if either the current node (root) is not null or the stack is not empty.
        while (root || !stk.empty()) {

            // If the current node (root) is not null, it means there is a node to process.
            if (root) {
                // Add the value of the current node to the result as per preorder traversal.
                res.push_back(root->val);

                // Push the current node to the stack so that we can return to it after
                // traversing its left subtree.
                stk.push(root);

                // Move to the left child of the current node.
                root = root->left;
            } 
            // If the current node is null, it means we have reached the end of a subtree.
            else {
                // Retrieve the most recently visited node from the stack.
                auto t = stk.top();
                stk.pop();

                // Move to the right child of the retrieved node.
                root = t->right;
            }
        }
        return res;
    }
};
```

***Detailed Steps of the Algorithm***:

1. **Initialize a Stack**: A stack is used to keep track of nodes. The stack is initially empty.
2. **Start from the Root Node**: The traversal begins from the root node of the binary tree.
3. **Process the Current Node**: If the current node is not null, several steps are followed:
      1. The value of the current node is added to the result list. This is because, in preorder traversal, the node is processed before its children.
      2. The current node is pushed onto the stack. This is done to keep a reference to the node, so we can later access its right child.
      3. The current node is then moved to its left child.
4. **Backtracking using the Stack**: If the current node is null (which happens when there's no left child), the algorithm 'backtracks' by popping a node from the stack. This node is the parent of the previously visited node.
5. **Visit the Right Child**: After backtracking to the parent node, the algorithm then proceeds to visit the right child of that node.
6. **Repeat the Process**: Steps 3 to 5 are repeated until there are no more nodes to visit, which is determined by both the current node being null and the stack being empty.

***Time Complexity Analysis***:

1. **Best and Average Case:** $O(n)$ where $n$ is the number of nodes in the binary tree. Each node is visited exactly once.
2. **Worst Case:** The worst-case time complexity is also $O(n)$ as even in the case of a skewed tree (like a linked list), each node is visited once.

***Space Complexity Analysis***:

1. **Best Case (Completely Balanced Tree):** $O(\log n)$, where $n$ is the number of nodes. In a balanced tree, the stack size will be proportional to the height of the tree, which is $\log n$.
2. **Average Case:** The average space complexity is $O(\log n)$ for the same reason as above. However, the tree might not be perfectly balanced, so the average height could be slightly more than $\log n$.
3. **Worst Case (Skewed Tree):** $O(n)$. In the worst case (like a linked list), the stack will hold all the nodes of one branch of the tree, which can be $n$ in the case of a skewed tree.

