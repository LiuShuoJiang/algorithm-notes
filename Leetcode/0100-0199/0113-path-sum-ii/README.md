# Path Sum II

[Link](https://leetcode.com/problems/path-sum-ii/description/)

## Description

Given the `root` of a binary tree and an integer `targetSum`, return all root-to-leaf paths where the sum of the node values in the path equals `targetSum`. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:

- Input: `root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22`
- Output: `[[5,4,11,2],[5,8,4,5]]`
- Explanation:
    - There are two paths whose sum equals targetSum:
    - `5 + 4 + 11 + 2 = 22`
    - `5 + 8 + 4 + 5 = 22`

Example 2:

- Input: `root = [1,2,3], targetSum = 5`
- Output: `[]`

Example 3:

- Input: `root = [1,2], targetSum = 0`
- Output: `[]`

Constraints:

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

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
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* node, int count) {
        if (!node->left && !node->right && count == 0) {
            res.push_back(path);
            return;
        }
        if (node->left) {
            path.push_back(node->left->val);
            traversal(node->left, count - node->left->val);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            traversal(node->right, count - node->right->val);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return res;
    }
};
```

Easier way of writing:

See [reference](https://leetcode.com/problems/path-sum-ii/solutions/36685/12ms-11-lines-c-solution/).

```C++
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void findPaths(TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) res.push_back(path);
        findPaths(root->left, sum - root->val);
        findPaths(root->right, sum - root->val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        findPaths(root, targetSum);
        return res;
    }
};
```

### Way 2 (Pass by Value)

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void findPaths(TreeNode* root, vector<int> path, int sum) {
        if (!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
            return;
        }
        findPaths(root->left, path, sum);
        findPaths(root->right, path, sum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        findPaths(root, path, targetSum);
        return res;
    }
};
```

- Time Complexity: $O(N\cdot H)$, where $N$ is the number of nodes and $H$ is the average length of the path. The extra factor of H comes from the time taken to copy the path vector at each node. In the worst case, the top half of the tree is in the form of a chain, the bottom half is in the form of a fully binary tree, and the paths from the root node to each leaf node meet the requirements of the question. In this case, the number of paths is $O(N)$ and the number of nodes in each path is also $O(N)$, so the time complexity to add all these paths to the answer is $O(N^2)$;
- Space complexity: $O(H)$ for each recursive call, but since they are not shared, the maximum simultaneous space used is still $O(H)$. In the worst case, it is $O(N)$.

## Note

***Way 1: Not Using Return After Adding Path***

In Way 1, the `path` vector is a class member and is modified in place. Here's the corresponding section:

```C++
if (!root->left && !root->right && sum == root->val) {
    res.push_back(path);
    // No return here
}
```

- **Why `return` is Not Used**: After adding a valid path to `res`, the function does not return immediately. Instead, it continues to the end, where `path.pop_back()` is called. This is crucial to maintain the correct state of `path` for other branches of the recursion.
- **Control Flow Management**: The absence of `return` here allows the function to reach `path.pop_back()` at the end, which is necessary to backtrack correctly in the recursive tree.

***Way 2: Returning After Adding Path***

In Way 2, the `path` vector is passed by value. Here's the key section:

```C++
if (!root->left && !root->right && sum == 0) {
    res.push_back(path);
    return;
}
```

- **Why `return` is Used**: Once a valid path is found (i.e., a leaf node where the sum equals the target), this path is added to `res`, and the function returns immediately. This return is crucial because the function's further execution (calling left and right subtrees) is unnecessary—the path has been completed and recorded.
- **Effect of `return`**: It prevents further unnecessary recursive calls for the current path.

***Summary***:

- **Way 1**: Does not use `return` immediately after finding a path, as it needs to reach the `pop_back` operation to correctly manage the state of the shared `path` vector for ongoing recursion.
- **Way 2**: Uses `return` to avoid unnecessary recursive calls after a complete path is found, as each recursive call works on its own copy of `path`.


