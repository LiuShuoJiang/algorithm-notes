/*
给定一个包含n个点(编号为1∼n)的无向图，初始时图中没有边。

现在要进行m个操作，操作共有三种：

C a b，在点a和点b之间连一条边，a和b可能相等；
Q1 a b，询问点a和点b是否在同一个连通块中，a和b可能相等；
Q2 a，询问点a所在连通块中点的数量；

输入格式
第一行输入整数n和m。

接下来m行，每行包含一个操作指令，指令为C a b，Q1 a b或Q2 a中的一种。

输出格式
对于每个询问指令Q1 a b，如果a和b在同一个连通块中，则输出Yes，否则输出No。
对于每个询问指令Q2 a，输出一个整数表示点a所在连通块中点的数量
每个结果占一行。

数据范围
1 ≤ n, m ≤ 10^5

输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

输出样例：
Yes
2
3
*/

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
//通过cnt数组维护每个集合中的点的数量
//注意只有根节点的cnt值才有意义
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--) {
        char op[5];
        int a, b;
        scanf("%s", op);

        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            //注意这里必须要先加连通块大小再操作集合
            //否则操作完集合后，a和b的根结点将会重叠，导致输出错误
            cnt[find(b)] += cnt[find(a)];
            p[find(a)] = find(b);

            /*
            //op[0] == 'C' 这个block的另一种写法
            cin >> a >> b;
            //这里先把a，b的根结点取出来了：a = find(a), b = find(b);
            //因此接下来是先将集合a接到集合b下再把a的连通块大小加到b上，还是先把a的连通块大小加到b上再操作集合都是可以的
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
                cnt[b] += cnt[a];
            }
            */
        } else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }

    return 0;
}