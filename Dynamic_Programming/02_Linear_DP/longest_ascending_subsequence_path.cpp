#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

int n;
int a[N], f[N], g[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        f[i] = 1; //只有a[i]一个数
        g[i] = 0;
        for (int j = 1; j < i ; j++) {
            if (a[j] < a[i]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }
        }
    }

    int k = 1;
    for (int i = 1; i <= n; i++) {
        if (f[k] < f[i])
            k = i;
    }

    printf("%d\n", f[k]);

    //倒着输出序列
    for (int i = 0, len = f[k]; i < len; i++) {
        printf("%d ", a[k]);
        k = g[k];
    }

    return 0;
}