#include <algorithm>
#include <iostream>

#include <tuple>
using namespace std;

tuple<int, int> largestSum(int *arr, int start, int end, int &sum) {
  if (end - start == 1) {
    return make_tuple(start, end);
  } else {
    int mid = (end + start) / 2;
    tuple<int, int> left = largestSum(arr, start, mid, sum);
    tuple<int, int> right = largestSum(arr, mid, end, sum);
    
    int leftSum = 0;
    for (int i = get<0>(left); i < get<1>(left); ++i) {
      leftSum+=arr[i];
    }
    int rightSum = 0;
    for (int i = get<0>(right); i < get<1>(right); ++i) {
      rightSum+=arr[i];
    }
    
    int leftMaxStart = get<0>(left);
    int leftMaxEnd = get<1>(left);
    int rightMaxStart = get<0>(right);
    int rightMaxEnd = get<1>(right);
    
    int leftMaxSum = leftSum;
    int rightMaxSum = rightSum;
    
    // leftMaxStart
    for (int i = get<0>(left) - 1; i >= start; --i) {
      leftSum +=arr[i];
      if (leftSum > leftMaxSum) {
        leftMaxStart = i;
        leftMaxSum = leftSum;
      }
    }
    
    leftSum = leftMaxSum;
    
    // leftMaxEnd
    for (int i = get<1>(left); i < end; ++i) {
      leftSum += arr[i];
      if (leftSum > leftMaxSum) {
        leftMaxEnd = i + 1;
        leftMaxSum = leftSum;
//        if (leftMaxEnd == get<0>(right)) {
//          return make_tuple(get<0>(left), get<1>(right));
//        }  // end if (leftMaxIndex == get<0>(right))
      } // end if (leftSum > leftMaxSum)
    } // end for
    
    // rightMaxStart
    for (int i = get<0>(right) - 1; i >= start; --i) {
      rightSum += arr[i];
      if (rightSum > rightMaxSum) {
        rightMaxSum = rightSum;
        rightMaxStart = i;
      }
    }
    
    rightSum = rightMaxSum;
    
    // rightMaxEnd
    for (int i = get<1>(right); i < end; ++i) {
      rightSum += arr[i];
      if (rightSum > rightMaxSum) {
        rightMaxSum = rightSum;
        rightMaxEnd = i + 1;
      }
    }
    
    if (rightMaxSum > leftMaxSum) {
      sum = rightMaxSum;
      return make_tuple(rightMaxStart,  rightMaxEnd);
    } else {
      sum = leftMaxSum;
      return make_tuple(leftMaxStart, leftMaxEnd);
    }
  }
}



int main() {
  size_t lineTotal;
  cin >> lineTotal;
  cin.ignore(1, '\n');
  for (size_t index = 0; index < lineTotal; index++) {
    int lineNumber = 0;
    cin >> lineNumber;
    int *arr = new int[lineNumber];
    for (size_t j = 0; j < lineNumber; ++j) {
      cin >> arr[j];
    }
    // -------
    
    int sum = 0;
    
    largestSum(arr, 0, lineNumber, sum);


    cout << sum;
    
    cout << endl;

    //-------
    delete []arr;
  }
}
