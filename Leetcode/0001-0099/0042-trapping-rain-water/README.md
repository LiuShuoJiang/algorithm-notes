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

### Double-Pointer Solution

#### Original Way of Writing

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

#### Optimized Way of Writing

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, lMax = INT_MIN, rMax = INT_MIN, sum = 0;
        while (left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);
            sum += (lMax < rMax) ? (lMax - height[left++]) : (rMax - height[right--]);
        }
        return sum;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize two pointers and two variables to keep track of the 
        // maximum height from left and right
        int left = 0, right = height.size() - 1;
        int lMax = INT_MIN, rMax = INT_MIN;
        int sum = 0; // Variable to store the total amount of trapped water

        // Loop until the two pointers meet
        while (left < right) {
            // Update the left max height
            lMax = max(lMax, height[left]);
            // Update the right max height
            rMax = max(rMax, height[right]);

            // Calculate trapped water and move pointers
            if (lMax < rMax) {
                // If left max is smaller, water trapped is limited by left max
                sum += lMax - height[left];
                left++; // Move left pointer
            } else {
                // If right max is smaller or equal, water trapped is limited by right max
                sum += rMax - height[right];
                right--; // Move right pointer
            }
        }
        return sum;
    }
};
```

***Idea and Algorithm***:

This approach uses a two-pointer technique to solve the problem. The idea is to move from both ends of the array towards the center, keeping track of the maximum height seen so far from both sides. The key observation is that the amount of water that can be trapped at a given position depends on the maximum height to its left and right.

1. **Initialization**: Two pointers (`left` and `right`) are initialized at the beginning and the end of the array. Two variables (`lMax` and `rMax`) are used to keep track of the maximum heights from the left and right sides, respectively.
2. **Processing**: The algorithm iterates until `left` and `right` pointers meet. At each step, it updates `lMax` and `rMax`.
3. **Trapping Water**: The amount of water that can be trapped at the current position is determined by the smaller of the two maximum heights (`lMax` and `rMax`) minus the height at the current position. The pointer corresponding to the smaller maximum height is then moved inward.
4. **Termination**: The loop terminates when the `left` and `right` pointers meet, ensuring that each position is visited exactly once.

- Time Complexity is $O(N)$: The algorithm iterates through the array only once. Each element is processed in constant time;
- Space Complexity is $O(1)$: No extra space is required apart from the variables used for iteration and tracking maximum heights, making this a space-efficient solution.

### Solution Using Monotonic Stack

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        // If there are less than 3 bars, no water can be trapped
        if (height.size() <= 2) return 0;

        // Initialize a stack to store the indices of bars
        stack<int> stk;

        int sum = 0; // Variable to store the total amount of trapped water

        // Iterate through each bar
        for (int i = 0; i < height.size(); i++) {

            // While the stack is not empty and the current bar is taller
            // than the bar at the top of the stack
            while (!stk.empty() && height[i] > height[stk.top()]) {
                // The top of the stack is the index of the 'valley' or 'pit'
                int mid = stk.top();
                stk.pop();

                // If the stack is empty, we cannot trap water here
                if (!stk.empty()) {
                    // Calculate the height of trapped water, which is the 
                    // minimum of the current bar and the next bar on the stack
                    // minus the height of the 'valley'
                    int h = min(height[stk.top()], height[i]) - height[mid];

                    // Width is the distance between the current bar and the next bar on the stack
                    int w = i - stk.top() - 1;

                    // Add the trapped water to the sum
                    sum += h * w;
                }
            }

            // Push the current index onto the stack
            stk.push(i);
        }

        // Return the total amount of trapped water
        return sum;
    }
};
```

- Time Complexity is $O(N)$: The algorithm iterates through each bar once. The while loop inside the for loop does not add additional complexity as each element is pushed and popped from the stack exactly once;
- Space Complexity is $O(N)$: In the worst case, all bar indices might be stored in the stack. However, this is a rare case and typically the stack will hold fewer elements.
