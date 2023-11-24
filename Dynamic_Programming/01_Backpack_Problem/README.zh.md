# 背包问题

总任务：求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

## 0-1背包问题

问题：有 $N$ 件物品和一个容量是 $V$ 的背包。**每件物品最多只能使用一次**。第 $i$ 件物品的体积是 $v_i$，价值是 $w_i$。

> 例题：[01背包问题的朴素解法](./01_knapsack.cpp)

最大价值是物品数量 $i$ 和背包容量 $j$ 的函数，设函数 $f(i,j)$ 表示前 $i$ 件物品放入容量为 $j$ 的背包的最大价值，最终的最大价值就是物品数量 $i$ 从0增长到 $N$，背包容量 $j$ 从0增长到 $V$ 时的 $f(N,V)$ 值。

动态规划 $D_p$：

- **状态表示**： $f(i,j)$ 是前 $i$ 个物品，背包容量 $j$ 下的最优解（最大价值）
  - ***集合***：所有选法的集合，需要满足如下条件
    - 只从前 $i$ 个物品当中选
    - 选出物品的总体积 $\leqslant j$
  - ***属性***：是一个数，是所有选法总价值的最大值 $\mu _{\max}$，最小值 $\mu _{\min}$，或元素数量等
- **状态计算**：最终答案是 $f(N,V)$，一般对应***集合的划分***，本问题可将集合划分为从1到 $i-1$ 中选择的总体积不超过 $j$ 的不含 $i$ 的集合( $f(i-1,j)$ )以及含 $i$ 的集合( $f(i-1,j-v_i)+w_i$ )，共两个集合；集合划分需满足如下原则：
  - ***不重***：一般要满足
  - ***不漏***：必须要满足

注意以上含 $i$ 的集合指的是从1到 $i-1$ 中选择的总体积不超过 $j-v_i$ 的选法的集合，也就是 $f(i-1,j-v_i)+w_i$。

可以得到：

$$
f\left( i,j \right) =\max [ f\left( i-1,j \right) , f\left( i-1,j-v_i \right) +w_i ]
$$

进一步写出完整的递推式：

$$
f\left( i,j \right) =\begin{cases}
	f\left( i-1,j \right) , j < v\left[ i \right]\\
	\max \left[ f\left( i-1,j \right) , f\left( i-1,j-v\left[ i \right] \right) +w\left[ i \right] \right] , j\geqslant v\left[ i \right]\\
\end{cases}
$$

其中 $f\left( i,0 \right) =0; \left( 1\leqslant i\leqslant N \right)$，且 $f\left( 0,j \right) =0; \left( 1\leqslant j\leqslant V \right)$，可见 $f(i,j)$ 应该全0初始化，可以声明为全局变量。

时间和空间复杂度均为 $O(N\cdot V)$，时间复杂度不能降低了，但空间复杂度还可以降为一维。是否可以用一维数组`f[j]`只记录一行数据，让 $j$ 值顺序循环，顺序更新`f[j]`呢？答案是不行，因为如果 $j$ 是顺序循环，`f[j - v[i]]`会先于`f[j]`更新，即用新值`f[j - v[i]]`去更新`f[j]`会出错。

**$D_p$ 优化**指的是对已有 $D_p$ 的代码、方程进行优化。

> 例题：[01背包问题的一维优化](./01_knapsack_1D.cpp)

将状态`f[i][j]`优化到一维`f[j]`，实际上只需要做一个等价变形。为什么可以这样变形呢？我们定义的状态`f[i][j]`可以求得任意合法的 $i$ 与 $j$ 最优解，但题目只需要求得最终状态`f[n][m]`，因此我们只需要一维的空间来更新状态。

状态 $f[j]$ 定义： $N$ 件物品，背包容量 $j$ 下的最优解。注意枚举背包容量 $j$ 必须从 $m$ 开始。用一维数组`f[j]`只记录一行数据，让 $j$ 值逆序循环，逆序更新`f[j]`的值。`f[j]`称为**滚动数组**。

