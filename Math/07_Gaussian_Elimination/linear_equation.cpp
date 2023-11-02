/*
输入一个包含n个方程n个未知数的线性方程组。
方程组中的系数为实数。
求解这个方程组。

输入格式
第一行包含整数n。
接下来n行，每行包含n+1个实数，表示一个方程的n个系数以及等号右侧的常数。

输出格式
如果给定线性方程组存在唯一解，则输出共n行，
其中第i行输出第i个未知数的解，结果保留两位小数。

注意：本题有SPJ，当输出结果为0.00时，输出-0.00也会判对。
在数学中，一般没有正零或负零的概念，所以严格来说应当输出 0.00，
但是考虑到本题作为一道模板题，考察点并不在于此，
在此处卡住大多代码没有太大意义，故增加SPJ，
对输出-0.00的代码也予以判对。

如果给定线性方程组存在无数解，则输出Infinite group solutions。
如果给定线性方程组无解，则输出No solution。

数据范围
1 ≤ n ≤ 100,
所有输入系数以及常数均保留两位小数，绝对值均不超过100。

输入样例：
3
1.00 2.00 -1.00 -6.00
2.00 1.00 -3.00 -9.00
-1.00 -1.00 2.00 7.00

输出样例：
1.00
-2.00
3.00
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {
    int c, r;  // c代表列，r代表行 
    for (c = 0, r = 0; c < n; c++) {
        // 先找到当前这一列绝对值最大的一个数字所在的行号
        int t = r;
        for (int i = r; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }
        // 如果当前这一列的最大数都是0，那么所有数都是0，
        //就没必要去算了，因为它的约束方程可能在上面几行
        if (fabs(a[t][c]) < eps) continue;

        //把当前这一行换到最上面（不是到第一行，是第r行）
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);

        //把当前这一行的第一个数变成1
        //方程两边同时除以第一个数，
        //必须要倒着算，不然第一个数直接变1，系数就被篡改，后面的数字没法算
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

        //把当前列下面的所有数，全部消成0
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > eps) {  //如果非0再操作，已经是0就没必要操作了
                //从后往前，当前行的每个数字，都减去对应列乘以行首非0的数字，
                //这样就能保证第一个数字是a[i][0] -= 1*a[i][0];
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
            }
        }

        r++;  //这一行的工作做完，换下一行
    }

    //说明剩下有效方程的个数是小于n的
    //说明不是唯一解，判断是无解还是无穷多解
    if (r < n) {
        for (int i = r; i < n; i++) {
            //a[i][n]代表bi，即左边=0，右边=bi，0 != bi, 所以无解
            if (fabs(a[i][n]) > eps)
                return 2;  //无解
        }
        //否则，0 = 0，就是r~n-1的方程都是多余方程
        return 1;  //无穷解
    }

    //对于唯一解，从下往上回代，得到方程的解
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++)
            //因为只要得到解，所以只用对bi进行操作，
            //中间的值可以不用操作，因为不用输出
            a[i][n] -= a[i][j] * a[j][n];
    }

    return 0;  //有唯一解
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    }

    int t = gauss();
    if (t == 0) {
        for (int i = 0; i < n; i++)
            //老版本编译器中：double类型scanf用%lf格式符，printf用%f格式符。
            //printf中没有%lf格式控制符。
            //在printf中，无论是float类型还是double类型，都需要用%f
            //新版本兼容了这种lf的格式符的写法
            printf("%.2lf\n", a[i][n]);  //保留两位小数
    } else if (t == 1) {
        puts("Infinite group solutions");
    } else {
        puts("No solution");
    }

    return 0;
}
