# 数组中的第K个最大元素

[Leetcode题目链接](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/kth-largest-element-in-an-array/)。

## 解答

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
