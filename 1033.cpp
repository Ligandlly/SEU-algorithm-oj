// 1033
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Activity {
  int d;
  int p;
  Activity() { d = p = 0; }
};

inline bool cmp_d(const Activity &a, const Activity &b) { return a.d < b.d; }
inline bool cmp_p(const Activity &a, const Activity &b) { return a.p > b.p; }

enum { max_activities_number = 50002 };
Activity arr[max_activities_number];

int main() {
  //  int test[] = {0, 1, 2, 3, 4, 5};
  //  make_heap(test, test + 6, [](int a, int b){
  //      return a < b;
  //      });
  //  for (int i = 0; i < 6; ++i) {
  //    cout << test[i] << ' ';
  //  }
  //  cout << endl;

  int group_number = 0;
  scanf("%d", &group_number);
  while (group_number--) {
    int activity_number = 0;
    scanf("%d", &activity_number);
    for (size_t i = 0; i < activity_number; ++i) {
      scanf("%d%d", &arr[i].d, &arr[i].p);
    }
    sort(arr, arr + activity_number, cmp_d);
    // input finish
    long long deadline = 0;
    long long selected_activity_number = 0;
    long long result = 0;

    for (size_t i = 0; i < activity_number; ++i) {
      if (deadline < arr[i].d) {
        deadline++;
        result += arr[i].p;

        swap(arr[i], arr[selected_activity_number]);
        selected_activity_number++;
        push_heap(arr, arr + selected_activity_number, cmp_p);
      } else {
        if (arr[i].p > arr[0].p) {
          result -= arr[0].p;
          result += arr[i].p;

          swap(arr[i], arr[selected_activity_number]);
          push_heap(arr, arr + selected_activity_number + 1, cmp_p);
          pop_heap(arr, arr + selected_activity_number + 1, cmp_p);
        }
      }
    }
    cout << result << endl;
  }
}
