# Combinations

[Link](https://leetcode.com/problems/combinations/description/)

## Description

Given two integers `n` and `k`, return all possible combinations of `k` numbers chosen from the range `[1, n]`.

You may return the answer in any order.

Example 1:

- Input: `n = 4, k = 2`
- Output: `[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]`
- Explanation: There are `4 choose 2 = 6` total combinations. Note that combinations are unordered, i.e., `[1,2]` and `[2,1]` are considered to be the same combination.

Example 2:

- Input: `n = 1, k = 1`
- Output: `[[1]]`
- Explanation: There is `1 choose 1 = 1` total combination.

Constraints:

- `1 <= n <= 20`
- `1 <= k <= n`

## Solution

### Backtracking Algorithm (Recursive)

Template pseudocode:

```
void backtracking(parameters) {
    if (termination condition) {
        store result;
        return;
    }

    for (choice : elements in the current level set (the number of children of a node in the tree is the size of the set)) {
        process node;
        backtracking(path, choice list); // recursion
        backtrack, undo processing result
    }
}
```

Original Solution:

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(int n, int k, int startIndex) {
        if (!k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k - 1, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};
```

Solution after pruning:

```C++
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }
};
```

Code with comments:

```C++
class Solution {
private:
    vector<vector<int>> res;  // To store all combinations
    vector<int> path;         // To store the current combination

    // The backtrack function to generate all combinations
    void backtrack(int n, int k, int startIndex) {
        // Base case: if the combination is of size k, add it to the result
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // Iterate through the numbers starting from startIndex
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);      // Include the number i in the current combination
            backtrack(n, k, i + 1); // Recur with the next number
            path.pop_back();        // Backtrack: remove the last number added
        }
    }

public:
    // The public function that initiates the backtracking
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);  // Start backtracking from 1
        return res;          // Return all generated combinations
    }
};
```

***Algorithm Steps***:

1. **Initialization**: The class maintains two vectors, `res` for storing all combinations and `path` for the current combination being explored.
2. **Backtracking Function (`backtrack`)**:
    - **Base Case**: If the size of `path` is equal to `k`, the desired combination size, the current combination is added to `res`.
    - **Recursive Case**: The function iterates from `startIndex` to `n - (k - path.size()) + 1`. This iteration limit ensures that there are enough elements left to complete the combination. For each iteration:
        - Add the current element `i` to `path`.
        - Recursively call `backtrack` with the next starting index (`i + 1`).
        - Perform backtracking by removing the last element from `path` to explore other combinations.
3. **Generating Combinations**: The public `combine` function initiates the backtracking process starting from index `1`.

Backtracking is a DFS (depth-first search) approach to explore all possible combinations. In this problem, backtracking helps in generating all combinations of size `k` from numbers `1` to `n`. Whenever a combination of size `k` is formed, it is added to the result. The algorithm then backtracks to replace the last element with the next possible number and continues this process until all combinations are explored.

Time Complexity:

- **Worst Case**: $O\left( C_{n}^{k}\times k \right)$
  - There are $C_{n}^{k}$ possible combinations.
  - For each combination, it takes $O(k)$ time to copy the `path` vector to `res`.

Space Complexity:

- $O\left( n+k \right) \approx O\left( n \right)$.

### Backtracking Algorithm (Iterative)

See [reference](https://leetcode.com/problems/combinations/solutions/26992/short-iterative-c-answer-8ms/).

```C++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;  // To store all combinations
        int index = 0;            // Tracks the current position in the combination
        vector<int> path(k, 0);   // Current combination, initialized with zeros

        while (index >= 0) {
            path[index]++;        // Increment the current element

            // If the current element exceeds n, move back to the previous element
            if (path[index] > n) index--;

            // If a complete combination is formed, add it to the results
            else if (index == k - 1) res.push_back(path);

            // Move to the next element and initialize it
            else {
                index++;
                path[index] = path[index - 1];
            }
        }
        return res;
    }
};
```

Code with comments:

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string toString(vector<int> v) {
    string ans = "[";
    for (int i: v) {
        ans += i + '0';
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2) + "]";
    return ans;
}

string toString(vector<vector<int>> v) {
    string ans = "[";
    for (vector<int> i: v) {
        ans += toString(i);
        ans += ", ";
    }
    ans = ans.substr(0, ans.length() - 2) + "]";
    return ans;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c(k, 0); // vector of length k, all 0s
        int i = 0;
        while (i >= 0) {
            // Increment element at index i
            c[i]++;
            cout << "Incremented element at index " << i << endl;
            cout << toString(c) << endl;
            
            /* Move index to the left if the element
             * at index i has exceeded n.
             */
            if (c[i] > n) {
                i--;
                cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
            }
            
            /* If the index is at the end of the vector
             * c, then (because the other conditions are
             * obeyed), we know we have a valid combination,
             * so push it to our ans vector<vector<>>
             */
            else if (i == k - 1) {
                ans.push_back(c);
                cout << "Combination found!" << endl;
                cout << "Added " << toString(c) << " as an answer!" << endl;
            }
            
            /* Move index to the right and set the
             * element at that index equal to the
             * element at the previous index.
             * 
             * Because of the increment at the beginning
             * of this while loop, we ensure that the
             * element at this index will be at least
             * one more than its neighbor to the left.
             */
            else {
                i++;
                c[i] = c[i - 1];
                cout << "Moved index to the right, and copied the value"
                << " from the left" << endl;
                cout << toString(c) << endl;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << toString(sol.combine(4, 2)) << endl;
    return 0;
}
```

Simulation result:

```
Incremented element at index 0
[1, 0]
Moved index to the right, and copied the value from the left
[1, 1]
Incremented element at index 1
[1, 2]
Combination found!
Added [1, 2] as an answer!
Incremented element at index 1
[1, 3]
Combination found!
Added [1, 3] as an answer!
Incremented element at index 1
[1, 4]
Combination found!
Added [1, 4] as an answer!
Incremented element at index 1
[1, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[2, 5]
Moved index to the right, and copied the value from the left
[2, 2]
Incremented element at index 1
[2, 3]
Combination found!
Added [2, 3] as an answer!
Incremented element at index 1
[2, 4]
Combination found!
Added [2, 4] as an answer!
Incremented element at index 1
[2, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[3, 5]
Moved index to the right, and copied the value from the left
[3, 3]
Incremented element at index 1
[3, 4]
Combination found!
Added [3, 4] as an answer!
Incremented element at index 1
[3, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[4, 5]
Moved index to the right, and copied the value from the left
[4, 4]
Incremented element at index 1
[4, 5]
n exceeded at 1, moving index to the left
Incremented element at index 0
[5, 5]
n exceeded at 0, moving index to the left
[[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
```

***Explanation***:

1. **Initialization**: `res` is used to store the resulting combinations. `index` is the position in the current combination being processed, and `path` is a vector of size `k`, initially filled with zeros.
2. **Iteration**: The `while` loop continues as long as `index` is non-negative.
3. **Incrementing Elements**: `path[index]++` increments the element at the current position.
4. **Backtracking**: If `path[index]` becomes greater than `n`, it means we need to backtrack, i.e., move back to the previous position (`index--`).
5. **Adding a Combination**: If `index` is `k - 1` and the current element is valid (≤ `n`), a complete combination is formed and added to `res`.
6. **Moving Forward**: If neither of the above conditions is met, the algorithm moves to the next position (`index++`) and initializes `path[index]` to `path[index - 1]`.
