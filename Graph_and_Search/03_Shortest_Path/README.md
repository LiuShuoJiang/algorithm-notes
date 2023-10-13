# 最短路问题

最短路问题的分类(以下 $n$ 为图的点数， $m$为图的边数)：

- ***单源最短路***：求一个点到其他所有点的最短路
  - *图中所有边权都是正数*：
    - **朴素Dijkstra算法**：时间复杂度 $O(n^2)$，比较适用于稠密图 (例如： $m$ 和 $n^2$ 在同一数量级)
    - **堆优化版的Dijkstra算法**：时间复杂度 $O(m\log n)$，比较适用于稀疏图 (例如： $m$ 和 $n$ 在同一数量级)
  - *图中存在负权边*：
    - **Bellman-Ford算法**：时间复杂度 $O(nm)$，适用于求不超过 $k$ 条边的最短路
    - **SPFA**: 是Bellman-Ford算法的优化，平均时间复杂度为 $O(m)$，最坏 $O(nm)$，相对应用限制最少
- ***多源汇最短路***：起点和终点是不确定的
  - **Floyd算法**：时间复杂度 $O(n^3)$

以上分类中可以不区分有向图和无向图，因为可以通过将无向图点之间连两条有向边来转化为有向图，因此可以只考虑有向边。

最短路算法常考察模型的建立(建图)，也就是如何把原问题抽象成最短路问题，而不是原理。

