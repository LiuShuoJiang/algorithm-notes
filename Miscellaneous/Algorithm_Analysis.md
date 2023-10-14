# Algorithm Analysis Basics

## How to write an algorithm

```
Algorithm swap(a, b)
Begin
    temp = a;
    a = b;
    b = temp;
End
```

## How to analysis an algorithm

1. Time
2. Space
3. Network/Internet consumption
4. Power
5. CPU registers

Time measuring:

```C
Algorithm swap(a, b)
Begin
    temp = a;---------1
    a = b;------------1
    b = temp;---------1
End

f(n) = 3: O(1)
```

Space measuring:

```C
Algorithm swap(a, b)
Begin
    temp = a;
    a = b;
    b = temp;
End

a-----1
b-----1
temp--1

s(n) = 3 words: O(1)
```

## Frequency Count Method

Example 1:

```C
Algorithm sum(A, n)
{
    s = 0;------------------------ 1
    for (i = 0; i < n; i++)------- n + 1
    {
        s = s + A[i];------------- n
    }
    return s;--------------------- 1
}

f(n) = 2*n + 3: O(n)

A-----n
n-----1
s-----1
i-----1
s(n) = n + 3: O(n)
```

Example 2:

```C
Algorithm Add(A, B, n)
{
    for (i = 0; i < n; i++)------------------ n + 1
    {
        for (j = 0; j <n; j++)--------------- n * (n + 1)
        {
            C[i, j] = A[i, j] + B[i, j];----- n * n
        }
    }
}

f(n) = 2*n^2 + 2*n + 1: O(n^2)

A-----n^2
B-----n^2
C-----n^2
n-----1
i-----1
j-----1
s(n) = 3*n^2 + 3: O(n^2)
```

## Asymptotic Notations

1. Big-oh Notation for upper bound: $O$
2. Big-omega Notation for lower bound: $\varOmega$
3. Big-theta Notation for average bound: $\varTheta$

**Big-oh**: The function $f(n)=O(g(n))$ if $\exists$ positive constants $c$ and $n_0$ such that $f\left( n \right) \leqslant c\cdot g\left( n \right)$ for $\forall n\geqslant n_0$.

Example: $f(n)=2n+3$: $2n+3\leqslant 10n$ for $n\geqslant 1$, $2n+3\leqslant 5n^2$ for $n\geqslant 1$

$$
\underset{\mathrm{lower} \mathrm{bound}}{\underbrace{1<\log n<\sqrt{n}}}<\underset{\mathrm{average} \mathrm{bound}}{\underbrace{n}}<\underset{\mathrm{upper} \mathrm{bound}}{\underbrace{n\log n<n^2<n^3<\cdots <2^n<3^n<\cdots n^n}}
$$

**Big-omega**: The function $f(n)=\varOmega (g(n))$ if $\exists$ positive constants $c$ and $n_0$ such that $f\left( n \right) \geqslant c\cdot g\left( n \right)$ for $\forall n\geqslant n_0$.

Example: $f(n)=2n+3$: $f(n)=\varOmega (n)$, $f(n)=\varOmega(\log n)$

**Big-theta**(recommend): The function $f\left( n \right) =\varTheta \left( g\left( n \right) \right)$ if $\exists$ positive constant $c_1$, $c_2$ and $n_0$ such that $c_1g\left( n \right) \leqslant f\left( n \right) \leqslant c_2g\left( n \right)$.

Example: $f(n)=2n+3$: $f(n)=\varTheta (n)$


