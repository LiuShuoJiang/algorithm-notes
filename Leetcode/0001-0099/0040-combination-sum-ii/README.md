# Combination Sum II

[Link](https://leetcode.com/problems/combination-sum-ii/description/)

## Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in candidates where the `candidate` numbers sum to `target`.

Each number in `candidates` may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

- Input: `candidates = [10,1,2,7,6,1,5], target = 8`
- Output:

```
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

Example 2:

- Input: `candidates = [2,5,2,1,2], target = 5`
- Output:

```
[
[1,2,2],
[5]
]
```

Constraints:

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Solution

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int sum, int startIndex) {
        // if (sum < 0) return;
        if (sum == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum - candidates[i] >= 0; i++) {
            if (i != startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, sum - candidates[i], i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};
```
