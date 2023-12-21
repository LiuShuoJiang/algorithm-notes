# Subsets

[Link](https://leetcode.com/problems/subsets/description/)

## Description

Given an integer array `nums` of unique elements, return all possible subsets (the power set).

A **subset** of an array is a selection of elements (possibly none) of the array.

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

- Input: `nums = [1,2,3]`
- Output: `[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]`

Example 2:

- Input: `nums = [0]`
- Output: `[[],[0]]`

Constraints:

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are unique.

## Solution

### Recursive Solution

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        
        // this terminating condition is optional
        // if (startIndex >= nums.size()) return;
        
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
```

- Time complexity: $O(n\times 2^n)$;
- Space complexity: $O(n)$.

### Iterative Solution Using Binary Representation

```C++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> path;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1)
                    path.push_back(nums[j]);
            }
            res.push_back(path);
        }
        return res;
    }
};
```

**Explanation**:

***Outer Loop: Generating Each Subset***:

```C++
for (int i = 0; i < (1 << n); i++) {
    ...
}
```

- This loop iterates through all possible binary representations of numbers from `0` to `2^n - 1` (where `n` is the size of the input set).
- Each number `i` in this range represents a unique subset. The binary representation of `i` determines which elements are included in the subset.

***Inner Loop: Deciding Which Elements to Include***:

```C++
vector<int> path;
for (int j = 0; j < n; j++) {
    if (i >> j & 1)
        path.push_back(nums[j]);
}
```

- For each `i`, a new vector `path` is created to store the current subset.
- The inner loop iterates through each bit of `i`.
- `i >> j` shifts the bits of `i` right by `j` places. This effectively checks each bit of `i` from right to left.
- The `& 1` operation checks if the rightmost bit is `1`. If it is, it means the element at index `j` in `nums` should be included in the current subset.
- If the condition is true, `nums[j]` is added to `path`.
