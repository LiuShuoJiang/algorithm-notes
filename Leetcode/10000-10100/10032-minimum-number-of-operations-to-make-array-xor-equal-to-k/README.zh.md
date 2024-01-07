# 数组异或和等于 K 的最少操作次数

[Leetcode题目链接](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/)

## 描述

详见[中文题目连接](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/)。

## 解答

```C++
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> oneCnt(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) oneCnt[i]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (k & (1 << i)) {  //if ith bit in k = 1
                if (!(oneCnt[i] % 2)) ans++;
            } else {
                if (oneCnt[i] % 2) ans++;
            }
        }
        return ans;
    }
};
```
