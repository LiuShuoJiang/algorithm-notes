# 排序数组

[Leetcode题目链接](https://leetcode.com/problems/sort-an-array/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/sort-an-array/)。

## 解答

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
