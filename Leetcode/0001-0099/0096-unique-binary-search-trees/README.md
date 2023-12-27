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

### Way 2 (Dynamic Programming)

***Define the `dp` array (`dp` table) and the meaning of its index***:

`dp[i]`: The number of binary search trees composed of nodes `1` to `i` is `dp[i]`.

It can also be understood as the number of binary search trees composed of `i` different element nodes is `dp[i]`, which is the same.

***Determine the recurrence relation***:

The recurrence relation can been observed: `dp[i] += dp[number of nodes in the left subtree with j as the root node] * dp[number of nodes in the right subtree with j as the root node]`.

`j` is equivalent to the element of the root node, iterating from `1` to `i`.

So the recurrence formula is: `dp[i] += dp[j - 1] * dp[i - j]`; where `j-1` is the number of nodes in the left subtree with `j` as the root, and `i-j` is the number of nodes in the right subtree with `j` as the root.

***How to initialize the dp array***:

For initialization, only `dp[0]` needs to be initialized, which is the basis for derivation, all based on `dp[0]`.

So, what should `dp[0]` be? From a definitional perspective, an empty node is also a binary tree, and it is also a binary search tree, which is reasonable.

From the perspective of the recurrence formula, in `dp[number of nodes in the left subtree with j as the root node] * dp[number of nodes in the right subtree with j as the root node]`, if the number of nodes in the left subtree with `j` as the root node is `0`, then `dp[number of nodes in the left subtree with j as the root node] = 1` is needed, otherwise, the result of the multiplication would become `0`.

Therefore, initialize `dp[0] = 1`.

```C++
class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
```

Formally, let $f(n)$ denotes the total number of binary search trees with $n$ unique nodes. The left subtree can have $0,1,\cdots ,n-2,n-1$ nodes, and the corresponding right subtree can have $n-1, n-2,\cdots ,1,0$ nodes. Therefore:

$$
f\left( n \right) =\sum_{k=0}^{n-1}{f\left( k \right) \cdot f\left( n-1-k \right)}
$$

- Time complexity: $O(n^2)$;
- Space complexity: $O(n)$.
