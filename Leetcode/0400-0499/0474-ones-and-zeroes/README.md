# Ones and Zeroes

[Link](https://leetcode.com/problems/ones-and-zeroes/description/)

## Description

You are given an array of binary strings `strs` and two integers `m` and `n`.

Return the size of the largest subset of `strs` such that there are at most `m` `0`'s and `n` `1`'s in the subset.

A set `x` is a subset of a set `y` if all elements of `x` are also elements of `y`.

Example 1:

- Input: `strs = ["10","0001","111001","1","0"], m = 5, n = 3`
- Output: `4`
- Explanation: The largest subset with at most 5 0's and 3 1's is `{"10", "0001", "1", "0"}`, so the answer is `4`. Other valid but smaller subsets include `{"0001", "1"}` and `{"10", "1", "0"}`. `{"111001"}` is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:

- Input: `strs = ["10","0","1"], m = 1, n = 1
- Output: `2`
- Explanation: The largest subset is `{"0", "1"}`, so the answer is `2`.

Constraints:

- `1 <= strs.length <= 600`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists only of digits `'0'` and `'1'`.
- `1 <= m, n <= 100`

## Solution

### Way 1

```C++
class Solution {
private:
    int count(const string &str, const char c) const {
        int cnt = 0;
        for (char ch : str) {
            if (ch == c) cnt++;
        }
        return cnt;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> zeros(strs.size() + 1), ones(strs.size() + 1);
        for (int i = 1; i <= strs.size(); i++) {
            zeros[i] = count(strs[i - 1], '0');
            ones[i] = count(strs[i - 1], '1');
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        
        for (int i = 1; i <= strs.size(); i++) {
            for (int j = m; j >= zeros[i]; j--) {
                for (int k = n; k >= ones[i]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros[i]][k - ones[i]] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
```

Another way of writing:

```C++
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (string str : strs) {
            int one = 0, zero = 0;
            for (char c : str) {
                (c == '0') ? zero++ : one++;
            }
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
```

- Time complexity: $O(knm)$, where $k$ is the number of elements of `strs`;
- Space complexity: $O(mn)$.
