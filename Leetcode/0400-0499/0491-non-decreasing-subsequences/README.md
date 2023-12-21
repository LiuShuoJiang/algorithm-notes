# Non-decreasing Subsequences

[Link](https://leetcode.com/problems/non-decreasing-subsequences/description/)

## Description

Given an integer array `nums`, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

Example 1:

- Input: `nums = [4,6,7,7]`
- Output: `[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]`

Example 2:

- Input: `nums = [4,4,3,2,1]`
- Output: `[[4,4]]`

Constraints:

- `1 <= nums.length <= 15`
- `-100 <= nums[i] <= 100`

## Solution

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() > 1) res.push_back(path);

        unordered_set<int> used;
        for (int i = startIndex; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) continue;
            if (!path.empty() && nums[i] < path.back()) continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```

- Time complexity: $O(n\times 2^n)$;
- Space complexity: $O(n)$.

Optimized solution:

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() > 1) res.push_back(path);

        bool used[210] = {false};
        for (int i = startIndex; i < nums.size(); i++) {
            if (used[nums[i] + 100]) continue;
            if (!path.empty() && nums[i] < path.back()) continue;

            used[nums[i] + 100] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```
