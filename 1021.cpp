#include <iostream>
using namespace std;

int F(int longitudo, int const *formula, int *tmp, const int longitudoNativa) {
  if (tmp[longitudo] != -1) {
    return tmp[longitudo];
  }
  
  int preciumTotum = formula[longitudo];
  
  int preciumMaxium = -1;
  for (int i = 1; i < longitudo; ++i) {
    int prePrecium = formula[i];
    if (prePrecium + F(longitudo - i, formula, tmp, longitudoNativa) > preciumMaxium) {
      preciumMaxium = prePrecium + F(longitudo - i, formula, tmp, longitudoNativa);
    }
  }
  
  return tmp[longitudo] = max(preciumTotum, preciumMaxium);
}

int main() {
  int numerusLinea = 0;
  cin >> numerusLinea;
  cin.ignore(1);
  for (int _ = 0; _ < numerusLinea; _++) {
    int longitudo = 0;
    cin >> longitudo;
    int numerusFormulaPrecii = 0;
    cin >> numerusFormulaPrecii;
    int *formulaPrecii = new int[longitudo + 1];
    fill(formulaPrecii, formulaPrecii + longitudo + 1, 0);
    
    for (int i = 0; i < numerusFormulaPrecii; ++i) {
      int L = 0;
      int P = 0;
      cin >> L;
      cin >> P;
      if (L <= longitudo) {
        formulaPrecii[L] = P;
      }
    }
    
    int *tmp = new int[longitudo + 1];
    fill(tmp, tmp + longitudo + 1, -1);
    
    cout << F(longitudo, formulaPrecii, tmp, longitudo) << endl;
//    for (int i = 0; i < longitudo + 1; ++i) {
//      cout << tmp[i] << ' ';
//    }
//    cout << endl;
    
    delete []formulaPrecii;
    delete [] tmp;
  }
}
