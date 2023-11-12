# Happy Number

[Link](https://leetcode.com/problems/happy-number/description/)

## Description

Write an algorithm to determine if a number `n` is happy.

A ***happy number*** is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.

Return `true` if `n` is a happy number, and `false` if not.

Example 1:

- Input: `n = 19`
- Output: `true`

Explanation:

```
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

Example 2:

- Input: `n = 2`
- Output: `false`

Constraints: `1 <= n <= 2^31 - 1`

## Solution

### Hash Set

The question says it will be an infinite loop, so that means the sum will be repeated during the summation process, which is important for solving the problem. When we encountered to quickly determine whether an element occurs in the set, we have to consider the ***hash method***. So this question uses the hash method, to determine whether the sum is repeated, if repeated is return false, otherwise, keep looking for, until the sum is 1. To determine whether the sum is repeated or not, just use `unordered_set`.

```C++
class Solution {
public:
    // get the sum of square for all digits of the given number 
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> S;
        while (true) {
            int sum = getSum(n);
            if (sum == 1) return true;
            // if this "sum" has occurred before, it means that we have encounter the infinite loop
            if (S.find(sum) != S.end()) {
                return false;
            } else {
                S.insert(sum);
            }
            n = sum;
        }
    }
};
```

Time and space complexity: $O(\log n)$

### Double Pointer

This problem is actually a wrapped circular chained table, where:

- A slow pointer sums the squares once for each digit.
- A fast pointer is one that sums the squares of the numbers twice each time.

There are two cases:

- Happy number: the last two pointers will be 1, and they will merge together.
- Not a happy number: it is equivalent to a circle, where the fast and slow pointers always meet at a certain number.

i.e., whether it is a happy number or not, the fast and slow pointers will eventually converge on a number, and we only need to determine whether this number is 1 or not.

```C++
class Solution {
public:
    // get the sum of square for all digits of the given number 
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = getSum(n), slow = n;
        while (fast != slow) {
            fast = getSum(getSum(fast));
            slow = getSum(slow);
        }
        return fast == 1;
    }
};
```
