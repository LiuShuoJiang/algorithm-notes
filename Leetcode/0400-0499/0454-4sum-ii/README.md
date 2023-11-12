# 4Sum II

[Link](https://leetcode.com/problems/4sum-ii/description/)

## Description

Given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4` all of length `n`, return the number of tuples `(i, j, k, l)` such that:

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

Example 1:

- Input: `nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]`
- Output: 2

Explanation:

The two tuples are:

1. `(0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0`
2. `(1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0`

Example 2:

- Input: `nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]`
- Output: 1

Constraints:

- `n == nums1.length`
- `n == nums2.length`
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- `-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28`

## Solution

### Hash Map

Steps to solve this problem:

1. First, define an `unordered_map`, put the key in the sum of the two numbers `num1` and `num2`, and the value in the number of times the sum of the two numbers `num1` and `num2` occurs.
2. Iterate through the large `nums1` and `nums2` arrays, count the sum of the elements of the two arrays and the number of occurrences, and put them into the map.
3. Define the int variable `res` to count the number of times `a + b + c + d == 0`.
4. Iterate through the big `nums3` and big `nums4` arrays, and find out if `0 - (c + d)` has appeared in the map, then use res to count the value corresponding to the key in the map, that is, the number of times it has appeared.
5. Finally, return the count value `res` can be.

```C++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mapping;
        for (auto num1 : nums1) {
            for (auto num2 : nums2) {
                mapping[num1 + num2]++;
            }
        }
        int res = 0;
        for (auto num3 : nums3) {
            for (auto num4 : nums4) {
                auto temp = -(num3 + num4);
                if (mapping.count(temp)) res += mapping[temp];
                //the two lines of code above can be replaced with this one line of code:
                //res += mapping[-(num3 + num4)];
            }
        }
        return res;
    }
};
```

Note: [Hash Mapping Indexing](https://stackoverflow.com/questions/10124679/what-happens-if-i-read-a-maps-value-where-the-key-does-not-exist)

Time and space complexity: $O(n^2)$
