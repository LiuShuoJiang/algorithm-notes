# Kth Largest Element in an Array

[Link](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

## Description

Given an integer array `nums` and an integer `k`, return the `k`-th largest element in the array.

Note that it is the `k`-th largest element in the sorted order, not the `k`-th distinct element.

Can you solve it without sorting?

Example 1:

- Input: `nums = [3,2,1,5,6,4], k = 2`
- Output: `5`

Example 2:

- Input: `nums = [3,2,3,1,2,4,5,5,6], k = 4`
- Output: `4`

Constraints:

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Solution

### Way 1

```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto num : nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};
```

- Time complexity: $O(n\log k)$;
- Space complexity: $O(k)$.

### Way 2

Quick select:

```C++
class Solution {
private:
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        int sl = j - l + 1;
        if (sl >= k) return quick_select(nums, l, j, k);

        return quick_select(nums, j + 1, r, k - sl);  // sl < k
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.
