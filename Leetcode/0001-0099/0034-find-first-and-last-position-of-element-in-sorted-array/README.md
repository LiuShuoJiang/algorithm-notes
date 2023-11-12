# Find First and Last Position of Element in Sorted Array

[Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

## Description

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with $O(\log n)$ runtime complexity.

Example 1:

- Input: `nums = [5,7,7,8,8,10], target = 8`
- Output: `[3,4]`

Example 2:

- Input: `nums = [5,7,7,8,8,10], target = 6`
- Output: `[-1,-1]`

Example 3:

- Input: `nums = [], target = 0`
- Output: `[-1,-1]`

Constraints:

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is a non-decreasing array.
- `-10^9 <= target <= 10^9`

## Solution

### Binary Search Template 1

```C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        // (NOTE!!!) We need to check if the array is empty
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid;
        }

        // (NOTE!!!) Check if r is within bounds and if the target is found
        if (r >= nums.size() || nums[r] != target) {
            return vector<int>{-1, -1};
        } else {
            res.push_back(r);
            l = -1, r = nums.size();
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] <= target) l = mid;
                else r = mid;
            }
            res.push_back(l);
        }
        return res;
    }
};
```

### Binary Search Template 2

```C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != target) return {-1, -1};
        int left_res = r;

        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return {left_res, r};  //return {left_res, l}; is also OK
    }
};
```
