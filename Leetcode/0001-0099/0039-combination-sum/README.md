# Combination Sum

[Link](https://leetcode.com/problems/combination-sum/description/)

## Description

Given an array of distinct integers `candidates` and a target integer `target`, return a list of all ***unique combinations*** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in any order.

The same number may be chosen from `candidates` an unlimited number of times. Two combinations are unique if the ***frequency*** of at least one of the chosen numbers is different.

Note: The frequency of an element x is the number of times it occurs in the array.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

Example 1:

- Input: `candidates = [2,3,6,7], target = 7`
- Output: `[[2,2,3],[7]]`
- Explanation:
    - `2` and `3` are candidates, and `2 + 2 + 3 = 7`. Note that `2` can be used multiple times.
    - `7` is a candidate, and `7 = 7`.
    - These are the only two combinations.

Example 2:

- `Input: candidates = [2,3,5], target = 8`
- `Output: [[2,2,2,2],[2,3,3],[3,5]]`

Example 3:

- Input: `candidates = [2], target = 1`
- Output: `[]`

Constraints:

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- All elements of `candidates` are distinct.
- `1 <= target <= 40`

## Solution

### Way 1

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            // No need to use i+1, meaning that the current number can be read repeatedly
            backtracking(candidates, sum - candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
};
```

- Time complexity: $O(n\times 2^n)$;
- Space complexity: $O(\mathrm{target})$.

***Optimized code with pruning***:

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        if (sum < 0) return ;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            if (sum - candidates[i] < 0) break;
            path.push_back(candidates[i]);
            backtracking(candidates, sum - candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};
```

After sorting the total set, if the `sum` of the next level (which is the `sum + candidates[i]` of this level) is already greater than `target`, we can end this round of traversal of the `for` loop.

### Way 2

See [reference](https://leetcode.com/problems/combination-sum/solutions/1777334/c-detailed-explanation-w-tree-diagram-recursion-backtracking-each-step-explained/).

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        // if index crosses the last index, we will return saying that no more element is left to choose
        if (startIndex == candidates.size()) return;

        // we are not taking the startIndex-th element,
        // so without decreasing sum we will move to next index because it will not contribute in making our sum
        backtracking(candidates, sum, startIndex + 1);

        // we are taking the startIndex-th element and not moving onto the next element 
        // because it may be possible that this element again contribute in making our sum.
        // but we decrease our target sum as we are considering that this will help us in making our target sum
        path.push_back(candidates[startIndex]);
        backtracking(candidates, sum - candidates[startIndex], startIndex);
        path.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
};
```
