#include <iostream>
#include <string>
using namespace std;

int LCS(string &s1, string &s2, int **tmp, int i, int j) {

  if (i < 0 || j < 0) {
    return 0;
  }
  if (tmp[i][j] != -1) {
    return tmp[i][j];
  }
  if (s1[i] == s2[j]) {
    return tmp[i][j] = 1 + LCS(s1, s2, tmp, i - 1, j - 1);
  } else {
    return tmp[i][j] = max(LCS(s1, s2, tmp, i - 1, j), LCS(s1, s2, tmp, i, j - 1));
  }
}

int main () {
  int groupNumber = 0;
  scanf("%d", &groupNumber);
  cin.ignore(1, '\n');
  for (int _ = 0; _ < groupNumber; ++_) {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    
    int **tmp = new int*[s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; ++i) {
      tmp[i] = new int[s2.size() + 1];
      fill(tmp[i], tmp[i] + s2.size() + 1, -1);
    }
    
    cout << LCS(s1, s2, tmp, (int)s1.size() - 1, (int)s2.size() - 1) << endl;
//    for (int i = 0; i < s1.size(); ++i) {
//      for (int j = 0; j < s2.size(); ++j) {
//        cout << tmp[i][j] << ' ';
//      }
//      cout << endl;
//    }
    
    
    for (int i =0; i < s1.size() + 1; ++i) {
      delete []tmp[i];
    }
    delete []tmp;
  }
}