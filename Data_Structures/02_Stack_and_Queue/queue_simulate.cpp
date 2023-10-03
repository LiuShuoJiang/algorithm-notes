/*
实现一个队列，队列初始为空，支持四种操作：
1. push x – 向队尾插入一个数x；
2. pop – 从队头弹出一个数；
3. empty – 判断队列是否为空；
4. query – 查询队头元素。

现在要对队列进行M个操作，其中的每个操作3和操作4都要输出相应的结果。

输入格式
第一行包含整数M，表示操作次数。
接下来M行，每行包含一个操作命令，操作命令为push x，pop，empty，query中的一种。

输出格式
对于每个empty和query操作都要输出一个查询结果，每个结果占一行。
其中，empty操作的查询结果为YES或NO，query操作的查询结果为一个整数，表示队头元素的值。

数据范围
1≤M≤100000,
1≤x≤10^9,
所有操作保证合法。

输入样例：
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6

输出样例：
NO
6
YES
4
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int hh, tt = -1, q[N];
int m, x;
string op;

int main() {
    scanf("%d", &m);
    while (m --) {
        cin >> op;
        if (op == "push") {
            scanf("%d", &x);
            q[++tt] = x;
        } else if (op == "pop") {
            hh ++;
        } else if (op == "query") {
            // 打印队头
            printf("%d\n", q[hh]);
        } else {
            // 如果 hh 和 tt 之间没有东西（即 hh > tt）的话，就为空。
            if (hh > tt) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
