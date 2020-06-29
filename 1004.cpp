#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//void mergeSort(int *arr, const int start, const int end, int len) {
//  if (start == end) {
//    return;
//  } else {
//    int *tmp = new int[end - start + 1];
//    int mid = (start + end) >> 1;
//    mergeSort(arr, start, mid, len);
//    mergeSort(arr, mid + 1, end, len);
//
//    if (end - start + 1 == len / 2 || end - start + 1 == len / 2 + 1) {
//      return;
//    }
//
//    int left = start;
//    int right = mid + 1;
//    for (int i = 0; i < end - start + 1; ++i) {
//      if (left == mid + 1) {
//        tmp[i] = arr[right++];
//      } else if (right == end + 1) {
//        tmp[i] = arr[left++];
//      } else if (arr[left] < arr[right] && left <= mid) {
//        tmp[i] = arr[left++];
//      } else if (arr[right] < arr[left] && right <= end){
//        tmp[i] = arr[right++];
//      }
//    }
//    for (int i = 0; i < end - start + 1; ++i) {
//      arr[start + i] = tmp[i];
//    }
//
//    delete [] tmp;
//  }
//}

void fuckSort(int *arr, int n) {
  int mid = (n-1) / 2;
  int ml = mid / 2;
  int mr = (n + mid) / 2;
  
  sort(arr, arr + ml + 1, less<int>());
  sort(arr + ml + 1, arr + mid + 1, less<int>());
  sort(arr + mid + 1, arr + mr + 1, less<int>());
  sort(arr + mr + 1, arr + n, less<int>());
}

int main() {
  size_t lineTotal;
  cin >> lineTotal;
  cin.ignore(1, '\n');
  for (int index = 0; index < lineTotal; index++) {
    int lineNumber = 0;
    cin >> lineNumber;
    int *arr = new int[lineNumber];
    for (int j = 0; j < lineNumber; ++j) {
      cin >> arr[j];
    }
    // -------
    
    fuckSort(arr, lineNumber);
    for (int i = 0; i < lineNumber; ++i ) {
      cout << arr[i] << ' ' ;
    }
    cout << endl;
    
    //-------
    delete []arr;
  }
}
