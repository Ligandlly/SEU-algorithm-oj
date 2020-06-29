#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Activity {
    int s;
    int f;
    int v;
    Activity() {
        s = f = v = 0;
    }
};

bool cmp(Activity &a, Activity &b) {
    return a.f < b.f;
}

Activity arr[10001];
int dp[10001];

int main() {
    int group_number = 0;
    scanf("%d", &group_number);
    while (group_number--) {

        int activity_number = 0;
        scanf("%d", &activity_number);
        for (size_t i = 0; i < activity_number; ++i) {
            scanf("%d%d%d", &arr[i].s, &arr[i].f, &arr[i].v);
        }
        sort(arr, arr + activity_number, cmp);

        for (size_t i = 0; i < activity_number; ++i) {
            dp[i] = arr[i].v;
            for (size_t j = 0; j < i; ++j) {
                if (arr[j].f <= arr[i].s) {
                    dp[i] = max(dp[i], dp[j] + arr[i].v);
                } 
            }
        }

        cout << *max_element(dp, dp + activity_number) << endl;
    }
}
