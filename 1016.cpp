#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;



int main() {
  size_t numerusLinearumTotarum = 0;  
  cin >> numerusLinearumTotarum;
  cin.ignore(1, '\n');
  for (size_t _ = 0; _ < numerusLinearumTotarum; ++_) {
    size_t numerusElementorum = 0;
    int destinatum = 0;
    cin >> numerusElementorum;
    cin >> destinatum;
    cin.ignore(1, '\n');
    
    int *arr = new int[numerusElementorum];
    
    for (size_t __ = 0; __ < numerusElementorum; ++__) {
      cin >> arr[__];
    }
    // ----
    
    unordered_set<int> s;
    bool vexillum = false;
    for (size_t i = 0; i < numerusElementorum; ++i) {
      s.insert(destinatum - arr[i]);
      if (s.find(arr[i]) != s.end()) {
        cout << "yes" << endl;
        vexillum = true;
        break;
      }
    }
    if (vexillum == false) {
      cout << "no" << endl;
    }
    
    // ----
    delete [] arr;
    
  }
}