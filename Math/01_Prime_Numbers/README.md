# 质数

**质数**：质数是针对大于1的自然数来定义的，如果该自然数只包含1和本身的这两个约数，就被称为质数(素数)。

## 质数的判定

> 例题：[试除法判定质数](./trial_division.cpp)

质数的判定：**试除法**，暴力做法(即枚举到 $n$ )的时间复杂度为 $O(n)$

性质：若 $\left. d \right|n$，则 $\left. \frac{n}{d} \right|n$

在枚举时，只用枚举 $d\leqslant \frac{n}{d}\Longleftrightarrow d\leqslant \sqrt{n}$ 的数，可将时间复杂度降到 $O(\sqrt{n})$ (这里的时间复杂度*必为* $O(\sqrt{n})$ )。

代码模板：

```C++
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}
```

## 分解质因数

> 例题：[分解质因数](./factoring.cpp)

分解质因数：**试除法**，从小到大枚举所有的数以尝试因子，暴力做法(即枚举到 $n$ )的时间复杂度为 $O(n)$

当枚举到满足`n % i == 0`的 $i$ 时，实际上所有从2到 $i-1$ 的所有质因子已经被除干净了，也就是 $n$ 已经不包含从2到 $i-1$ 的质因子；因为 $n$ 是 $i$ 的倍数，说明 $i$ 也不包含从2到 $i-1$ 的质因子，因此 $i$ 一定是质数

性质：不超过 $n$ 的自然数中最多只包含一个大于 $\sqrt{n}$ 的质因子。

在枚举时，可以只枚举到 $\sqrt{n}$，然后单独处理大于 $\sqrt{n}$ 的质因子，可将时间复杂度降到 $O(\sqrt{n})$ (这里的时间复杂度*不一定为* $O(\sqrt{n})$，最好可以达到 $O(\log n)$ ，这时 $n=2^k$ )。

代码模板：

```C++
void divide(int x) {
    for (int i = 2; i < = x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
```

## 质数筛选

> 例题：[筛质数](./prime_counting.cpp)

暴力做法的思想是从2到 $n$ 看每一个数，把2的所有倍数筛掉，再把3的所有倍数筛掉，再把5的所有倍数筛掉，...，这样剩余的所有数都是质数。时间复杂度为 $O\left( \frac{n}{2}+\frac{n}{3}+\cdots +\frac{n}{n} \right) \approx O\left( n\ln n \right) \approx O\left( n\log n \right)$

**埃氏筛法**(Sieve of Eratosthenes)：

从小到大枚举每个数：

- 如果当前数没被划掉，则必定是质数，记录该质数
  - 枚举当前质数的倍数，必定是合数，划掉合数

性质([Prime Number Theorem](https://en.wikipedia.org/wiki/Prime_number_theorem))：从1到 $n$ 中有约 $\frac{n}{\ln n}$ 个质数。

采用埃氏筛法优化后，时间复杂度约为 $O(n)$，真实时间复杂度为 $O(n\log \log n)$，因为一个合数可能被筛掉不止一次

代码模板：

```C++
typedef long long LL;
const int N = 100000010;
int primes[N], cnt;  //primes[]存储所有质数，cnt存储质数个数
bool st[N];  //st[x]存储x是否被筛掉

void get_primes(int n) {
    for (LL i = 2; i <= n; i++) {
        if (st[i]) continue;
        primes[++cnt] = i;
        for (LL j = i * i; j <= n; j += i)
            st[j] = true;
    }
}
```

**线性筛法**：

采用线性筛法进行优化，这里 $n$ 只会被它的最小质因子筛掉：

- 若`i % primes[j] == 0`：则`primes[j]`一定是`i`的最小质因子，`primes[j]`也一定是`primes[j] * i`的最小质因子；
- 若`i % primes[j] != 0`：因为我们是从小到大枚举所有的质数且没有枚举到`i`的质因子，则`primes[j]`必定小于`i`的所有质因子，`primes[j]`也一定是`primes[j] * i`的最小质因子

对于一个合数`x`，假设`primes[j]`为`x`的最小质因子，当`i`枚举到`x / primes[j]`时，就可以筛掉

线性筛法(又名欧拉筛法)的步骤为：

从小到大***枚举每一个数***：

- 如果当前数没有被划掉，则必定是质数，记录该质数
- ***枚举已记录的质数***(如果合数已越界则中断)
  - 合数未越界，则划掉合数
  - 条件`i % p == 0`，保证合数***只被最小质因子***划掉
    - 若`i`是质数，则最多枚举到自身中断
    - 若`i`是合数，则最多枚举到自身的最小质数中断

代码模板：

```C++
int primes[N], cnt;  //primes[]存储所有素数
bool st[N];  //st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[++cnt] = i;
        //以下范围判断也可写 1LL * i * primes[j] <= n; (LL为long long)
        for (int j = 1; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
```

线性筛法时间复杂度为 $O(n)$
