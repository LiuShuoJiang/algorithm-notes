/*
维护一个集合，初始时集合为空，支持如下几种操作：
1. I x，插入一个数x；
2. PM，输出当前集合中的最小值；
3. DM，删除当前集合中的最小值(数据保证此时的最小值唯一)；
4. D k，删除第k个插入的数(提示：怎么找到第k个插入的数？)；
5. C k x，修改第k个插入的数，将其变为x

现在要进行N次操作，对于所有第2个操作，输出当前集合的最小值。

输入格式
第一行包含整数N。
接下来N行，每行包含一个操作指令，操作指令为I x，PM，DM，D k或C k x中的一种。

输出格式
对于每个输出指令PM，输出一个结果，表示当前集合中的最小值。
每个结果占一行。

数据范围
1 ≤ N ≤ 10^5
−10^9 ≤ x ≤ 10^9
数据保证合法。

输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM

输出样例：
-10
6
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;

//p代表pointer，h代表heap
/*
ph[k] = x表示第k个插入的元素在树中存放的位置x
此时如果要交换 ph 中的两个元素需要知道树中位置x是第几个被插入的, 于是便引入了数组hp
hp[x] = k表示树中位置x存放的为第k个插入的元素
*/
int h[N], ph[N], hp[N], size_h;

//凡是需要交换节点的地方 h, ph, hp 三个数组中的值都要同步交换
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
    while (u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main() {
    int n, idx = 0;
    scanf("%d", &n);
    while (n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        //strcmp()逐字符比较两个字符串，如果字符串相等，函数将返回0
        if (!strcmp(op, "I")) {  //在堆数据结构中，数据的插入都是插入到堆尾，然后再up
            scanf("%d", &x);
            size_h++;
            idx++;  //记录第几次插入(设置新的idx)
            ph[idx] = size_h, hp[size_h] = idx;  //每次插入都是在堆尾插入(设置ph与hp)
            h[size_h] = x;  //记录插入的值
            up(size_h);
        } else if (!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        } else if (!strcmp(op, "DM")) {
            heap_swap(1, size_h);
            size_h--;
            down(1);
        } else if (!strcmp(op, "D")) {
            /*
            删除操作的三个步骤：
            1. 找到第idx个插入元素在堆数组中的位置(堆数组下标)
            2. 与堆尾元素交换
            3. 在原来第idx个元素所在的位置进行down和up操作(up，down，swap操作的都输入都是下标)
            */
            scanf("%d", &k);
            //由于交换完后ph[k]的值变为堆尾的下标了，所以必须要在之前保存ph[k]的值
            k = ph[k];
            heap_swap(k, size_h);  //第k个插入的元素移到了堆尾，此时ph[k]指向堆尾
            size_h--;  //删除堆尾
            down(k), up(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
