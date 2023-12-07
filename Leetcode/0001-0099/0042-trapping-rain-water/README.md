# Trapping Rain Water

[Link](https://leetcode.com/problems/trapping-rain-water/description/)

## Description

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

Example 1:

![Rain Water](./rainwatertrap.png)

- Input: `height = [0,1,0,2,1,0,1,3,2,1,2,1]`
- Output: `6`
- Explanation: The above elevation map (black section) is represented by array `[0,1,0,2,1,0,1,3,2,1,2,1]`. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

- Input: `height = [4,2,0,3,2,5]`
- Output: `9`

Constraints:

- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

## Solution

### Original Solution

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
