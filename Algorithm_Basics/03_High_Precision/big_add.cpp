/*
给定两个正整数（不含前导 0），计算它们的和。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的和。

数据范围
1≤整数长度≤100000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;

    int t = 0;  //进位
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(1);
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  //a = "123456"
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  //A = [6,5,4,3,2,1]
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}