## 完全背包问题

问题：有 $N$ 件物品和一个容量是 $V$ 的背包。**每件物品都有无限件可用**。第 $i$ 件物品的体积是 $v_i$，价值是 $w_i$。

动态规划问题：

- 状态表示：
  - 集合： $f(i,j)$表示考虑前 $i$ 个物品且总体积不大于 $j$ 的所有选法
  - 属性：所有选法的最大价值
- 状态计算：集合的划分，按照第 $i$ 个物品选了多少个可以分为若干组
  - 去掉 $k$ 个物品 $i$
  - 求最大值： $f(i-1,j-k\cdot v[i])$
  - 再加回来 $k$ 个物品 $i$

状态转移方程为：

$$
f\left( i,j \right) =\max [ f\left( i,j \right) , f\left( i-1, j-k\cdot v\left[ i \right] \right) +k\cdot w\left[ i \right] ]
$$

更完整地，设第 $i$ 种物品最多能选 $t$ 个，可知 $t=\lfloor \frac{j}{v\left[ i \right]} \rfloor$，可得完整递推式：

$$
f\left( i,j \right) =\max_{0\leqslant k\leqslant t} f\left( i-1, j-k\cdot v\left[ i \right] \right) +k\cdot w\left[ i \right] 
$$

> 例题：[完全背包问题的朴素解法](./complete_knapsack.cpp)

朴素解法时间复杂度为 $O\left( V^2N \right)$

为了优化朴素解法，可以观察原递推方程：

$$
f\left( i,j-v\left[ i \right] \right) =\max [ f\left( i-1,j-v\left[ i \right] \right) , f\left( j-1,j-2\cdot v\left[ i \right] \right) +w\left[ i \right] ,  f\left( j-1,j-3\cdot v\left[ i \right] \right) +2\cdot w\left[ i \right] , \cdots ]
$$

$$
f\left( i,j \right) =\max [ f\left( i-1,j \right) , f\left( i-1,j-v\left[ i \right] \right) +w\left[ i \right], f\left( j-1,j-2\cdot v\left[ i \right] \right) +2\cdot w\left[ i \right] ,  f\left( j-1,j-3\cdot v\left[ i \right] \right) +3\cdot w\left[ i \right] , \cdots ]
\\
=\max [ f\left( i-1,j \right) , f\left( i,j-v\left[ i \right] \right) +w\left[ i \right] ]
$$

不用再枚举 $k$ 重循环了，时间复杂度为 $O(NV)$。

> 例题：[完全背包问题的递推优化](./complete_knapsack_modified.cpp)

类似地，完全背包问题也可以优化到一维。上式对应的是 $j$ 从小到大遍历，于是我们只需把0-1背包问题的代码中的 $j$ 改为从小到大遍历即可。不用由大到小遍历，因为要的就是覆盖的效果！

> 例题：[完全背包问题的一维优化](./complete_knapsack_1D.cpp)

时间复杂度不变，空间复杂度降为 $O(V)$

因为`j`是顺序循环，`f[j-v[i]]`会先于`f[j]`更新，也就是说用新值`f[j-v[i]]`去更新`f[j]`，相当于用第`i`行的`f[j-v[i]]`值更新`f[j]`，所以可以顺序循环。

## 多重背包问题

问题：有 $N$ 件物品和一个容量是 $V$ 的背包。**第 $i$ 种物品最多有 $s_i$ 件**。第 $i$ 件物品的体积是 $v_i$，价值是 $w_i$。

动态规划问题：

- 状态表示： $f(i,j)$
  - 集合：所有只从前 $i$ 个物品中选择，并且总体积不超过 $j$ 的选法
  - 属性：集合中每个选法对应的总价值的最大值
- 状态计算：根据第 $i$ 个物品选了多少个来划分集合(可选0个，1个，...，直到 `s[i]`个)

状态转移方程：

$$
f\left( i,j \right) =\max [ f\left( i-1,j-v\left[ i \right] \cdot k \right) +w\left[ i \right] \cdot k ] ; k=0,1,2,\cdots ,s\left[ i \right]
$$

