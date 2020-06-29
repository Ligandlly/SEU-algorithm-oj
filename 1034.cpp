#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define BLACK 0
#define WHITE 1

int dp[50002][2];
bool vis[50002];
vector<int> nodeArr[50002];

void F(int n) {
  vis[n] = true;
  for (int item: nodeArr[n]) {
    if (vis[item] == false) {
      F(item);
      dp[n][BLACK] += dp[item][WHITE];
      dp[n][WHITE] += max(dp[item][BLACK], dp[item][WHITE]);
    }
  }
}

void input() {
  int nodeNumber = 0;
  scanf("%d", &nodeNumber);
  for (int i = 0; i < nodeNumber - 1; ++i) {
    int super, sub;
    scanf("%d%d", &super, &sub);
    nodeArr[super].push_back(sub);
    nodeArr[sub].push_back(super);
  }
}

int main() {
  int groupNumber = 0;
  scanf("%d", &groupNumber);
  while (groupNumber--) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 50002; ++i) {
      dp[i][BLACK] = 1;
    }
    memset(vis, 0, sizeof(vis));
    input();
    F(1);
    cout << max(dp[1][BLACK], dp[1][WHITE]) << endl;
    for (int i = 0; i < 50001; ++i) {
      nodeArr[i].clear();
    }
  }
}
