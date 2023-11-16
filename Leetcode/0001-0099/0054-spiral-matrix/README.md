# Spiral Matrix

[Link](https://leetcode.com/problems/spiral-matrix/description/)

## Description

Given an $m\times n$ `matrix`, return all elements of the `matrix` in spiral order.

Example 1:

- Input: `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
- Output: `[1,2,3,6,9,8,7,4,5]`

Example 2:

- Input: `matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]`
- Output: `[1,2,3,4,8,12,11,10,9,5,6,7]`

Constraints:

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

## Solution

### Way 1

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int upper_bound = 0, lower_bound = m - 1;
        int left_bound = 0, right_bound = n - 1;
        // res.size() == m * n then all the array is traversed
        while (res.size() < m * n) {
            if (upper_bound <= lower_bound) {
                // Iterate from left to right at the top
                for (int j = left_bound; j <= right_bound; j++)
                    res.push_back(matrix[upper_bound][j]);
                // Move the upper boundary down
                upper_bound++;
            }

            if (left_bound <= right_bound) {
                // Iterate from top to bottom on the right side
                for (int i = upper_bound; i <= lower_bound; i++)
                    res.push_back(matrix[i][right_bound]);
                // Shift the right boundary left
                right_bound--;
            }

            if (upper_bound <= lower_bound) {
                // Iterate from right to left at the bottom
                for (int j = right_bound; j >= left_bound; j--)
                    res.push_back(matrix[lower_bound][j]);
                // Move the lower boundary up
                lower_bound--;
            }

            if (left_bound <= right_bound) {
                // Iterate from bottom to top on the left side
                for (int i = lower_bound; i >= upper_bound; i--)
                    res.push_back(matrix[i][left_bound]);
                // Move the left boundary right
                left_bound++;
            }
        }
        return res;
    }
};
```

- Time complexity: $O(nm)$;
- Space complexity: $O(1)$

### Way 2: Direction Array (Preferred)

$$
\begin{cases}
	\Rightarrow : \left( 0,1 \right)\\
	\Downarrow : \left( 1,0 \right)\\
	\Leftarrow : \left( 0,-1 \right)\\
	\Uparrow : \left( -1,0 \right)\\
\end{cases}
$$

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();  // # of rows of matrix
        if (!n) return res;
        int m = matrix[0].size();  // # of columns of matrix

        // direction array
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        // track if we have traversed to the element
        vector<vector<bool>> state(n, vector<bool>(m));

        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i++) {
            res.push_back(matrix[x][y]);
            state[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            // change direction
            if (a < 0 || a >= n || b < 0 || b >= m || state[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
```

- Time complexity: $O(nm)$;
- Space complexity: $O(n)$
