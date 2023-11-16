# Spiral Matrix II

[Link](https://leetcode.com/problems/spiral-matrix-ii/description/)

## Description

Given a positive integer $n$, generate an $n\times n$ matrix filled with elements from 1 to $n^2$ in spiral order.

Example 1:

- Input: `n = 3`
- Output: `[[1,2,3],[8,9,4],[7,6,5]]`

Example 2:

- Input: `n = 1`
- Output: `[[1]]`

Constraints:

- `1 <= n <= 20`

## Solution

### Way 1

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));  // define a 2D array using vector
        
        int start_x, start_y;  //define staring position for looping every circle
        // This number records how many loops each circle is made, 
        // e.g., if n is an odd number 3, then loop = 1 is just one circle, 
        // and the values in the middle of the matrix need to be handled separately
        int loop = n / 2;
        
        int count = 1;  // assign value to every element of matrix
        
        // The position in the middle of the matrix, 
        // e.g., if n is 3, the position in the middle is (1, 1) 
        // and if n is 5, the position in the middle is (2, 2)
        int mid = n / 2;
        
        // The length of each edge traversal needs to be controlled 
        // by shrinking the right boundary one position per loop.
        int offset = 1;
        
        int i, j;

        while (loop--) {
            i = start_x;
            j = start_y;
            
            // fills the upper row from left to right (left-closed-right-open intervals)
            for (j = start_y; j < n - offset; j++) res[start_x][j] = count++;
            // fills the right column from top to bottom (left-closed right-open intervals)
            for (i = start_x; i < n - offset; i++) res[i][j] = count++;
            // fills the lower row from right to left (left-closed-right-open intervals)
            for (; j > start_y; j--) res[i][j] = count++;
            // fills the left column from bottom to top (left-closed-right-open intervals)
            for (; i > start_x; i--) res[i][j] = count++;

            // At the beginning of the second lap, 
            // the starting position should be increased by 1 each, 
            // e.g. the starting position of the first circle is (0, 0), 
            // and the starting position of the second circle is (1, 1)
            start_x++;
            start_y++;

            // offset controls the length of each edge traversed in each circle
            offset++;
        }

        // If n is odd, we need to assign a separate value 
        // to the middle-most position of the matrix
        if (n % 2) res[mid][mid] = count;

        return res;
    }
};
```

- Time complexity: $O(n^2)$;
- Space complexity: $O(1)$

### Way 2: Direction Array (Preferred)

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 1, x = 0, y = 0, d = 0; i <= n * n; i++) {
            res[x][y] = i;

            int a = x + dx[d], b = y + dy[d];
            // change direction
            if (a < 0 || a >= n || b < 0 || b >= n || res[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
```
