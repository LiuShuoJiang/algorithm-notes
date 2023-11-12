# 3 Sum

[Link](https://leetcode.com/problems/3sum/description/)

## Description

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

Example 1:

- Input: `nums = [-1,0,1,2,-1,-4]`
- Output: `[[-1,-1,2],[-1,0,1]]`

Explanation:

- `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`.
- `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`.
- `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`.
- The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`.
- Notice that the order of the output and the order of the triplets does not matter.

Example 2:

- Input: `nums = [0,1,1]`
- Output: `[]`

Explanation: The only possible triplet does not sum up to 0.

Example 3:

- Input: `nums = [0,0,0]`
- Output: `[[0,0,0]]`

Explanation: The only possible triplet sums up to 0.

Constraints:

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

## Solution

### Double Pointer Starter Way

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return res;

            // wrong! e.g. [-1, -1, 2]
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            //the correct way to remove duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // remove duplicates
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
```

Time complexity: $O(n^2)$

### Double Pointer Simpler Way

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k--;
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
```

Note: Why are we checking for `nums[i] + nums[j] + nums[k-1]` in the `while` loop, but `nums[i] + nums[j] + nums[k]` when adding the result? This is because in the `while` loop, if a `k` has been found that makes the sum of the three elements less than 0, then the next `k` (i.e., `k-1`) must make the sum of the three elements smaller (because `nums[k-1] <= nums[k]`). So, if `nums[i] + nums[j] + nums[k-1]` is still greater than or equal to 0, then we need to keep decreasing `k`. Then at the end of the `while` loop, since we may have missed the `k` that makes the sum of the three elements equal to 0, we finally check if `nums[i] + nums[j] + nums[k] == 0` or not.

If we do not use `k - 1` in that section, we can rewrite the code:

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (j < k && nums[i] + nums[j] + nums[k] > 0) k--;
                // we need to check if j < k here!
                if (j < k && nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
```