- [最短路问题](#最短路问题)
  - [Dijkstra算法](#dijkstra算法)
    - [朴素Dijkstra算法](#朴素dijkstra算法)
    - [堆优化的Dijkstra算法](#堆优化的dijkstra算法)
  - [Bellman-Ford算法](#bellman-ford算法)
  - [SPFA](#spfa)
  - [Floyd算法](#floyd算法)

## Dijkstra算法

### 朴素Dijkstra算法

朴素Dijkstra算法基于贪心，伪代码如下：

```SQL
function Dijkstra(Graph, source):
    distance[source] ← 0                 --初始化起点距离
    for each vertex v in Graph:             
        if v ≠ source
            distance[v] ← infinity       --初始化其他点距离
            previous[v] ← undefined      --v的前驱
        end if
    end for

    visitedSet ← empty set               --当前已确定最短距离的点

    while size of visitedSet < size of Graph:
        --用不在visitedSet中的距离最近的点更新current
        current ← vertex not in visitedSet with smallest distance
        
        add current to visitedSet

        --用current更新其他点的距离
        for each neighbor v of current:  --Consider all neighbors
            if v not in visitedSet:
                alt ← distance[current] + weight(current, v)
                if alt < distance[v]:    --一个距离v的更短距离被找到
                    distance[v] ← alt
                    previous[v] ← current
                end if
            end if
        end for
    end while

    return distance[], previous[]
end function
```

朴素Dijkstra算法适用于稠密图，可以用邻接矩阵来存图。

> 例题：[Dijkstra求最短路 I](./Dijkstra_simple.cpp)

代码模板：

```C++
int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];  // 存储每个点的最短路是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j < = n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        // 用t更新其他点的距离
        for (int j = 1; j < n; j++) {
            dist[j] = min(dist[j], dist[t] +g[t][j]);
        }

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```

补充：用邻接表存图的另一种代码模板：

```C++
struct edge {
    int v, w;
};
//e[u]存节点u的所有出边的终点和边权
vector<edge> e[N];
//d[u]存u到源点s的最小距离，vis[u]标记u是否出圈
int d[N], vis[N];

void dijkstra(int s) {
    //初始时所有点都在圈(集合)内，vis = 0, d[s] = 0, d[其他点] = 正无穷
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0;

    //重复如下操作直到圈内为空
    for (int i = 1; i < n; i++) {
        //从圈内选一个距离最小的点u，打标记移出圈(该算法性能瓶颈)
        int u = 0;
        for (int j = 1; j <= n; j++) {  //枚举点
            if (!vis[j] && d[j] < d[u]) u = j;
        }
        vis[u] = 1; //标记u已经出圈

        //对u的所有出边执行松弛操作，即尝试更新邻点v的最小距离
        for (auto ed : e[u]) {  //枚举邻边
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w) d[v] = d[u] + w;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    dijkstra(1);
}
```

算法时间复杂度为 $O(n^2+m)\approx O(n^2)$， $n$ 为图的点数， $m$为图的边数

### 堆优化的Dijkstra算法

使用堆来存储起点到所有点的距离，时间复杂度变为 $O(m\log n)$。堆的实现可以采用手写支持修改任意元素的堆(堆中有 $n$ 个数)，也可以用C++的优先队列数据结构`priority_queue`(Python可以直接用`set`)，堆中有 $m$ 个数(这样时间复杂度变为 $O(m \log m)$，但依然和 $O(m\log n)$相近)。

由于图为稀疏图，故需采用邻接表存储图。

> 例题：[Dijkstra求最短路 II](./Dijkstra_heap.cpp)

堆优化版的Dijkstra是对朴素版Dijkstra进行了优化，在朴素版Dijkstra中时间复杂度最高的寻找距离最短的点(时间复杂度 $O(n^2)$ 的这一过程)可以使用小根堆优化。

1. 一号点的距离初始化为零，其他点初始化成无穷大。
2. 将一号点放入堆中。
3. 不断循环，直到堆空。每一次循环中执行的操作为：
   1. 弹出堆顶(与朴素版Dijkstra找到`visitedSet`外距离最短的点相同，并标记该点最短路径已经确定)；
   2. 用该点更新临界点的距离，若更新成功就加入到堆中。

代码模板(使用小根堆)：

```C++
typedef pair<int, int> PII;

int n;  // 点的数量
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N];  // 存储所有点到1号点的距离
bool st[N];  // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // first存储距离，second存储节点编号
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```

时间复杂度为 $O(m \log n)$，其中 $n$ 表示点数， $m$ 表示边数

补充：使用`struct`的且记录路径并递归输出的堆优化版Dijkstra算法模板如下(此处使用大根堆)：

```C++
struct edge {
    int v, w;
};
vector<edge> e[N];
int d[N], vis[N], pre[N];

//创建一个pair类型的大根堆q{-距离, 点}，把距离取负值，距离最小的元素最大，必在堆顶
priority_queue<pair<int, int>> q;

void dijkstra(int s) {
    //初始化：{0, s}入队，d[s] = 0，d[其他点]=正无穷
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0;
    q.push({0, s});

    //重复直到队列为空
    while (q.size()) {
        //从队头弹出距离最下的点u
        auto t = q.top();
        q.pop();

        //若u扩展过则跳过，否则打标记
        int u = t.second;
        if (vis[u]) continue;  //再次出队的，跳过
        vis[u] = 1;  //标记u已出队

        //对u的所有出边执行松弛操作，把{-d[v], v}压入队尾
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                q.push({-d[v], v});  //大根堆
            }
        }
    }
}

void dfs_path(int u) {
    if (u == s) {
        printf("%d ", u);
        return;
    }
    dfs_path(pre[u]);
    printf("%d ", u);
}
```

## Bellman-Ford算法

Bellman-Ford算法的伪代码如下：

```SQL
function BellmanFord(Graph, source):
    for each vertex v in Graph:
        distance[v] ← infinity
        predecessor[v] ← null
    end for
    distance[source] ← 0

    --松弛操作
    for i from 1 to |V| - 1:                  --|V|为顶点数
        for each edge (u, v) in Graph:
            if distance[u] + weight(u, v) < distance[v]:
                distance[v] ← distance[u] + weight(u, v)
                predecessor[v] ← u
            end if
        end for
    end for

    for each edge (u, v) in Graph:
        --如果还存在不满足三角不等式的情况
        if distance[u] + weight(u, v) < distance[v]:
            print "Graph contains a negative-weight cycle"
            return
        end if
    end for

    return distance[], predecessor[]
end function
```

图中存在负权回路时，可能不存在从起点到目标点的最短路径，例如当路径上存在负权回路时，可以沿着该回路无限循环，导致最短路径变为 $-\infty$。

> 例题：[有边数限制的最短路](./short_path_within_k_hops.cpp)

注意在该例题中需要对下面的模板稍作修改，加上备份数组`backup`。

代码模板：

```C++
int n, m;  // n表示点数，m表示边数
int dist[N];  // dist[x]存储1到x的最短路距离

// 边，a表示出点，b表示入点，w表示边的权重
struct edge {
    int a, b, w;
} edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1
int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径
    // 由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;

            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}
```

因为每轮循环是 $O(m)$ 的，若最短路存在，一轮松弛操作会使最短路的边数至少加1，而最短路的边数最多为 $n-1$，因此最多执行 $n-1$轮松弛操作。故总时间复杂度为 $O(nm)$，其中 $n$ 表示点数， $m$表示边数。

Bellman-Ford算法能够判断负环存在：如果第 $n$ 轮循环是仍然存在能够松弛的边，说明从源点出发能够抵达一个负环。

补充：Bellman-Ford的使用`vector`的另一种代码实现如下：

```C++
struct edge {
    int v, w;
};
//e[u]存u点的出边的邻点和边权
vector<edge> e[N];
//d[u]存u点到源点的距离
int d[N];

bool bellman_ford(int s) {
    //初始化d[s] = 0，d[其他点]=正无穷
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    bool flag;  //是否松弛

    //执行多轮循环，每轮循环对所有边都尝试进行一次松弛操作
    for (int i = 1; i <= n; i++) {  //n轮
        flag = false;
        
        for (int u = 1; u <= n; u++) {  //n点
            if (d[u] == 0x3f3f3f3f) continue;

            for (auto ed : e[u]) {  //u的出边
                int v = ed.v, w = ed.w;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    flag = true;
                }
            }
        }

        //当一轮循环中没有成功的松弛操作时，算法终止
        if (!flag) break;
    }

    return flag;  //第n轮为true则有负环
}
```

## SPFA

SPFA (Shortest Path Faster Algorithm)是对Bellman-Ford算法的改进。事实上，只有本轮被更新的点，其出边才有可能引起下一轮的松弛操作，因此可以用队列来维护被更新的点的集合。

SPFA伪代码如下：

```SQL
function SPFA(Graph, source):
    for each vertex v in Graph:
        distance[v] ← infinity
        inQueue[v] ← false
    end for
    distance[source] ← 0

    queue ← empty queue
    queue.push(source)
    inQueue[source] ← true

    while queue is not empty:
        u ← queue.pop()
        inQueue[u] ← false

        for each neighbor v of u:
            if distance[u] + weight(u, v) < distance[v]:
                distance[v] ← distance[u] + weight(u, v)
                if not inQueue[v]:
                    queue.push(v)
                    inQueue[v] ← true
            end if
        end for
    end while

    --Optional: Negative cycle detection
    for each vertex v in Graph:
        for each neighbor w of v:
            if distance[v] + weight(v, w) < distance[w]:
                print "Graph contains a negative-weight cycle"
                return
            end if
        end for
    end for

    return distance[]
end function
```

> 例题：[SPFA求最短路](./SPFA.cpp)

代码模板：

```C++
int n; // 总点数
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N];   // 存储每个点到1号点的最短距离
bool st[N];  // 存储每个点是否在队列中

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int SPFA() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];

                // 如果队列中已存在j，则不需要将j重复插入
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
```

`st`数组的作用：判断当前的点是否已经加入到队列当中了；已经加入队列的结点就不需要反复的把该点加入到队列中了，就算此次还是会更新到源点的距离，那只用更新一下数值而不用加入到队列当中。即便不使用`st`数组最终也没有什么关系，但是使用的好处在于可以提升效率。

SPFA看上去和Dijkstra算法长得有一些像，但是其中的意义还是相差甚远的:

- Dijkstra算法中的st数组保存的是当前确定了到源点距离最小的点，且一旦确定了最小那么就不可逆了(不可标记为`true`后改变为`false`)；SPFA算法中的`st`数组仅仅只是表示的当前发生过更新的点，且SPFA中的`st`数组可逆(可以在标记为`true`之后又标记为`false`)。注意BFS中的`st`数组记录的是当前已经被遍历过的点。
- Dijkstra算法里使用的是优先队列保存的是当前未确定最小距离的点，目的是快速的取出当前到源点距离最小的点；SPFA算法中使用的是队列(也可以使用别的数据结构),目的只是记录一下当前发生过更新的点。

Bellman-Ford算法里最后`return -1`的判断条件写的是`dist[n] > 0x3f3f3f3f / 2`，而SPFA写的是`dist[n] == 0x3f3f3f3f`，其原因在于Bellman Ford算法会遍历所有的边，因此不管是不是和源点连通的边它都会得到更新，但是SPFA算法不一样，它相当于采用了BFS，因此遍历到的结点都是与源点连通的，因此如果要求的`n`和源点不连通，它不会得到更新，还是保持0x3f3f3f3f。

由于SPFA是由Bellman-Ford算法优化而来，在最坏的情况下时间复杂度和它一样，即时间复杂度为 $O(nm)$，但平均时间复杂度为 $O(m)$，其中 $n$ 为点数， $m$ 为边数。假如题目时间允许可以直接用SPFA去解Dijkstra算法的题目。

SPFA可以处理负权边，但是不能处理有负权回路的图；而Dijkstra不能处理带有负权边和负权回路的图，因为Dijkstra算法在计算最短路径时，不会因为负边的出现而更新已经计算过(收录过)的顶点的路径长度。可见Bellman-Ford可以处理任意带负权边和负权环的图，SPFA可以处理带负权边的图，Dijkstra只能处理带正权边的图。

> 例题：[SPFA判断负环](./SPFA_negative_loop.cpp)

判断负环的模板代码：

```C++
int n;  // 总点数
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
// dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
int dist[N], cnt[N];
bool st[N];  // 存储每个点是否在队列中

// 如果存在负环，则返回true，否则返回false
bool SPFA() {
    // 不需要初始化dist数组

    // 判负环：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}
```

在SPFA中，`dist[x]`表示从1号点到`x`号点的最短距离，为了判断负权回路，还可以另开一个`cnt[x]`数组表示从从1号点到`x`号点的最短路的边的数量。每次更新时除了`dist[x] = dist[t]+ w[i];`之外再加上`cnt[x] = xnt[t] + 1;`。如果某次出现`cnt[x] >= n`，则可以根据抽屉原理判断该路径上至少有两个点的距离是相同的，即路径上存在环，而且该环必为负环。

补充：另一种使用`vector`的SPFA代码实现(能判负环和递归输出路径)：

```C++
struct edge {
    int v, w;
};
vector<edge> e[N];
//vis[u]标记u点是否在队内，cnt[v]记录边数，判负环
int d[N], cnt[N], vis[N], pre[N];
queue<int> q;  //队列

bool SPFA(int s) {
    //初始化：s入队，标记s在队内，d[s] = 0，d[其他点] = 正无穷
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    vis[s] = 1;
    q.push(s);

    //重复直到队列为空
    while (q.size()) {
        //从队头弹出u点，标记u不在队内
        int u = q.front();
        q.pop();
        vis[u] = 0;

        //枚举u的所有出边
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            //执行松弛操作
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;  //记录前驱点
                
                //记录从s走到v的边数并判负环
                cnt[v] = cnt[u] + 1;  //记录边数
                //如果有负环返回true
                if (cnt[v] >= n) return true;

                //如果v不在队内则把v压入队尾，并打上标记
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    return false;
}

void dfs_path(int u) {  //递归输出路径
    if (u == 1) {
        printf("%d ", u);
        return;
    }
    dfs_path(pre[u]);
    printf("%d ", u);
}
```

## Floyd算法

Floyd算法基于动态规划，使用邻接矩阵，`d[i][j]`存储所有的边，共三重循环，循环完之后`d[i][j]`就是从点`i`到点`j`的最短距离。时间复杂度为 $O(n^3)$，其中 $n$ 为点数。

> 例题：[Floyd求最短路](./Floyd.cpp)

代码模板：

```C++
//初始化
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
```
