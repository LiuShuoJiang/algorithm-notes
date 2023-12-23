# Validate Binary Search Tree

[Link](https://leetcode.com/problems/validate-binary-search-tree/description/)

## Description

Given the `root` of a binary tree, determine if it is a valid binary search tree (BST).

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys ***less than*** the node's key.
- The right subtree of a node contains only nodes with keys ***greater than*** the node's key.
- Both the left and right subtrees must also be binary search trees.

(A **subtree** of `treeName` is a tree consisting of a node in treeName and all of its descendants.)

Example 1:

- Input: `root = [2,1,3]`
- Output: `true`

Example 2:

- Input: `root = [5,1,4,null,null,3,6]`
- Output: `false`
- Explanation: The root node's value is `5` but its right child's value is `4`.

Constraints:

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

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
    vector<int> inorder = {};
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1]) return false;
        }
        return true;
    }
};
```

***Idea and Algorithm***:

- The idea behind this approach is based on the property of BSTs: ***an in-order traversal of a BST produces a sorted list of values in ascending order***.
- The `traversal` function recursively visits all nodes in the tree in in-order fashion (left, root, right) and adds their values to the `inorder` vector.
- After the traversal, the `isValidBST` function checks if the `inorder` vector is sorted in strictly ascending order. If not, the tree is not a valid BST.

***Complexity***:

- Time Complexity: The time complexity is $O(N)$, where $N$ is the number of nodes in the tree. This is because each node is visited exactly once to build the `inorder` vector, and then we iterate through the vector once to check if it is sorted.
- Space Complexity: The space complexity is $O(N)$, mainly due to the space used by the `inorder` vector, which can potentially hold all $N$ node values in the tree. Additionally, the space complexity of the recursion stack in the worst case (a skewed tree) can be $O(N)$. In the best case (a balanced tree), it would be $O(\log N)$, but the dominant factor is the space for the `inorder` vector.

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
    // The traversal function checks if the subtree rooted at 'node' is a valid BST.
    bool traversal(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        // Base case: An empty node is always a valid BST.
        if (!node) return true;

        // Check if the current node's value violates the BST properties.
        // If 'minNode' is not null and the current node's value is not greater than 'minNode',
        // then it's not a valid BST.
        if (minNode && node->val <= minNode->val) return false;

        // Similarly, if 'maxNode' is not null and the current node's value is not less than 'maxNode',
        // then it's not a valid BST.
        if (maxNode && node->val >= maxNode->val) return false;

        // Recursively check the left and right subtrees, updating the constraints.
        // For the left subtree, the current node becomes the new 'maxNode', and
        // for the right subtree, it becomes the new 'minNode'.
        return traversal(node->left, minNode, node) && traversal(node->right, node, maxNode);
    }
public:
    // Public interface to start the BST validation from the root.
    bool isValidBST(TreeNode* root) {
        // Initiate the traversal with null pointers for minNode and maxNode,
        // as the root has no constraints initially.
        return traversal(root, nullptr, nullptr);
    }
};
```

- Time Complexity: The time complexity is $O(N)$, where $N$ is the number of nodes in the tree. This is because we visit each node exactly once during the traversal.
- Space Complexity: The space complexity is $O(H)$, where $H$ is the height of the tree. This is due to the recursive stack used for DFS. In the worst case (a skewed tree), the height of the tree can be $O(N)$, leading to $O(N)$ space complexity. In the best case (a balanced tree), it would be $O(\log N)$.

### Way 3

```C++
class Solution {
private:
    TreeNode *pre = nullptr;  // Pointer to keep track of the previously visited node in in-order traversal.

public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;  // Base case: An empty tree is a valid BST.

        // Recursively check the left subtree.
        bool l = isValidBST(root->left);
        
        // Check if the current node's value is greater than the previous node's value.
        if (pre && pre->val >= root->val) return false;
        pre = root;  // Update 'pre' to the current node.

        // Recursively check the right subtree.
        bool r = isValidBST(root->right);
        
        // The tree is a valid BST if both left and right subtrees are valid BSTs.
        return l && r;
    }
};
```

***Idea and Algorithm***:

- Similar to an in-order traversal, this approach visits nodes in a left-root-right order.
- The difference lies in how it uses the `pre` pointer to remember the last node visited (in the in-order sequence).
- When visiting each node, it checks if its value is greater than the value of the `pre` node. If not, the BST property is violated, and it returns `false`.
- After checking, it updates `pre` to the current node and then proceeds to the right subtree.
- Finally, the tree is a valid BST if both the left and right subtree checks return `true`.

***Complexity***:

- Time Complexity: The time complexity is $O(N)$, where $N$ is the number of nodes in the tree. Despite the recursive calls, each node is visited exactly once.
- Space Complexity: The space complexity is $O(H)$, where $H$ is the height of the tree. This space is used by the recursion stack. In the worst case (a skewed tree), $H$ can be $O(N)$. In a balanced tree, $H$ would be $O(\log N)$. The `pre` pointer does not add significant space complexity, as it's just a single additional pointer.
