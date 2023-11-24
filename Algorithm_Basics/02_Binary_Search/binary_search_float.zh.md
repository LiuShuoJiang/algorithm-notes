# 例题：浮点数二分

[代码](./binary_search_float.cpp)

## 描述

给定一个浮点数 $n$，求它的三次方根。

### 输入格式

共一行，包含一个浮点数 $n$。

### 输出格式

共一行，包含一个浮点数，表示问题的解。

注意，结果保留 $6$ 位小数。

### 数据范围

$−10000 \leqslant n \leqslant 10000$

## 解答

```C++
#include <iostream>
using namespace std;

double x;

int main() {
    cin >> x;
    double l = -1000, r = 1000;

    //也可以直接for循环100次
    while (r - l >= 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= x) l = mid;
        else r = mid;
    }
    printf("%.6lf", l);
    return 0;
}
```
