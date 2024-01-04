# Kth Largest Element in a Stream

[Link](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

## Description

Design a class to find the `k`-th largest element in a stream. Note that it is the `k`-th largest element in the sorted order, not the `k`-th distinct element.

Implement `KthLargest` class:

- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Appends the integer `val` to the stream and returns the element representing the `k`-th largest element in the stream.

Example 1:

- Input:

```C++
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
```

- Output:

```C++
[null, 4, 5, 5, 8, 8]
```

- Explanation:

```C++
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

Constraints:

- `1 <= k <= 10^4`
- `0 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to add.
- It is guaranteed that there will be at least `k` elements in the array when you search for the `k`-th element.

## Solution

### Using Set

```C++
class KthLargest {
private:
    int _k;
    multiset<int> s;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            s.insert(num);
            if (s.size() > k) s.erase(s.begin());
        }
        _k = k;
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() > _k) s.erase(s.begin());
        return *s.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

### Using Heap

```C++
class KthLargest {
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        this->_k = k;
    }
    
    int add(int val) {
       q.push(val);
       if (q.size() > _k) q.pop();
       return q.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

- Time complexity: $O(n\log k)$ for initializing elements in the heap, and $O(\log k)$ for each insertion operation;
- Space complexity: $O(k)$.
