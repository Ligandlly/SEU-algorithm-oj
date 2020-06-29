#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long long F(int arr[], long long **tmp, int start, const int size, int k) {
  if (tmp[start][k] != -1) {
    return tmp[start][k];
  }
  if (size-start - 1< k)
    return 0;
  if (k == 0)
    return tmp[start][k] = accumulate(arr + start, arr + size, 0);
  if (size - start == 1) {
    return tmp[start][k] = arr[start];
  }
  
  long long eventusMaximus = 0;
  long long prefixSum = 0;
  for (int i = start + 1; i < size; ++i) {
    prefixSum += arr[i - 1];
    if (prefixSum * F(arr, tmp, i, size, k-1) > eventusMaximus) {
      eventusMaximus = prefixSum * F(arr, tmp, i, size, k-1);
    }
  }
  return tmp[start][k] = eventusMaximus;
}

int main() {
  // 数据输入
  int lineNumber = 0;  // 数据组数
  cin >> lineNumber;
  cin.ignore(1, '\n');
  for (int _ = 0; _ < lineNumber; ++_) {
    int intNumber = 0;  // 每组整数个数
    int multiNumber = 0;  // 乘号个数
    cin >> intNumber;
    cin >> multiNumber;
    int *arr = new int[intNumber];
    for (int i = 0; i < intNumber; ++i) {
      cin >> arr[i];
    }
    // ----
    //  新建数组tmp[][]
    long long **tmp = new long long*[intNumber];
    for (int i = 0; i < intNumber; ++i) {
      tmp[i] = new long long[multiNumber + 1];
      fill(tmp[i], tmp[i] + multiNumber + 1, -1);
    }
    
    cout << F(arr, tmp, 0, intNumber, multiNumber) << endl;
    //---
    
    for (int i = 0; i < intNumber; ++i) {
      delete [] tmp[i];
    }
    delete []tmp;
    delete []arr;
  }
}
