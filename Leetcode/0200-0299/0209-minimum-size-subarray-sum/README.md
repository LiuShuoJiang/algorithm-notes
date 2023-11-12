# Minimum Size Subarray Sum

[Link](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

## Description

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray (A ***subarray*** is a contiguous non-empty sequence of elements within an array) whose sum is greater than or equal to `target`. If there is no such subarray, return 0 instead.

Example 1:

- Input: `target = 7, nums = [2,3,1,2,4,3]`
- Output: 2

Explanation: The subarray `[4,3]` has the minimal length under the problem constraint.

Example 2:

- Input: `target = 4, nums = [1,4,4]`
- Output: 1

Example 3:

- Input: `target = 11, nums = [1,1,1,1,1,1,1,1]`
- Output: 0

Constraints:

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

## Solution

### Sliding Window

```C++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int left = 0, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
