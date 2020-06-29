#include <iostream>
using namespace std;

enum {max_node_number = 50002};
int arr[max_node_number];
int merge_sort_tmp_left[max_node_number];
int merge_sort_tmp_right[max_node_number];

int inverse(int start, int end) {
  if (end - start <= 1)  return 0;

  int mid = (end + start) >> 1;
  int l_result =  inverse(start, mid);
  int r_result = inverse(mid, end);

  int result = 0;
  int l_number = mid - start;
  int r_number = end - mid;

  for (size_t i = 0; i < l_number; ++i) {
    merge_sort_tmp_left[i] = arr[start + i];
  }
  for (size_t i = 0; i < r_number; ++i) {
    merge_sort_tmp_right[i] = arr[mid + i];
  }

  int l_ptr = 0;
  int r_ptr = 0;
  int arr_ptr = start;

  while (l_ptr < l_number && r_ptr < r_number) {
    if (merge_sort_tmp_left[l_ptr] <= merge_sort_tmp_right[r_ptr]) {
      arr[arr_ptr] = merge_sort_tmp_left[l_ptr];
      l_ptr++;
    } else {
      result += (l_number - l_ptr);
      arr[arr_ptr] = merge_sort_tmp_right[r_ptr];
      r_ptr++;
    }
    arr_ptr++;
  }

  while (l_ptr < l_number) {
    arr[arr_ptr] = merge_sort_tmp_left[l_ptr];
    arr_ptr++;
    l_ptr++;
  }
  
  while (r_ptr < r_number) {
    arr[arr_ptr] = merge_sort_tmp_right[r_ptr];
    arr_ptr++;
    r_ptr++;
  }

  return result + l_result + r_result;
}

int main() {
  int gruop_number = 0;
  cin >> gruop_number;
  while (gruop_number--) {
    int node_number = 0;
    cin >> node_number;
    for (size_t i = 0; i < node_number; ++i) {
      cin >> arr[i];
    }
    cout << inverse(0, node_number) << endl;

  }
}
