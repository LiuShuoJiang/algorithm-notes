# 数位统计动态规划

> 例题：[计数问题](./counting.cpp)

**分情况讨论**：

要统计`[a,b]`区间中每个整数出现的数字0到9的次数，可以设计一个`count`函数：`count(n,x)`表示从1到`n`中`x`出现的次数(`x`可以是0到9)，则`count(b, x)-count(a - 1, x)`就是我们想要的结果。现在只需实现`count`函数即可。

例如，假设 $n$ 为 $\overline{abcdefg}$，需要分别求出1在每一位上出现的次数，累加起来就是1出现的次数。比如求1在第4位上出现的次数，就是要找到形如 $1\leqslant \overline{xxx1yyy}\leqslant \overline{abcdefg}$ 的整数：

- 情况一：如果前三位 $\overline{xxx}=000\sim \overline{abc}-1$，则后三位  $\overline{yyy}=\overline{000}\sim \overline{999}$，共 $\overline{abc}\cdot 1000$ 种选法
- 情况二：如果前三位 $\overline{xxx}=\overline{abc}$：
  - 若 $d<1$(即 $d=0$ )，则 $\overline{abc1yyy}>\overline{abc0efg}$，方案数为0
  - 若 $d=1$，则 $\overline{yyy}=\overline{000}\sim \overline{efg}$，共有 $\overline{efg}+1$种方案
  - 若 $d>1$，则 $\overline{yyy}=\overline{000}\sim \overline{999}$，共 $1000$ 种方案

运用类似的分类讨论方式可以求出1在其他位出现的次数，也可以求出其他数字在每一位出现的次数。

边界问题：

- 当要枚举的数字出现在最高位时，以上情况一不存在；
- 当要枚举数字0时，不能有前导0的存在，需要重新考虑情况一：假如第 $k$ 位为0，并且它的前面是全0，那么就相当于第 $k$ 位并不存在，也就不能算是一个方案数。例如，要在 $\overline{abcdefg}$ 中找第4位为0的数。假如 $\overline{abc}$ 为 $\overline{000}$， $d$也为0，那么就会有 $\overline{0000efg}$。但是， $\overline{0000efg}$ 实际上就是 $\overline{efg}$，它并不存在第四位，因此也就不能算是第4位为0的数。在该情况下应该把情况一修改成从前三位从 $\overline{001}$ 开始枚举，而不是从 $\overline{000}$ 开始。

