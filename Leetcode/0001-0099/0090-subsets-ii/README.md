# Subsets II

[Link](https://leetcode.com/problems/subsets-ii/description/)

## Description

Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set).

A **subset** of an array is a selection of elements (possibly none) of the array.

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

- Input: `nums = [1,2,2]`
- Output: `[[],[1],[1,2],[1,2,2],[2],[2,2]]`

Example 2:

- Input: `nums = [0]`
- Output: `[[],[0]]`

Constraints:

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

## Solution

### Way 1

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        res.push_back(path);
        unordered_set<int> used;
        for (int i = startIndex; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
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
    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       backtracking(nums, 0);
       return res; 
    }
};
```
