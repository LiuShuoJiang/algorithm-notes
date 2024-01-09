/*
给定n个正整数ai，对于每个整数ai，请你按照从小到大的顺序输出它的所有约数。

输入格式
第一行包含整数n。
接下来n行，每行包含一个整数ai。

输出格式
输出共n行，其中第i行输出第i个整数ai的所有约数。

数据范围
1 ≤ n ≤ 100,
1 ≤ ai ≤ 2 × 10^9

输入样例：
2
6
8
输出样例：

1 2 3 6 
1 2 4 8 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int n) {
    vector<int> res;

    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) 
                res.push_back(n / i);
        }
    }
    //这里排序的时间复杂度为 O(log(n)*log(log(n)))
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        auto res = get_divisors(x);
        for (auto t : res) cout << t << ' ';
        cout << endl;
    }
    return 0;
}
