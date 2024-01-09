# Example: Binary Search Float

[code](./binary_search_float.cpp)

## Description

Given a floating point number $n$, find its cubic root.

### Input format

One line containing a floating point number $n$.

### Output format

A single line containing a floating point number representing the solution to the problem.

Note that the result is preserved to $6$ decimal places.

### Data range

$-10000 \leqslant n \leqslant 10000$

## Solution

```C++
#include <iostream>
using namespace std;

double x;

int main() {
    cin >> x;
    double l = -1000, r = 1000;

    // we can also execute "for" loop for 100 times
    while (r - l >= 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= x) l = mid;
        else r = mid;
    }
    printf("%.6lf", l);
    return 0;
}
```