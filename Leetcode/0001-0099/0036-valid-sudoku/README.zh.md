# 有效的数独

[Leetcode题目链接](https://leetcode.com/problems/valid-sudoku/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/valid-sudoku/description/)。

## 解答

```C++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int box[3][3][9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if (row[i][num] || col[j][num] || box[i / 3][j / 3][num])
                    return false;
                row[i][num] = col[j][num] = box[i / 3][j / 3][num] = 1;
            }
        }
        return true;
    }
};
```
