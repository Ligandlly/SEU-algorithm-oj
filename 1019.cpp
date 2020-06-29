#include <array>
#include <iostream>
using namespace std;

array<array<int, 101>, 501> dp;  // 动态规划, dp[i][c] = f(n, i, c)
array<array<int, 501>, 2> arr;   // arr[0][i]存储大小, arr[1][i]存储价值

int f(int n, int i, int c) {
  // n表示物品总数
  // i表示从第i个物品开始(包含第i个)
  // c表示容量
  // 返回容量为c时, 从第i个物品开始 的最大价值

  // 最后一个物品
  if (i == n - 1) {
    return dp[i][c] = (arr[0][i] > c ? 0 : arr[1][i]);
  }

  // 已经计算过
  if (dp[i][c] != -1) {
    return dp[i][c];
  }

  // 可以装下第i个物品
  if (arr[0][i] <= c) {
    return dp[i][c] =
               max(f(n, i + 1, c - arr[0][i]) + arr[1][i],  // 装第i个物品
                   f(n, i + 1, c)  // 不装第i个物品
               );

    // 不能装下第i个物品
  } else {
    return dp[i][c] = f(n, i + 1, c);
  }
}

int main() {
  int groupNumber = 0;
  scanf("%d", &groupNumber);
  while (groupNumber--) {
    // dp中未计算过的设为-1
    for (auto &a : dp) {
      fill(a.begin(), a.end(), -1);
    }

    int n, c;  // n是物品数, c是容量
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; ++i) {
      int s, v;  // s是大小, v是价值
      scanf("%d %d", &s, &v);
      // arr[0][i]存储大小, arr[1][i]存储价值
      arr[0][i] = s;
      arr[1][i] = v;
    }
    // 以上是输入
    // -------
    cout << f(n, 0, c) << endl;
  }
}
