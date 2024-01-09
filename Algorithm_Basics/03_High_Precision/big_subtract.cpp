/*
给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的差。

数据范围
1≤整数长度≤10^5
*/

#include <iostream>
#include <vector>

using namespace std;

//判断是否有A>=B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

//C=A-B
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];  //B有数时再减B
        C.push_back((t + 10) % 10); //合二为一：t>=0时为0，t<0时为t+10
        if (t < 0) t = 1;  //借位
        else t = 0;
    }

    //因为答案中C和A的位数相同，因此可能需要去掉前导0
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  //a = "123456"
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  //A = [6,5,4,3,2,1]
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    } else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    
    return 0;
}