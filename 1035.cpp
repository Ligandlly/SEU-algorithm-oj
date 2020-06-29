#include <iostream>

using namespace std;

enum { max_month_number = 100001 };
long long cost[max_month_number];
long long need[max_month_number];


long long solve(const int month) {
  long long result = 0;
  int lowest_cost_month = 0;
  for (int i = 0; i < month; ++i) {
    if (cost[i] < cost[lowest_cost_month] +i - lowest_cost_month) {
      lowest_cost_month = i;
    } else {
      cost[i] = cost[lowest_cost_month] + i - lowest_cost_month;
    }
    result += cost[i] * need[i];
  }

  return result;
}

int main() {
  int group_number = 0;
  cin >> group_number;
  for (int i = 0; i < group_number; ++i) {
    int month;
    cin >> month;
    for (int i = 0; i < month; ++i) {
      cin >> cost[i];
    }
    for (int i = 0; i < month; ++i) {
      cin >> need[i];
    }

    cout << solve(month) << endl;

  }
}
