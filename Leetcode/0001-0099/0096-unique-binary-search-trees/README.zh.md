# 不同的二叉搜索树

[Leetcode题目链接](https://leetcode.com/problems/unique-binary-search-trees/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/unique-binary-search-trees/)。

## 解答

```C++
class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for (int i = n + 1; i <= 2 * n; i++) {
            res = res * i / (i - n);
        }
        return res / (n + 1);
    }
};
```
