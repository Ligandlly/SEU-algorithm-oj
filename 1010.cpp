#include <algorithm>
#include <iostream>
using namespace std;

bool BinSearch(int *R, int n,int  K, int &father)
{
  //在有序表R[0..n-1]中进行二分查找，成功时返回结点的位置，失败时返回-1
  int low=0,high=n-1,mid=0;    //置当前查找区间上、下界的初值
  while(low<=high)
  {
    father = R[mid];
    mid=(high+low)/2;
    if(R[mid]==K)
      return true;             //查找成功返回
    if(R[mid]<K)
      low=mid+1;              //继续在R[mid+1..high]中查找
    else
      high=mid-1;             //继续在R[low..mid-1]中查找
  }
  if(low>high) {
    father = R[mid];
    return false;//当low>high时表示所查找区间内没有结果，查找失败
  }
  return false;
}


int main() {
  size_t lineTotal;
  cin >> lineTotal;
  cin.ignore(1, '\n');
  for (int index = 0; index < lineTotal; ++index) {
    int lineNumber = 0;
    cin >> lineNumber;
    
    int key = 0;
    cin >> key;
    
    int *arr = new int[lineNumber];
    for (int j = 0; j < lineNumber; ++j) {
      cin >> arr[j];
    }
    
    int father = 0;
    bool b = BinSearch(arr,lineNumber, key, father);
    if (b) {
      cout << "success, father is "<< father << endl;
    } else {
      cout << "not found, father is " << father << endl;
    }
    
    
    delete []arr;
  }
}
