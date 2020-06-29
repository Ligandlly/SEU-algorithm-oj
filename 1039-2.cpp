// 1039
#include <iostream>
#include <list>
#include <queue>
using namespace std;

enum {max_node_number = 300};
struct Node {
  list<Node *> adjancent;
  int in_degree;
  Node() {
    in_degree = 0;
  }
};
Node arr[max_node_number];

int main() {
  int gruop_number = 0;
  cin >> gruop_number;
  for (int _ = 0; _ < gruop_number; ++_) {
    int m, n;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
      arr[i].adjancent.clear();
      arr[i].in_degree = 0;
    }

    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      arr[u].adjancent.push_back(arr + v);
      arr[v].in_degree++;
    }

    queue<Node *> q;

    for (int i = 1; i <= n; ++i) {
      if (arr[i].in_degree == 0) {
        q.push(arr + i);
      }
    }

    list<int> result;

    while (!q.empty()) {
      for (auto item : q.front()->adjancent) {
        item->in_degree--;
        if (item->in_degree == 0)
          q.push(item);
      }

      result.push_back(q.front() - arr);
      q.pop();
    }
    
    if (result.size() == n) {
      for (int item : result) {
        cout << item << ' ';
      }
      cout << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
