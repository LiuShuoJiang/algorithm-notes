# 每日温度

[Leetcode题目链接](https://leetcode.com/problems/daily-temperatures/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/daily-temperatures/)。

## 解答

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return res;
    }
};
```
