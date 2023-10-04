# 哈希表

## 简介

哈希表的作用：把大的数据(如： $10^9$ )映射到小的数据范围(如： $10^6$ )

哈希函数：

$$
h\left( x \right) :x\in \left( -10^9,10^9 \right) \mapsto h\in \left( 0,10^5 \right) ;
\\
h\left( x \right) =x\,\,\left( \mathrm{mod}10^5 \right) 
$$

可能会有**哈希冲突**

实际操作中，取模的数一般为质数，且需离2的整数次幂尽可能远，这样可以保证冲突概率最小。

哈希表存储结构(按照处理冲突的方式)：

- 开放寻址法
- 拉链法/链地址法

注：离散化是一种极其特殊的(保序)的哈希方式。

## 整数哈希

### 拉链法

**拉链法**是把所有的同义词用**单链表**链接起来的方法。在这种方法中，哈希表的每个单元存储的不再是元素本身，而是相应同义词单链表的头指针(注意是头指针而不是头节点)。

一般而言，可视时间复杂度为 $O(1)$ ；算法题中一般考察插入和查询，而较少考察删除。

对于单链表，我们可以采用模拟数组的方式进行实现。此外，使用拉链法时， $m$ 的大小通常和 $n$ 差不多。例如，若 $n\leqslant 10^5$ ，我们可以寻找大于等于 $10^5$ 的第一个质数，即 $m=100003$ 。

> 例题：[拉链法](./hash_simulate_chaining.cpp)

```C++
int h[N], e[N], ne[N], idx;

//向哈希表中插入一个数
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

//在哈希表中查询某个数是否存在
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }
    return false;
}
```

### 开放寻址法(常用)

**开放寻址法**就是在插入一个关键字为 $k$ 的元素时，若发生哈希冲突，则通过某种哈希冲突解决函数(也称为**再哈希**)得到一个新空闲地址再插入该元素的方法。再哈希的设计有很多种，常见的有*线性探测法*和*平方探测法*，此处只分析前者，后者可类比得到。

线性探测法是从发生冲突的地址开始，依次探测下一个地址，直到找到一个空闲单元为止。当到达下标为 $m-1$ 的哈希表表尾时，下一个探测地址是表首地址 $0$ 。当 $m\geqslant n$ 时一定能找到一个空闲单元。

使用开放寻址法时， $m$ 通常取 $n$ 的 $2\sim 3$ 倍左右。例如若 $n\leqslant 10^5$ ，则我们可以取上表中的 $196613$ 作为哈希表的大小。

> 例题：[开放寻址法](./hash_simulate_open_addressing.cpp)

```C++
int h[N];

//如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null_num && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}
```

例题代码注：

- `const int null = 0x3f3f3f3f`和`memset(h, 0x3f, sizeof h)`之间的关系：
  - 首先，必须要清楚`memset`函数到底是如何工作的：先考虑一个问题，为什么`memset`初始化比循环更快？答案：`memset`更快，为什么？因为`memset`是直接对内存进行操作。`memset`是按字节(byte)进行复制的。
  - `void * memset(void *_Dst,int _Val,size_t _Size);`这是`memset`的函数声明：第一个参数为一个指针，即要进行初始化的首地址；第二个参数是初始化值，注意，并不是直接把这个值赋给一个数组单元(对`int`来说不是这样)；第三个参数是要初始化首地址后多少个字节。`h`是`int`类型，其为4个字节， 第二个参数`0x3f`八位为一个字节，所以`0x3f * 4`(从高到低复制4份) = `0x3f3f3f3f`。
  - 这也说明了为什么在`memset`中不设置除了`-1,0`以外常见的值：比如1, 字节表示为`00000001`，`memset(h, 1, 4)`则表示为`0x01010101`
- 为什么要取`0x3f3f3f`,为什么不直接定义无穷大`INF = 0x7fffffff`,即32个1来初始化呢？
  - 首先，`0x3f3f3f`的体验感很好，`0x3f3f3f3f`的十进制是`1061109567`，也就是`10^9`级别的(和`0x7fffffff`一个数量级)，而一般场合下的数据都是小于`10^9`的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。比如`0x3f3f3f3f+0x3f3f3f3f=2122219134`，这非常大但却没有超过`32-bit,int`的表示范围，所以`0x3f3f3f3f`还满足了我们“无穷大加无穷大还是无穷大”的需求。但是`INF`不同，一旦加上某个值，很容易上溢，数值有可能转成负数。
  - `0x3f3f3f3f`还能给我们带来一个意想不到的额外好处：如果我们想要将某个数组清零，我们通常会使用`memset(a,0,sizeof(a))`这样的代码来实现(方便而高效)，但是当我们想将某个数组全部赋值为无穷大时(例如解决图论问题时邻接矩阵的初始化)，就不能使用`memset`函数而得自己写循环了，我们知道这是因为`memset`是按字节操作的，它能够对数组清零是因为0的每个字节都是0，现在如果我们将无穷大设为`0x3f3f3f3f`，0x3f3f3f3f的每个字节都是`0x3f`！所以要把一段内存全部置为无穷大，我们只需要`memset(a,0x3f,sizeof(a))`。

## 字符串哈希

