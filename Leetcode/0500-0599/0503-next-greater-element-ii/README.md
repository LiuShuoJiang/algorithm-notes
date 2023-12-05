# Next Greater Element II

[Link](https://leetcode.com/problems/next-greater-element-ii/description/)

## Description

Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return the next greater number for every element in `nums`.

The **next greater number** of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return `-1` for this number.

Example 1:

- Input: `nums = [1,2,1]`
- Output: `[2,-1,2]`
- Explanation: The first 1's next greater number is 2; The number 2 can't find next greater number. The second 1's next greater number needs to search circularly, which is also 2.

Example 2:

- Input: `nums = [1,2,3,4,3]`
- Output: `[2,3,4,-1,4]`

Constraints:

- `1 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`

## Solution

### Original Solution

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Duplicate the input array 'nums' and append it to itself.
        // This is done to simulate the circular nature of the problem.
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        
        // Initialize a result vector 'res' of the same size as the modified 'nums'.
        // Fill it with -1, which will be the default value if no greater element is found.
        vector<int> res(nums.size(), -1);

        // Use a stack 'stk' to store indices of elements.
        // Elements in the stack will be in decreasing order from top to bottom.
        stack<int> stk;

        // Iterate through the doubled array.
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is greater than the element corresponding to the
            // index at the top of the stack, then we have found the next greater element
            // for the element at the top of the stack.
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                int prevIndex = stk.top(); // Get the index of the smaller element.
                res[prevIndex] = nums[i];  // Assign the next greater element for this index.
                stk.pop();                 // Remove the index from the stack.
            }

            // Push the current index onto the stack.
            stk.push(i);
        }

        // Since we have iterated through a doubled array, but we only need the results
        // for the original array, we cut off the extra results.
        vector<int> cutoffRes(res.begin(), res.begin() + nums1.size());

        return cutoffRes;
    }
};
```

***Explanation of the Algorithm***:

1. **Circular Array Simulation**: The algorithm first creates a duplicate of the input array and appends it to itself. This effectively simulates the circular nature of the array, allowing the algorithm to find the next greater element for each element in a single pass.
2. **Stack for Indices**: A stack is used to keep track of indices of elements. The stack maintains elements in decreasing order (from the top of the stack to the bottom). This way, when a greater element is found, it will be greater than all elements currently in the stack.
3. **Finding Next Greater Elements**: As the algorithm iterates through the doubled array, it uses the stack to track and assign the next greater elements. When a greater element is found, it updates the result array (`res`) for indices in the stack.
4. **Result Adjustment**: Because the array was doubled for the algorithm, the final result is adjusted to reflect only the results for the original array length.

### Optimized Solution

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Initialize a result vector 'res' of the same size as 'nums'.
        // Fill it with -1, which will be the default value if no greater element is found.
        vector<int> res(nums.size(), -1);

        // Use a stack 'stk' to store indices of elements.
        // Elements in the stack will be in decreasing order from top to bottom.
        stack<int> stk;

        // Iterate through the array twice to simulate the circular nature.
        // 'i % nums.size()' is used to loop back to the start of the array.
        for (int i = 0; i < nums.size() * 2; i++) {
            // If the current element is greater than the element corresponding to the
            // index at the top of the stack, then we have found the next greater element
            // for the element at the top of the stack.
            while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
                res[stk.top()] = nums[i % nums.size()]; // Assign the next greater element.
                stk.pop(); // Remove the index from the stack.
            }

            // Push the current index (mod nums.size()) onto the stack.
            stk.push(i % nums.size());
        }

        return res;
    }
};
```

***Explanation of the Algorithm***:

1. **Circular Array Simulation**: Instead of duplicating the array, this solution cleverly simulates the circular nature by iterating through the array twice (`nums.size() * 2`) and using modulo operator (`i % nums.size()`) to loop back to the start of the array.
2. **Stack for Indices**: Similar to the previous solution, a stack is used to keep track of indices, and the next greater element is found in a similar manner.
3. **Efficiency**: Since the array is not duplicated, this approach saves on the space complexity. However, the time complexity remains the same.

***Time and Space Complexity***:

- **Time Complexity**: Both versions of the solution have a time complexity of $O(n)$, where $n$ is the number of elements in the input array. Each element is pushed and popped from the stack at most once.
- **Space Complexity**:
    - The **original solution** has a space complexity of $O(2n) = O(n)$ because it duplicates the array and creates a stack of size $n$.
    - The **optimized solution** improves on space complexity as it does not duplicate the array, resulting in a space complexity of $O(n)$ only for the stack.

