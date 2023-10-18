# Huffman树

伪代码为：

```SQL
HUFFMAN(C):
    n = |C|
    Q = priority_queue(C, key=frequency)  -- Initialize priority queue with frequencies
    for i = 1 to n - 1:
        z = new node
        z.left = x = EXTRACT-MIN(Q)
        z.right = y = EXTRACT-MIN(Q)
        z.frequency = x.frequency + y.frequency
        INSERT(Q, z)
    return EXTRACT-MIN(Q)  -- Return the root of the Huffman tree
```

- `C`是要编码的字符集
- `C`中的每个字符`c`都有一个频率`c.frequency`
- `Q`是一个优先队列，它根据节点的频率存储节点
- `z`是一个新的内部节点，具有子节点`x`和`y`
- 该算法构造了一个二叉树，其中叶子是`C`中的字符
- `EXTRACT-MIN(Q)`操作从优先级队列Q中移除并返回具有最小key（在本例中为频率）的元素

时间复杂度为 $O(n\log n)$
