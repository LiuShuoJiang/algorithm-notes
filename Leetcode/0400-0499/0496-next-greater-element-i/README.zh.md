# 下一个更大元素 I

[Leetcode题目链接](https://leetcode.com/problems/next-greater-element-i/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/next-greater-element-i/)。

## 解答

关于单调栈的讲解，[此篇博文](https://raelum.blog.csdn.net/article/details/128969669)可供参阅。

```C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> res(nums1.size(), -1);
        
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums1.size(); i++) mapping[nums1[i]] = i;
        stk.push(0);

        for (int i = 1; i < nums2.size(); i++) {
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                if (mapping.count(nums2[stk.top()])) {
                    int index = mapping[nums2[stk.top()]];
                    res[index] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        }

        return res;
    }
};
```
