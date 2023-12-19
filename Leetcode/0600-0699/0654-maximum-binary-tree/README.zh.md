# 最大二叉树

[Leetcode题目链接](https://leetcode.com/problems/maximum-binary-tree/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/maximum-binary-tree/)。

## 解答

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
