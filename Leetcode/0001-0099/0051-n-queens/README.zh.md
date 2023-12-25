# N皇后

[Leetcode题目链接](https://leetcode.com/problems/n-queens/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/n-queens/)。

## 解答

```C++
class Solution {
private:
    int sizeBoard;
    vector<bool> column, lDiagonal, rDiagonal;
    vector<vector<string>> res;
    vector<string> path;
    void backtracking(int index) {
        if (index == sizeBoard) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < sizeBoard; j++) {
            if (column[j] || lDiagonal[index + j] || rDiagonal[sizeBoard - index + j]) continue;
            column[j] = lDiagonal[index + j] = rDiagonal[sizeBoard - index + j] = true;
            path[index][j] = 'Q';
            backtracking(index + 1);
            path[index][j] = '.';
            column[j] = lDiagonal[index + j] = rDiagonal[sizeBoard - index + j] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        sizeBoard = n;
        column = vector<bool>(sizeBoard, false);
        lDiagonal = rDiagonal = vector<bool>(2 * sizeBoard, false);
        path = vector<string>(sizeBoard, string(sizeBoard, '.'));
        
        backtracking(0);
        
        return res;
    }
};
```
