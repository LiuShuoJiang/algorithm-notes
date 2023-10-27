# 约数

## 试除法求约数

> 例题：[试除法求约数](./divisor.cpp)

时间复杂度为 $O(\sqrt{n})$

## 约数个数和约数和

**算术基本定理**：对于$\forall A\in \mathbb{N} , A>1$，都 

$$
\exists \prod_{i=1}^n{{p_i}^{\alpha _i}}=A
$$

其中 $p_1<p_2<\cdots <p_n$，且 $p_i$ 为质数， ${\alpha}_i\in \mathbb{Z} ^+$。这种表示方法存在且唯一。

> 例题：[约数个数](./num_of_divisors.cpp)

结论：对于正整数 $A$，其正约数**个数**为：

$$
\prod_{i=1}^n{\left( \alpha _i+1 \right)}
$$

注：`int`范围内的数 $A\leqslant 2^{31}-1$，其约数个数最多为 $1536$，例如 $1745944200=2^3\times 3^3\times 5^2\times 7\times 11\times 13\times 17\times 19$， $2113511400=2^3\times 3^3\times 5^2\times 7\times 11\times 13\times 17\times 23$。

> 例题：[约数之和](./sum_pf_divisors.cpp)

结论：正整数 $A$ 的正约数**和**为：

$$
\left( {p_1}^0+{p_1}^1+{p_1}^2+\cdots +{p_1}^{\alpha _1} \right) \cdot \left( {p_2}^0+{p_2}^1+{p_2}^2+\cdots +{p_2}^{\alpha _2} \right) \cdots \left( {p_n}^0+{p_n}^1+{p_n}^2+\cdots +{p_n}^{\alpha _n} \right) 
$$

$$
=\prod_{i=1}^n{\left( \sum_{j=0}^{\alpha _i}{{p_i}^j} \right)}
$$


