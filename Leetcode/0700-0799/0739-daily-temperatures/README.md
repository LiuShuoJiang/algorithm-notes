# Daily Temperatures

[Link](https://leetcode.com/problems/daily-temperatures/description/)

## Description

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `i-th` day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

Example 1:

- Input: `temperatures = [73,74,75,71,69,72,76,73]`
- Output: `[1,1,4,2,1,1,0,0]`

Example 2:

- Input: `temperatures = [30,40,50,60]`
- Output: `[1,1,1,0]`

Example 3:

- Input: `temperatures = [30,60,90]`
- Output: `[1,1,0]`

Constraints:

- `1 <= temperatures.length <= 10^5`
- `30 <= temperatures[i] <= 100`

## Solution

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

- Time complexity: $O(N)$;
- Space complexity: $O(N)$.

### Analysis of Solution

**Understanding Monotonic Stack**: A monotonic stack is a stack where the elements are always in sorted order. In this problem, we'll use a decreasing monotonic stack. The stack will store the indices of the `temperatures` array, and at each step, we'll use it to find the next warmer temperature.

**Algorithm**:

- Initialize an empty stack and a result vector of the same size as `temperatures`, with all values set to 0.
- Iterate over the `temperatures` array.
- For each temperature, while the stack is not empty and the current temperature is greater than the temperature at the index on the top of the stack:
    - Pop the index from the stack.
    - Calculate the number of days between the current day and the popped day, and update the corresponding position in the result vector.
- Push the current index onto the stack.

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> indices;

        for (int i = 0; i < n; i++) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                int prevIndex = indices.top();
                indices.pop();
                answer[prevIndex] = i - prevIndex;
            }
            indices.push(i);
        }

        return answer;
    }
};
```

**Explanation**:

- The stack `indices` stores indices of days with temperatures for which we haven't found a warmer day yet.
- If the current day's temperature is warmer than the temperature at the top index of the stack, we calculate the difference in days and store it in `answer`.
- We continue this process until we find a day in the stack which has a temperature equal to or warmer than the current day or the stack becomes empty.
- The `answer` array stores the number of days to wait for a warmer temperature for each day. If no warmer temperature is found in the future, it remains 0 (as initialized).

### About Monotonic Stack

The monotonic stack is a specialized stack used for solving problems related to sequences, where we need to find the next or previous greater or smaller elements in an array. It's useful in this problem because it efficiently maintains a collection of elements in sorted order (either increasing or decreasing), allowing us to quickly access the next or previous element that satisfies a certain condition.

In the "Daily Temperatures" problem, the monotonic stack is used to keep track of temperatures that haven't yet found a warmer day in the future. As we iterate through the temperatures:

- If the current temperature is higher than the temperature at the index on the top of the stack, it means we have found a warmer day for that index. We pop it from the stack and update our answer.
- If the current temperature is not higher, it gets pushed onto the stack to wait for its warmer day.

This approach is efficient because each element is pushed and popped at most once, leading to an $O(N)$ time complexity.

1. **First Greater Element to the Right (Decreasing Monotonic Stack)**
   - **Property**: Use a decreasing monotonic stack.
   - **Why**: To find the next greater element, we want the stack to pop smaller elements when a greater element is encountered.

```C++
vector<int> nextGreaterElementRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // initialize with -1
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}
```

2. **First Smaller Element to the Right (Increasing Monotonic Stack)**
   - **Property**: Use an increasing monotonic stack.
   - **Why**: To find the next smaller element, the stack should pop larger elements when a smaller element is encountered.

```C++
vector<int> nextSmallerElementRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] > nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}
```

3. **First Greater Element to the Left (Decreasing Monotonic Stack)**
   - **Property**: Use a decreasing monotonic stack.
   - **Why**: Similar to the first case but iterating from right to left.

```C++
vector<int> previousGreaterElementLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            result[i] = nums[s.top()];
            s.pop();
        }
        s.push(i);
    }

    return result;
}
```

4. **First Smaller Element to the Left (Increasing Monotonic Stack)**
   - **Property**: Use an increasing monotonic stack.
   - **Why**: Similar to the second case but iterating in reverse.

```C++
vector<int> previousSmallerElementLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] > nums[i]) {
            result[i] = nums[s.top()];
            s.pop();
        }
        s.push(i);
    }

    return result;
}
```
