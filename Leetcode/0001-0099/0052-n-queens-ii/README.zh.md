# N皇后 II

[Leetcode题目链接](https://leetcode.com/problems/n-queens-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/n-queens-ii/description/)。

## 解答

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
