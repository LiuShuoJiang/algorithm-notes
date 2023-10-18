# 最小生成树

1. Prim算法
   1. 朴素版Prim(常用)：稠密图，时间复杂度 $O(n^2)$
   2. 堆优化版Prim(不常用)：稀疏图，时间复杂度 $O(m\log n)$
2. Kruskal算法(常用)：稀疏图，时间复杂度 $O(m\log m)$

## Prim算法

### 朴素版Prim算法

算法伪代码为：

```SQL
PRIM(G, w, r):
    for each u in G.V:
        u.key = ∞
        u.π = NIL
    r.key = 0
    Q = G.V
    while Q ≠ ∅:
        u = EXTRACT-MIN(Q)
        for each v in G.Adj[u]:
            if v ∈ Q and w(u, v) < v.key
                v.π = u
                v.key = w(u, v)
```

> 例题：[Prim算法求最小生成树](./Prim.cpp)

### 堆优化的Prim算法

略

## Kruskal算法

1. 将所有边按权重从小到大排序，本步骤时间复杂度为 $O(m\log m)$；
2. 从小到大依次枚举每条边 $a,b$，权重 $c$，如果 $a,b$ 不连通，就将这条边加入到集合中。本步骤时间复杂度为 $O(m)$。

以上步骤类似于并查集。

算法伪代码为：

```SQL
KRUSKAL(G, w):
    A = ∅
    for each vertex v in G.V:
        MAKE-SET(v)
    sort the edges of G.E into non-decreasing order by weight w
    for each edge (u, v) in G.E, taken in non-decreasing order by weight:
        if FIND-SET(u) ≠ FIND-SET(v):
            A = A ∪ {(u, v)}
            UNION(u, v)
    return A
```

> 例题：[Kruskal算法求最小生成树](./Kruskal.cpp)
