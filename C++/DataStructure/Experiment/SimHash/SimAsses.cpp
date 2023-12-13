//
// Created by admin on 2023/12/13.
//

#include "SimAsses.h"

void CreateVectorSim(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHptr p;

  s = new char[10];
  ifstream fin("../file/similar.c", ios::in);
  while (!fin.eof()) {
    ReadWord(fin, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      //                        cout<<" "<<p->data.key;
      vector[j++] = p->data.Data;
      p = p->next;
    }
  }
  cout << "VectorSim ";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fin.close();
}

void CreateVectorDif(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHptr p;

  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  s = new char[10];
  ifstream fin("../file/different.c", ios::in);

  while (!fin.eof()) {
    ReadWord(fin, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      // cout<<" "<<p->data.key;
      vector[j++] = p->data.Data;
      p = p->next;
      // cout<<" "<<vector[j-1];
    }
  }
  cout << "VectorDif ";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fin.close();
}

void CreateVectorMain(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHptr p;

  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  s = new char[10];
  ifstream fin("../file/main.c", ios::in);

  while (!fin.eof()) {
    ReadWord(fin, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      // cout<<" "<<p->data.key;
      vector[j++] = p->data.Data;
      p = p->next;
      // cout<<" "<<vector[j-1];
    }
  }
  cout << "VectorMain";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fin.close();
}

double X1(const int vector1[], const int vector2[]) {
  int i;
  int m;
  double n1, n2;
  n1 = n2 = 0;
  m = 0;
  for (i = 0; i < 17; i++) {
    m = m + vector1[i] * vector2[i];
  }
  for (i = 0; i < 17; i++) {
    n1 = n1 + vector1[i] * vector1[i];
    n2 = n2 + vector2[i] * vector2[i];
  }
  n1 = sqrt(n1);
  n2 = sqrt(n2);
  return m / (n1 * n2);
}

double X2(const int vector1[], const int vector2[]) {
  int i;
  int m = 0;
  double k;
  for (i = 0; i < 17; i++) {
    m = m + (vector1[i] - vector2[i]) * (vector1[i] - vector2[i]);
  }

  k = sqrt(m);
  return k;
}

bool ReadWord(ifstream &fin, char str[]) {
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
