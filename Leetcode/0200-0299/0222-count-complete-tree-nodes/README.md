# Count Complete Tree Nodes

[Link](https://leetcode.com/problems/count-complete-tree-nodes/description/)

## Description

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees), every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2^h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than $O(n)$ time complexity.

Example 1:

- Input: `root = [1,2,3,4,5,6]`
- Output: `6`

Example 2:

- Input: `root = []`
- Output: `0`

Example 3:

- Input: `root = [1]`
- Output: `1`

Constraints:

- The number of nodes in the tree is in the range `[0, 5 * 10^4]`.
- `0 <= Node.val <= 5 * 10^4`
- The tree is guaranteed to be complete.

## Solution

### Classical Approach

#### Recursive Method

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

***Time Complexity***: $O(N)$

The time complexity of this algorithm is $O(N)$, where $N$ is the number of nodes in the tree. This is because the algorithm makes a single pass over all the nodes in the tree. Every node is visited exactly once.

***Space Complexity***: $O(\log (N))$

The space complexity depends on the height of the tree, which affects the depth of the recursion stack.

- In the worst case (a skewed tree), the height of the tree can be $N$ (number of nodes), leading to a space complexity of $O(N)$ due to the recursion stack;
- In the best case (a perfectly balanced tree), the height of the tree is $\log (N)$, leading to a space complexity of $O(\log (N))$;
- For a complete binary tree, the tree is almost perfect, so the space complexity will be closer to $O(\log (N))$.

#### Iterative Method (Level-order)

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto node = q.front();
                q.pop();
                res++;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
```

***Time Complexity***:

The time complexity of this approach is $O(N)$, where $N$ is the number of nodes in the tree. This is because each node in the tree is visited exactly once.

***Space Complexity***:

- The space complexity primarily depends on the maximum number of nodes that can be present in the queue at any time. This occurs when the queue contains all nodes of the level with the maximum width;
- Worst Case: In the worst case (for a complete binary tree), the last level can have up to $\frac{N}{2}$ nodes (in a full binary tree scenario). Therefore, the space complexity in the worst case is $O(N)$;
- Average Case: On average, the space complexity will depend on the width of the tree, but it will not exceed $O(N)$.

### Optimized Approach for Complete Binary Tree

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* l = root, * r = root;
        int lDepth = 0, rDepth = 0;
        while (l) { l = l->left; lDepth++; }
        while (r) { r = r->right; rDepth++; }
        if (lDepth == rDepth) return (1 << lDepth) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

***Code Explanation***:

1. **Base Case**: 
   - `if (!root) return 0;`
   - If the tree is empty (i.e., `root` is `nullptr`), it contains zero nodes. This is the base case for recursion.
2. **Initializing Variables**:
   - `TreeNode* l = root, * r = root;`
   - `int lDepth = 0, rDepth = 0;`
   - Two pointers (`l` and `r`) are initialized to the root, and two depth counters (`lDepth` and `rDepth`) are set to zero.
3. **Calculating Left Depth**:
   - `while (l) { l = l->left; lDepth++; }`
   - This loop traverses the tree to the leftmost node, incrementing `lDepth` at each step. It calculates the depth of the left subtree.
4. **Calculating Right Depth**:
   - `while (r) { r = r->right; rDepth++; }`
   - Similarly, this loop calculates the depth of the right subtree by moving to the rightmost node.
5. **Checking for Complete Tree**:
   - `if (lDepth == rDepth) return (1 << lDepth) - 1;`
   - If the depths of the left and right subtrees are equal, it indicates that the tree is a perfect binary tree at this level. The total number of nodes in a perfect binary tree of depth `d` is `2^d - 1`.
6. **Recursive Case**:
   - `return 1 + countNodes(root->left) + countNodes(root->right);`
   - If the tree is not perfect, the function recursively counts the nodes in the left and right subtrees. The `1 +` accounts for the current root node.

***Recursion Details***:

- The recursion occurs in the case where the tree is not perfect. The function is called recursively for the left and right children of the current node.
- Each recursive call breaks down the problem into smaller sub-trees until it reaches a point where the sub-trees are perfect binary trees or empty.

***Time Complexity Analysis***:

1. **Depth Calculation**:
   - Calculating the leftmost and rightmost depths takes $O(\log N)$ time each, where $N$ is the total number of nodes. This is because the height of a complete binary tree is $O(\log N)$.
2. **Recursion**:
   - The recursive calls are not made to both left and right subtrees in all cases. If the left and right depths are equal, the node count for that subtree is determined without further recursion.
   - In the worst-case scenario, the tree is almost complete but missing some nodes in the rightmost part of the last level. In this case, the recursion will go down to the deepest level on the leftmost path but will terminate early on all other paths.
3. **Complexity Calculation**:
   - Each recursive call involves two depth calculations (one for the leftmost path and one for the rightmost path) and possibly two recursive calls.
   - However, due to the tree's complete nature, these recursive calls don't always process the entire subtree. As we go deeper, the number of nodes that need to be processed decreases roughly by half each time.

Given these considerations, the time complexity of this algorithm is better than $O(N)$ but worse than $O(\log N)^2$. A more accurate estimation would be $O(\log N \times \log N)$, which arises from the logarithmic number of recursive calls (since the tree height is $O(\log N)$, and in each call, the depth is computed, which again takes $O(\log N)$ time.

***Space Complexity Analysis***:

- The space complexity is $O(\log N)$ due to the recursion stack. In the worst case, the height of the tree (which is the maximum depth of the recursion stack) will be $\log N$ for a balanced tree.
