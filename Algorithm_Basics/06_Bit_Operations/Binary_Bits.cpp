#include <iostream>
using namespace std;

//返回x的最后一位1
//树状数组
//例子：输入二进制(10100)。输出二进制(100)
//注：-x == ~x + 1   其中~x表示取反

int low_bit(int x) {
    return x&(-x);
}

int main() {
    int n = 10;
    for (int k = 3; k >= 0; k--) cout << (n >> k & 1);
    cout << endl;

    unsigned int x = n;
    // 打印n的补码
    for (int i = 31; i >= 0; i--) cout << (x >> i & 1);

    return 0;
}