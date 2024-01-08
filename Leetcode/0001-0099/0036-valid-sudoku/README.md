# Valid Sudoku

[Link](https://leetcode.com/problems/valid-sudoku/description/)

## Description

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

- Each row must contain the digits `1-9` without repetition.
- Each column must contain the digits `1-9` without repetition.
- Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

Note:

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

Example 1:

![sudoku](./250px-Sudoku-by-L2G-20050714_solution.svg.png)

- Input:

```C++
board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```

- Output: `true`

Example 2:

- Input:

```C++
board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
```

- Output: `false`
- Explanation: `Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.`

Constraints:

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `1-9` or `'.'`.

## Solution

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
