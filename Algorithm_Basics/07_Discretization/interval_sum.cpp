/*
假定有一个无限长的数轴，数轴上每个坐标上的数都是0。

现在，我们首先进行n次操作，每次操作将某一位置x上的数加c。

接下来，进行m次询问，每个询问包含两个整数l和r，你需要求出在区间[l,r]之间的所有数的和。

输入格式
第一行包含两个整数n和m。
接下来n行，每行包含两个整数x和c。
再接下来m行，每行包含两个整数l和 r。

输出格式
共m行，每行输出一个询问中所求的区间内数字和。

数据范围
−10^9≤x≤10^9,
1≤n,m≤10^5,
−10^9≤l≤r≤10^9,
−10000≤c≤10000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

// alls[N] 为什么要开 3e5+10？
// 因为最多可以执行 n 次插入操作，m 次询问操作，而每次询问操作中会包含两个坐标。
// 所以说虽然题目中说数轴是无限长，但离散化的数组只需要开 3e5+10 就够了
const int N = 300010;  //n次插入和m次查询相关数据量的上界

int n, m;
int a[N];  //存储坐标插入的值
int s[N];  //存储数组a的前缀和

vector<int> alls;  //存储（所有与插入和查询有关的）坐标
vector<PII> add, query;  //存储插入和询问操作的数据

// 注意映射是从1开始
int find(int x) {  //返回的是输入的坐标的离散化下标
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    //  因为要求前缀和，故下标从1开始方便，不用额外的再处理边界
    // alls[]数组的index还是从0开始，而a[]数组和s[]数组的index从1开始
    return r + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);  //先把下标放入向量中 统一离散化
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        //将其左右端点也映射进来，目的是可以让我们在虚拟的映射表里找到，
        //这对于我们后面的前缀和操作时是十分的方便的。如果当我们在虚拟的
        //映射表里找的时候，如果没有找到左右端点，那么前缀和无法求
        alls.push_back(l);
        alls.push_back(r);
    }

    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item: add) {  //先对添加的元素映射，赋值
        int x = find(item.first);  //找到x的映射值，往原数组中加c
        a[x] += item.second;  // 处理插入
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    //处理询问
    //每个元素都对应一组{first, first}键值对pair
    //键值对中的第一个成员称为first，第二个成员称为second
    for (auto item: query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

// unique()函数的实现方法(数组应该sort过)
/*
vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!i || a[i] != a[i - 1])
            a[j++] = a[i];
        // a[0] ~ a[j - 1] 所有a中不重复的数
    }
    return a.begin() + j;
}
*/
