//
// Created by admin on 2023/12/13.
//

#include "SimAsses.h"

void CreateEigenvector(LHashTable H, int X[], const string& FileAddress) {
  KeyType s;
  int n;
  int i, j = 0;
  LHptr p;

  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  s = new char[10];
  ifstream fin(FileAddress, ios::in);

  while (!fin.eof()) {
    ReadWord(fin, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      // cout<<" "<<p->data.key;
      X[j++] = p->data.Data;
      p = p->next;
      // cout<<" "<<X[j-1];
    }
  }
  cout << "X_(" << FileAddress << "):" << endl;
  for (i = 0; i < 17; i++) {
    cout << X[i] << " ";
  }
  cout << endl;

  fin.close();
}

double SAsses(const int X1[], const int X2[]) {
  int i, m = 0;
  double n1 = 0, n2 = 0;

  for (i = 0; i < 17; i++) {
    m = m + X1[i] * X2[i];
  }
  for (i = 0; i < 17; i++) {
    n1 = n1 + X1[i] * X1[i];
    n2 = n2 + X2[i] * X2[i];
  }

  n1 = sqrt(n1);
  n2 = sqrt(n2);
  return m / (n1 * n2);
}

double DAsses(const int X1[], const int X2[]) {
  int i, m = 0;
  double k;

  for (i = 0; i < 17; i++) {
    m = m + (X1[i] - X2[i]) * (X1[i] - X2[i]);
  }

  k = sqrt(m);
  return k;
}

bool ReadWord(ifstream& fin, char str[]) {
  char c;
  int counter = 0;

  while (fin.get(c)) {
    if (!isalpha(c) && (counter <= 0)) {
      // 跳过非字母字符
      continue;
    } else if (!isalpha(c) && (counter > 0)) {
      // 一个单词读取完毕
      break;
    }
    str[counter++] = c;
  }

  str[counter] = '\0';

  // 成功返回true,否则返回false
  return counter > 0;
}
