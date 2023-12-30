# Target Sum

[Link](https://leetcode.com/problems/target-sum/description/)

## Description

You are given an integer array `nums` and an integer `target`.

You want to build an expression out of nums by adding one of the symbols `'+'` and `'-'` before each integer in `nums` and then concatenate all the integers.

For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.
Return the number of different expressions that you can build, which evaluates to `target`.

Example 1:

- Input: `nums = [1,1,1,1,1], target = 3`
- Output: `5`
- Explanation: There are `5` ways to assign symbols to make the sum of nums be target `3`.

```
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

Example 2:

- Input: `nums = [1], target = 1`
- Output: `1`

Constraints:

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`

## Solution

### Way 1

```C++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), offset = 1000;
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        dp[0][offset] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = -1000; j <= 1000; j++) {
                if (j - nums[i - 1] >= -1000)
                    dp[i][j + offset] += dp[i - 1][j - nums[i - 1] + offset];
                if (j + nums[i - 1] <= 1000)
                    dp[i][j + offset] += dp[i - 1][j + nums[i - 1] + offset];
            }
        }
        return dp[n][target + offset];
    }
};
```

### Way 2

```C++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (sum + target) % 2) return 0;
        int m = (sum + target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][m];
    }
};
```

***Mapping to Subset Sum Problem***:

1. **Sum of all Elements**: Let's denote the sum of all elements in `nums` as `sum`.
2. **Partitioning into Two Subsets**: Imagine splitting the `nums` array into two subsets, `S1` and `S2`, where `S1` contains elements with a '+' sign, and `S2` contains elements with a '-' sign. Then, the problem boils down to finding subsets `S1` and `S2` such that `sum(S1) - sum(S2) = target`.
3. **Rearranging the Equation**: Rearranging the equation, we get `sum(S1) = (target + sum(S2)) = (target + sum - sum(S1))`. Simplifying, `2 * sum(S1) = target + sum`.
4. **Finding sum(S1)**: The problem now is to find a subset `S1` such that `sum(S1) = (target + sum) / 2`. This is a standard subset sum problem.

- Time Complexity: $O(nm)$ where $n$ is the number of elements in nums and $m$ is `(sum + target) / 2`.
- Space Complexity: $O(nm)$ due to the 2D array.

### Way 3

```C++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto x : nums) sum += x;
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;
        int m = (sum + target) / 2;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = m; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[m];
    }
};
```

- Time Complexity: Same as the 2D approach, $O(nm)$.
- Space Complexity: $O(m)$, a significant improvement over the 2D approach, as we are only using a single array of size $m + 1$.
