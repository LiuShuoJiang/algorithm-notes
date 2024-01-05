# 被围绕的区域

[Leetcode题目链接](https://leetcode.com/problems/surrounded-regions/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/surrounded-regions/description/)。

## 解答

```C++
class Solution {
private:
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') return;
        board[x][y] = '#';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
```
