# 岛屿数量

[Leetcode题目链接](https://leetcode.com/problems/number-of-islands/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/number-of-islands/description/)。

## 解答

```C++
class Solution {
private:
    int n, m;
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
```
