# C++ STL

[速查网站](https://www.rankred.com/useful-c-cheat-sheets/)

[速查PDF](https://upload.cppreference.com/mwiki/images/e/e7/container-library-overview-2012-12-27.pdf)

通用操作：

- `size()`: 返回元素个数
- `empty()`: 返回是否为空

## vector

`vector`: 变长数组，基本思想是倍增

`clear()`: 清空

注：系统为某一个程序分配空间时，所需的时间与空间大小基本无关，而与申请次数有关，因此变长数组要尽量减小申请空间的次数(可以浪费空间)。对长度为 $n$ 的`vector`，开辟空间的次数为 $\log n$ ，而额外copy的次数为 $O(1)$

- `front()`, `back()`:
- `push_back()`, `pop_back()`:
- `begin()`, `end()`: 注意`end()`代表最后一个数的下一个数的迭代器

`vector`支持随机寻址，支持比较运算。

## pair

`pair`: 定义一个二元组，前后两个变量类型可以不一样；类似于有两个变量且实现了一些函数的结构体

- `first`: 第一个元素
- `second`: 第二个元素

`pair`支持比较运算，以`first`为第一个关键字，`second`为第二个关键字(字典顺序)

## 字符串

`string`: 字符串，`substr()`, `c_str()`

- `clear()`: 清空
- `substr()`: 
- `c_str()`: 
- `length()`: 作用同`size()`，都是返回字符串长度

## 队列

### queue

`queue`: 队列，`push()`, `front()`, `back()`, `pop()`

- `push()`: 向队尾插入一个元素
- `front()`: 返回队头元素
- `back()`: 返回队尾元素
- `pop()`: 弹出队头元素

注：`queue`没有`clear()`函数！

### priority_queue

`priority_queue`: 优先队列(堆)，`push()`, `top()`, `pop()`

注：默认为大根堆，如果想得到小根堆，可以插入原插入数的负数(`h.push(-x)`)，或是直接定义小根堆

注：`priority_queue`也没有`clear()`函数！

- `push()`: 插入一个元素
- `top()`: 返回堆顶元素
- `pop()`: 弹出堆顶元素

## 栈

`stack`: 栈，`push()`, `top()`, `pop()`

注：`stack`也没有`clear()`函数！

- `push()`: 向栈顶插入一个元素
- `top()`: 返回栈顶元素
- `pop()`: 弹出栈顶元素

## deque

`deque`: 双端队列，队头队尾均可插入和删除，支持随机访问\寻址；类似于加强版的`vector`，缺点是速度慢

- `clear()`: 清空元素
- `front()`: 
- `back()`: 
- `push_back()`: 
- `pop_back()`: 
- `push_front()`: 
- `pop_front()`: 
- `begin()` \ `end()`:

## set和map

`set`, `map`, `multiset`, `multimap`: 基于平衡二叉树(红黑树)实现，本质是动态维护有序序列

通用操作：

- `clear()`: 
- `begin()` \ `end()`: 支持`++`和`--`操作(时间复杂度为 $O(\log n)$ )，返回*前驱*和*后继*

### set

`set` / `multiset`支持：

- `insert()`: 插入一个数，时间复杂度为 $O(\log n)$
- `find()`: 查找一个数
- `count()`: 返回某一个数的个数(`set`里仅有0和1两种情况)
- `erase()`: 若输入是一个数 $x$ ，则删除所有 $x$ ，时间复杂度为 $O(k+\log n)$ ，其中 $k$ 为 $x$ 的个数；若输入是一个迭代器，则删除这个迭代器
- `lower_bound()`(重要): 返回大于等于 $x$ 的最小的数的迭代器，若不存在返回`end`
- `upper_bound()`(重要): 返回大于 $x$ 的最小的数的迭代器，若不存在返回`end`

### map

`map` / `multimap`支持：

- `insert()`: 插入的数是一个`pair`
- `erase()`: 输入的参数是`pair`或迭代器
- `find()`: 
- `[]`(重要): 像数组一样用`map`，时间复杂度为 $O(\log n)$
- `lower_bound()`: 
- `upper_bound()`: 

## 哈希表

`unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap`: 哈希表

和上面类似(一一对应)，好处是增删改查的时间复杂度为 $O(1)$ ，但不支持`lower_bound()`和`upper_bound()`，也不支持迭代器的`++`和`--`(凡是和排序有关的操作都不支持)

## bitset

`bitset`: 压位

支持`~`, `&`, `|`, `^`, `>>`, `<<`, `!=` 等操作，也支持`[]`操作符

- `count()`: 返回有多少个1
- `any()`: 判断是否至少有一个1
- `none()`: 判断是否全为0
- `set()`: 把所有位置成1
- `set(k, v)`: 将第`k`位变为`v`
- `reset()`: 把所有位变成0
- `flip()`: 等价于`~`
- `flip(k)`: 把第`k`位取反
