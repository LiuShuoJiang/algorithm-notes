# 中国剩余定理

[**中国剩余定理**](https://zh.wikipedia.org/zh-cn/%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86)：对于以下的一元线性同余方程组：

$$
\left( S \right) : \begin{cases}
	x\equiv a_1\ \left( \mathrm{mod}\ m_1 \right)\\
	x\equiv a_2\ \left( \mathrm{mod}\ m_2 \right)\\
	\vdots\\
	x\equiv a_n\ \left( \mathrm{mod}\ m_n \right)\\
\end{cases}
$$

若整数 $m_1, m_2,\cdots , m_n$ 中任意两数互质，则对任意的整数 $a_1, a_2,\cdots , a_n$，方程组 $(S)$ 有解，且通解可通过如下方式构造得到：

- 设 $M=m_1\times m_2\times \cdots \times m_n=\prod_{i=1}^n{m_i}$ 为整数 $m_1, m_2,\cdots , m_n$ 的乘积，并设 $\forall i=1,2,\cdots ,n:\ M_i=\frac{M}{m_i}$，即 $M_i$ 是除了 $m_i$ 之外的 $n-1$ 个整数的乘积；
- 设 $t_i={M_i}^{-1}$ 为 $M_i$ 模 $m_i$ 的模逆元，即 $t_iM_i\equiv 1\ \left( \mathrm{mod}\ m_i \right) ,\ \forall i=1,2,\cdots ,n$；
- 方程组 $(S)$ 的通解形式为：

$$
x=a_1t_1M_1+a_2t_2M_2+\cdots +a_nt_nM_n+kM=kM+\sum_{i=1}^n{a_it_iM_i},\ k\in \mathbb{Z} 
$$

在模 $M$ 的意义下，方程组 $(S)$ 仅有一个解：

$$
x=\sum_{i=1}^n{a_it_iM_i}
$$


