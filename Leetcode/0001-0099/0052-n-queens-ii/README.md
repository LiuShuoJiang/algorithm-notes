# N-Queens II

[Link](https://leetcode.com/problems/n-queens-ii/description/)

## Description

The n-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return the number of distinct solutions to the n-queens puzzle.

Example 1:

- Input: `n = 4`
- Output: `2`
- Explanation: There are two distinct solutions to the `4`-queens puzzle as shown.

Example 2:

- Input: `n = 1`
- Output: `1`

Constraints:

- `1 <= n <= 9`

## Solution

```C++
class Solution {
private:
    int res;
    vector<bool> dg, udg, col;
    int _n;
    void backtracking(int row) {
        if (row == _n) {
            res++;
            return;
        }
        for (int i = 0; i < _n; i++) {
            if (!col[i] && !dg[row - i + _n] && !udg[row + i]) {
                col[i] = dg[row - i + _n] = udg[row + i] = true;
                backtracking(row + 1);
                col[i] = dg[row - i + _n] = udg[row + i] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        _n = n;
        col = vector<bool>(n, false);
        dg = udg = vector<bool>(2 * n, false);
        res = 0;
        backtracking(0);
        return res;
    }
};
```

- Time complexity: $O(N!)$;
- Space complexity: $O(N)$.

Another way of writing:

```C++
class Solution {
private:
    vector<bool> col, dg, udg;
    int _n;
    int backtracking(int row) {
        if (row == _n) return 1;
        int res = 0;
        for (int i = 0; i < _n; i++) {
            if (!col[i] && !dg[row - i + _n] && !udg[row + i]) {
                col[i] = dg[row - i + _n] = udg[row + i] = true;
                res += backtracking(row + 1);
                col[i] = dg[row - i + _n] = udg[row + i] = false;
            }
        }
        return res;
    }
public:
    int totalNQueens(int n) {
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        _n = n;
        return backtracking(0);
    }
};
```
