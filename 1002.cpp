#include <algorithm>
#include <iostream>
#include <cstring>
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
  
    
    make_heap(arr, arr + lineNumber, greater<int>());
    pop_heap(arr, arr + lineNumber, greater<int>());
    cout << arr[0] << endl;
    
    delete []arr;
  }
}
