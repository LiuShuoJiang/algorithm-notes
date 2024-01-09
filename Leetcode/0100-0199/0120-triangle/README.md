# Triangle

[Link](https://leetcode.com/problems/triangle/description/)

## Description

Given a `triangle` array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

Example 1:

- Input: `triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]`
- Output: `11`
- Explanation: The triangle looks like:

```
   2
  3 4
 6 5 7
4 1 8 3
```

The minimum path sum from top to bottom is `2 + 3 + 5 + 1 = 11` (underlined above).

Example 2:

- Input: `triangle = [[-10]]`
- Output: `-10`

Constraints:

- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- `-10^4 <= triangle[i][j] <= 10^4`

## Solution

### Way 1 (Top-down)

```C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = 210;
        int n = triangle.size();
        vector<vector<int>> dp(N, vector<int>(N, 0x3f3f3f3f));

        dp[1][1] = triangle[0][0];
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + triangle[i - 1][j - 1], dp[i - 1][j] + triangle[i - 1][j - 1]);
            }
        }

        int res = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) res = min(res, dp[n][i]);
        return res;
    }
};
```

- Time complexity: $O(n^2)$;
- Space complexity: $O(n^2)$.

### Way 2 (Bottom-up)

```C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```

`DP[i][j] = triangle[i][j] + min(DP[i+1][j], DP[i+1][j+1])`

- Time complexity: $O(n^2)$;
- Space complexity: $O(1)$.
