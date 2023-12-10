# Binary Tree Postorder Traversal

[Link](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

## Description

Given the `root` of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

- Input: `root = [1,null,2,3]`
- Output: `[3,2,1]`

Example 2:

- Input: `root = []`
- Output: `[]`

Example 3:

- Input: `root = [1]`
- Output: `[1]`

Constraints:

- The number of the nodes in the tree is in the range `[0, 100]`.
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
    void postOrder(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if (root == nullptr) return res;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

***Breakdown***:

1. **Initialization and Base Case Check:**
      - The solution begins by initializing a stack (`stk`) and a result vector (`res`).
      - It checks if the `root` is `nullptr`, returning an empty `res` if true. This handles the edge case of an empty tree.
2. **Starting the Traversal:**
      - The `root` node is pushed onto the stack. This is the starting point of the traversal.
3. **Iterative Traversal:**
      - The traversal occurs inside a `while` loop, continuing as long as the stack is not empty.
      - In each iteration, the top node of the stack is popped and its value is added to `res`.
      - Then, if the left child of this node exists, it is pushed onto the stack, followed by the right child if it exists.
4. **Order of Pushing Children:**
      - The left child is pushed before the right child. This is crucial because stacks are LIFO (Last In, First Out) structures. By pushing the right child last, it ensures that the right child will be processed after the left child in subsequent iterations.
5. **Reverse the Result:**
      - After the traversal, the `res` vector, which is in root-right-left order, is reversed to achieve the left-right-root order of postorder traversal.

#### Way 2

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root || !stk.empty()) {
            if (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->right;
            } else {
                auto t = stk.top();
                stk.pop();
                root = t->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // A stack to hold TreeNode pointers during traversal.
        stack<TreeNode*> stk;

        // A vector to store the traversal result.
        vector<int> res;

        // Continue until all nodes are processed.
        while (root || !stk.empty()) {
            if (root) {
                // Instead of processing the current node, push its value to the result.
                // This is the reverse of the postorder.
                res.push_back(root->val);

                // Push the current node to the stack for later processing.
                stk.push(root);

                // Move to the right child, opposite of the usual left move in postorder.
                root = root->right;
            } else {
                // Retrieve the most recently visited node.
                auto t = stk.top();
                stk.pop();

                // Move to the left child.
                root = t->left;
            }
        }

        // Reverse the result to convert it into the correct postorder sequence.
        reverse(res.begin(), res.end());

        return res;
    }
};
```

***Steps of the Solution***:

1. **Initialize a Stack and Result Vector:** A stack and a result vector are initialized to manage the traversal and store the results, respectively.
2. **Iterative Traversal:**
      - If the current node (`root`) is not null, its value is added to the `res` vector (mimicking postorder but in reverse).
      - The current node is then pushed to the stack, and the traversal moves to the right child (not the left, as would be typical in postorder).
      - If `root` is null, which indicates the end of a branch, the algorithm backtracks using the stack, retrieving the last visited node and moving to its left child.
3. **Reverse the Result:** After the traversal, the `res` vector, which is in root-right-left order, is reversed to align with the left-right-root order of postorder traversal.

***Time Complexity Analysis***:

- $O(n)$: Each node in the tree is visited exactly once, leading to a time complexity of $O(n)$, where $n$ is the number of nodes in the tree.

***Space Complexity Analysis***:

- **Best Case (Balanced Tree):** $O(\log n)$, where the height of the tree is $\log n$ and the stack's size will be proportional to the tree's height.
- **Worst Case (Skewed Tree):** $O(n)$, where the tree is like a linked list, and the stack can potentially hold all the nodes.
- **Average Case:** Generally between $O(\log n)$ and $O(n)$, depending on the tree's structure.

#### Way 3

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == nullptr) return postOrder;

        stack<TreeNode*> stk;
        TreeNode *curr = root;
        TreeNode *lastVisited = nullptr;

        while (curr || ! stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                TreeNode *peekNode = stk.top();
                if (peekNode->right && peekNode->right != lastVisited) {
                    curr = peekNode->right;
                } else {
                    stk.pop();
                    postOrder.push_back(peekNode->val);
                    lastVisited = peekNode;
                }
            }
        }
        return postOrder;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Vector to store the postorder traversal
        vector<int> postOrder;
        // If the root is null, return an empty vector
        if (root == nullptr) return postOrder;

        // Stack to hold the nodes during the traversal
        stack<TreeNode*> stk;
        // 'curr' will point to the current node being processed
        TreeNode *curr = root;
        // 'lastVisited' keeps track of the last visited node
        TreeNode *lastVisited = nullptr;

        // Continue until all nodes are processed
        while (curr || !stk.empty()) {
            if (curr) {
                // If the current node is not null, push it onto the stack and go to its left child
                stk.push(curr);
                curr = curr->left;
            } else {
                // Peek at the node at the top of the stack without removing it
                TreeNode *peekNode = stk.top();
                // If the right child exists and hasn't been visited yet, go to the right child
                if (peekNode->right && peekNode->right != lastVisited) {
                    curr = peekNode->right;
                } else {
                    // If there is no right child or it's already visited, then process this node
                    stk.pop(); // Remove the node from the stack
                    postOrder.push_back(peekNode->val); // Add the node's value to the result vector
                    lastVisited = peekNode; // Mark this node as visited
                }
            }
        }
        return postOrder; // Return the postorder traversal
    }
};
```

***Explanation of the Algorithm***:

1. **Initialization**: The algorithm starts by initializing a vector `postOrder` to store the result of the postorder traversal. A stack `stk` is used to keep track of nodes, and two pointers `curr` and `lastVisited` are initialized.
2. **Traversal Loop**: The while loop continues as long as there are unprocessed nodes, indicated by either `curr` not being null or the stack not being empty.
3. **Left Subtree Processing**: If `curr` is not null, it means we are going down the left subtree. The current node is pushed onto the stack, and we move `curr` to its left child.
4. **Right Subtree and Node Processing**: If `curr` is null, it means we have reached a leaf or are backtracking. We then peek at the top of the stack. If the right child of the peeked node exists and hasn't been visited, we set `curr` to this right child. Otherwise, it's time to visit the peeked node: we pop it from the stack, add its value to `postOrder`, and mark it as `lastVisited`.
5. **Completion**: Once all nodes are processed, the `postOrder` vector contains the elements in postorder traversal order.
