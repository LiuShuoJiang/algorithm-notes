# 快速幂

## 快速幂的介绍

**快速幂**(二进制取幂)是在较快时间内求出 $a^k\ \left( \mathrm{mod}\ p \right)$ 的结果的方法，其中 $1\leqslant a,p,k\leqslant 10^9$，时间复杂度为 $O(\log k)$，以替代暴力算法 $O(k)$ 的时间复杂度。

> 例题：[快速幂](./exponentiating_by_squaring.cpp)

该算法的核心是反复平方，先预处理如下结果：

$$
\log k\text{个}\begin{cases}
	a^{2^0}\ \left( \mathrm{mod}\ p \right)\\
	a^{2^1}\ \left( \mathrm{mod}\ p \right)\\
	a^{2^2}\ \left( \mathrm{mod}\ p \right)\\
	\vdots\\
	a^{2^{\log k}}\ \left( \mathrm{mod}\ p \right)\\
\end{cases}
$$

以上预处理结果之间满足递推关系： $a^{2^{t+1}}=\left( a^{2^t} \right) ^2$

为了使用预处理结果的乘积，可以将 $k$ 拆成二进制：若 $k=n_s2^s+n_{s-1}2^{s-1}+n_{s-2}2^{s-2}+\cdots +n_12^1+n_02^0$，其中 $n_i\in \left\{ 0,1 \right\}$，则：

$$
a^k=a^{n_s2^s+n_{s-1}2^{s-1}+n_{s-2}2^{s-2}+\cdots +n_12^1+n_02^0}=a^{n_02^0}\times a^{n_12^1}\times \cdots \times a^{n_s2^s}
$$

## 快速幂的应用：求质数模的逆元

**逆元**：若整数 $b,m$ 互质，并且对于任意的整数 $a$，若满足 $\left. b \right|a$，则存在一个整数 $x$，使得 $\frac{a}{b}\equiv a\cdot x\ \left( \mathrm{mod}\ m \right)$，则称 $x$ 为 $b$ 的模 $m$ 的**乘法逆元**，记为 $b^{-1}\ \left( \mathrm{mod}\ m \right)$。

> 例题：[快速幂求逆元](./multiplicative_inverse.cpp)

$b$ 存在乘法逆元的充要条件是 $b$ 与模数 $m$ 互质；逆元满足 $b\cdot b^{-1}\equiv 1\ \left( \mathrm{mod}\ m \right)$；当模数 $m$ 为质数时，根据费马小定理， $b^{m-2}$ 即为 $b$ 的乘法逆元。




