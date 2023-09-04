# 高精度计算(Java、Python不适用)

一般应用于 $A+B$ ， $A-B$ ， $A\cdot\alpha$ 以及 $\frac{A}{\alpha}$ 等操作，其中 $A$ 的*位数*一般为 $10^6$ 这一量级， $\alpha<10000$ 。

C++中将大整数存储在数组里，数组第零位存数字的个位，方便进位，通过代码模拟人工加减法。

减法的判断规则：

$$
A-B:\begin{cases}
	A\geqslant B\rightarrow A-B\\
	A-B\rightarrow -\left( B-A \right)\\
\end{cases}
$$

减法每一位的计算方式：

$$
A_i-B_i-t:\begin{cases}
	\geqslant 0: A_i-B_i-t\\
	<0: A_i-B_i+10-t\\
\end{cases}
$$


