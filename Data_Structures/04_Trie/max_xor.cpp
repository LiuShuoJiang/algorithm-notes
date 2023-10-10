/*
在给定的N个整数A1，A2……AN中选出两个进行xor(异或)运算，得到的结果最大是多少？

这里的异或是二进制按位异或。

输入格式
第一行输入一个整数N。
第二行输入N个整数A1～AN。

输出格式
输出一个整数表示答案。

数据范围
1 ≤ N ≤ 10^5,
0 ≤ Ai < 2^31

输入样例：
3
1 2 3

输出样例：
3
*/

#include <iostream>
#include <algorithm>
using namespace std;

//使用trie的时间复杂度为100000*31，大概为O(n*log(n))

const int N = 100010, M = 31 * N;

int n;
int a[N];
int son[M][2];
int idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;  //取x的第i位的二进制数是什么
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        /*
        对于当前位的二进制数，尽可能往其出现过的相反的方向走
        例如：假设当前位u = 0，若1的那个方向的trie树枝干被创建则向那个方向走；
        若没有被创建，则先将就一下走0的方向
        */
        if (son[p][!u]) {
            p = son[p][!u];
            res = res * 2 + !u;  //将当前位加到左移后空出的第0位上
        }
        else {
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0;

    for (int i = 0; i < n; i++) {
        insert(a[i]);
        int t = query(a[i]);
        res = max(res, a[i] ^ t);
    }
    printf("%d\n", res);
    return 0;
}
