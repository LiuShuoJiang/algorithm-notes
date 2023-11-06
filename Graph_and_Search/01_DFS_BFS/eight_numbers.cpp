/*
在一个3×3的网格中，1∼8这8个数字和一个x恰好不重不漏地分布在这3×3的网格中。
例如：
1 2 3
x 4 6
7 5 8
在游戏过程中，可以把x与其上、下、左、右四个方向之一的数字交换（如果存在）。
我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：
1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让x先后与右、下、右三个方向的数字交换成功得到正确排列。
交换过程如下：
1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

输入格式
输入占一行，将3×3的初始网格描绘出来。
例如，如果初始网格如下所示：
1 2 3 
x 4 6 
7 5 8 
则输入为：1 2 3 x 4 6 7 5 8

输出格式
输出占一行，包含一个整数，表示最少交换次数。
如果不存在解决方案，则输出 −1。

输入样例：
2 3 4 1 5 x 7 6 8

输出样例
19
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string start) {
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size()) {
        auto t = q.front();
        q.pop();

        int distance = d[t];

        if (t == end) return distance;

        //状态转移

        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);

                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }

                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main() {
    string start;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}
