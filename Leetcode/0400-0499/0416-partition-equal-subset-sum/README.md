# Partition Equal Subset Sum

[Link](https://leetcode.com/problems/partition-equal-subset-sum/description/)

## Description

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or `false` otherwise.

Example 1:

- Input: `nums = [1,5,11,5]`
- Output: `true`
- Explanation: The array can be partitioned as `[1, 5, 5]` and `[11]`.

Example 2:

- Input: `nums = [1,2,3,5]`
- Output: `false`
- Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

## Solution

### Way 1

```C++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};
```

***Connection to 0-1 Knapsack Problem***:

The 0-1 Knapsack problem involves choosing items with given weights to maximize the total value without exceeding a given weight limit. Here, we tweak this idea:

- **'Weights' of items:** The elements in `nums`.
- **'Weight limit' (knapsack capacity):** Half of the total sum of elements in `nums`. This is because if one subset can reach half the total sum, the other subset automatically has the remaining elements, making their sums equal.
- **'Values' of items:** In the traditional knapsack problem, each item has a value. Here, the value is the same as the weight, as we're interested in the sum.

The problem becomes finding a subset of `nums` whose sum is ***exactly*** half of the total sum.

***Analysis***:

1. **Calculate Total Sum and Target:**
   - First, calculate the total sum of elements in `nums`.
   - If the sum is odd, it's impossible to split into two equal parts, hence return `false`.
   - Otherwise, set `target` as half of the total sum.
2. **Dynamic Programming Array Initialization:**
   - A `dp` array of size 10001 is initialized with zeros. This array will store the best sum achievable using subsets of the elements up to the current element.
3. **Populating the DP Array:**
   - For each element `num` in `nums`, iterate backward from `target` to `num`.
   - Update `dp[j]` with the maximum of `dp[j]` and `dp[j - nums[i]] + nums[i]`.
     - `dp[j]`: Best sum achievable without the current element.
     - `dp[j - nums[i]] + nums[i]`: Best sum achievable by including the current element.
   - This process essentially tries to find the best sum close to `target` achievable with the current set of elements.
4. **1-Dimensional Array for Space Optimization:**
   - Instead of a 2D array (common in knapsack problems), a 1D array is used.
   - Each element `dp[j]` gets updated based on its previous state and the state `j - nums[i]` steps before.
   - This is possible because we only need information from the previous iteration (i.e., when considering the previous element in `nums`), not the entire history.
5. **Checking for Solution:**
   - If `dp[target]` equals `target`, it means there exists a subset of `nums` whose sum is exactly `target`. Hence, return `true`.
   - Otherwise, return `false`.

***Complexity***:

- **Space Complexity:** Reduced from $O(n\times \mathrm{sum})$ in a 2D approach to $O(\mathrm{sum})$, where `sum` is the total sum of elements in `nums`.
- **Time Complexity:** $O(n\times \mathrm{target})$.

### Way 2

```C++

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int x : nums) sum += x;
        
        if (sum % 2) return false;
        else sum /= 2;
        
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = sum; j >= x; j--) {
                dp[j] |= dp[j - x];
            }
        }
        return dp[sum];
    }
};
```

***Explanation***:

1. **Calculate Total Sum and Target:**
   - The total sum of elements in `nums` is calculated.
   - If the sum is odd (`sum % 2`), it's impossible to split into two equal sums, hence return `false`.
   - Otherwise, the target is set to half of the total sum.
2. **Dynamic Programming (DP) Array Initialization:**
   - A `dp` array of size `sum + 1` is initialized to zero, except `dp[0]` which is set to 1.
   - `dp[i]` will represent whether it's possible to achieve a sum of `i` using the elements from `nums`.
3. **Populating the DP Array:**
   - Iterate over each element `x` in `nums`.
   - For each `x`, iterate backward from `sum` to `x`.
   - Update `dp[j]` using the bitwise OR operator: `dp[j] |= dp[j - x]`.

Understanding `dp[j] |= dp[j - x]`:

- `dp[j]`: Represents if it's possible to achieve a sum of `j` with the current set of elements.
- `dp[j - x]`: Represents if it's possible to achieve a sum of `j - x` with the elements considered so far. If this is true, then adding `x` to this subset would achieve the sum `j`.

The bitwise OR operation `|=` is used here for a critical reason:

- `dp[j] |= dp[j - x]` effectively sets `dp[j]` to 1 if either `dp[j]` was already 1 (meaning a sum of `j` was already achievable) or if `dp[j - x]` is 1 (meaning by adding the current element `x`, we can achieve a sum of `j`).
- It's a concise way of saying `dp[j] = dp[j] || dp[j - x]`, where `||` is the logical OR operator.

This approach updates the DP array to reflect whether each target sum is achievable with the current subset of numbers.

### Way 3

```C++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> f;
        f[0] = 1;
        int sum = 0;
        for (auto x : nums) {
            f |= f << x;
            sum += x;
        }
        if (sum % 2) return false;
        return f[sum / 2];
    }
};
```
