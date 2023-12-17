# Construct Binary Tree from Preorder and Inorder Traversal

[Link](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

## Description

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

- Input: `preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]`
- Output: `[3,9,20,null,null,15,7]`

Example 2:

- Input: `preorder = [-1], inorder = [-1]`
- Output: `[-1]`

Constraints:

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` and `inorder` consist of unique values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is guaranteed to be the preorder traversal of the tree.
- `inorder` is guaranteed to be the inorder traversal of the tree.

## Solution

1. First, use pre-order traversal to find the root node: the first number in the pre-order traversal is the value of the root node;
2. Find the position of the root node in the in-order traversal, `pos`. Then, the left side of `pos` is the in-order traversal of the left subtree, and the right side is the in-order traversal of the right subtree;
3. Assume that the length of the in-order traversal of the left subtree is `index`. Then, in the pre-order traversal, the `index` numbers following the root node are the pre-order traversal of the left subtree, and the remaining numbers are the pre-order traversal of the right subtree;
4. With the pre-order and in-order traversals of the left and right subtrees, we can first recursively create the root node, then recursively create the left and right subtrees, and finally attach these two subtrees to the left and right positions of the root node.

***Illustration***:

```
preorder: |      |------------------------|                   |-------------------------|
         preL  preL+1         (preL+1)+(index-1-inL)  (preL+1)+(index-1-inL)+1         preR


inorder:  |------------------------|           |              |-------------------------|
         inL                     index-1     index         index+1                     inR
```

***Code***:

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
    unordered_map<int, int> pos;
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) return nullptr;
        auto root = new TreeNode(preorder[preorderLeft]);
        int index = pos[root->val];
        root->left = treeBuilder(preorder, inorder, 
            preorderLeft + 1, preorderLeft + 1 + index - 1 - inorderLeft, 
            inorderLeft, index - 1);
        root->right = treeBuilder(preorder, inorder, 
            preorderLeft + 1 + index - 1 - inorderLeft + 1, preorderRight, 
            index + 1, inorderRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int treeSize = inorder.size();
        for (int i = 0; i < treeSize; i++) pos[inorder[i]] = i;
        return treeBuilder(preorder, inorder, 0, treeSize - 1, 0, treeSize - 1);
    }
};
```

Code with comments:

```C++
class Solution {
private:
    // A hash map to store the position of each value in the inorder traversal.
    unordered_map<int, int> pos;

    // Helper function to build the tree.
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder, 
                          int preorderLeft, int preorderRight, 
                          int inorderLeft, int inorderRight) {
        // Base case: if the current subtree is empty.
        if (preorderLeft > preorderRight) return nullptr;

        // The first element in preorder traversal is the root of the subtree.
        auto root = new TreeNode(preorder[preorderLeft]);

        // Find the position of the root in inorder traversal.
        int index = pos[root->val];

        // Recursively construct the left subtree.
        root->left = treeBuilder(preorder, inorder, 
                                 preorderLeft + 1, preorderLeft + index - inorderLeft, 
                                 inorderLeft, index - 1);

        // Recursively construct the right subtree.
        root->right = treeBuilder(preorder, inorder, 
                                  preorderLeft + index - inorderLeft + 1, preorderRight, 
                                  index + 1, inorderRight);

        return root;
    }

public:
    // Public function to be called to build the tree.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int treeSize = inorder.size();
        // Fill the hash map with elements from the inorder traversal.
        for (int i = 0; i < treeSize; i++) pos[inorder[i]] = i;
        // Start the tree construction process.
        return treeBuilder(preorder, inorder, 0, treeSize - 1, 0, treeSize - 1);
    }
};
```

***Explanation of Algorithm***:

The algorithm uses recursion to construct the binary tree. It leverages the property that the first element of a preorder traversal is always the root of the tree, and then finds this root's index in the inorder traversal to divide the tree into left and right subtrees.

1. **Initializing Hash Map**: The `unordered_map` named `pos` maps each value in the inorder traversal to its index. This speeds up the search operation which is required to find the root node in the inorder sequence.
2. **Recursive Tree Construction**: The `treeBuilder` function is the core of the algorithm. It takes the current interval of preorder and inorder traversals to construct the tree. The first element of the current preorder interval is the root. The function then finds this root in the inorder interval, which divides the tree into left and right subtrees. The left and right child nodes are then recursively constructed.
3. **Interval Changes in Recursion**: The preorder and inorder intervals are updated in each recursive call to reflect the current subtree being constructed. The index found in the inorder traversal helps in determining the size of the left and right subtrees, which is then used to update the intervals.

***Time and Space Complexity Analysis***:

- **Time Complexity**: $O(n)$
    - The hash map reduces the search operation for the root in the inorder traversal to $O(1)$.
    - Each node is visited exactly once, leading to a linear time complexity.
- **Space Complexity**: $O(n)$
    - The space for the hash map, which contains n elements.
    - The recursive stack space, which, in the worst case, can go up to $O(n)$ in the case of a skewed tree.

***Additional Notes***:

Constructing the Left Subtree:

```C++
root->left = treeBuilder(preorder, inorder, 
                         preorderLeft + 1, preorderLeft + index - inorderLeft, 
                         inorderLeft, index - 1);
```

In this line, the algorithm is constructing the left subtree of the current root node. Here's how it works:

1. **Finding the Root of the Left Subtree**:
    - `preorderLeft + 1`: The left child of the current root in the preorder sequence is always the next element (`preorderLeft + 1`).
2. **Determining the Bounds of the Left Subtree**:
    - `preorderLeft + index - inorderLeft`: This expression calculates the right bound of the left subtree in the preorder sequence. 
    - `index` is the position of the current root in the inorder sequence. 
    - `inorderLeft` is the left bound of the inorder sequence for the current subtree.
    - The difference `index - inorderLeft` gives the size of the left subtree. Adding this to `preorderLeft` (and adjusting by 1 for the root) sets the right boundary in the preorder sequence.
3. **Setting the Inorder Interval**:
    - `inorderLeft, index - 1`: In the inorder sequence, the left subtree is always to the left of the root. So, the left subtree spans from `inorderLeft` to `index - 1` (one element before the root).

Constructing the Right Subtree:

```C++
root->right = treeBuilder(preorder, inorder, 
                          preorderLeft + index - inorderLeft + 1, preorderRight, 
                          index + 1, inorderRight);
```

In this line, the algorithm constructs the right subtree:

1. **Finding the Root of the Right Subtree**:
    - `preorderLeft + index - inorderLeft + 1`: This expression finds the starting point of the right subtree in the preorder sequence. The logic is similar to the left subtree, but it includes an additional `+1` to skip over the entire left subtree.
2. **Determining the Bounds of the Right Subtree**:
    - `preorderRight`: The right boundary in the preorder sequence remains the same as the parent's right boundary, as we are now dealing with the right subtree.
3. **Setting the Inorder Interval**:
    - `index + 1, inorderRight`: In the inorder sequence, the right subtree is always to the right of the root. Therefore, the interval for the right subtree starts from `index + 1` (one element after the root) to `inorderRight`.

