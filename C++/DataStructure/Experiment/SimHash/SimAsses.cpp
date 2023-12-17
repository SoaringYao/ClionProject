//
// Created by admin on 2023/12/13.
//

#include "SimAsses.h"

void CreateEigenvector(LHashTable H, int X[], const string& FileAddress) {
  KeyType s;
  int n;
  int i, j = 0;
  LHptr p;

  // 初始化哈希表H
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  // 创建一个字符串数组
  s = new char[10];
  ifstream fin(FileAddress, ios::in);

  // 读取文件
  while (!fin.eof()) {
    ReadWord(fin, s);
    // 计算哈希值
    n = Hash(s);
    // 搜索哈希表
    SearchHash(H, n, s);
  }

  // 用哈希表H.elem给X[j]赋值
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      // cout<<" "<<p->data.key;
      X[j++] = p->data.Data;
      p = p->next;
      // cout<<" "<<X[j-1];
    }
  }

  // 打印X_(FileAddress)
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

  // 计算X1和X2的点积
  for (i = 0; i < 17; i++) {
    m += X1[i] * X2[i];
  }
  // 计算X1和X2的模
  for (i = 0; i < 17; i++) {
    n1 += X1[i] * X1[i];
    n2 += X2[i] * X2[i];
  }
  n1 = sqrt(n1);
  n2 = sqrt(n2);

  // 返回S
  return m / (n1 * n2);
}

double DAsses(const int X1[], const int X2[]) {
  int i, m = 0;
  double k;

  // 计算X1和X2之差的模
  for (i = 0; i < 17; i++) {
    m += (X1[i] - X2[i]) * (X1[i] - X2[i]);
  }
  k = sqrt(m);

  // 返回D
  return k;
}

bool ReadWord(ifstream& fin, char str[]) {
  char c;
  int counter = 0;

  // 读取文件中的每一个字符
  while (fin.get(c)) {
    if (!isalpha(c) && (counter <= 0)) {
      // 跳过非字母字符
      continue;
    } else if (!isalpha(c) && (counter > 0)) {
      // 一个单词读取完毕
      break;
    }
    // 将字符存入str[counter]
    str[counter++] = c;
  }

  str[counter] = '\0';

  // 成功返回true,否则返回false
  return counter > 0;
}