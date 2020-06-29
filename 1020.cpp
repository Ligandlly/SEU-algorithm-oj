#include <iostream>
#include <cstring>
using namespace std;

int dp[502][502];
int arr[2][502];

int f(int start, int end) {
  if (dp[start][end] != -1) {
    return dp[start][end];
  }
  
  if (end - start < 2) {
    return 0;
  }
  
  if (end - start == 2) {
    return (dp[start][end] = arr[0][start] * arr[1][start] * arr[1][start + 1]);
  }
  for (int i = start + 1; i < end; ++i) {
    int cost = f(start, i) + f(i, end) + arr[0][start] * arr[0][i] * arr[1][end - 1];
    if (cost < dp[start][end] || dp[start][end] == -1) {
      dp[start][end] = cost;
    }
  }
  return dp[start][end];
}

int main() {
  int groupNumber = 0;
  scanf("%d", &groupNumber);
  while (groupNumber--) {
    memset(dp, -1, sizeof(dp));
    
    int matrixNumber = 0;
    scanf("%d", &matrixNumber);
    for (int i = 0; i < matrixNumber; ++i) {
      scanf("%d", &arr[0][i]);
      scanf("%d", &arr[1][i]);
    }
    
    cout << f(0, matrixNumber) << endl;
  }
}
