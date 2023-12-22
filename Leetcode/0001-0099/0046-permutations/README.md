# Permutations

[Link](https://leetcode.com/problems/permutations/description/)

## Description

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

- Input: `nums = [1,2,3]`
- Output: `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

Example 2:

- Input: `nums = [0,1]`
- Output: `[[0,1],[1,0]]`

Example 3:

- Input: `nums = [1]`
- Output: `[[1]]`

Constraints:

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are unique.

## Solution

### Way 1

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
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};
```

### Way 2

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    void backtracking(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path[index] = nums[i];
                used[i] = true;
                backtracking(nums, index + 1);
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size(), 0);
        used = vector<bool>(nums.size(), false);
        backtracking(nums, 0);
        return res;
    }
};
```

- Time complexity: $O(n\times n!)$;
- Space complexity: $O(n)$.
