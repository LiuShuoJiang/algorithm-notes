# 数位统计动态规划

> 例题：[计数问题](./counting.cpp)

分情况讨论：

要统计`[a,b]`区间每个整数出现的数字0到9的次数，可以设计一个`count`函数：`count(n,x)`表示从1到`n`中`x`出现的次数(`x`为从0到9)，则`count(b, x)-count(a - 1, x)`就是我们想要的结果。

例如，假设 $n$ 为 $\overline{abcdefg}$，要分别求出1在每一位上出现的次数。比如求1在第4位上出现的次数，就是要找到形如 $1\leqslant \overline{xxx1xxx}\leqslant \overline{abcdefg}$ 的整数：

- 如果前三位 $\overline{xxx}=000\sim \overline{abc}-1$，则  $\overline{yyy}=\overline{000}\sim \overline{999}$，共 $\overline{abcd}\cdot 1000$ 种选法
- 如果前三位 $\overline{xxx}=\overline{abc}$：
  - $d<1$，则 $\overline{abc1yyy}>\overline{abc0efg}$，方案数为0







