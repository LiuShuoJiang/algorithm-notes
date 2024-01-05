# 堆

如何手写堆？

## 堆的介绍

**堆**是一个**完全二叉树**：除了最后一层节点外，上面所有层节点都是满的，最后一层节点从左到右依次排布。

关于二叉树的概念详见[此文](https://www.cnblogs.com/idorax/p/6441043.html) (原始内容存档于[此页面](https://web.archive.org/web/20221203035541/https://www.cnblogs.com/idorax/p/6441043.html))。

堆的类型：

- **小根堆**(这里讨论)：每个点的值都小于等于左右儿子的值，则根节点是最小值所在的点；
- **大根堆**：父节点的值大于等于其子节点的值。

堆的存储方式：用 ***一维数组*** 存储。`1`号点是根节点，采用**左右孩子编号法**，每个下标为`x`的节点的左儿子(若存在)下标为`2 * x`，右儿子(若存在)下标为`2 * x + 1`；下标为`i`节点的父节点(若存在)下标是`i / 2`。

## 堆的基本操作

基本函数：

- `down(x)`：把一个节点 ***往下调整***；
- `up(x)`：把一个节点 ***往上调整***。

小根堆的操作(下标从`1`开始)：

- **插入一个数**：在整个堆的最后一个位置插入`x`，也就是需要先把新元素从堆尾插入，再逐层**上浮**到合适位置 (`heap[++size] = x; up(size);`)；
- **求集合当中的最小值**：对于小根堆就是取出根节点`heap[1]`的值；
- **删除最小值**：(删除堆的顶点)因为这里删除位于尾部的节点较为简单，所以可以用整个堆的最后一个元素覆盖掉堆顶元素，也就是先把尾元素移到根上，再逐层**下沉**到合适位置 (`heap[1] = heap[size]; size--; down(1);`)；
- (STL的堆无内置实现) **删除任意一个元素**：删除第`k`个点(`heap[k] = heap[size]; size--; down(1); down(k); up(k);`)，注意这里`down`和`up`只会执行一个；
- (STL的堆无内置实现) **修改任意一个元素**：修改第`k`个点(`heap[k] = x; down(k); up(k);`)。

## 模板与例题

### 堆的插入

一次操作时间复杂度为 $O(\log n)$。

模板：

```C++
int h[1000010], size_h;

void up(int u) {  //上浮
    if (u / 2 && h[u / 2] > h[u]) {
        swap(h[u], h[u / 2]);
        up(u / 2);
    }
}

void push(int x) {  //压入
    h[++size_h] = x;
    up(size_h);
}
```

### 堆的删除

一次操作时间复杂度为 $O(\log n)$。

模板：

```C++
void down(int u) {  //下沉
    int v = u;
    if (u * 2 <= size_h && h[u * 2] < h[v]) v = u * 2;
    if (u * 2 + 1 <= size_h && h[u * 2 + 1] < h[v]) v = 2 * u + 1;
    if (u != v) {
        swap(h[u], h[v]);
        down(v);
    }
}

void pop() {  //删除
    h[1] = h[size_h--];
    down(1);
}
```

> 例题：[堆排序](./heap_sort.cpp)

堆排序和快速排序都是不稳定的排序，而归并排序是稳定的。

### 综合

#### 堆的插入与删除的STL代码

时间复杂度为 $O(n \log n)$。

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n;
    scanf("%d", &n);  //操作次数
    while (n--) {
        int op, x;
        scanf("%d", &op);
        if (op == 1) scanf("%d", &x), q.push(x);
        else if (op == 2) printf("%d\n", q.top());
        else q.pop();
    }
    return 0;
}
```

#### 模拟堆

> 例题：[模拟堆](./heap_simulation.cpp)

堆中的每次插入都是在堆尾，但是堆中经常有`up`和`down`操作，所以节点与节点的关系并不是用类似Trie的`ne[idx][2]`就可以很好地维护的。但是好在堆是个完全二叉树，子父节点的关系可以通过下标来联系(左儿子`2*n`，右儿子`2*n + 1`)。就数组模拟来说，知道数组的下标就知道结点在堆中的位置。所以核心就在于即使有`down`和`up`操作也能维护堆数组的下标`k`和节点`idx`的映射关系。比如：`h[k] = x`，`h`数组存的是节点的值，按理来说应该用`h[idx]`来存，但是节点位置总是在变的，因此可以维护`k`和`idx`的映射关系，比如说用`ph`数组来表示`ph[idx] = k`，那么结点值为`h[ph[idx]]`，儿子下标为`ph[idx] * 2`和`ph[idx] * 2 + 1`，这样值和儿子节点可以通过`idx`联系在一起了。

可见`ph`数组主要用于帮助从`idx`映射到下标`k`，似乎有了`ph`数组就可以完成所有操作了，但为什么还要有一个`hp`数组呢？原因就在于在`swap`操作中我们输入是堆数组的下标，无法知道每个堆数组的`k`下标对应的`idx`(第`idx`个插入)，所以需要`hp`数组方便查找`idx`。

```C++
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size_h;

// 交换两个点，及其映射关系
void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= size_h && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size_h && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)建堆
for (int i = n / 2; i; i--) down(i);
```
