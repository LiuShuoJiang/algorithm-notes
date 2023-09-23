# 离散化

## 思路

一串有序序列的值域很大( $10^9$ )，但个数相对较少( $10^5$ )，要求将自数组的下标映射到从0开始的依次标号。如：

$$
a\left[ \cdots \right] : \begin{cases}
	1\rightarrow 0\\
	100\rightarrow 1\\
	2000\rightarrow 2\\
	50000\rightarrow 3\\
\end{cases}
$$

离散化的本质，是映射，将间隔很大的点，映射到相邻的数组元素中。减少对空间的需求，也减少计算量。也就是把无限空间中有限的个体映射到有限的空间中去。

注意：

- 数组是有序数组，要先`sort`
- `a[]`中可能有重复元素，所以要去重：使用库函数`unique`，将数组元素去重并返回去重后数组的尾端点，再`erase`
- 如何算出`a[i]`(保序)离散化后的值是多少：二分

## 模板

```C++
vector<int> alls;  // 存储所有待离散化的值
sort(alls.begin(), alls.end());  // 将所有值排序
// 去掉重复元素
alls.erase(unique(alls.begin(), alls.end()), alls.end());

// 二分求出x对应的离散化的值
int find(int x) {  // 找到第一个大于等于x的位置
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;  // 映射到1, 2, ...n
}
```

`alls.erase(unique(alls.begin(), alls.end()), alls.end());`代码解析：

- `erase(pos, n);` 删除从`pos`开始的`n`个字符，例如`erase(0, 1)`，
删除`0`位置的一个字符，即删除第一个字符
- `erase(position)`; 删除`position`处的一个字符（`position`是个`string`类型的迭代器）
- `erase(first，last);`删除从`first`到`last`之间的字符，（`first`和`last`都是迭代器），`last`不能是`x.end()`
- `unique`使用必须要先过一遍`sort`排序。`unique`函数返的返回值是一个迭代器，它指向的是去重后容器中不重复序列的最后一个元素的下一个元素。所以如果想要得到不重复元素的个数就需要用返回值减去开始地址

注：`unique()`函数的大致实现思路：双指针算法

所有不同元素(排序后)必满足如下性质：它是第一个；它和前面元素不一样(`a[i] != a[i - 1]`)

```C++
vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!i || a[i] != a[i - 1])
            a[j++] = a[i];
        // a[0] ~ a[j - 1] 所有a中不重复的数
    }
    return a.begin() + j;
}
```
