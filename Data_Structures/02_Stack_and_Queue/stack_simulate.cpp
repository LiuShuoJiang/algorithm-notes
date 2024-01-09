/*
实现一个栈，栈初始为空，支持四种操作：
1. push x – 向栈顶插入一个数x；
2. pop – 从栈顶弹出一个数；
3. empty – 判断栈是否为空；
4. query – 查询栈顶元素。
现在要对栈进行M个操作，其中的每个操作3和操作4都要输出相应的结果。

输入格式
第一行包含整数M，表示操作次数。
接下来M行，每行包含一个操作命令，操作命令为push x，pop，empty，query中的一种。

输出格式
对于每个empty和query操作都要输出一个查询结果，每个结果占一行。
其中，empty操作的查询结果为YES或NO，query操作的查询结果为一个整数，表示栈顶元素的值。

数据范围
1 ≤ M ≤ 100000,
1 ≤ x ≤ 10^9
所有操作保证合法。

输入样例：
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty

输出样例：
5
5
YES
4
NO
*/

#include <iostream>
using namespace std;

const int N = 100010;

int stk[N];

//tt为栈顶下标
int tt = -1;

/*
//插入
stk[++tt] = x;

//删除
tt--;

//判断栈是否为空
if (tt > 0) {not empty}
else {empty}

//栈顶元素
stk[tt];
*/

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {  //栈顶所在索引往后移动一格，然后放入x
            int a;
            cin >> a;
            stk[++tt] = a;
        } else if (s == "pop") {  //往前移动一格
            tt--;
        } else if (s == "query") {  //返回栈顶元素
            cout << stk[tt] << endl;
        } else if (s == "empty") { //大于等于0 栈非空，小于0 栈空
            cout << (tt == -1 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
