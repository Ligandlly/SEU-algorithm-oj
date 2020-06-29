#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  size_t lineTotal;
  cin >> lineTotal;
  cin.ignore(1, '\n');
  for (int i = 0; i < lineTotal; i++) {
    int lineNumber = 0;
    cin >> lineNumber;
    int *arr = new int[lineNumber];
    for (int j = 0; j < lineNumber; ++j) {
      cin >> arr[j];
    }
    // -------
    
    make_heap(arr, arr + lineNumber, greater<>());
    
    for (int index = 0; index < lineNumber; ++index) {
      cout << arr[index] << " ";
    }
    cout << endl;
    
    //-------
    delete []arr;
  }
}
