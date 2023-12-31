# Sliding Window Maximum

[Link](https://leetcode.com/problems/sliding-window-maximum/description/)

## Description

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

Example 1:

- Input: `nums = [1,3,-1,-3,5,3,6,7], k = 3`
- Output: `[3,3,5,5,6,7]`
- Explanation:

```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

Example 2:

- Input: `nums = [1], k = 1`
- Output: `[1]`

Constraints:

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

## Solution

### Implementing Monotonic Queue Data Structure

```C++
class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int value) {
            if (!que.empty() && value == que.front()) que.pop_front();
        }
        void push(int value) {
            while (!que.empty() && value > que.back()) que.pop_back();
            que.push_back(value);
        }
        int front() const { return que.front(); }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) que.push(nums[i]);
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
```

Code with comments:

```C++
class Solution {
private:
    // The MyQueue class is an internal class used for managing the sliding window.
    class MyQueue {
    public:
        deque<int> que;  // A double-ended queue to store the elements of the window

        // Pop operation for the queue which only pops the front element if it is equal to 'value'
        void pop(int value) {
            if (!que.empty() && value == que.front()) 
                que.pop_front();
        }

        // Push operation for the queue. It ensures that the queue is always arranged in a way
        // that the maximum element is at the front.
        void push(int value) {
            // Remove all elements smaller than 'value' from the back of the queue
            while (!que.empty() && value > que.back()) 
                que.pop_back();
            // Add the new 'value' to the back of the queue
            que.push_back(value);
        }

        // Returns the front element of the queue, which is the maximum element of the current window
        int front() const { return que.front(); }
    };

public:
    // The main function to find the maximum value in each sliding window of size 'k' in the array 'nums'
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que; // Instance of MyQueue to manage our sliding window
        vector<int> result; // Result vector to store the maximums of each window

        // Initialize the first window
        for (int i = 0; i < k; i++) 
            que.push(nums[i]);

        // Store the maximum of the first window
        result.push_back(que.front());

        // Iterate over the array, sliding the window one element at a time
        for (int i = k; i < nums.size(); i++) {
            // Remove the element that is exiting the window
            que.pop(nums[i - k]);
            // Add the new element to the window
            que.push(nums[i]);
            // Store the maximum of the current window
            result.push_back(que.front());
        }

        return result;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(k)$.

Easier way of writing (recommended):

```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() < i - k + 1) dq.pop_front();
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
```

### Simulate Queue Using Array

A **monotonic queue** is a type of queue where elements can be *enqueued* and ***dequeued*** from the rear, and *dequeued* from the front. Its purpose is to maintain the monotonicity of a subsequence. To maintain the maximum value, a **descending subsequence** within a sliding window is maintained.

Key points to note:

- Condition for dequeuing from the rear: ***The queue is not empty and the new element is more optimal, causing older elements to be dequeued from the rear***;
- Each element will be enqueued from the rear once;
- Condition for dequeuing from the front: Elements in the queue slide out of the window;
- The queue stores the ***indices*** of elements (rather than the elements of the array), which facilitates determining when to dequeue from the front.

Steps inside the `for` loop of the code:

1. Address the issue of the queue's front element sliding out of the window;
2. Address the issue of the rear of the queue and the current element `a[i]` not maintaining monotonicity;
3. Add the current element's index to the rear of the queue;
4. Output the result if the conditions are met.

Details to be aware of in the above steps:

- In the four steps mentioned above, step 3 should be done before step 4, as the newly added element might be the one that needs to be output;
- The queue stores the indices of the original array, so when accessing values, a further layer of indexing is needed, `a[q[]]`;
- Before calculating the maximum value, reset `hh` and `tt`;
- If `hh` starts from `0`, then the array indices should also start from `0`.

Regarding initialization:

- The initialization of `hh` and `tt` is related to the index of the first value of the array: `hh` should be less than or equal to the first index of the array (e.g., if the array index starts from `0`, `hh <= 0`; if it starts from `1`, `hh <= 1`, which could be `1`, `0`, `-1`, etc.);
- Whether the array index starts from `0` or `1` also affects the `if` condition for output, which needs to be modified accordingly:
    - If the index starts from `0`, it should be `i >= k - 1`, as the first window is `0 1 2`;
    - If the index starts from `1`, it should be `i >= k`, as the first window is `1 2 3`;
- During initialization, there should be a gap between `hh` and `tt`, i.e., `hh == tt + 1`.

```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int q[100010];
        vector<int> res;
        int hh = 0, tt = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (hh <= tt && i - k + 1 > q[hh]) hh++;
            while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;
            q[++tt] = i;
            if (i >= k - 1) res.push_back(nums[q[hh]]);
        }
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int q[100010];  // q stores the array indices
        vector<int> res;
        int hh = 0, tt = -1;  // Initialize the queue empty (hh is the head of the queue, tt is the tail of the queue)
        for (int i = 0; i < nums.size(); i++) {  // Iterate through the array
            /*
            To maintain the size of the sliding window,
            when the queue is not empty (hh <= tt) 
            and the current sliding window size (i - q[hh] + 1) is greater than the set sliding window size (k),
            dequeue the front element of the queue to maintain the size of the sliding window.
            */
            // hh <= tt means the queue is not empty
            if (hh <= tt && i - k + 1 > q[hh]) hh++;  // Dequeue from the front (front element slides out of the window)

            /*
            Constructing a monotonically increasing queue
            When the queue is not empty (hh <= tt) 
            and the tail element of the queue is less than or equal to the current element (nums[i]),
            then the tail element is definitely not the maximum value of the current window,
            so remove the tail element and add the current element (q[++tt] = i)
            */
            // Dequeue from the tail (queue not empty and new element is better)
            while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;  // This is a unique operation of the monotonic queue
            // Enqueue at the tail (note that the queue stores array indices, 
            // which facilitates determining when to dequeue from the front)
            q[++tt] = i;

            // Use the maximum value
            if (i >= k - 1) res.push_back(nums[q[hh]]);
        }
        return res;
    }
};
```
