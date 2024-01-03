# Sort an Array

[Link](https://leetcode.com/problems/sort-an-array/description/)

## Description

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in $O(n\log n)$ time complexity and with the smallest space complexity possible.

Example 1:

- Input: `nums = [5,2,3,1]`
- Output: `[1,2,3,5]`
- Explanation: `After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).`

Example 2:

- Input: `nums = [5,1,1,2,0,0]`
- Output: `[0,0,1,1,2,5]`
- Explanation: `Note that the values of nums are not necessairly unique.`

Constraints:

- `1 <= nums.length <= 5 * 10^4`
- `-5 * 10^4 <= nums[i] <= 5 * 10^4`

## Solution

### Merge Sort

```C++
class Solution {
private:
    vector<int> tmp;
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        merge_sort(nums, l, mid); merge_sort(nums, mid + 1, r);
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= r) tmp[k++] = nums[j++];
        for (i = l, j = 0; i <= r; i++, j++) nums[i] = tmp[j];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp = vector<int>(nums.size(), 0);
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
```

- Time complexity: $O(n\log n)$;
- Space complexity: $O(\log n)$ for recursive approach, and $O(1)$ for iterative approach.

### Quick Sort

```C++
class Solution {
private:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l == r) return;
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
```

- Time complexity: average case $O(n\log n)$, worst case $O(n^2)$ (but we rarely reach the worst case);
- Space complexity: $O(\log n)$.
