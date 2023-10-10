#include <iostream>
using namespace std;

int main() {
    int n = 10;
    //打印x的每一位
    for (int k = 3; k >= 0; k--) cout << (n >> k & 1);
    cout << endl;

    unsigned int x = n;
    // 打印n的补码
    for (int i = 31; i >= 0; i--) cout << (x >> i & 1);

    return 0;
}