/*
维护一个集合，初始时集合为空，支持如下几种操作：
1. I x，插入一个数x；
2. PM，输出当前集合中的最小值；
3. DM，删除当前集合中的最小值(数据保证此时的最小值唯一)；
4. D k，删除第k个插入的数(提示：怎么找到第k个插入的数？)；
5. C k x，修改第k个插入的数，将其变为x；

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

int h[N], ph[N], hp[N], size_h;

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
    int n, m = 0;
    scanf("%d", &n);
    while (n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            size_h++;
            m++;
            ph[m] = size_h, hp[size_h] = m;
            h[size_h] = x;
            up(size_h);
        } else if (!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        } else if (!strcmp(op, "DM")) {
            heap_swap(1, size_h);
            size_h--;
            down(1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, size_h);
            size_h--;
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
