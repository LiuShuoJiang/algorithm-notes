# Integer Break

[Link](https://leetcode.com/problems/integer-break/description/)

## Description

Given an integer `n`, break it into the sum of `k` positive integers, where `k >= 2`, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:

- Input: `n = 2`
- Output: `1`
- Explanation: `2 = 1 + 1, 1 × 1 = 1`.

Example 2:

- Input: `n = 10`
- Output: `36`
- Explanation: `10 = 3 + 3 + 4, 3 × 3 × 4 = 36`.

Constraints:

- `2 <= n <= 58`

## Solution

### Way 1

```C++
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++)
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
        return dp[n];
    }
};
```

- Time complexity: $O(n^2)$;
- Space complexity: $O(n)$.

### Way 2

See [reference](https://www.acwing.com/solution/content/368/).

```C++
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return 1 * (n - 1);
        int p = 1;
        while (n >= 5) n -= 3, p *= 3;
        return p * n;
    }
};
```

There are only a finite number of ways to split a positive integer into a number of positive integers, so there exists a maximum product. Assume $N=n_1+n_2+\cdots +n_k$, and $n_1\cdot n_2\cdot \cdots \cdot n_k$ is the maximum product.

1. Obviously $1$ won't be in there;
2. If for some $i$ such that $n_i \geqslant 5$, then we split $n_i$ into $3+\left( n_i-3 \right)$. We have $3\cdot \left( n_i-3 \right) =3n_i-9>n_i$;
3. If $n_i =4$, Splitting into a $2+2$ product leaves the product unchanged, so it might as well be assumed that there is no $4$;
4. If there are more than three $2$'s, then $3\times 3>2\times 2\times 2$, so the substitution into $3$ multiplies the product even more.

To summarize, choose as many $3$s as possible until $2$ or $4$ are left, then use $2$.

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
