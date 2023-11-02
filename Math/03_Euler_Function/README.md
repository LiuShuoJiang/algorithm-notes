# 欧拉函数

**欧拉函数**的定义： $1\sim A$ 中与正整数 $A$ 互质的数的个数被称为欧拉函数，记为 $\varphi \left( A \right)$。

## 欧拉函数的基本公式

> 例题：[欧拉函数](./Euler_function.cpp)

结论：若在算术基本定理中，有 $A$ 分解质因数后的结果为 $A={p_1}^{\alpha _1}\cdot {p_2}^{\alpha _2}\cdots {p_n}^{\alpha _n}$，则：

$$
\varphi \left( A \right) =A\times \frac{p_1-1}{p_1}\times \frac{p_2-1}{p_2}\times \cdots \times \frac{p_n-1}{p_n}
$$

即：

$$
\varphi \left( A \right) =A\left( 1-\frac{1}{p_1} \right) \cdot \left( 1-\frac{1}{p_2} \right) \cdots \left( 1-\frac{1}{p_n} \right) 
$$

证明：要求 $1\sim A$ 中和 $A$ 互质的数的个数，需要进行以下步骤：

1. 从 $1\sim A$ 中去掉 $p_1,p_2,\cdots ,p_k$ 的所有倍数，也就是 $A-\frac{A}{p_1}-\frac{A}{p_2}-\cdots -\frac{A}{p_n}$
2. 根据容斥原理，还需要加上所有 $p_i\cdot p_j$ 的倍数，也就是 $A-\sum_{i=1}^n{p_i}+\sum_{1\leqslant i < j\leqslant n}{p_i\cdot p_j}$
3. 根据容斥原理，还需要减去所有 $p_i\cdot p_j\cdot p_k$ 的倍数，也就是 $A-\sum_{i=1}^n{p_i}+\sum_{1\leqslant i < j\leqslant n}{p_i\cdot p_j}-\sum_{1\leqslant i < j < k\leqslant n}{p_i\cdot p_j\cdot p_k}$
4. 以此类推......
5. 最终得到的式子即为原公式

可见欧拉函数仅由 $A$ 和其质因子决定，与次数无关。

使用公式求欧拉函数的时间复杂度为 $O(\sqrt{n})$

代码模板：

```C++
int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    
    if (x > 1) res = res / x * (x - 1);

    return res;
}
```

结论：若 $p$ 为质数， $k\geqslant 1,k\in \mathbb{N}$，则 $\varphi \left( p^k \right) =\left( p-1 \right) p^{k-1}$

结论：欧拉函数为***积性函数***，即若 $m,n$ 互质，则 $\varphi \left( m\cdot n \right) =\varphi \left( m \right) \cdot \varphi \left( n \right)$

## 通过筛法求欧拉函数

以上方法适合求一个数的欧拉函数的情形，有时我们需要求出 $1\sim N$ 中每个数的欧拉函数，可以采用线性筛法，通过 $O(n)$ 的时间复杂度求出每一个数的欧拉函数

> 例题：[筛法求欧拉函数](./Euler_filter.cpp)

线性筛法的每个合数 $m$ 都是被最小的质因子筛掉的，设 $p_j$ 为 $m$ 的最小质因子，则 $m$ 通过 $m=p_j\times i$ 筛掉。以下分类讨论：

- 一个质数 $p$ 的欧拉函数为 $\varphi (p)=p-1$
- 欧拉函数与质因子次数无关。当 $i\ \mathrm{mod}\ p_j=0$时，说明 $i$ 包含了 $m$ 的所有质因子。有 $\varphi \left( p_j\cdot i \right) =p_j\cdot \varphi \left( i \right)$
- 当 $i\ \mathrm{mod}\ p_j\ne 0$时，则 $i$ 和 $p_j$ 是互质的，根据线性筛法的性质，有 $p_j$ 必为 $i\cdot p_j$ 的最小质因子，则 $\varphi \left( p_j\cdot i \right) =p_j\cdot \varphi \left( i \right) \cdot \left( 1-\frac{1}{p_j} \right) =\varphi \left( i \right) \cdot \left( p_j-1 \right)$

代码模板：

```C++
int primes[N], cnt;  //primes[]存储所有质数
int euler[N];  //存储每个数的欧拉函数
bool st[N];  //st[x]存储x是否被筛掉

void get_eulers(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
```

**欧拉定理**：若正整数 $n,a$ 互质，则 $a^{\varphi \left( n \right)}\equiv 1  \left( \mathrm{mod}\ n \right)$

**费马小定理**：对于整数 $a$，质数 $p$，有 $a^p\equiv a\ \left( \mathrm{mod}\ p \right)$；进一步，若 $a$ 不是 $p$ 的倍数，则有 $a^{p-1}\equiv 1\ \left( \mathrm{mod}\ p \right)$
