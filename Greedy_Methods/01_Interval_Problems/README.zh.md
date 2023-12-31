# 区间问题

贪心算法难在证明算法的正确性，且算法基本没有模板和套路。区间何时按左端点排序，何时按右端点排序，取决于不同问题。

## 区间选点问题

> 例题：[区间选点](./choose_points.cpp)

算法步骤：

1. 将每个区间按照**右端点**从小到大排序；
2. 从前往后依次枚举每个区间，`end`值初始化为负无穷；
   1. 如果当前区间中已经包含最后选的那个点(即可以覆盖掉上次区间的右端点)，则直接跳过，进行下一轮循环；
   2. 否则，如果本次区间不能覆盖掉上次区间的右端点(即`ed < range[i].l`)，说明需要选择一个新的点，故选择当前区间的右端点(即`res++; ed = range[i].r;`)。

如何证明算法正确性？

首先，当前选择的方案必然是一组合法的方案(可行解)。假设最优解为`ans`个点，贪心算法求出的为`cnt`个点。只需要证明`ans == cnt`即可。

- 因为`ans`是最优解，所以`ans <= cnt`；
- 贪心算法求出的结果为`cnt`，根据算法步骤，***每次让选取点数加一的区间一定没有交集***，共计`cnt`个这样的区间。为了覆盖这`cnt`个区间，至少需要`cnt`个点，所以`ans >= cnt`。

因此该算法一定能得到最优解。

代码：

```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n;
vector<vector<int>> nums;

int main() {
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }

    int res = 1;
    sort(nums.begin(), nums.end());
    int end = nums[0][1];
    for (int i = 1; i < nums.size(); i++) {
        if (end < nums[i][0]) {
            res++;
            end = nums[i][1];
        } else {
            end = min(end, nums[i][1]);
        }
    }

    cout << res << endl;
    return 0;
}
```

时间复杂度： $O(n\log n)$。

## 最大不相交区间数量问题

> 例题：[最大不相交区间数量](./maximum_disjoint_intervals.cpp)

1. 将区间按**右端点**排序；
2. 从前往后枚举每个区间：
   1. 如果该区间和上一个选的区间有重合，则跳过；
   2. 如果和上一个选的区间没有重合，则选取该区间；
3. 输出所选区间的个数。

证明：

- 假设`ans`是最优解，表示最多有`ans`个不相交的区间；`cnt`是可行解，表示算法求出`cnt`个不相交的区间，显然有`ans >= cnt`；
- 反证法证明`ans <= cnt`：假设`ans > cnt`，由最优解的含义知，最多有`ans`个不相交的区间，因此至少需要`ans`个点才能覆盖所有区间，而根据算法知，只需`cnt`个点就能覆盖全部区间，且`cnt < ans`，这与前边分析至少需要ans个点才能覆盖所有区间相矛盾，故`ans <= cnt`。

综上所述：`ans == cnt`。

## 区间分组问题

> 例题：[区间分组](./interval_grouping.cpp)

贪心算法的解决步骤：

1. 将区间按**左端点**排序；
2. 从前往后依次遍历区间：
   1. 如果当前区间能放到之前的某个集合中，则把该区间放到该集合；
   2. 如果当前不能放到任意一个之前的集合中，则新开一个集合，把当前区间放到新开的集合中；
3. 集合的数量就是答案。

关键步骤是第二步，如何判断当前区间能否放到之前的集合中。解决方法如下:

- 为了快速找出右侧端点最小的那个集合，可以使用小根堆保存*每个集合的右端点*；
- 记录每个集合中保存的区间的最右侧端点，如果当前区间的左端点不和某个集合中保存的区间的最右侧端点相交，则当前区间不和该集合相交，能放到该集合中；
- 也就是说，我们只需判断当前区间的左端点是否和右侧端点最小的那个集合是否相交即可：
  - 如果一个区间的左端点比最小组的右端点要小，即`ranges[i].l <= heap.top()`，就开一个新组，即`heap.push(range[i].r);`
  - 如果一个区间的左端点比最小组的右端点要大，则放在该组，即`heap.pop(), heap.push(range[i].r);`

每组去除右端点最小的区间，只保留一个右端点较大的区间，这样`heap`有多少区间，就有多少组。

可看[视频讲解](https://www.bilibili.com/video/BV1cu4y127Lj)。

## 区间覆盖问题

> 例题：[区间覆盖](./interval_covering.cpp)

思路总览(设最初的区间左端点为`start`，右端点为`end`)：

1. 将所有区间按照**左端点**从小到大进行排序；
2. 从前往后依次枚举每个区间，在所有能覆盖`start`的区间中，选择右端点值最大的一个区间，然后将`start`更新成这个右端点的最大值。

注意，对于当前区间`[a0, b0]`来说，下一个选择区间的左端点`a1`应满足`a1 <= b0`，否则就不能完成“覆盖”；对于当前区间`[a0, b0]`来说，如果有多个区间都满足条件，那么一定选择右端点最大的区间，否则就不能满足“所选区间个数最小”这一目的。

重点：

- 按区间左端点排序；
- 从前往后依次枚举每个区间：判断左端点在`st`之前的区间，循环找到最大右端点，如果右端点也在`st`之前，说明无法覆盖。下一次枚举的时候依旧用这个区间(`i`不变)；
- 如果找到左端点在`st`之前，右端点在`st`之后的区间，`i++`；
- 每循环一次，没有在前面跳出的话，说明找到了一个区间，`res++`；
- 如果这个区间右端点能覆盖`end`，说明能覆盖；
- 把`st`更新成`right`，保证后面的区间适合之前的区间有交集，从而形成对整个序列的覆盖；
- 如果遍历了所有的数组，还是没有覆盖最后的`end`，说明不能成功。

代码：

```C++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

struct Range {
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
} range[N];

int main() {
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; ) {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st) {
            r = max(r, range[j].r);
            j++;
        }
        if (r < st) {
            res = -1;
            break;
        }
        res++;
        if (r >= ed) {
            success = true;
            break;
        }
        st = r;
        i = j;
    }

    if (!success) res = -1;
    printf("%d\n", res);
    return 0;
}
```
