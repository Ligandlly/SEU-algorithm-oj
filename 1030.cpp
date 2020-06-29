#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

enum { max_node_number = 20002 };

// bool nodes[max_node_number];

int main() {
  int group_number = 0;
  scanf("%d", &group_number);
  while (group_number--) {
    stack<int> s;
    int result = 0;
    int pairs_number = 0;
    scanf("%d", &pairs_number);
    bool first_color = 0;
    for (int i = 0; i < (pairs_number << 1); ++i) {
      if (s.empty()) {
        cin >> first_color;
        s.push(i);
      } else {
        bool color = 0;
        cin >> color;
        if (color == first_color) {
          s.push(i);
        } else {
          result += (i - s.top());
          s.pop();
        }
      }
    }
    cin.ignore(1, '\n');
    cout << result << endl;
  }
}
