# Next Greater Element I

[Link](https://leetcode.com/problems/next-greater-element-i/description/)

## Description

The **next greater element** of some element `x` in an array is the first greater element that is to the right of `x` in the same array.

You are given two ***distinct 0-indexed*** integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the next greater element of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return an array `ans` of length `nums1.length` such that `ans[i]` is the next greater element as described above.

Example 1:

- Input: `nums1 = [4,1,2], nums2 = [1,3,4,2]`
- Output: `[-1,3,-1]`
- Explanation: The next greater element for each value of `nums1` is as follows:
    - 4 is underlined in `nums2 = [1,3,4,2]`. There is no next greater element, so the answer is -1.
    - 1 is underlined in `nums2 = [1,3,4,2]`. The next greater element is 3.
    - 2 is underlined in `nums2 = [1,3,4,2]`. There is no next greater element, so the answer is -1.

Example 2:

- Input: `nums1 = [2,4], nums2 = [1,2,3,4]`
- Output: `[3,-1]`
- Explanation: The next greater element for each value of `nums1` is as follows:
    - 2 is underlined in `nums2 = [1,2,3,4]`. The next greater element is 3.
    - 4 is underlined in `nums2 = [1,2,3,4]`. There is no next greater element, so the answer is -1.

Constraints:

- `1 <= nums1.length <= nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 10^4`
- All integers in `nums1` and `nums2` are unique.
- All the integers of `nums1` also appear in `nums2`.

## Solution

### Solution 1

- Use a decreasing monotonic stack to find the next greater element for each element in `nums2`.
- Store these mappings (element to its next greater element) in a hash map.
- Iterate through `nums1` and use the hash map to find the next greater element for each number. If it doesn't exist in the hash map, it means there is no next greater element, so we use -1.

```C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> nextGreater;

        // Building the map for next greater elements in nums2
        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                nextGreater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        // Filling the results for nums1 based on the map
        vector<int> res;
        for (int num : nums1) {
            if (nextGreater.find(num) != nextGreater.end())
                res.push_back(nextGreater[num]);
            else
                res.push_back(-1);
        }

        return res;
    }
};
```

- The stack `s` keeps track of elements in `nums2` for which we are yet to find the next greater element.
- When iterating through `nums2`, if we find an element greater than the element on the top of the stack, it means we've found the next greater element for the stack's top element. We record this in the `nextGreater` map.
- Finally, for each element in `nums1`, we look up the `nextGreater` map. If an entry exists, we add it to the result; otherwise, we add -1.

Complexity:

- Time complexity: $O(N+M)$, where $N$ and $M$ are the lengths of `nums1` and `nums2`, respectively;
- Space complexity: $O(N)$.

### Solution 2

```C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> res(nums1.size(), -1);  // Initialize the result array with -1 for each element in nums1
        
        // Create a mapping from elements of nums1 to their indices
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums1.size(); i++) mapping[nums1[i]] = i;

        // Push the first index of nums2 onto the stack
        stk.push(0);

        // Iterate through nums2 to find next greater elements
        for (int i = 1; i < nums2.size(); i++) {
            // Check if the current element is greater than the element at the index on top of the stack
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                // If the element at the top of the stack is in nums1 (using mapping)
                if (mapping.count(nums2[stk.top()])) {
                    int index = mapping[nums2[stk.top()]];  // Get the corresponding index in nums1
                    res[index] = nums2[i];  // Update the result array for that element in nums1
                }
                stk.pop();  // Pop the element from the stack as we've found its next greater element
            }
            stk.push(i);  // Push the current index onto the stack
        }

        return res;
    }
};
```

- Time complexity: $O(N+M)$, where $N$ and $M$ are the lengths of `nums1` and `nums2`, respectively;
- Space complexity: $O(N+M)$.
