/*
给定两个长度分别为N和M的字符串A和B，
求既是A的子序列又是B的子序列的字符串长度最长是多少。

输入格式
第一行包含两个整数N和M。
第二行包含一个长度为N的字符串，表示字符串A。
第三行包含一个长度为M的字符串，表示字符串B。
字符串均由小写字母构成。

输出格式
输出一个整数，表示最大长度。

数据范围
1 ≤ N, M ≤ 1000

输入样例：
4 5
acbd
abedc

输出样例：
3
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) 
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    printf("%d\n", f[n][m]);

    return 0;
}
