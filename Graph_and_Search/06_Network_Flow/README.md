# 网络流问题

Ford–Fulkerson算法：

算法的基本流程为：

```
Initialize flow f to 0 for all edges in the graph
while there exists an augmenting path p in the residual graph Gf:
    2.1 Find bottleneck capacity (minimum capacity along the path) f' of path p
    2.2 Augment each edge (u, v) and its reverse (v, u) along p by f'
    2.3 Update the residual graph Gf
return the flow f
```

算法伪代码为：

```SQL
FORD-FULKERSON(G, s, t):
    for each edge (u, v) in G.E:
        (u, v).f = 0
        (v, u).f = 0
    while there exists an augmenting path p in the residual graph G_f:
        f' = ∞
        for each edge (u, v) in p:
            f' = min(f', (u, v).c - (u, v).f)
        for each edge (u, v) in p:
            (u, v).f = (u, v).f + f'
            (v, u).f = (v, u).f - f'
    return the flow f
```

算法时间复杂度为 $O(E\times \max flow)$， $E$ 是边的数量，“ $\max flow$ ”是网络中最大流量的值。