### 字符串哈希简介

这里讲述**字符串前缀哈希法**。

例如：`str="ASDFGHJ"`，有`h[0]=0`，`h[1]="A"`，`h[2]="AS"`，`h[3]="ASD"`等。

在这里需要把字符串`str`当作一个 $p$ 进制数，比如字符串`ABCD`可以当作 $\left( 1234 \right) _p$ ，则转化为10进制后取模得到 $\left( 1\times p^3+2\times p^2+3\times p^1+4\times p^0 \right) \mathrm{mod} Q$ ，事实上取模可以通过将`h[...]`数据类型设计成`unsigned long long`，数据溢出就是取模。

注意：不要映射成0，否则可能导致冲突，建议从1开始。

根据经验，当 $p=131$ 或 $p=1331$ ，且 $Q=2^{64}$ 时，基本不会发生冲突。

前缀哈希的好处是可以通过前缀的哈希算出所有子串的哈希。

### 数学语言描述

对于一个长度为 $l$ 的字符串 $s$ 来说，哈希函数定义为：

$$
h\left( s \right) =\sum_{i=1}^l{s\left[ i \right] \times p^{l-i}}\left( \mathrm{mod} Q \right) 
$$

其中 $s[i]$ 为字符的ASCII码， $p$ 通常取 $131$ 或 $131313$ ， $M$ 取 $2^{64}$ (使用这种取值，哈希冲突的概率几乎为 $0$ ，故下文不再考虑哈希冲突)

注意到使用`unsigned long long`这个变量类型存储哈希值，溢出时就相当于对 $M$ 取模。记 $h(s)\triangleq h(s[1..l])$ ，可见：

$$
h\left( s\left[ 1\cdots l \right] \right) =\sum_{i=1}^{l-1}{s\left[ i \right] \times p^{l-i}}+s\left[ l \right] =p\times h\left( s\left[ 1\cdots l-1 \right] \right) +s\left[ l \right] 
$$

接下来分别开两个数组 $h$ 和 $p$ ，其中 $h[i]\triangleq h(s[1..i])$ 用来存储原串长度为 $i$ 的前缀的哈希值， $p[i]$ 用来存储 $p^i$ ，于是得到递推式：

$$
\begin{cases}
	h\left[ i \right] =h\left[ i-1 \right] \cdot p+s\left[ i \right] , 1\leqslant i\leqslant l\\
	p\left[ i \right] =p\left[ i-1 \right] \cdot p, 1\leqslant i\leqslant l\\
	h\left[ 0 \right] =0, p\left[ 0 \right] =1\\
\end{cases}
$$

从而， $h[l]$ 就代表字符串 $s$ 的哈希值。在求解的过程中我们还得到了 $s$ 的所有前缀哈希值。利用前缀哈希值，我们可以在 $O(1)$ 的时间内求出 $s$ 的任一子串的哈希值。具体来说，设子串为 $s[l..r]$（这里的 $l$ 并非指长度，而是`left`的意思），注意到

$$
h\left[ l-1 \right] =\sum_{i=1}^{l-1}{s\left[ i \right] \cdot p^{l-1-i}},
\\
h\left[ r \right] =\sum_{i=1}^r{s\left[ i \right] \cdot p^{r-i}}
$$

则可以得到：

$$
h\left[ r \right] -p^{r-l+1}\cdot h\left[ l-1 \right] =\sum_{i=1}^r{s\left[ i \right] \cdot p^{r-i}}-\sum_{i=1}^{l-1}{s\left[ i \right] \cdot p^{r-i}}
\\
=\sum_{i=l}^r{s\left[ i \right] \cdot p^{r-i}}
$$

可记忆如下公式：字符串 $h$ 的下标 $l$ 至 $r$ 段的哈希值为 $h\left[ r \right] -h\left[ l-1 \right] \cdot p^{r-l+1}$

字符串哈希的公式中 $h\left[ r \right] -h\left[ l-1 \right] \cdot p^{r-l+1}$ ， $h[l-1]$ 要乘上 $p^{r-l+1}$ 的原因举例：

比如`aabbaabb`这个字符串，要求下标`3`到`7`(`bbaab`)这一段哈希值，需要知道 $h[l - 1] = h[2]$ 和 $h[r] = h[7]$ ，即`aa`和`aabbaab`的哈希值，转换为 $p$ 进制就是 ${(11)}_p$ 和 ${(1122112)}_p$ ，我们需要求`bbaab`这一个子串的哈希值，转换为 $p$ 进制就是 ${(22112)}_p$，而将 $h[l-1] \times P[r-l+1]$ 就是左移 $r-l+1$ 位变成 ${(1100000)}_p$ ，而 $h[r] - h[l-1] \times P[r-l+1]$ 就是 ${(22112)}_p$ ，也就是子串`bbaab`的哈希值。

### 模板与例题

常用于快速判断两个字符串是否相等(时间复杂度由 $O(n)$ 降为 $O(1)$ )，可以替代KMP(但在寻找循环节的问题上只能用KMP)。

> 例题：[字符串哈希](./string_hash.cpp)

```C++
//核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
//小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果
typedef unsigned long long ULL;
ULL h[N], p[N];  // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}
```
