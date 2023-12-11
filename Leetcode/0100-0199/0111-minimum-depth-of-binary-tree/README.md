# Minimum Depth of Binary Tree

[Link](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

## Description

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:

- Input: `root = [3,9,20,null,null,15,7]`
- Output: `2`

Example 2:

- Input: `root = [2,null,3,null,4,null,5,null,6]`
- Output: `5`

Constraints:

- The number of nodes in the tree is in the range `[0, 10^5]`.
- `-1000 <= Node.val <= 1000`

## Solution

### Recursive Solution

#### Way 1

The recursion is based on the following ideas:

1. **Base Case**: If the current node (`root`) is `nullptr`, it means we've reached beyond a leaf node, and we return 0. This case handles an empty tree or reaching the end of a branch.
2. **Only Right Child Exists**: If the current node has no left child but has a right child, we recursively find the minimum depth of the right subtree and add 1 (for the current node).
3. **Only Left Child Exists**: If the current node has a left child but no right child, we similarly find the minimum depth of the left subtree and add 1.
4. **Both Children Exist**: If both children exist, we find the minimum depth of both subtrees and take the minimum of these two values, then add 1.

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && root->right) return 1 + minDepth(root->right);
        if (root->left && !root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
```

***Recursive Cases Explained***:

- **Case 1: No Children (Leaf Node)**: If a node is a leaf (no children), the recursion ends, and it returns 1 (the depth of a leaf node is 1).
- **Case 2: One Child**: If a node has only one child, the algorithm only considers the subtree with the child. It ignores the null side as it's not a valid path to a leaf.
- **Case 3: Two Children**: If a node has two children, it compares the depth of both subtrees and takes the smaller one. This ensures we are finding the minimum path to a leaf.

***Complexity Analysis***:

- Time Complexity: The time complexity of this algorithm is $O(N)$, where $N$ is the number of nodes in the tree. This is because, in the worst case, the algorithm needs to visit every node once to determine the minimum depth;
- Space Complexity: The space complexity is $O(H)$, where $H$ is the height of the tree. This is due to the recursive stack. In the worst case (a skewed tree), the space complexity can be $O(N)$, but for a balanced tree, it's $O(\log N)$.

***Additional Insights***:

- **Tail Recursion**: This is not a tail-recursive solution because the recursive call is not the last operation in the function (there is an addition after it).
- **Efficiency**: The solution is efficient as it avoids unnecessary computation by stopping as soon as it finds a leaf node and also handles cases where a node has only one child.
- **Improvement**: In some cases, iterative solutions (like BFS) might be more efficient, especially for finding the minimum depth, as they can stop early once the first leaf is reached.

#### Way 2

Another way of writing:

```C++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        if (root->left) res = min(res, minDepth(root->left) + 1);
        if (root->right) res = min(res, minDepth(root->right) + 1);
        if (res == INT_MAX) res = 1;
        return res;
    }
};
```

***Analysis***:

1. **Base Case**: If the `root` is `nullptr`, the function returns 0, indicating that there is no tree or it has reached the end of a branch.
2. **Initialize `res`**: The variable `res` is initialized to `INT_MAX`, which represents a very high value. This is a common approach in minimum computation problems to ensure that any real result found will be less than this initial value.
3. **Left Subtree**: If there is a left child, the function calculates the minimum depth of the left subtree and updates `res` if this value is smaller than the current `res`.
4. **Right Subtree**: Similarly, if there is a right child, the function does the same for the right subtree.
5. **Leaf Node Handling**: If `res` remains `INT_MAX` after checking both children, it means the current node is a leaf node (since neither left nor right subtree depth was calculated). Thus, `res` is set to 1.
6. **Return Value**: The function returns `res`, which represents the minimum depth from the current node to the nearest leaf node.

### Iterative Solution

```C++
class Solution {
public:
    int minDepth(TreeNode* root) {
        // If the root is null, the tree is empty, so the depth is 0
        if (!root) return 0;

        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root); // Start with the root

        int depth = 0; // Initialize depth

        // Continue until the queue is empty
        while (!q.empty()) {
            int len = q.size(); // Number of nodes at the current level
            depth++; // Increase depth as we move to a new level

            // Iterate over all nodes at the current level
            while (len--) {
                auto node = q.front(); // Get the front node
                q.pop(); // Remove the node from the queue

                // If it's a leaf node, return the current depth
                if (!node->left && !node->right) return depth;

                // Add the left and right children to the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        // Depth of the tree, this line is technically not reachable as the function will return upon finding a leaf
        return depth;
    }
};
```

***Details of the Algorithm***:

- The algorithm performs a breadth-first search (BFS) or level-order traversal on the tree.
- A queue is used to keep track of nodes at each level.
- For each level, all nodes are processed, and their children are added to the queue for the next level.
- The depth is incremented as the algorithm moves to a new level.
- The first time a leaf node (node with no children) is encountered, the current depth is returned. This ensures that the minimum depth is found, as BFS processes nodes level by level.

***Time Complexity Analysis***:

- The time complexity is $O(N)$, where $N$ is the number of nodes in the tree.
- Each node is visited exactly once in the level-order traversal.

***Space Complexity Analysis***:

- The space complexity is primarily dependent on the breadth of the tree, which can vary.
- In the worst case (a completely unbalanced tree), it could be $O(N)$ if all nodes are on a single level.
- In the best case (a perfectly balanced tree), it would be $O(\log N)$ due to the properties of a complete binary tree where the maximum number of nodes at any level is proportional to the height of the tree.

***Iterative vs Recursive Solutions***:

- Unlike the recursive approach, which uses the call stack for recursion, this iterative approach explicitly manages the queue.
- This makes the iterative solution more suitable for situations where the tree is highly unbalanced, as it avoids the potential stack overflow that might occur with deep recursion.