> 例题：[多重背包问题的朴素解法](./multiple_knapsack.cpp)

我们不能直接用完全背包问题的优化方法来优化多重背包问题，因为`max`操作不具有可减性。可以采用**二进制优化**。

引论：如何将正整数 $s$ 表示？选择 $1, 2, 4, 8, \cdots , 2^k, c$ 这些数字进行相加(每个数字最多选一次)，其中 $2^k\leqslant s, 2^{k+1}>s$，且 $c<2^{k+1}$；它们(除了 $c$ 外)可以凑出 $0\sim 2^{k+1}-1$ 的数，加上 $c$ 后可以凑出 $0\sim 2^{k+1}-1+c$ 的数，要求区间 $\left[ 0, 2^{k+1}-1 \right] , \left[ c, s \right]$中间不能有缝隙，事实上因为 $c<2^{k+1}$ 显然成立。故从0到 $s$ 的所有数可以拼接出来。

举例：水果店里有40个苹果，小明计划购买 $n(1\leqslant n\leqslant 40)$ 个苹果，如何让小明尽可能快速地完成购买？一个显而易见的暴力做法是，让小明一个个拿(单位是个)，但效率过于低下。事实上，店员可事先准备好6个箱子，每个箱子中的苹果数量分别为 $[1,2,4,8,16,9]$，再让小明按箱子拿(单位是箱子)，无论小明计划购买多少个，他最多只需要拿6次，而在暴力做法中，小明最多需要拿40次。

用数学表达式，可以断定对任意的正整数 $s$，都可以找到 $\lfloor \log _2s \rfloor +1\triangleq k$ 个正整数 $a_1,a_2,\cdots ,a_k$，使得 $\forall n\in [0,s]$，都有：

$$
n=\boldsymbol{v}^T\cdot \boldsymbol{a}; \boldsymbol{a}=\left[ \begin{array}{c}
	a_1\\
	\vdots\\
	a_k\\
\end{array} \right] , a_i=\begin{cases}
	2^{i-1},\\
	s-2^{i-1}+1;\left( \in \left[ 1,2^{k-1} \right] \right)\\
\end{cases}
$$

其中：

$$
\boldsymbol{v}=\left[ \begin{array}{c}
	v_1\\
	\vdots\\
	v_k\\
\end{array} \right]
$$

且 $\boldsymbol{v}$ 的每个分量要么是0要么是1。

现在对于每种物品 $i$，可以将这`s[i]`个物品分散至 $\lfloor \log _2s\left[ i \right] \rfloor +1$ 个箱子中，将多重背包便化成0-1背包，多重背包问题中的一个箱子相当于0-1背包问题中的一件物品。

这样可以把时间复杂度从 $O(N\cdot V\cdot S)$ 变为 $O(N\cdot V\cdot \log S)$

> 例题：[多重背包问题的二进制优化](./multiple_knapsack_binary.cpp)

## 分组背包问题

问题：有 $N$ 组物品和一个容量是 $V$ 的背包。每组物品有若干个，**同一组内的物品最多只能选一个**。每件物品的体积是 $v_{ij}$，价值是 $w_{ij}$，其中 $i$ 是组号， $j$ 是组内编号。 $s_i$ 表示第 $i$ 个物品组的物品数量

动态规划问题：

- 状态表示
  - 集合：只从前 $i$ 组物品中选，且总体积不大于 $j$ 的所有选法
  - 属性：最大值
- 状态计算
  - 枚举第 $i$ 组物品选哪个
  - $f\left( i-1, j-v\left[ i,k \right] \right) +w\left[ i,k \right]$

递推式：

$$
f\left( j \right) =\max \left[ f\left( j \right) ,\max_{1\leqslant k\leqslant s\left[ i \right]} f\left( j-v\left[ i,k \right] \right) +w\left[ i,k \right] \right] 
$$

> 例题：[分组背包问题](./grouping_knapsack.cpp)
