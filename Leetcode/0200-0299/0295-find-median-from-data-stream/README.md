# Find Median from Data Stream

[Link](https://leetcode.com/problems/find-median-from-data-stream/description/)

## Description

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

- For example, for `arr = [2,3,4]`, the median is `3`.
- For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the MedianFinder class:

`MedianFinder()` initializes the `MedianFinder` object.
`void addNum(int num)` adds the integer `num` from the data stream to the data structure.
`double findMedian()` returns the median of all elements so far. Answers within `10^-5` of the actual answer will be accepted.

Example 1:

- Input:
    - `["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]`
    - `[[], [1], [2], [], [3], []]`
- Output:
    - `[null, null, null, 1.5, null, 2.0]`

Explanation:

```C++
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

Constraints:

- `-10^5 <= num <= 10^5`
- There will be at least one element in the data structure before calling `findMedian`.
- At most `5 * 10^4` calls will be made to `addNum` and `findMedian`.

## Solution

```C++
class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.size() >= large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (large.size() < small.size()) return small.top();
        else if (large.size() > small.size()) return large.top();

        return (large.top() + small.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

### Class Structure

- **Class MedianFinder**: Contains two priority queues `small` and `large`.
  - `small`: A max heap (standard priority queue in C++) that stores the smaller half of the numbers.
  - `large`: A min heap (priority queue with `greater<int>` comparison) that stores the larger half of the numbers.

### Constructor

- **MedianFinder()**: Initializes the MedianFinder object. It doesn't require any specific initialization for the heaps as their constructors handle that.

### Function addNum(int num)

- The function ensures that the two heaps are either equal in size or have a size difference of one.
- If `small` has more or equal elements than `large`, the new number is added to `small` and then the maximum element from `small` is moved to `large`.
- Otherwise, the new number is added to `large` and then the minimum element from `large` is moved to `small`.
- This approach maintains the heaps such that `small` contains the smaller half of the numbers, and `large` contains the larger half. The top of `small` is always less or equal to the top of `large`.

### Function findMedian()

- Returns the median of the current data stream.
- If `small` has more elements, the median is the top of `small`.
- If `large` has more elements, the median is the top of `large`.
- If they are of equal size, the median is the average of the tops of both `small` and `large`.

### Complexity Analysis

- Time Complexity:
    - `addNum(int num)`
        - Insertion into a priority queue: $O(\log n)$, where $n$ is the number of elements in the heap.
        - Extracting the top and inserting into the other heap: $O(\log n)$.
        - Total for each insertion: $O(\log n)$.
    - `findMedian()`
        - Returning the top of a heap or calculating the average of the tops of two heaps: $O(1)$.
- Space Complexity: The space complexity is $O(n)$, where $n$ is the number of elements in the data stream. This is because the data structure stores all the elements in the two heaps.

## Follow-Up

If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

```C++
class MedianFinder {
private:
    map<int, int> head, tail;
    int arr[101] = {0};
    int a = 0, b = 0, c = 0;

public:
    void addNum(int num) {
        if (num >= 0 && num <= 100) {
            arr[num]++;
            b++;
        } else if (num < 0) {
            head[num]++;
            a++;
        } else { // num > 100
            tail[num]++;
            c++;
        }
    }

    double findMedian() {
        int size = a + b + c;
        if (size % 2 == 0) {
            return (find(size / 2) + find(size / 2 + 1)) / 2.0;
        }
        return find(size / 2 + 1);
    }

    int find(int n) {
        if (n <= a) {
            for (const auto& p : head) {
                n -= p.second;
                if (n <= 0) return p.first;
            }
        } else if (n <= a + b) {
            n -= a;
            for (int i = 0; i <= 100; ++i) {
                n -= arr[i];
                if (n <= 0) return i;
            }
        } else {
            n -= a + b;
            for (const auto& p : tail) {
                n -= p.second;
                if (n <= 0) return p.first;
            }
        }
        return -1; // should never reach here
    }
};
```
