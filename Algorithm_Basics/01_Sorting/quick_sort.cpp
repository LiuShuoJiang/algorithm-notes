#include <iostream>
using namespace std;

const int N = 1e6+10;

int n;
int q[N];

void quick_sort_v1(int q[], int l, int r) {
    if (l >= r) return;  //边界条件

    //此处不能写int x = q[r]; 否则有可能死循环(无限递归)
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);  //交换两个数
    }
    
    quick_sort_v1(q, l, j);
    quick_sort_v1(q, j + 1, r);
}

void quick_sort_v2(int q[], int l, int r) {
    if (l >= r) return;

    //此处不能写int x = q[l]; 否则有可能死循环，如q=[1,2]
    int x = q[(l + r + 1) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort_v2(q, l, i - 1);
    quick_sort_v2(q, i, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort_v2(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}