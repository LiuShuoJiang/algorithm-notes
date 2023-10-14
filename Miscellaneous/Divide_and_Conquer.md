# Divide and Conquer

General idea:

```C++
DAC(P) {
    if (small(P)) {
        Solve(P);
    } else {
        Divide P into P1, P2, P3, ..., Pk;
        Apply DAC(P1), DAC(P2), ...
        Combine(DAC(P1), DAC(P2), ...);
    }
}
```

Sample problems:

1. Binary search
2. Finding maximum and minimum
3. Merge sort
4. Quick sort
5. Strassen's matrix multiplication

## Recurrence Relations

1. $T(n) = T(n-1) + 1$

```C++
void Test(int n) {         //T(n)
    if (n > 0) {
        printf("%d ", n);  //1
        Test(n - 1);       //T(n - 1)
    }
}
```

`Test(n)` will make $n+1$ calls, and `prinf()` will execute $n$ times. Time complexity $T(n)=n+1\propto O(n)$

Recurrence relation is:

$$
T\left( n \right) =\begin{cases}
	1, n=0\\
	T\left( n-1 \right) +1, n>0\\
\end{cases}
$$

We can get: $T\left( n \right) =T\left( n-k \right) +k$. Assume $n-k=0$, then $T(n)=1+n$

2. $T(n)=T(n-1)+n$

```C++
void Test(int n) {
    if (n > 0) {                    //1
        for (int i = 0; i < n; i++) //n + 1 
            printf("%d ", i);       //n
        Test(n - 1);                //T(n - 1)
    }
}
```

We get $T(n)=T(n-1)+2n+2$. For simplicity, let $T(n)=T(n-1)+n$. Recurrence relation is:

$$
T\left( n \right) =\begin{cases}
	1, n=0\\
	T\left( n-1 \right) +n, n>0\\
\end{cases}
$$

We get $T(n)=T(n-k)+(n-(k-1))+(n-(k-2))+\cdots +(n-1)+n$.The total time: $T\left( n \right) =\frac{n\left( n+1 \right)}{2}\propto O\left( n^2 \right)$

3. $T(n)=T(n-1)+\log n$

```C++
void Test(int n) {                        //T(n)
    if (n > 0) {
        for (int i = 1; i < n; i = i * 2)
            printf("%d ", i);            //log(n)
        Test(n - 1);                     //T(n - 1)
    }
}
```

The recurrence relation:

$$
T\left( n \right) =\begin{cases}
	1, n=0\\
	T\left( n-1 \right) +\log n, n>0\\
\end{cases}
$$

Because $T\left( n \right) =T\left( n-k \right) +\log 1+\log 2+\cdots \log \left( n-1 \right) +\log n$, we get: $T\left( n \right) =\log n!\propto O\left( n\log n \right)$

Based on the examples above, we can summarize:

$$
T\left( n \right) =T\left( n-1 \right) +1\propto O\left( n \right) ;
\\
T\left( n \right) =T\left( n-1 \right) +n\propto O\left( n^2 \right) ;
\\
T\left( n \right) =T\left( n-1 \right) +\log n\propto O\left( n\log n \right) ;
\\
T\left( n \right) =T\left( n-1 \right) +n^2\propto O\left( n^3 \right) ;
\\
T\left( n \right) =T\left( n-2 \right) +1\propto O\left( n \right) ;
\\
T\left( n \right) =T\left( n-100 \right) +1\propto O\left( n^2 \right) 
$$

4. $T(n)=2T(n-1)+1$

```C++
void Test(int n) {         //T(n)
    if (n > 0) {
        printf("%d ", n);  //1
        Test(n - 1);       //T(n - 1)
        Test(n - 1);       //T(n - 1)
    }
}
```

Recurrence relation:

$$
T\left( n \right) =\begin{cases}
	1, n=0\\
	2T\left( n-1 \right) +1, n>0\\
\end{cases}
$$

$T\left( n \right) =2^k\cdot T\left( n-k \right) +2^{k-1}+2^{k-2}+\cdots +2^2+2+1$. Total time: $1+2+2^2+\cdots +2^n=2^{n+1}-1\propto O(2^n)$

Similarly:

$$
T\left( n \right) =3T\left( n-1 \right) +1\propto O\left( 3^n \right) ;
\\
T\left( n \right) =2T\left( n-1 \right) +n\propto O\left( n\cdot 2^n \right) 
$$

5. Dividing Function $T\left( n \right) =T\left( \frac{n}{2} \right) +1$

```C++
void Test(int n) {        //T(n)
    if (n > 1) {
        printf("%d ", n); //1
        Test(n / 2);      //T(n / 2)
    }
}
```

Recurrence relation:

$$
T\left( n \right) =\begin{cases}
	1, n=1\\
	T\left( \frac{n}{2} \right) +1, n>1\\
\end{cases}
$$

Because $T\left( n \right) =T\left( \frac{n}{2^k} \right) +k$, we get $T\left( n \right) \propto O\left( \log n \right)$

Similarly, if $T\left( n \right) =T\left( \frac{n}{2} \right) +n$, then $T\left( n \right) \propto O\left( n \right)$;

If $T\left( n \right) =2T\left( \frac{n}{2} \right) +n$, then $T\left( n \right) \propto O\left( n\log n \right)$ because $T\left( n \right) =2^k\cdot T\left( \frac{n}{2^k} \right) +k\cdot n$

6. Root function

```C++
void Test(double n) {
    if (n > 2) {
        printf("%d ", n);
        Test(sqrt(n));
    }
}
```

Recurrence relation:

$$
T\left( n \right) =\begin{cases}
	1, n=2\\
	T\left( \sqrt{n} \right) +1, n>2\\
\end{cases}
$$

We get $T\left( n \right) =T\left( n^{\frac{1}{2^k}} \right) +k$. Assume $n=2^m$, then $T\left( n \right) \propto \varTheta \left( \log\log _2n \right)$.

## Masters Theorem

### Masters Theorem for Decreasing Functions

If $T\left( n \right) =aT\left( n-b \right) +f\left( n \right)$, where $a>0, b>0, f\left( n \right) =O\left( n^k \right)$ for $k\geqslant 0$:

If $a=1$, we get $T\left( n \right) \propto O\left( n\cdot f\left( n \right) \right)$;

If $a>1$, we get $T\left( n \right) \propto O\left( a^{\frac{n}{b}}\cdot f\left( n \right) \right)$;

If $a<1$, we get $T\left( n \right) \propto O\left( f\left( n \right) \right)$

### Masters Theorem for Dividing Functions

If $T\left( n \right) =aT\left( \frac{n}{b} \right) +f\left( n \right)$, where $a\geqslant 1, b>1, f\left( n \right) =\varTheta \left( n^k\left( \log n \right) ^p \right)$:

**Case 1**: If $\log _ba>k$, then $T\left( n \right) \propto \varTheta \left( n^{\log _ba} \right)$

**Case 2**: If $\log _ba=k$:

- If $p>-1$, then $T\left( n \right) \propto \varTheta \left( n^k\left( \log n \right) ^{p+1} \right)$;
- If $p=-1$, then $T\left( n \right) \propto \varTheta \left( n^k\log\log n \right)$;
- If $p<-1$, then $T\left( n \right) \propto \varTheta \left( n^k \right)$

**Case 3**: If $\log _ba<k$: 

- If $p\geqslant 0$, then $T\left( n \right) \propto \varTheta \left( n^k\left( \log n \right) ^p \right)$;
- If $p<0$, then $T\left( n \right) \propto \varTheta \left( n^k \right)$

