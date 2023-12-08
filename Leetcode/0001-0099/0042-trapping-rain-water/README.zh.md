# 接雨水

[Leetcode题目链接](https://leetcode.com/problems/trapping-rain-water/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/trapping-rain-water/)。

## 解答

### 双指针

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int sizeH = maxRight.size();

        maxLeft[0] = height[0];
        for (int i = 1; i < sizeH; i++)
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        
        maxRight[sizeH - 1] = height[sizeH - 1];
        for (int i = sizeH - 2; i >= 0; i--)
            maxRight[i] = max(height[i], maxRight[i + 1]);
        
        int res = 0;
        for (int i = 0; i < sizeH; i++) {
            int sum = min(maxLeft[i], maxRight[i]) - height[i];
            if (sum >= 0) res += sum;
        }
        return res;
    }
};
```

### 单调栈

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> stk;
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int h = min(height[stk.top()], height[i]) - height[mid];
                    int w = i - stk.top() - 1;
                    sum += h * w;
                }
            }
            stk.push(i);
        }
        return sum;
    }
};
```
