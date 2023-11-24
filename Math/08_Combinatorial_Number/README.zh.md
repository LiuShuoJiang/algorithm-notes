# 组合数的计算

从 $n$ 个不同元素中取出 $k$ 个元素的所有不同组合的个数，叫做从 $n$ 个不同元素中取出 $k$ 个元素的**组合数**，记作 $C_{n}^{k}$

$C_{n}^{k}$ 的公式为：

$$
C_{n}^{k}=\left( \begin{array}{c}
	n\\
	k\\
\end{array} \right) =\frac{A_{n}^{k}}{k!}
$$

$$
=\frac{n\times \left( n-1 \right) \times \cdots \times \left( n-k+1 \right)}{1\times 2\times 3\times \cdots \times k}=\frac{n!}{k!\cdot \left( n-k \right) !}
$$


## 计算组合数

### 基本递推求法

> 例题：[求组合数 1](./combination_1.cpp)

对于组合数，有如下递推式：

$$
C_{n}^{k}=C_{n-1}^{k-1}+C_{n-1}^{k}
$$

### 使用逆元的求法

另一种组合数的求法：

> 例题：[求组合数 2](./combination_2.cpp)

注意到：

$$
C_{a}^{b}=\frac{a!}{b!\cdot \left( a-b \right) !}\equiv a!\cdot \left( b! \right) ^{-1}\cdot \left( \left( a-b \right) ! \right) ^{-1}\ \ \left( \mathrm{mod}\ p \right) 
$$

上述"-1"代表乘法逆元。

根据费马小定理，若 $p$ 为质数，且整数 $b$ 不是 $p$ 的倍数，则 $b^{p-1}\equiv 1\ \left( \mathrm{mod}\ p \right)$，因此 $b\cdot b^{-1}\equiv b\cdot b^{p-2}\equiv 1\ \left( \mathrm{mod}\ p \right)$，故 $b^{-1}\equiv b^{p-2}$。

### 使用卢卡斯定理的求法

另一种组合数求法：

> 例题：[求组合数 3](./combination_3.cpp)

**卢卡斯定理**：对于非负整数 $m,n$ 和质数 $p$，以下同余式：

$$
C_{m}^{n}\equiv \prod_{i=0}^k{C_{m_i}^{n_i}}\ \ \left( \mathrm{mod}\ p \right) 
$$

成立，其中 $m=m_kp^k+m_{k-1}p^{k-1}+\cdots +m_1p+m_0$ 以及 $n=n_kp^k+n_{k-1}p^{k-1}+\cdots +n_1p+n_0$ 是 $m$ 和 $n$ 的 $p$ 进制展开。

特别地，对于质数 $p$ ，有：

$$
C_{m}^{n}\ \ \left( \mathrm{mod}\ p \right) \ \ \equiv \ \ C_{\lfloor m/p \rfloor}^{\lfloor n/p \rfloor}\cdot C_{m\left( \mathrm{mod}\ p\ \right)}^{n\left( \mathrm{mod}\ p \right)}\ \ \left( \mathrm{mod}\ p \right) 
$$

对于组合数公式可做如下变换：

$$
C_{n}^{k}=\frac{n!}{k!\cdot \left( n-k \right) !}=\frac{n\left( n-1 \right) \left( n-2 \right) \cdots \left( n-k+1 \right)}{k!}
$$

$$
\equiv n\times \left( n-1 \right) \times \cdots \times \left( n-k+1 \right) \times 1^{-1}\times 2^{-1}\times \cdots \times k^{-1}\ \ \left( \mathrm{mod}\ p \right) 
$$

使用卢卡斯定理时间复杂度为 $O\left( \log _pN\cdot p\cdot \log p \right)$

### 组合数具体数值计算(高精度)

如果需要求出组合数的具体数值而不取模，需要用到高精度数字表示。

> 例题：[求组合数 4](./combination_4.cpp)

在求之前，可以把 $C_{n}^{k}$ 分解质因数，这样只需实现高精度乘法即可。在质因数分解时最好使用此公式： $C_{n}^{k}=\frac{n!}{k!\cdot \left( n-k \right) !}$。如何求一个阶乘包含的质因子？有结论([勒让德定理](https://en.wikipedia.org/wiki/Legendre%27s_formula))： $n!$ 中质因子 $p$ 的次数为：

$$
d_p\left( n! \right) =\lfloor \frac{n}{p} \rfloor +\lfloor \frac{n}{p^2} \rfloor +\lfloor \frac{n}{p^3} \rfloor +\cdots =\sum_{i=1}^{\infty}{\lfloor \frac{n}{p^k} \rfloor}=\sum_{k=1}^{\lfloor \log _pn \rfloor}{\lfloor \frac{n}{p^k} \rfloor}
$$

步骤：

- 筛质数(本题可以把1~5000内的质数筛出来)
- 根据上述公式求每个质数的次数
- 用高精度乘把所有质因子乘上

## 卡塔兰数

> 例题：[满足条件的01序列](./Catalan_number.cpp)

[**卡塔兰数**](https://en.wikipedia.org/wiki/Catalan_number) 的定义为：

$$
C_n=\frac{C_{2n}^{n}}{n+1}=\frac{\left( 2n \right) !}{\left( n+1 \right) !\cdot n!}
$$

将01序列置于坐标系中，起点定于原点。若0表示向右走，1表示向上走，那么任何前缀中0的个数不少于1的个数就转化为：路径上的任意一点，横坐标大于等于纵坐标。题目所求即为这样的合法路径数量。也就是求在n乘n格点中不越过对角线的单调路径的个数。一个单调路径从格点左下角出发，在格点右上角结束，每一步均为向上或向右。计算结果为：

$$
C_n=C_{2n}^{n}-C_{2n}^{n+1}=\frac{1}{n+1}C_{2n}^{n}
$$

