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

### Way 1

Pre-order:

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

### Way 2

```C++
class Solution {
private:
    vector<string> ans;
    vector<int> path;

    void findPath(TreeNode* root) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
                sPath += to_string(path[i]) + "->";
            sPath += to_string(path[path.size() - 1]);
            ans.push_back(sPath);
        } else {
            if (root->left) findPath(root->left);
            if (root->right) findPath(root->right);
        }
        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) findPath(root);
        return ans;
    }
};
```

### Way 3

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
    void traversal(TreeNode* curr, string path, vector<string>& res) {
        path += to_string(curr->val);
        if (!curr->left && !curr->right) {
            res.push_back(path);
            return;
        }
        if (curr->left) traversal(curr->left, path + "->", res);
        if (curr->right) traversal(curr->right, path + "->", res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        if (!root) return res;
        traversal(root, path, res);
        return res;
    }
};
```

Another way of writing:

```C++
class Solution {
private:
    vector<string> res;
    void findPaths(TreeNode* root, string path) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        findPaths(root->left, path + "->");
        findPaths(root->right, path + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        findPaths(root, "");
        return res;
    }
};
```

***Time Complexity***:

1. **Traversal Complexity**: Each node in the tree is visited exactly once. If there are $N$ nodes in the tree, the traversal part of the algorithm is $O(N)$.
2. **String Operations**: In each recursive call, a new string is created that includes the current path plus the value of the current node. The time complexity for string concatenation in C++ can vary, but in the worst case, it is proportional to the length of the new string being created.
3. **Worst-Case Scenario for String Concatenation**:
    - For a balanced tree, the length of the path (and thus the length of the string) at any node is proportional to the height of the tree, which is $\log N$ for a balanced tree.
    - In an unbalanced tree, in the worst case, the length can be proportional to $N$, such as in a skewed tree (where each node has only one child).

Combining these factors, the time complexity is $O(N \cdot L)$, where $L$ represents the average length of the path string in each recursive call. In the worst case, especially for unbalanced trees, $L$ can approach $N$, leading to a time complexity of $O(N^2)$.

***Space Complexity***:

1. **Space for Recursive Calls (Recursion Stack)**: The maximum depth of the recursion stack is proportional to the height of the tree. In the worst case, for a skewed tree, this can be $O(N)$.
2. **Space for Path Strings**:
    - Each recursive call creates a new string representing the path. Although these strings are temporary and each exists only during the execution of a single recursive call, the space occupied by these strings at any moment is proportional to the depth of the recursion and the length of the path string.
    - In the worst case, where the tree is skewed, the length of the path string can be proportional to \( N \), leading to a space complexity of $O(N^2)$ due to the concatenation of strings at each level of the tree.
    - In the bast case, the binary tree is balanced, leading to the space complexity of $O((\log n)^2)$.

### Way 4: Iterative Method

See [reference](https://leetcode.cn/problems/binary-tree-paths/solutions/400326/er-cha-shu-de-suo-you-lu-jing-by-leetcode-solution/) (Chinese).

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(root, to_string(root->val)));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (!(t.first)->left && !(t.first)->right) paths.push_back(t.second);
            else {
                if ((t.first)->left) {
                    q.push(make_pair((t.first)->left, t.second + "->" + to_string((t.first)->left->val)));
                }
                if ((t.first)->right) {
                    q.push(make_pair((t.first)->right, t.second + "->" + to_string((t.first)->right->val)));
                }
            }
        }
        return paths;
    }
};
```

We can also implement this with a breadth-first search. We maintain a queue that stores the node and the path from the root to that node. At first this queue has only the root node in it. At each iteration step, we take out the first node in the queue and if it is a leaf node, add its corresponding path to the answer. If it is not a leaf node, all its child nodes are added to the end of the queue. When the queue is empty the breadth-first search ends and we get the answer.

- Worst time complexity: $O(N^2)$;
- Worst space complexity: $O(N^2)$.
