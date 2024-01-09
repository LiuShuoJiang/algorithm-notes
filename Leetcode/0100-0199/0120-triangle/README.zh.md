# 三角形最小路径和

[Leetcode题目链接](https://leetcode.com/problems/triangle/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/triangle/description/)。

## 解答

```C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```
