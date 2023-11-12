# Two Sum

[Link](https://leetcode.com/problems/two-sum/description/)

## Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

- Input: `nums = [2,7,11,15], target = 9`
- Output: `[0,1]`
- Explanation: Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

Example 2:

- Input: `nums = [3,2,4]`, `target = 6`
- Output: `[1,2]`

Example 3:

- Input: `nums = [3,3]`, `target = 6`
- Output: `[0,1]`

Constraints:

- `2 <= nums.length <= 104`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

## Solution

### Double Pointer

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> sumPos;

        for (int i = 0; i < nums.size(); i++) {
            sumPos.push_back(make_pair(nums[i], i));
        }
        
        sort(sumPos.begin(), sumPos.end());
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++) {
            while (j >= 0 && sumPos[i].first + sumPos[j].first > target) j--;
            if (sumPos[i].first + sumPos[j].first == target) {
                vector<int> res = {sumPos[i].second, sumPos[j].second};
                return res;
            }
        }
        return {};
    }
};
```

### Hash Map

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (maps.count(r)) return {maps[r], i};
            maps[nums[r]] = i;
        }
        return {};
    }
}
```

Time and space complexity: $O(n)$
