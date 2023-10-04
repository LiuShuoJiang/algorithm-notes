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

const int N = 100003;

//开一个槽h
int h[N], e[N], ne[N], idx;

void insert(int x) {
    //加N是保证余数为正数
    //例如原本C++中：-10%3为-1
    //(x+N)%N是不行的。因为x+N还有可能是负数
    int k = (x % N + N) % N;

    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main() {
    //寻找大于100000的第一个质数
    /*
    for (int i = 100000; ; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;  //100003
            break;
        }
    }
    */

    int n;
    scanf("%d", &n);

    //空指针一般用-1表示
    //将槽先清空
    memset(h, -1, sizeof h);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}