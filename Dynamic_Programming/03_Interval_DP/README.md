# 区间动态规划

## 石子合并问题

> 例题：[石子合并](./merge_stone.cpp)

石子合并动态规划问题：

- 状态表示： $f(i,j)$
  - 集合：所有将第 $i$ 堆石子到第 $j$ 堆石子合并成一堆石子的合并方式
  - 属性：所有合并方式代价最小值，最终答案为 $f(1,n)$
- 状态计算：以最后一次合并的分界线位置来划分集合，从左边1个到左边 $k-1$ 个

如果区间划分为 $[i,k]$ 和 $[k+1,j]$，则最小代价可以表示为 $f(i,k)+f(k+1,j)+s[j]-s[i-1]$ (也就是左边的最小代价，加右边的最小代价，加最后一步的最小代价)，其中 $s[j]$ 为前缀和，故：

$$
f\left( i,j \right) =\min \left[ f\left( i,k \right) +f\left( k+i,j \right) +s\left[ j \right] -s\left[ i-1 \right] \right] ; k=i,\cdots ,j-1
$$

初值为 $f(i,i)=0$，其余为正无穷。

```C++
const int N = 310;
int n;  //石子堆数
int a[N];  //记录每堆石子的质量
int s[N]; //记录前缀和
int f[N][N];  //f[l][r]表示把从l到r合并成一堆的最小代价

int main() {
    //预处理
    memset(f, 0x3f, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  //每堆石子的质量
        s[i] = s[i - 1] + a[i];  //前缀和
        f[i][i] = 0;  //合并每一堆石子的代价为0
    }

    //状态计算
    for (int len = 2; len <= n; len++) {  //阶段：枚举区间长度
        for (int l = 1; l + len - 1 <= n; l++) {  //状态：枚举区间起点
            int r = l + len - 1;  //区间终点
            for (int k = l; k < r; k++) {  //决策：枚举分割点
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    cout << f[1][n] << endl;
    return 0;
}
```

时间复杂度为 $O(n^3)$
