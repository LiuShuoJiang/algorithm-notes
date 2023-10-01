# 并查集

特点：思维性较强，代码较短，常出现于面试

## 定义

并查集的操作：

- 将两个集合合并(并)
- 询问两个元素是否在一个集合当中(查)

并查集维护的是一堆集合(集)

## 算法

### 理论考察

原始可以使用两个数组：第一个数组保存所有元素；第二个数组使用数组的下标来代表数组一中元素，对应位置上存放的值表示元素所属的集合。但第二个数组中保存的是第一个数组中各个元素所属集合，所以合并集合的时候，第二个数组中需要修改元素比较多。

修正：可以为每个元素选出一个代表它的元素，数组二中存放代表元素。第一个数组保存了所有元素，第二个数组保存了能代表该元素的元素。这个时候，如果要合并两个集合，只需要修改代表元素即可。

步骤：

- 用一个数组保存对应位置元素所属集合的代表元素
- AB两个集合合并：将B集合代表元素的代表元素设置为A集合的代表元素
- 查找C元素属于哪个集合：找C元素的代表元素，如果不是他自己，就重复查找代表元素的代表元素，知道查找到一个元素的代表元素是它自己，C就属于整个代表元素所代表的集合

时间复杂度：近乎 $O(1)$

### 实现的基本原理

用树的形式维护集合，每个集合用一棵树来表示，树根的编号就是整个集合的编号，每个节点存储它的父节点，`p[x]`表示`x`的父节点

- 问题1：如何判断树根？`if (p[x] == x)`
- 问题2：如何求`x`的集合编号？`while (p[x] != x) x = p[x];`
- 问题3：如何合并两个集合？ $p_x$ 是`x`的集合编号， $p_y$ 是`y`的集合编号，令`p[x] = y`

并查集的优化：路径压缩(常用)；二值合并(略)

## 模板

### 朴素并查集

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

```C++
int p[N], d[N];
//p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

// 返回x的祖宗节点
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
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