# Squares of a Sorted Array

[Link](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

## Description

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

- Input: `nums = [-4,-1,0,3,10]`
- Output: `[0,1,9,16,100]`

Explanation: After squaring, the array becomes `[16,1,0,9,100]`. After sorting, it becomes `[0,1,9,16,100]`.

Example 2:

- Input: `nums = [-7,-3,2,3,11]`
- Output: `[4,9,9,49,121]`

Constraints:

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in non-decreasing order.

## Solution

### Trivial Solution

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```

Time complexity: $O\left( n+n\log n \right) \approx O\left( n\log n \right)$

### Double Pointer Solution

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int k = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j; ) {  // NOTE!!!  write i <= j because we need to handle the last 2 elements
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                res[k--] = nums[j] * nums[j];
                j--;
            } else {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};
```

Time complexity: $O(n)$
