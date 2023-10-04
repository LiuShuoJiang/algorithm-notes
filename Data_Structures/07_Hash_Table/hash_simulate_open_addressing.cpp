/*
维护一个集合，支持如下几种操作：
1. I x，插入一个数x
2. Q x，询问数x是否在集合中出现过

现在要进行N次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数N，表示操作数量。

接下来N行，每行包含一个操作指令，操作指令为I x，Q x中的一种。

输出格式
对于每个询问指令Q x，输出一个询问结果，
如果x在集合中出现过，则输出Yes，否则输出No。

每个结果占一行。

数据范围
1 ≤ N ≤ 10^5
−10^9 ≤ x ≤ 10^9

输入样例：
5
I 1
I 2
I 3
Q 2
Q 5

输出样例：
Yes
No
*/

#include <iostream>
#include <cstring>

using namespace std;

//开放寻址法一般开数据范围的2~3倍, 这样大概率就没有冲突了
//选择大于数据范围的第一个质数
const int N = 200003;
//规定空指针为 null 0x3f3f3f3f
const int null_num = 0x3f3f3f3f;
/*
我们常常需要用到设置一个常量用来代表“无穷大”。
比如对于int类型的数，有的人会采用INT_MAX，即0x7fffffff作为无穷大。但是以INT_MAX为无穷大常常面临一个问题，即加一个其他的数会溢出。
而这种情况在动态规划，或者其他一些递推的算法中常常出现，很有可能导致算法出问题。
所以我们常采用0x3f3f3f3f来作为无穷大。0x3f3f3f3f主要有如下好处：
0x3f3f3f3f的十进制为1061109567，和INT_MAX一个数量级，即10^9数量级，而一般场合下的数据都是小于10^9的。
0x3f3f3f3f * 2 = 2122219134，无穷大相加依然不会溢出。
可以使用memset(array, 0x3f, sizeof(array))来为数组设初值为0x3f3f3f3f，因为这个数的每个字节都是0x3f。
*/

int h[N];

int find(int x) {
    int k = (x % N + N) % N;

    //如果该位置有人且这个人不是x，则不能进去，要寻找下一个坑位
    while (h[k] != null_num && h[k] != x) {
        k++;
        if (k == N) k = 0;  //循环寻找
    }
    //若x在哈希表中，k为x的下标
    //若x不在哈希表中，k为x应该存储的位置
    return k;
}

int main() {
    //找到大于200000的最小质数
    /*
    for (int i = 200000; ; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;  //200003
            break;
        }
    }
    */

    int n;
    scanf("%d", &n);

    //以字节为单位对内存初始化(注：一个字节有八位，int为四个字节)
    //memset是按字节复制，一个int需要四次才能初始化。
    //当memset的第二个参数大于1个字节长度时，只会取低八位。
    //规定空指针为 0x3f3f3f3f
    memset(h, 0x3f, sizeof h);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x);

        if (*op == 'I') {
            h[k] = x;
        } else {
            if (h[k] != null_num) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
