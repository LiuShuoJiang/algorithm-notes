# C++ STL

- [C++ STL](#c-stl)
  - [数组 (array)](#数组-array)
  - [向量 (vector)](#向量-vector)
  - [对 (pair)](#对-pair)
  - [字符串 (string)](#字符串-string)
  - [链表 (list)](#链表-list)
    - [单向链表 (forward\_list)](#单向链表-forward_list)
    - [双向链表 (list)](#双向链表-list)
  - [队列](#队列)
    - [普通队列 (queue)](#普通队列-queue)
    - [优先队列 (priority\_queue)](#优先队列-priority_queue)
  - [栈 (stack)](#栈-stack)
  - [双端队列 (deque)](#双端队列-deque)
  - [集合和映射](#集合和映射)
    - [集合 (set, multiset)](#集合-set-multiset)
    - [映射 (map, multimap)](#映射-map-multimap)
  - [哈希表](#哈希表)
  - [位集 (bitset)](#位集-bitset)

STL的更多资源详见 [速查网站](https://www.rankred.com/useful-c-cheat-sheets/) 和 [速查PDF](https://upload.cppreference.com/mwiki/images/e/e7/container-library-overview-2012-12-27.pdf)。

C++的 ***Standard Template Library(STL)*** 包含以下三个部分：

- **Container(容器)**: 用来存储数据；
- **Iterator(迭代器)**: 用来访问数据；
- **Algorithm(算法)**: 对STL相关操作的算法。

通用操作：

- `size()`: 返回元素个数
- `empty()`: 返回是否为空

## 数组 (array)

语法：`std::array<T, N> arr;`

`array`是一个封装了 ***固定*** 大小数组的容器，编译期间需要知道数组大小！`array`的“值传递”确实是值传递(回忆：传统的非STL的数组是指针传递)。

`array`访问元素的方式：

- `at()`: 例如`arr.at(4)`指的是`arr[4]`，如果下标越界会抛出out of bound exception；
- `[]`: 下标越界的行为与`at()`不同；
- `front()`: 返回第一个元素；
- `back()`: 返回最后一个元素；
- `data()`: 返回`arr`的指针。

> 测试代码：[array](./array_usage.cpp)

## 向量 (vector)

语法：`std::vector<T> vec;`

`vector`( ***Sequence Container*** )是 ***变长数组***，基本思想是倍增，有时被称为Dynamic Array或Array List。`vector`可以看作集合了“链表+数组”优点的容器。

`std::vector`是一种序列容器，可封装动态大小的数组。元素是连续存储的，这意味着不仅可以通过迭代器访问元素，还可以使用指向元素的常规指针的偏移量访问元素。这意味着指向`vector`元素的指针可以传递给任何期望指向数组元素指针的函数。

`vector`的存储会自动处理，并根据需要进行扩展。`vector`通常比静态数组占用更多空间，因为会分配更多内存来处理未来的增长。这样，每次插入一个元素时，`vector`都不需要重新分配，而只需在额外内存用完时重新分配。使用`capacity()`函数可以查询分配的内存总量。多余的内存可以通过调用`shrink_too_fit()`返回给系统。就性能而言，重新分配通常是代价高昂的操作。如果事先知道元素的数量，可以使用`reserve()`函数来消除重新分配。

`vector`常见操作的开销如下：

- 随机存取：常量 $O(1)$
- 在末尾插入或移除元素：摊销时间为常数(Constant Amortized Time) $O(1)$
- 插入或移除元素：与向量末端的距离成线性关系 $O(n)$

`vector`访问元素的方式：

- `at()`:
- `[]`: 时间复杂度为 $O(1)$
- `front()`:
- `back()`:
- `data()`:

注：系统为某一个程序分配空间时，所需的时间与空间大小基本无关，而与申请次数有关，因此变长数组要尽量减小申请空间的次数(可以浪费空间)。对长度为 $n$ 的`vector`，开辟空间的次数为 $\log n$ ，而额外copy的次数为 $O(1)$。

`vector`的常见操作：

- `front()`, `back()`:
- `push_back()`:
- `pop_back()`:
- `insert()`:
- `emplace()`:
- `emplace_back()`:
- `resize()`:
- `swap()`:
- `erase()`:
- `clear()`: 清空
- `reserve()`: 将`vector`的容量(`vector`在不需要重新分配的情况下可容纳的元素总数)增加到大于或等于新设定的值。如果新设定大于当前的`capacity()`，就会分配新的存储空间，否则函数不会执行任何操作；
- `begin()`, `end()`: 注意`end()`代表最后一个数的下一个数的迭代器

`vector`支持随机寻址，支持比较运算。

区分：

- `size()`: 返回当前元素个数；
- `capacity()`: 返回当前分配的存储空间可容纳的元素个数。

> 测试代码：[vector 1](./vector_basic_usage.cpp); [vector 2](./vector_basic_usage_2.cpp); [vector 3](./vector_and_pair_usage.cpp)

## 对 (pair)

```C++
template<
    class T1,
    class T2
> struct pair;
```

`std::pair`是一个类模板，它提供了一种将两个异构对象存储为一个单元的方法。一个`pair`是包含两个元素的`std::tuple`的一种特殊情况。

`pair`: 定义一个二元组，前后两个变量类型可以不一样；类似于有两个变量且实现了一些函数的结构体。

- `first`: 第一个元素
- `second`: 第二个元素

`pair`支持比较运算，以`first`为第一个关键字，`second`为第二个关键字(字典顺序)。

> 测试代码：[pair](./pair_usage.cpp)

## 字符串 (string)

`string`: 字符串，`substr()`, `c_str()`

- `clear()`: 清空
- `substr()`: 
- `c_str()`: 
- `length()`: 作用同`size()`，都是返回字符串长度

## 链表 (list)

STL链表种类：

- `forward_list`: 单向链表
- `list`: 双向链表

### 单向链表 (forward_list)

`std::forward_list`是一个容器，支持从容器中的任何位置快速插入和移除元素。不支持快速随机存取。它以单链表的形式实现。与`std::list`相比，当不需要双向迭代时，该容器能提供更节省空间的存储空间。

在列表或多个列表中添加、删除和移动元素不会使当前引用列表中其他元素的迭代器失效。但是，当相应的元素从列表中删除(通过`erase_after`)时，指向该元素的迭代器或引用就会失效。

支持操作：`operator =`, `assign`, `front`, `empty`, `max_size`, `clear`, `insert_after`, `emplace_after`, `reverse`, `sort`, `merge`, `splice_after`, `unique`, `remove`, `remove_if`, `resize`等。

> 测试代码：[forward_list](./list_usage.cpp)

### 双向链表 (list)

`std::list`是一种容器，支持从容器中的任何位置定时插入和移除元素。不支持快速随机存取。它通常以双链表的形式实现。与`std::forward_list`相比，该容器提供双向迭代功能，但空间效率较低。

在列表或多个列表中添加、删除和移动元素不会使迭代器或引用失效。只有删除相应元素时，迭代器才会失效。

支持操作：`operator =`, `assign`, `front`, `back`(`forward_list`无此操作), `empty`, `size`(`forward_list`无此操作), `max_size`, `clear`, `insert`, `emplace`, `push_back`(`forward_list`无此操作), `pop_back`(`forward_list`无此操作), `push_front`(`forward_list`无此操作), `pop_front`(`forward_list`无此操作), `reverse`, `sort`, `merge`, `splice`, `unique`, `remove`, `remove_if`, `resize`等。

> 测试代码：[list](./list_usage_2.cpp)

## 队列

### 普通队列 (queue)

```C++
template<
    class T,
    class Container = std::deque<T>
> class queue;
```

`std::queue`类是一个容器适配器(container adaptor)，它为程序员提供了队列的功能，特别是先进先出(FIFO)数据结构。该类模板充当底层容器的封装器，只提供一组特定的函数。`queue`将元素推到底层容器的后面，然后从前面取出。

`queue`允许在`back`进行`push`(insert)，或者在`front`进行`pop`(remove)。

`queue`支持操作: `push()`, `front()`, `back()`, `pop()`, `empty()`, `size()`等。

- `push()`: 向队尾插入一个元素
- `front()`: 返回队头元素
- `back()`: 返回队尾元素
- `pop()`: 弹出队头元素

注：`queue`没有`clear()`函数！

> 测试代码：[quque](./queue_usage.cpp)

### 优先队列 (priority_queue)

```C++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

优先队列(堆)`priority_queue`是一种容器适配器(container adaptor)，它以 ***对数*** 插入和提取为开销，提供 *最大* (默认情况下)元素的 ***常数*** 时间查找。用户可以提供一个`Compare`来改变排序，例如，使用`std::greater<T>`会使 *最小* 的元素显示为`top()`。

使用`priority_queue`类似于在随机存取容器中管理[`heap`](https://en.cppreference.com/w/cpp/algorithm/make_heap)，好处是不会意外地使`heap`失效。

注意`Container`指的是用于存储元素的底层容器类型，标准容器`std::vector`(包括`std::vector<bool>`)和`std::deque`可以满足这些要求。

`priority_queue`使用`std::make_heap`, `std::push_heap`, `std::pop_heap`函数作为底层实现。

`priority_queue`支持操作: `push()`, `top()`, `pop()`等。

注：默认为大根堆，如果想得到小根堆，可以插入原插入数的负数(`h.push(-x)`)，或是直接定义小根堆

注：`priority_queue`也没有`clear()`函数！

- `push()`: 插入一个元素
- `top()`: 返回堆顶元素
- `pop()`: 弹出堆顶元素

> 测试代码：[priority_queue](./priority_queue_usage.cpp)

## 栈 (stack)

```C++
template<
    class T,
    class Container = std::deque<T>
> class stack;
```

`std::stack`类是一个容器适配器(container adaptor)，它为程序员提供了堆栈的功能，特别是后进先出(LIFO)数据结构。该类模板充当底层容器的封装器，只提供一组特定的函数。`stack`从底层容器的后部(即堆栈顶部)推入和弹出元素。默认情况下，如果没有为特定`stack`实例化指定容器(Container)类，就会使用标准容器`std::deque`作为底层容器实现(其他选项可能为`std::vector`或`std::list`)。

`stack`支持操作: `push()`, `top()`, `pop()`, `empty()`, `size()`等。

注：`stack`也没有`clear()`函数！

- `push()`: 向栈顶插入一个元素
- `top()`: 返回栈顶元素
- `pop()`: 弹出栈顶元素

> 测试代码：[stack](./stack_usage.cpp)

## 双端队列 (deque)

```C++
template<
    class T,
    class Allocator = std::allocator<T>
> class deque;
```

`deque`: 双端队列，队头队尾均可插入和删除，支持随机访问或寻址；类似于加强版的`vector`，缺点是速度慢。

`std::deque`(双端队列，double-ended queue)是一种索引序列容器，允许在其开始和结束位置快速插入和删除。此外，在`deque`的任何一端插入和删除都不会使指向其余元素的指针或引用失效。与`std::vector`不同的是，`deque`的元素并 ***不是连续存储的***：典型的实现方法是使用一系列单独分配的固定大小数组，并进行额外的簿记(bookkeeping)，这意味着对`deque`的索引访问必须执行两次指针反引用，而`vector`的索引访问只需执行一次。

`deque`的存储空间会根据需要自动扩展和收缩。`deque`的扩展比`std::vector`的扩展成本 ***低***，因为它不需要将现有元素复制到新的内存位置。但另一方面，`deque`通常具有***较大***的最小内存成本；一个只容纳一个元素的`deque`需要分配其整个内部数组(例如，在64位`libstdc++`上是对象大小的8倍；在64位`libc++`上是对象大小的16倍或4096字节，以较大者为准)。

对`deque`进行常见操作的开销如下：

- 随机存取：常数 $O(1)$
- 在结尾或开头插入或移除元素：常数 $O(1)$
- 插入或删除元素：线性 $O(n)$

常见操作：

- `clear()`: 清空元素
- `front()`: 
- `back()`: 
- `push_back()`: 
- `pop_back()`: 
- `push_front()`: 
- `pop_front()`: 
- `begin()` \ `end()`:

> 测试代码：[deque](./deque_usage.cpp)

## 集合和映射

`set`, `map`, `multiset`, `multimap` 均是 ***Associative Container***，基于平衡二叉树(红黑树)实现，本质是动态维护有序序列

通用操作：

- `clear()`: 
- `begin()` \ `end()`: 支持`++`和`--`操作(时间复杂度为 $O(\log n)$ )，返回*前驱*和*后继*

### 集合 (set, multiset)

```C++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
```

`std::set`是一个关联容器，它包含一个由`Key`类型的唯一对象组成的 ***排序*** 集合。排序是通过键比较函数`Compare`完成的。搜索、移除和插入操作的复杂度为对数。`set`通常以红黑树的形式实现。我们可以在构建`set`对象时传入排序的规则。

```C++
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class multiset;
```

`std::multiset`是一个关联容器，使用红黑树实现，它包含一个由`Key`类型对象组成的 ***排序*** 集合。与`set`不同，它允许 ***多个*** 具有相同值的键。排序使用键比较函数`Compare`完成。搜索、插入和删除操作的复杂度为对数。我们同样可以在构建`multiset`对象时传入排序的规则。

`set` / `multiset`支持：

- `insert()`: 插入一个数，时间复杂度为 $O(\log n)$
- `find()`: 查找一个数
- `count()`: 返回某一个数的个数(`set`里仅有0和1两种情况)
- `erase()`: 若输入是一个数 $x$ ，则删除所有 $x$ ，时间复杂度为 $O(k+\log n)$ ，其中 $k$ 为 $x$ 的个数；若输入是一个迭代器，则删除这个迭代器
- `lower_bound(const Key& x)`(重要): 返回大于等于 $x$ 的最小的数的迭代器，若不存在返回`end`
- `upper_bound(const Key& x)`(重要): 返回大于 $x$ 的最小的数的迭代器，若不存在返回`end`

注：`emplace`和`insert`的区分：

- `insert`函数：
  - 使用方法：`insert`函数用于向容器中添加元素，它可用于`vector`、`list`和`map`等各种容器；
  - 工作原理：使用`insert`时，首先构造元素，然后将其复制或移动到容器中，这意味着元素必须有一个复制或移动构造函数；
  - 效率：与`emplace`相比，`insert`的效率可能较低，因为它涉及复制或移动对象。
- `emplace`函数：
  - 使用方法：在C++11中引入，`emplace`函数(`vector`还有`emplace_back`)通过就地构建的方式向容器中添加新元素；
  - 工作原理：`emplace`直接在容器中构造元素，这是通过将提供的参数传给元素的构造函数来实现的；
  - 效率：`emplace`比`insert`更有效率，尤其是对于复杂对象，因为它省去了额外的复制或移动操作。它可以在容器中需要的位置构造对象。

> 测试代码：[insert和emplace](./insert_emplace_usage.cpp)

### 映射 (map, multimap)

```C++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;
```

`std::map`是一个已 ***排序*** 的关联容器，它包含具有 ***唯一键*** 的键值对。键值通过比较函数`Compare`排序。搜索、移除和插入操作的复杂度为对数。`map`通常以红黑树的形式实现。

```C++
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class multimap;
```

`std::multimap`是一个关联容器，包含键值对的 ***排序*** 列表，同时允许 ***多个*** 条目具有相同的键值。排序是根据应用于键的比较函数`Compare`进行的。搜索、插入和删除操作的复杂度为对数。

注意：`multimap`没有像`map`那样的`at()`或`[]`的索引操作，可考虑使用`equal_range()`！

`map` / `multimap`支持：

- `insert()`: 插入的数是一个`pair`
- `erase()`: 输入的参数是`pair`或迭代器
- `find(const Key& key)`: 查找键值与`key`相同的元素。对于`multimap`而言，如果容器中有多个具有`key`的元素，可以返回其中任何一个；
- `[]`(重要，仅`map`支持，`multimap`不支持): 像数组一样用`map`，时间复杂度为 $O(\log n)$
- `lower_bound(const Key& key)`: 返回指向 ***不小于*** (即大于或等于)`key`的第一个元素的迭代器；
- `upper_bound(const Key& key)`: 返回指向 ***大于*** `key`的第一个元素的迭代器。

> 测试代码：[set和map 1](./set_and_map_usage.cpp); [set和map 2](./set_and_map_usage_2.cpp)

## 哈希表

`unordered_set`, `unordered_map`, `unordered_multiset`, `unordered_multimap`: 哈希表

和上面类似(一一对应)，好处是增删改查的时间复杂度为 $O(1)$ ，但不支持`lower_bound()`和`upper_bound()`，也不支持迭代器的`++`和`--`(凡是和排序有关的操作都不支持)

## 位集 (bitset)

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
