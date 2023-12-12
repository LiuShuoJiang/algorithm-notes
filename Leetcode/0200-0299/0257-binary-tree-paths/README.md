# Binary Tree Paths

[Link](https://leetcode.com/problems/binary-tree-paths/description/)

## Description

Given the `root` of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

- Input: `root = [1,2,3,null,5]`
- Output: `["1->2->5","1->3"]`

Example 2:

- Input: `root = [1]`
- Output: `["1"]`

Constraints:

- The number of nodes in the tree is in the range `[1, 100]`.
- `-100 <= Node.val <= 100`

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
private:
    void traversal(TreeNode* curr, vector<int>& path, vector<string>& result) {
        path.push_back(curr->val);
        /*
        The base case of the recursion checks if the current node is a leaf node 
        (both left and right children are null).
        If it's a leaf, the code constructs a string representing the path from the root to this leaf 
        and adds it to result.
        */
        if (!curr->left && !curr->right) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        /*
        If the current node has a left child, the function is recursively called for the left child. 
        After returning from the left child, path.pop_back() is called 
        to remove the last element, implementing backtracking.
        */
        if (curr->left) {
            traversal(curr->left, path, result);
            path.pop_back();
        }
        /*
        Similarly, if there's a right child, the function is recursively called for it, 
        followed by a pop_back() for backtracking.
        */
        if (curr->right) {
            traversal(curr->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        traversal(root, path, res);
        return res;
    }
};
```

- Time Complexity: $O(N)$, where $N$ is the number of nodes in the tree. Each node is visited exactly once in the traversal.
- Space Complexity: $O(H)$, where $H$ is the height of the tree. This is due to the space taken up by the recursion stack. In the worst case (a skewed tree), it could become $O(N)$, but in a balanced tree, it's $O(\log N)$.

***Recursion and Backtracking in the Context of Binary Tree Traversal***:

**Recursion** is a method of solving problems where a function calls itself as a subroutine. This allows the function to be repeated several times, as it can call itself during its execution. In the code, the `traversal` function is recursive. Here's how it works:

1. **Initial Call**: The `traversal` function is initially called with the root node of the tree.
2. **Recursive Calls**: Inside the function, if the current node (`curr`) has a left or right child, the function calls itself (`traversal`) for these children.

This process creates a chain of function calls, each dealing with a smaller part of the tree (either the left or right subtree of the current node).

**Backtracking** is a general algorithmic technique that considers searching every possible combination in order to solve a computational problem. In the context of tree traversal, it involves retracting one step back in the tree when you reach a leaf or a dead end, and then exploring other paths.

Here's how backtracking is implemented:

1. **Path Construction**: As the recursion goes deeper into the tree, the path from the root to the current node is constructed by adding nodes to the `path` vector.
2. **Leaf Node Reached**: When a leaf node is reached (no left or right child), a complete root-to-leaf path has been found, and this path is recorded.
3. **Backtracking Step**: After recording the path or if a node doesn't have a left or right child, the function backtracks by removing the last element from the `path` vector (`path.pop_back()`). This step is crucial as it effectively removes the current node from the path, reverting the path to the state it was in before the current node was added.
4. **Continuing the Traversal**: The function then returns to its caller, which is the previous step in the path. The caller then continues to explore other branches of the tree (e.g., the right child if the left child was explored first).

Example: Suppose we have a binary tree like this:

```
    1
   / \
  2   3
```

- Start at root (1). `path = [1]`.
- Go to left child (2). `path = [1, 2]`.
- 2 is a leaf node, so add `1->2` to `result`.
- **Backtrack**: Remove 2 from path. `path = [1]`.
- Go to right child (3). `path = [1, 3]`.
- 3 is a leaf node, so add `1->3` to `result`.
- **Backtrack**: Remove 3 from path. `path = [1]`.
- All paths explored, function ends.

