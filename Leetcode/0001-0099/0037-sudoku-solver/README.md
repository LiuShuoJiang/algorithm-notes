# Sudoku Solver

[Link](https://leetcode.com/problems/sudoku-solver/description/)

## Description

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

The `'.'` character indicates empty cells.

Example 1:

![question](./Sudoku-by-L2G-20050714.svg.png)

- Input:

```C++
board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
```

- Output:

```C++
[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
```

- Explanation: The input board is shown above and the only valid solution is shown below:

![solution](./250px-Sudoku-by-L2G-20050714_solution.svg.png)

Constraints:

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit or `'.'`.
- It is guaranteed that the input board has only one solution.

## Solution

```C++
class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            if (backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val)
                return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[j][col] == val)
                return false;
        }
        int rowIndex = (row / 3) * 3;
        int colIndex = (col / 3) * 3;
        for (int i = rowIndex; i < rowIndex + 3; i++) {
            for (int j = colIndex; j < colIndex + 3; j++) {
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
```
