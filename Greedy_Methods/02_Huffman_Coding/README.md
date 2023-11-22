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

- `C`是要编码的字符集；
- `C`中的每个字符`c`都有一个频率`c.frequency`；
- `Q`是一个优先队列，它根据节点的频率存储节点；
- `z`是一个新的内部节点，具有子节点`x`和`y`；
- 该算法构造了一个二叉树，其中叶子是`C`中的字符；
- `EXTRACT-MIN(Q)`操作从优先级队列Q中移除并返回具有最小key（在本例中为频率）的元素。

时间复杂度为 $O(n\log n)$。

> 例题：[合并果子](./merge_fruit.cpp)

基本思路：每次合并重量最小的两堆果子。

注意，本题与[石子合并](../../Dynamic_Programming/03_Interval_DP/README.md)问题不一样，本问不要求合并的“果子”相邻。

我们使用小根堆维护所有果子，每次弹出堆顶的两堆果子，并将其合并，合并之后将两堆重量之和再次插入小根堆中。

每次操作会将果子的堆数减一，一共操作 $n-1$ 次即可将所有果子合并成一堆。每次操作涉及到两次堆的删除操作和一次堆的插入操作，计算量是 $O(\log n)$，因此总的时间复杂度为 $O(n\log n)$。

代码模板：

```C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 小根堆
    priority_queue<int, vector<int>, greater<int> > heap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
    }
    
    int res = 0;
    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    
    cout << res << endl;
    return 0;
}
```
