#include <iostream>

#include "function.h"

int main() {
  LinkList a;
  cout << "带头结点的头插法" << endl;
  cout << "a:" << endl;
  a = CreateList();
  LinkList b;
  cout << "b:" << endl;
  b = CreateList();

  LinkList c;
  //  c = Merge(a, b);
  c = MergeLinkList(a, b);  // 非减合成非减
  Reverse(c);               // 转为非增
  cout << "c:" << endl;
  DisplayList(c);

  return 0;
}