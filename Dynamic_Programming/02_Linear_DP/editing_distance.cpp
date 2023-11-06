/*
给定n个长度不超过10的字符串以及m次询问，每次询问给出一个字符串和一个操作次数上限。
对于每次询问，请求出给定的n个字符串中有多少个字符串可以在上限操作次数内经过操作变成询问给出的字符串。
每个对字符串进行的单个字符的插入、删除或替换算作一次操作。

输入格式
第一行包含两个整数n和m。
接下来n行，每行包含一个字符串，表示给定的字符串。
再接下来m行，每行包含一个字符串和一个整数，表示一次询问。
字符串中只包含小写字母，且长度均不超过10。

输出格式
输出共m行，每行输出一个整数作为结果，表示一次询问中满足条件的字符串个数。

数据范围
1 ≤ n, m ≤ 1000

输入样例：
3 2
abc
acd
bcd
ab 1
acbd 2

输出样例：
1
3
*/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 15, M = 1010;

int n, m;
int f[N][N];
char str[M][N];

int edit_distance(char a[], char b[]) {
    int la = strlen(a + 1), lb = strlen(b + 1);

    for (int i = 0; i <= lb; i++) f[0][i] = i;
    for (int i = 0; i <= la; i++) f[i][0] = i;

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return f[la][lb];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", str[i] + 1);

    while (m--) {
        char s[N];
        int limit;
        scanf("%s%d", s + 1, &limit);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (edit_distance(str[i], s) <= limit)
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
