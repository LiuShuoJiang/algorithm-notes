# 高斯消元法

高斯消元法可以以 $O(n^3)$ 的时间复杂度求解 $n$ 个未知数的线性方程组，核心是先把系数矩阵消成上三角矩阵，再从下到上回代求解。

对于以下线性方程组：

$$
\boldsymbol{Ax}=\boldsymbol{b}
$$

$$
\boldsymbol{A}=\left[ \begin{array}{l}
	a_{11}&		a_{12}&		\cdots&		a_{1n}\\
	a_{21}&		a_{22}&		\cdots&		a_{2n}\\
	\vdots&		\vdots&		\ddots&		\vdots\\
	a_{n1}&		a_{n2}&		\cdots&		a_{nn}\\
\end{array} \right] , \boldsymbol{x}=\left[ \begin{array}{c}
	x_1\\
	x_2\\
	\vdots\\
	x_n\\
\end{array} \right] , \boldsymbol{b}=\left[ \begin{array}{c}
	b_1\\
	b_2\\
	\vdots\\
	b_n\\
\end{array} \right] 
$$

增广矩阵：

$$
\bar{\boldsymbol{A}}=\left[ \begin{array}{c:c}
	\boldsymbol{A}&		\boldsymbol{b}\\
\end{array} \right] =\left[ \begin{array}{cccc:c}
	a_{11}&		a_{12}&		\cdots&		a_{1n}&		b_1\\
	a_{21}&		a_{22}&		\cdots&		a_{2n}&		b_2\\
	\vdots&		\vdots&		\ddots&		\vdots&		\vdots\\
	a_{n1}&		a_{n2}&		\cdots&		a_{nn}&		b_n\\
\end{array} \right] \in \mathbb{R} ^{n\times \left( n+1 \right)}
$$

> 例题：[高斯消元解线性方程组](./linear_equation.cpp)

如下三类变换不改变原方程的解，称为**初等行(列)变换**：

- 把某一行乘一个非零的数
- 交换某两行
- 把某行的若干倍加到另一行上去

为了求解方程，最终需要将增广矩阵做初等行变换化为如下的梯形矩阵：

$$
\left[ \begin{array}{cccc:c}
	1&		&		&		&		\xi _1\\
	&		1&		&		&		\xi _2\\
	&		&		\ddots&		&		\vdots\\
	&		&		&		1&		\xi _n\\
\end{array} \right] 
$$

通过初等变换可以首先将系数矩阵转化成**上三角矩阵**，转化成的矩阵可能有如下情况：

- 完美阶梯形：唯一解
- 出现了“0=非0”的等式：无解
- 出现了“0=0”的等式：无穷多组解

枚举每一列`c`主元：

- 找到每列的绝对值最大的一个非0的数所在行
- 将第一行的值与该行交换，使得该行换到最上面
- 将第一行的数字除以该数，使得该行的第一个数成为1
- 对每一行做初等变换，使得下面所有行的第`c`列变为0

设 $\boldsymbol{A}\in \mathbb{R} ^{n\times n}$， $\boldsymbol{PA}=\boldsymbol{LU}$，高斯消元法的LU分解步骤为：

令 $\boldsymbol{U}=\boldsymbol{A}, \boldsymbol{L}=\mathbf{I}, \boldsymbol{P}=\mathbf{I}$；

For $k=1,2,\cdots ,n-1$:

- 选择 $i\geqslant k$ ，使得 $|u_{ik}|$ 最大；
- $u_{k,k:n}\leftrightarrow u_{i,k:n}$ (交换两行)；
- $l_{k,1:k-1}\leftrightarrow l_{i,1:k-1}$；
- $p_{k,:}\leftrightarrow p_{i,:}$；
- For $j=k+1,k+2,\cdots ,n$:
  - $l_{jk}=\frac{u_{jk}}{u_{kk}}$；
  - $u_{j,k:m}=u_{j,k:m}-l_{jk}u_{k,k:m}$；

现在得到了 $\boldsymbol{Rx}=\boldsymbol{b}$，即：

$$
\left[ \begin{matrix}
	r_{11}&		r_{12}&		\cdots&		r_{1n}\\
	&		r_{22}&		&		\vdots\\
	&		&		\ddots&		\vdots\\
	&		&		&		r_{nn}\\
\end{matrix} \right] \left[ \begin{array}{c}
	x_1\\
	x_2\\
	\vdots\\
	x_n\\
\end{array} \right] =\left[ \begin{array}{c}
	b_1\\
	b_2\\
	\vdots\\
	b_n\\
\end{array} \right] 
$$

以上步骤完成后，反向替代的过程为：

$$
x_n=\frac{b_n}{r_{nn}};
$$

$$
x_{n-1}=\frac{b_{n-1}-x_nr_{n-1,n}}{r_{n-1,n-1}};
$$

$$
x_{n-2}=\frac{b_{n-2}-x_{n-1}r_{n-2,n-1}-x_nr_{n-2,n}}{r_{n-2,n-2}};
$$

$$
\vdots 
$$

$$
x_j=\frac{1}{r_{jj}}\left( b_j-\sum_{k=j+1}^n{x_kr_{jk}} \right) 
$$

注：在代码的做法中，已有 $r_{ii}=1$，以上描述的步骤适用范围更广。
