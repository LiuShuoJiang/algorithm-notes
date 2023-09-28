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
