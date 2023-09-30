/*
一共有n个数，编号是1∼n，最开始每个数各自在一个集合中。

现在要进行m个操作，操作共有两种：
1. M a b，将编号为a和b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
2. Q a b，询问编号为a和b的两个数是否在同一个集合中；

输入格式
第一行输入整数n和m。
接下来m行，每行包含一个操作指令，指令为M a b或Q a b中的一种。

输出格式
对于每个询问指令Q a b，都要输出一个结果，
如果a和b在同一集合内，则输出Yes，否则输出No。
每个结果占一行。

数据范围
1 ≤ n, m ≤ 10^5

输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4

输出样例：
Yes
No
Yes
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int p[N];

//返回x的祖宗节点 + 路径压缩
//find函数(并查集的核心!)不仅有找祖宗的功能，还把这个查找路径上所有节点直接变成了祖宗节点的孩子
int find(int x) {
    //祖先节点的父节点是自己本身
    if (p[x] != x) p[x] = find(p[x]);  //将x的父亲置为x父亲的祖先节点,实现路径的压缩
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    //初始化代表元素集合，开始的时候，各自属于一个集合，即每个元素的代表元素是他自己
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);

        if (op[0] == 'M') p[find(a)] = find(b);  //让a的祖宗节点的父亲为b的祖宗节点
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
