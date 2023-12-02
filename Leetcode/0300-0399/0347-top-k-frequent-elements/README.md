# Top K Frequent Elements

[Link](https://leetcode.com/problems/top-k-frequent-elements/description/)

## Description

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

Example 1:

- Input: `nums = [1,1,1,2,2,3], k = 2`
- Output: `[1,2]`

Example 2:

- Input: `nums = [1], k = 1`
- Output: `[1]`

Constraints:

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is guaranteed that the answer is unique.

## Solution

### Using Max Heap

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a hash map to store the frequency of each number
        unordered_map<int, int> mapping;
        for (auto num : nums) mapping[num]++;

        // Create a max heap to store pairs of (frequency, number)
        priority_queue<pair<int, int>> q;

        // Resultant vector to store the top k frequent elements
        vector<int> res;

        // Iterate over the frequency map
        for (auto it = mapping.begin(); it != mapping.end(); it++) {
            // Push the pair (frequency, number) into the max heap
            q.emplace(make_pair(it->second, it->first));

            // If the size of the max heap is greater than the number of unique elements minus k
            if (q.size() > mapping.size() - k) {
                // Add the top element (number with highest frequency so far) to the result
                res.emplace_back(q.top().second);
                // Remove the top element from the max heap
                q.pop();
            }
        }
        
        // Return the resultant vector containing top k frequent elements
        return res;
    }
};
```

***Explanation***:

1. **Frequency Mapping**: First, the algorithm creates a hash map (`unordered_map`) to count the frequency of each element in the input vector `nums`.
2. **Max Heap Creation**: It then uses a max heap (`priority_queue`) to store pairs of (frequency, element). The max heap is used to efficiently retrieve the element with the highest frequency.
3. **Heap Manipulation**: For each element in the frequency map, the algorithm pushes a pair of (frequency, element) into the max heap. If the size of the max heap exceeds the number of unique elements minus `k`, it means we have found one of the top `k` frequent elements. This element is added to the result vector, and then removed from the max heap.
4. **Result Compilation**: This process is repeated until all top `k` frequent elements are found and added to the result vector.

***Time Complexity Analysis***:

1. **Frequency Mapping**: $O(N)$, where $N$ is the number of elements in `nums`. Each element is visited once to update the frequency map.
2. **Heap Operations**:
   - Inserting an element into the heap takes $O(\log M)$ time, where $M$ is the number of unique elements in `nums`.
   - The for loop iterates $M$ times, and each iteration may involve a heap insertion.
   - Therefore, the total time for heap operations is $O(M \log M)$.

Overall, the time complexity is $O(N + M \log M)$. In the worst case, where all elements are unique, $M$ becomes $N$, and the time complexity is $O(N \log N)$.

***Space Complexity Analysis***:

1. **Frequency Map**: $O(M)$, where $M$ is the number of unique elements in `nums`.
2. **Max Heap**: $O(M)$, for storing the frequency and element pairs.
3. **Result Vector**: $O(K)$, for storing the top $k$ frequent elements.

Hence, the total space complexity is $O(M + K)$. In the worst case, this becomes $O(N)$, where $N$ is the number of elements in `nums` and all elements are unique.

### Using Min Heap

The min heap now keeps the least frequent elements at the top. When its size exceeds `k`, the least frequent element is popped out, ensuring that only the `k` most frequent elements remain.

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Using unordered_map for frequency mapping
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Custom comparator for min heap
        auto comp = [&freqMap](int n1, int n2) { return freqMap[n1] > freqMap[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        // Keep the size of the heap to k
        for (auto& [num, freq] : freqMap) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Prepare the result vector
        vector<int> topK;
        topK.reserve(k); // Reserve space for k elements
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top());
            minHeap.pop();
        }

        return topK;
    }
};
```

- Time complexity: $O(N\log k)$;
- Space complexity: $O(N + k)$.

### Counting Sort

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashing;
        for (auto elm : nums) hashing[elm]++;
        int n = nums.size();
        vector<int> count(n + 1, 0);
        for (auto &p : hashing) count[p.second]++;
        int i = n, t = 0;
        while (t < k) t += count[i--];
        vector<int> res;
        for (auto &p : hashing) {
            if (p.second > i) res.push_back(p.first);
        }
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a hash map to store the frequency of each number
        unordered_map<int, int> cnt;
        for (auto elm : nums) cnt[elm]++;

        // Get the size of the input vector
        int n = nums.size();

        // Create a vector to count the frequencies of frequencies
        vector<int> count(n + 1, 0);
        for (auto [elm, freq] : cnt) count[freq]++;

        // Find the minimum frequency that allows us to reach k elements
        int threshold = n, t = 0;
        while (t < k) t += count[threshold--];

        // Collect elements whose frequency is greater than the threshold
        vector<int> res;
        for (auto [elm, freq] : cnt) {
            if (freq > threshold) res.push_back(elm);
        }

        return res;
    }
};
```

***Explanation***:

1. **Frequency Mapping**: The algorithm starts by creating a hash map (`unordered_map`) to count the frequency of each element in the input vector `nums`.
2. **Frequency of Frequencies**: It then creates a vector `count` where `count[i]` represents how many elements appear exactly `i` times in `nums`. This is a key step that differentiates this solution from others, as it essentially performs a counting sort on the frequencies.
3. **Finding the Threshold**: The algorithm then determines the minimum frequency (`threshold`) that is needed to ensure that the sum of the counts of elements with frequency higher than `threshold` is at least `k`. This step ensures that we include only the top `k` frequent elements.
4. **Collecting Results**: Finally, it iterates over the frequency map again and adds elements to the result vector `res` if their frequency is greater than the determined `threshold`.

***Time Complexity Analysis***:

1. **Frequency Mapping**: $O(N)$, where N is the number of elements in `nums`.
2. **Counting Frequencies**: $O(N)$, as it iterates over the frequency map which can have at most $N$ unique elements.
3. **Finding the Threshold**: $O(N)$, in the worst case, it might iterate through the entire `count` vector.
4. **Collecting Results**: $O(N)$, as it iterates over the frequency map again.

Overall, the time complexity is $O(N)$, which is quite efficient as it linearly scales with the input size.

***Space Complexity Analysis***:

1. **Frequency Map**: $O(N)$, for storing the frequency of each element.
2. **Count Vector**: $O(N)$, for counting the frequencies of frequencies.
3. **Result Vector**: $O(K)$, for storing the top $k$ frequent elements.

Thus, the total space complexity is $O(N + K)$, which is mainly dominated by the size of the input and the frequency map.
