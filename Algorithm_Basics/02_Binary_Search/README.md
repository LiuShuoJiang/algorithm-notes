# 二分法

## 整数二分(难)

![binary](../../images/Binary_Search.drawio.png)

有单调性，一定能二分；没单调性，也有可能能二分。

二分的本质是**边界**：只要找到某种*性质*(如：右半边满足，左半边不满足)，使得整个区间一分为二，那么就可以二分把分界点找到。

每次都要保证答案在选中区间内。

[这篇博文](https://blog.csdn.net/raelum/article/details/128687109) 讲解得较好。

### 情况一：(如果 $mid$ 属于左边)

在右半段寻找左边界(即寻找符合性质的第一个点)
每次将区间划分为 $[l, mid]$ 和 $[mid + 1, r]$ ( $[l, mid]$ 是因为 $mid$ 点可能就是左边界，所以这里不用 $[l, mid - 1]$ )

- $mid=\frac{l+r}{2}$
- If (`check(mid)`是否满足绿色性质)
  - True: Desired point must be in $[l, mid]$: $r\Leftarrow mid$
  - False: Desired point must be in $[mid+1, r]$: $l\Leftarrow mid+1$

```C++
bool check(int x) {/*检查x是否满足某种性质*/}

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用
//查找左边界 SearchLeft
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
```

### 情况二：(如果 $mid$ 属于右边)

在左半段寻找右边界(即寻找符合性质的最后一个点)
每次将区间划分为 $[l, mid - 1]$ 和 $[mid, r]$  (这是因为如果 $mid$ 点符合性质，那么下次划分右边界肯定从 $mid-1$ 开始)

- $mid=\frac{l+r+1}{2}$
- If (`check(mid)`是否满足红色性质)
  - True: Desired point must be in $[mid, r]$: $l\Leftarrow mid$
  - False: Desired point must be in $[l, mid-1]$: $r\Leftarrow mid-1$

$mid=\frac{l+r+1}{2}$ 这里的 $+1$ 是因为除法下取整，在`r = l + 1`时更新`l = mid`时会出现`l = mid = l`的死循环。 $+1$ 则相当于上取整，解决了这个隐患。

```C++
bool check(int x) {/*检查x是否满足某种性质*/}

// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用
//查找右边界 SearchRight
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1; //需要+1 防止死循环
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

### 整数二分的另一种模板

详见[此页面](https://www.acwing.com/solution/content/83783/)

```C++
const int N = 1e5+10;
int q[N];

int BS_left_border(int x) {
    int l = -1, r = n;
    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (x > q[mid]) l = mid;
        else r = mid;
    }
    if (r == n || a[r] != x) return -1;

    return r;
}

int BS_right_border(int x) {
    int l = -1, r = n;
    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (x < q[mid]) r = mid;
        else l = mid;
    }
    if (l == -1 || a[l] != x) return -1;
    
    return l;
}
```

## 浮点数二分

较为容易。

```C++
bool check(double x) {/*检查x是否满足某种性质*/}

double bsearch_3(double l, double r) {
    const double eps = 1e-6; // eps表示精度，取决于题目对精度的要求
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```
