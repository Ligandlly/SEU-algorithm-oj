#include <algorithm>
#include <iostream>
using namespace std;

int partition(int *arr, int start, int end) {
  int povix = arr[start];
  int top = start + 1;
  for (int i = start + 1; i < end; ++i) {
    if (arr[i] < povix) {
      swap(arr[i], arr[top++]);
    }
  }
  swap(arr[start], arr[top - 1]);
//  for (int i = 0; i < 11; ++i) {
//    cout << arr[i] << ' ' << flush;
//  }
//  cout << endl;
  return top - 1;
}

void quickSort(int *arr, int start, int end, int stack) {
  if (end - start < 1) {
    return;
  } else {
    
    if (stack == 3){
      return;
    }

    int povix = partition(arr, start, end);
    
//    cout << stack;
//    cout << endl;
    quickSort(arr, start, povix, stack + 1);
    quickSort(arr, povix + 1, end, stack + 1);



  }
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

    quickSort(arr, 0, lineNumber, 1);
    
    for (int i = 0; i < lineNumber; ++i) {
      cout << arr[i] << ' ';
    }
    cout << endl;

    //-------
    delete []arr;
  }
}
