# Intersection of Two Arrays

[Link](https://leetcode.com/problems/intersection-of-two-arrays/description/)

## Description

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

- Input: `nums1 = [1,2,2,1]`, `nums2 = [2,2]`
- Output: `[2]`

Example 2:

- Input: `nums1 = [4,9,5]`, `nums2 = [9,4,9,8,4]`
- Output: `[9,4]`
- Explanation: `[4,9]` is also accepted.

Constraints:

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

## Solution

### Hash Map Way 1

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for (auto num: nums2) {
            if (nums_set.find(num) != nums_set.end())
                result_set.insert(num);
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```

### Hash Map Way 2

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S;
        for (auto x : nums1) S.insert(x);

        vector<int> res;
        for (auto y : nums2) {
            if (S.count(y)) {
                res.push_back(y);
                /*
                It ensures that each element from nums2 is only added once to the result, even if nums2 contains duplicates. It also reduces the number of unnecessary checks for subsequent elements in nums2. Once an element from nums2 is found in S and added to res, it doesn't need to be checked again.
                */
                S.erase(y);
            }
        }
        return res;
    }
};
```
