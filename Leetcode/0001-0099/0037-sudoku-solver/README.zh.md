# 解数独

[Leetcode题目链接](https://leetcode.com/problems/sudoku-solver/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/sudoku-solver/description/)。

## 解答

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
