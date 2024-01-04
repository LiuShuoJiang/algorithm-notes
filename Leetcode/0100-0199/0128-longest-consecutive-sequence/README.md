# Longest Consecutive Sequence

[Link](https://leetcode.com/problems/longest-consecutive-sequence/description/)

## Description

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in $O(n)$ time.

Example 1:

- Input: `nums = [100,4,200,1,3,2]`
- Output: `4`
- Explanation: `The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.`

Example 2:

- Input: `nums = [0,3,7,2,5,8,4,6,0,1]`
- Output: `9`

Constraints:

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Solution

### Way 1

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            if (s.find(x - 1) == s.end()) {
                int curr = x + 1;
                while (s.find(curr) != s.end()) curr++;
                best = max(best, curr - x);
            }
        }
        return best;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.

### Way 2

```C++
class Solution {
private:
    unordered_map<int, int> fa, cnt;

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    void join_sets(int x, int y) {
        int m = find(x), n = find(y);
        if (m != n) {
            fa[m] = n;
            cnt[n] += cnt[m];
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        for (int i : nums) {
            if (!fa.count(i)) {
                fa[i] = i;
                cnt[i] = 1;
            } else continue;

            if (fa.count(i - 1)) join_sets(i, i - 1);
            if (fa.count(i + 1)) join_sets(i, i + 1);
        }
        int res = 0;
        for (auto p : cnt) res = max(res, p.second);
        return res;
    }
};
```
