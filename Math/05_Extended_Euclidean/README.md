# 扩展欧几里得算法

**裴蜀定理**(Bézout's Lemma)：对整数 $a,b,m$，关于未知数 $x$ 和 $y$ 的线性不定方程(称作*裴蜀等式*) $ax+by=m$ 有整数解当且仅当 $m$ 为 $a,b$ 最大公约数 $d$ 的倍数。裴蜀等式有解时必然有无穷多个整数解。

推论：对于任意正整数 $a,b$，必存在非零整数 $x,y$，使得 $ax+by=\mathrm{gcd}(a,b)$。

**扩展欧几里得算法**是辗转相除法的扩展。已知整数 $a,b$，扩展欧几里得算法可以在求得 $a,b$ 的最大公约数的同时，找到整数 $x,y$ (其中一个可能是负数)，使它们满足裴蜀等式 $ax+by=\mathrm{gcd}(a,b)$。如果 $a$ 是负数，可以把问题转化成 $\left| a \right|\cdot \left( -x \right) +b\cdot y=\mathrm{gcd}\left( \left| a \right|,b \right)$，然后令 $x\prime=-x$

> 例题：[扩展欧几里得算法](./extended_Euclidean_algorithm.cpp)

求解方程 $ax+by=\mathrm{gcd}(a,b)$：

当 $b=0$ 时， $ax+by=a$，故 $x=1,\ y=0$

当 $b\ne 0$ 时，因为 $\mathrm{gcd}\left( a,b \right) =\mathrm{gcd}\left( b,a\%b \right)$，则 $bx\prime+\left( a\%b \right) y\prime=\mathrm{gcd}\left( b,a\%b \right)$，可知：

$$
b\cdot x\prime+\left( a-\lfloor \frac{a}{b} \rfloor \cdot b \right) \cdot y\prime=\mathrm{gcd}\left( b,a\%b \right) ;
\\
\Rightarrow a\cdot y\prime+b\cdot \left( x\prime-\lfloor \frac{a}{b} \rfloor \cdot y\prime \right) =\mathrm{gcd}\left( b,a\%b \right) =\mathrm{gcd}\left( a,b \right) 
$$

故 $x=y\prime, y=x\prime-\lfloor \frac{a}{b} \rfloor \cdot y\prime$，可以采用递归算法，先求出下一层的 $x\prime$ 和 $y\prime$，再利用上述公式进行回代。


