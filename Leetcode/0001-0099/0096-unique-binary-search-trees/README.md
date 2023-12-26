# Unique Binary Search Trees

[Link](https://leetcode.com/problems/unique-binary-search-trees/description/)

## Description

Given an integer `n`, return the number of structurally unique **BST**'s (binary search trees) which has exactly `n` nodes of unique values from `1` to `n`.

Example 1:

![unique trees](./uniquebstn3.jpg)

- Input: `n = 3`
- Output: `5`

Example 2:

- Input: `n = 1`
- Output: `1`

Constraints:

- `1 <= n <= 19`

## Solution

### Way 1 (Catalan Number)

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

The $n$-th [Catalan number](https://en.wikipedia.org/wiki/Catalan_number) is $\frac{1}{n+1}C_{2n}^{n}$.

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
