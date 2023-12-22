# Permutations II

[Link](https://leetcode.com/problems/permutations-ii/description/)

## Description

Given a collection of numbers, `nums`, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

- Input: `nums = [1,1,2]`
- Output: `[[1,1,2], [1,2,1], [2,1,1]]`

Example 2:

- Input: `nums = [1,2,3]`
- Output: `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

Constraints:

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

## Solution

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
```
