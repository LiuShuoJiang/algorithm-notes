# Symmetric Tree

[Link](https://leetcode.com/problems/symmetric-tree/description/)

## Description

Given the `root` of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

- Input: `root = [1,2,2,3,4,4,3]`
- Output: `true`

Example 2:

- Input: `root = [1,2,2,null,3,null,3]`
- Output: `false`

Constraints:

- The number of nodes in the tree is in the range `[1, 1000]`.
- `-100 <= Node.val <= 100`

## Solution

### Recursive Solution (Post-order)

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
    bool compare(TreeNode* lNode, TreeNode* rNode) {
        if (!lNode && !rNode) return true;
        if (!lNode || !rNode || lNode->val != rNode->val) return false;
        return compare(lNode->left, rNode->right) && compare(lNode->right, rNode->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};
```

Code with comments:

```C++
class Solution {
public:
    // A helper function to compare two nodes.
    bool compare(TreeNode* lNode, TreeNode* rNode) {
        // If both nodes are null, they are symmetric.
        if (!lNode && !rNode) return true;

        // If one of the nodes is null or their values are not equal, they are not symmetric.
        if (!lNode || !rNode || lNode->val != rNode->val) return false;

        // Recursively compare the left child of lNode with the right child of rNode
        // and the right child of lNode with the left child of rNode.
        return compare(lNode->left, rNode->right) && compare(lNode->right, rNode->left);
    }

    // Main function to check if the tree is symmetric.
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric. (optional)
        if (!root) return true;

        // Check if the left subtree and right subtree are symmetric.
        return compare(root->left, root->right);
    }
};
```

***Algorithm Idea and Steps***:

1. **Symmetry Definition**: A tree is symmetric if the left subtree is a mirror reflection of the right subtree. This means each node's left child in the left subtree must be equal to the right child of the corresponding node in the right subtree, and vice versa.
2. **Recursive Approach**: The `compare` function is a recursive function that takes two nodes (`lNode` and `rNode`) as arguments and checks whether they are mirror images of each other.
3. **Base Cases**:
    - If both nodes are null, they are symmetric (mirror images of each other).
    - If one is null and the other is not, or their values are different, they are not symmetric.
4. **Recursive Calls**:
    - The function recursively checks two pairs of nodes:
        - The left child of `lNode` and the right child of `rNode`.
        - The right child of `lNode` and the left child of `rNode`.
5. **Starting the Check**: The `isSymmetric` function starts the process by calling `compare` with the left and right children of the root.

***Complexity Analysis***:

- Time Complexity: $O(n)$, where $n$ is the number of nodes in the tree. Each node in the tree is visited once;
- Space Complexity: $O(h)$, where $h$ is the height of the tree. This is due to the recursive stack. In the worst case (a skewed tree), this can become $O(n)$, but in the best case (a balanced tree), it's $O(\log n)$.

### Iterative Solution

#### Using Stack

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        
        while (!stk.empty()) {
            TreeNode *leftNode = stk.top(); stk.pop();
            TreeNode *rightNode = stk.top(); stk.pop();
            
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
            
            stk.push(leftNode->left);
            stk.push(rightNode->right);
            stk.push(leftNode->right);
            stk.push(rightNode->left);
        }
        return true;
    }
};
```

***Algorithm Idea and Steps***:

1. **Initialization**: Start by pushing the left and right children of the root onto the stack.
2. **Iterative Process**:
    - Pop two nodes from the stack and compare them.
    - If both are null, continue to the next iteration (they are symmetric in this case).
    - If only one is null or their values are different, return false (tree is not symmetric).
3. **Mirrored Order Insertion**:
    - For each pair of nodes, push their children onto the stack in a mirrored order: left child of the first node with the right child of the second node, and right child of the first node with the left child of the second node.
4. **Completion**: If the stack becomes empty and no asymmetry is found, the tree is symmetric.

***Complexity Analysis***:

Time Complexity:

- $O(n)$: Each node is visited exactly once.

Space Complexity:

- $O(n)$ in the worst case: The stack might hold all the nodes at the tree's breadth at its maximum level, which can be up to $\frac{n}{2}$ nodes in a complete binary tree.
- $O(\log n)$ in the best case for a balanced tree: The stack will hold at most a number of nodes proportional to the height of the tree.

#### Using Queue

```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *leftNode = q.front(); q.pop();
            TreeNode *rightNode = q.front(); q.pop();
            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) return false;
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};
```
