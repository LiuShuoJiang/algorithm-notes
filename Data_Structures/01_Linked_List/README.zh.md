# 链表

这里主要涉及**数组模拟链表**的方法(比`new`快)，而非面试中常考的动态创建链表。

附注：面试中创建链表的方式如下：

```C++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

## 单链表

单链表的常见用途是*邻接表*(其实就是一堆单链表)，邻接表最重要的应用是存储图和树。

单链表每个点都会存储`value`值和`next`指针。用数组模拟时，构建两个数组`e[N]`和`ne[N]`分别代表某一个点的当前值和`next`指针。空节点的下标用`-1`表示。

![链表](../../images/Linked_List.png)

> 例题：[单链表](./single_linked_list.cpp)

`head`表示头节点，`e`数组存储元素，`ne`数组存储下一个节点索引，`idx`表示下一个可以存储元素的位置索引。

1. 头节点前面添加元素：
    1. 在`e`的`idx`处存储元素`e[idx] = x;`
    2. 该元素插入到头节点前面`ne[idx] = head;`
    3. 头节点指向该元素`head = idx;`
    4. `idx`指向下一个可存储元素的位置 `idx++;`
2. 在索引`k`后插入一个数：
    1. 在`e`的`idx`处存储元素`e[idx] = x;`
    2. 该元素插入到第`k`个插入的数后面`ne[idx] = ne[k];`
    3. 第`k`个插入的数指向该元素`ne[k] = idx;`
    4.  `idx`指向下一个可存储元素的位置`idx++;`
3.  删索引为`k`的元素的后一个元素：
    1.  `ne[k]`的值更新为`ne[ne[k]]`。

模板：

```C++
// head存储链表头，e[]存储节点的值
//ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init() {
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert_from_head(int a) {
    e[idx] = a, ne[idx] = head, head = idx++;
}

// 将a插入到下标为k的点的后面
void insert_from_k(int k, int a) {
    e[idx] = a;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 将头结点删除，需要保证头结点存在
void remove_head() {
    head = ne[head];
}

// 将下标是k的点的后面的点删掉
void remove_k(int k) {
    ne[k] = ne[ne[k]];  // 算法题中不用考虑空间浪费问题
}

// 遍历链表
for (int i = head; i != -1; i = ne[i]) 
    std::cout << e[i] << ' ';
```

## 双链表

常用双链表优化某些问题。

为简化起见，可以不定义头节点、尾节点，而直接用`0`和`1`代表头和尾，所以最右边插入只要在指向`1`的那个点的右边插入就可以了。

> 例题：[双链表](./double_linked_list.cpp)

模板：

```C++
// e[]表示节点的值，l[]表示节点的左指针
//r[]表示节点的右指针，idx表示当前用到了哪个节点
int e[N], l[N], r[N], idx;

//初始化
void init() {
    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 在下标为k的节点的右边插入一个数x
void insert(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k]; //将新节点分别指向插入位置的右节点和左节点
    //将新节点右边一节点向左指向新节点,将新节点左边一节点向右指向新节点
    // 更新索引
    l[r[k]] = idx, r[k] = idx++;  // 不能写反！
}

// 删除节点a
void remove(int a) {
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}
```

参考[这篇题解](https://www.acwing.com/solution/content/211726/)。
