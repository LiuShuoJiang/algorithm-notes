# 下一个更大元素II

[Leetcode题目链接](https://leetcode.com/problems/next-greater-element-ii/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/next-greater-element-ii/)。

## 解答

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        for (int i = 0; i < nums.size() * 2; i++) {
            while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
                res[stk.top()] = nums[i % nums.size()];
                stk.pop();
            }
            stk.push(i % nums.size());
        }
        return res;
    }
};
```
