# 4 Sum

[Link](https://leetcode.com/problems/4sum/description/)

## Description

Given an array `nums` of `n` integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are distinct.
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in any order.

Example 1:

- Input: `nums = [1,0,-1,0,-2,2], target = 0`
- Output: `[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]`

Example 2:

- Input: `nums = [2,2,2,2,2], target = 8`
- Output: `[[2,2,2,2]]`

Constraints:

- `1 <= nums.length <= 200`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## Solution

### Double Pointer

```C++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Pruning process (optional)
            if (nums[i] > target && nums[i] >= 0) break;

            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                // Pruning process (optional)
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                for (int k = j + 1, l = nums.size() - 1; k < l; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    // use long to avoid overflow
                    while (k < l && (long) nums[i] + nums[j] + nums[k] + nums[l] > target) l--;

                    if (k < l && (long) nums[i] + nums[j] + nums[k] + nums[l] == target)
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
        return res;
    }
};
```

Time complexity: $O(n^3)$
