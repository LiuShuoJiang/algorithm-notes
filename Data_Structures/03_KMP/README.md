# KMP匹配算法

暴力算法怎么做？如何去优化？

朴素算法：

```C++
int s[N], p[M];
for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= m; j++) {
        if (s[i + j - 1] != p[j]) {
            flag = false;
            break;
        }
    }
}
```

朴素算法时间复杂度为 $O(mn)$

`next[i] = j`表示以`i`为终点的后缀和从1开始的前缀相等(`p[1,j]=p[i-j+1, i]`)，且后缀最长。

> 例题：[KMP字符串](./KMP.cpp)

KMP模板：

```C++
//s[]是长文本，p[]是模式串，n是s的长度，m是p的长度

//求模式串的Next数组
for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
}

//匹配
//s串和p串都是从1开始的。i从1开始，j从0开始，每次s[i]和p[j + 1]比较
for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) {
        j = ne[j];
        //匹配成功后的逻辑
    }
}
```

> C++文件：[KMP](./KMP_template.cpp)

完整模板程序：

```C++
#include <iostream>
using namespace std;
const int N = 100010, M = 10010; //N为模式串长度，M匹配串长度

int n, m;
int ne[M]; //next[]数组，避免和头文件next冲突
char s[N], p[M];  //s为模式串， p为匹配串

int main() {
    cin >> n >> s + 1 >> m >> p + 1;  //下标从1开始

    //求next[]数组
    for(int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    //匹配操作
    for(int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) { //满足匹配条件，打印开头下标, 从0开始
            //匹配完成后的具体操作
            //如：输出以0开始的匹配子串的首字母下标
            printf("%d ", i - m); // (若从1开始，加1)
            j = ne[j];            //再次继续匹配
        }
    }
    return 0;
}
```
