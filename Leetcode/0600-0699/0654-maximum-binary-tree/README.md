# Maximum Binary Tree

[Link](https://leetcode.com/problems/maximum-binary-tree/description/)

## Description

You are given an integer array `nums` with no duplicates. A maximum binary tree can be built recursively from `nums` using the following algorithm:

Create a root node whose value is the maximum value in `nums`.

- Recursively build the left subtree on the **subarray prefix** to the **left** of the maximum value.
- Recursively build the right subtree on the **subarray suffix** to the **right** of the maximum value.

Return the maximum binary tree built from `nums`.

Example 1:

![tree](./tree1.jpg)

- Input: `nums = [3,2,1,6,0,5]`
- Output: `[6,3,5,null,2,0,null,null,1]`
- Explanation: The recursive calls are as follow:

```
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
```

Example 2:

- Input: `nums = [3,2,1]`
- Output: `[3,null,2,null,1]`

Constraints:

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`
- All integers in nums are unique.

## Solution

### Recursive Solution

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
    TreeNode* traversal(vector<int> &nums, int left, int right) {
        if (left >= right) return nullptr;

        // int maxIndex = left;
        // for (int i = left + 1; i < right; i++) {
        //     if (nums[i] > nums[maxIndex]) maxIndex = i;
        // }
        int maxIndex = distance(nums.begin(), max_element(nums.begin() + left, nums.begin() + right));

        TreeNode *root = new TreeNode(nums[maxIndex]);

        root->left = traversal(nums, left, maxIndex);
        root->right = traversal(nums, maxIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
```

***Time Complexity Analysis***:

1. **Finding the Maximum Element**: The use of `max_element` in each recursive call requires iterating over each element of the subarray. This operation has a linear time complexity relative to the size of the subarray.
2. **Recursive Tree Construction**: The function `traversal` is called recursively for different parts of the array. However, each element of the array is part of exactly one subarray for which the maximum is found. Therefore, each element contributes to $O(N)$ operations overall.
3. **Overall Complexity**: Considering the recursive nature of the algorithm and the way each element is visited, the overall time complexity is $O(N^2)$, where $N$ is the number of elements in the array. This quadratic complexity arises because for each element (in the worst case), we might have to scan all the remaining elements to find the maximum.

***Space Complexity Analysis***:

1. **Recursive Call Stack**: The depth of the recursive call stack will be $O(N)$ in the worst case (e.g., when the array is sorted in ascending or descending order). This is because the tree becomes a skewed tree (like a linked list), and the height of the tree, which determines the depth of the recursive stack, is equal to $N$.
2. **TreeNode Allocation**: For every element in the array, a new TreeNode is created. Thus, the space used for TreeNode allocation is $O(N)$.
3. **Overall Complexity**: Considering the recursive stack and the tree node allocation, the overall space complexity is $O(N)$.

### Optimized Solution

This is a [**Cartesian tree**](https://en.wikipedia.org/wiki/Cartesian_tree) problem, and we can use monolithic stack to optimize the time complexity. See [reference 1 (in Chinese)](https://leetcode.cn/problems/maximum-binary-tree/solutions/1762400/zhua-wa-mou-si-by-muse-77-myd7/) and [reference 2](https://leetcode.com/problems/maximum-binary-tree/solutions/106146/c-o-n-solution/).

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int x : nums) {
            auto node = new TreeNode(x);
            while (!stk.empty() && stk.top()->val < x) {
                node->left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.top()->right = node;
            stk.push(node);
        }
        while (stk.size() > 1) stk.pop();
        return stk.top();
    }
};
```

***Analysis***:

1. **Stack Initialization**: A stack of `TreeNode*` is created. This stack will be used to maintain a monotonically decreasing sequence of nodes.
2. **Iterating Over `nums`**: The function iterates over each element `x` in the input vector `nums`.
3. **Creating a New Node**: For each element `x`, a new tree node is created.
4. **Updating the Stack and Constructing the Tree**:
   - As long as the stack is not empty and the value of the top node in the stack is less than `x`, the following steps are repeated:
     - The current top of the stack is set as the left child of the new node. This is based on the property of the maximum binary tree, where the nodes in the left subtree are less than the root.
     - The top node is then popped from the stack.
   - If the stack is not empty after this process, the new node is set as the right child of the current top of the stack. This is because in the monotonically decreasing stack, the top element will be the first element that is greater than `x` on its right.
5. **Pushing the New Node to the Stack**: The new node is pushed onto the stack. This ensures that the stack maintains its monotonically decreasing property.
6. **Finalizing the Root of the Tree**:
   - After processing all elements in `nums`, the stack may contain more than one node. The nodes in the stack are in decreasing order, and each node is the root of a subtree where all elements to its right (in the original array) are smaller.
   - The loop `while (stk.size() > 1) stk.pop();` pops all nodes except the one at the bottom of the stack, which is the root of the maximum binary tree.
7. **Returning the Root**: The function returns the remaining node on the stack, which is the root of the constructed maximum binary tree.

***Complexity Analysis***:

- **Time Complexity**: $O(N)$. Each element in `nums` is processed exactly once. The while loop inside the for loop might seem like it could lead to a higher time complexity, but each node is added to and removed from the stack exactly once. Therefore, the total number of operations is proportional to the number of elements in `nums`.
- **Space Complexity**: $O(N)$. The space complexity is primarily due to the storage of the nodes in the stack and the tree itself. In the worst case (when the array is sorted in ascending order), all elements will be in the stack before they start getting popped, which would require O(N) space.

