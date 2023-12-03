# 并查集

特点：思维性较强，代码较短，常出现于面试

## 定义

**并查集**的操作：

- 将两个集合合并(***并***)
- 询问两个元素是否在一个集合当中(***查***)

并查集维护的是一堆集合(***集***)

## 算法

### 理论考察

原始可以使用两个数组：第一个数组保存所有元素；第二个数组使用数组的下标来代表数组一中元素，对应位置上存放的值表示元素所属的集合。但第二个数组中保存的是第一个数组中各个元素所属集合，所以合并集合的时候，第二个数组中需要修改元素比较多。

修正：可以为每个元素选出一个代表它的元素，数组二中存放代表元素。第一个数组保存了所有元素，第二个数组保存了能代表该元素的元素。这个时候，如果要合并两个集合，只需要修改代表元素即可。

步骤：

- 用一个数组保存对应位置元素所属集合的代表元素
- $A,B$ 两个集合合并：将 $B$ 集合代表元素的代表元素设置为 $A$ 集合的代表元素
- 查找 $C$ 元素属于哪个集合：找 $C$ 元素的代表元素，如果不是他自己，就重复查找代表元素的代表元素，直到查找到一个元素的代表元素是它自己， $C$ 就属于整个代表元素所代表的集合

时间复杂度：近乎 $O(1)$

### 实现的基本原理

用**树**的形式维护集合，每个集合用一棵树来表示，树根的编号就是整个集合的编号，每个节点存储它的父节点，`p[x]`表示`x`的父节点

- 问题1：如何判断树根？`if (p[x] == x)`
- 问题2：如何求`x`的集合编号？`while (p[x] != x) x = p[x];`
- 问题3：如何合并两个集合？ $p_x$ 是`x`的集合编号， $p_y$ 是`y`的集合编号，令`p[x] = y`

并查集的优化：路径压缩(常用)；二值合并(略)

不带路径压缩的查找如下：

```C++
//根节点就是集合的代表，查找就是找到元素所在集合的根
int find(int x) {
    //如果父节点等于自己，则找到了并返回
    if (p[x] == x) return x;
    //如果还没找到根，则继续递归查找
    return find(p[x]);
}
```

带路径压缩的查找和合并如下(能够加快以后的查找进程)：

```C++
int find(int x) {
    if (p[x] == x) return x;
    //在返回的路上，顺带修改各节点父节点为根
    return p[x] = find(p[x]);
}

//把一个集合的根指向另一个集合的根
void union_set(int x, int y) {
    p[find(x)] = find(y);
}
```

为了把小集合的根指向大集合的根，合并时可以采用**启发式合并**(也叫**按秩合并**，不常用)：

```C++
//记录并初始化子树的大小为1
vector<int> siz(N, 1);

void union_set(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    p[x] = y;
    siz[y] += siz[x];  //在根节点上维护新节点的大小
}
```

## 模板与例题

### 朴素并查集

> 例题：[合并集合](./union_sets.cpp)

```C++
int p[N]; //存储每个点的祖宗节点

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i++) p[i] = i;

// 合并a和b所在的两个集合
p[find(a)] = find(b);
```

### 维护size的并查集

> 例题：[连通块中点的数量](./connected_blocks.cpp)

```C++
int p[N], size[N];
//p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i++) {
    p[i] = i;
    size[i] = 1;
}

// 合并a和b所在的两个集合
size[find(b)] += size[find(a)];
p[find(a)] = find(b);
```

### 维护到祖宗节点距离的并查集

> 例题：[食物链](./food_chain.cpp)

思路是用“距离”来描述关系、判断关系，所有的距离都以根节点为基准，按照`mod`类别数3分为三类。

- “距离”：`x`吃`y`表示`y`到`x`的距离为1，`y`是第`0`代，吃`y`的`x`是第1代，吃`x`的是第2代，根节点是第0代等
- 三种关系：用点到根节点之间的距离表示其余根节点之间的关系
  - 模3余1：可以吃根节点
  - 模3余2：可以被根节点吃
  - 模3余0：和根节点同类

这样就把集合中所有的点划分为上述三类。

`d[i]`理解是第`i`个节点到其父节点的距离，`find()`函数进行了路径压缩，当查询某个节点`i`时，如果`i`的父节点不为根节点的话，就会进行递归调用，将`i`节点沿途路径上所有节点均指向父节点，此时的`d[i]`存放的是`i`到父节点，也就是根节点的距离。不路径压缩取得的是到父节点的距离，路径压缩后既是到根的距离，也是到父节点的距离，因为压缩后将父亲指向根了，父亲和根是一个东西。而由于每次取`d[x]`都必然经过路径压缩，因此`d[x]`在结果上既是到根的距离，也是到父亲的距离。但是在过程中它仅代表到父亲的距离，因为没更新的时候它的父亲并不是根。[总结：`d[x]`始终代表到父节点的距离，只不过在`find`之后`x`的父节点直接变成了根节点(祖宗)，所以逻辑上成了到祖宗的距离]

```C++
int p[N], d[N];
//p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) {
        //先把父节点及以上压缩到根节点，这时父节点是根节点的一级子节点，x是根节点的二级子节点。过程中d[p[x]]被更新为父节点到根节点的距离
        int u = find(p[x]);
        //先更新边权，再把x也压到根节点。否则x的父节点到根节点的距离d[p[x]]没加上就丢失了
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i++) {
    p[i] = i;
    d[i] = 0;
}

// 合并a和b所在的两个集合
p[find(a)] = find(b);
d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量
```