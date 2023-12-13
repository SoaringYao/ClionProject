#include "stable.h"

void CreateHash(LHashTable &H) {
  KeyType keyword[23];  // typedef char *KeyType 此处为23个指针数组
  LHptr p;
  char ch;
  int n;
  int i, j;
  ifstream fin("../file/keywords.txt", ios::in);

  keyword[0] = new char[30];  // 给指针数组分配空间

  for (i = 1; i < 23; i++) {
    keyword[i] = new char[10];
  }

  fin.get(keyword[0], 26);
  // 将"const char *keywords[] = "存入keyword[0],关键字从1开始存储

  i = 1, j = 0;
  while (!fin.eof()) {  // 关键字输入
    fin.get(ch);

    if (ch >= 97 && ch <= 122) {
      keyword[i][j] = ch;
      j++;

    } else {
      keyword[i][j] = '\0';
      j = 0;
      i++;
    }
  }

  H.size = 43;
  H.count = 0;
  H.elem = new LHptr[H.size];  // 初始化为所有结点指针的头指针
  for (i = 0; i < H.size; i++) {
    H.elem[i] = new LHNode;  // 注意两个new不一样
    H.elem[i]->next = nullptr;
  }
  for (i = 1; i < 18; i++) {
    n = (keyword[i][0] * 100 + FindLast(keyword[i])) %
        41;  // 此处为哈希函数运算
    p = new LHNode;
    p->next = nullptr;
    p->data.Data = 0;  // 计数
    p->data.key = new char[10];
    // p->data.key=keyword[i];
    strcpy(p->data.key, keyword[i]);

    if (!H.elem[n]->next) {
      H.elem[n]->next = p;
    } else {
      p->next = H.elem[n]->next;
      H.elem[n]->next = p;
    }
    // cout<<" "<<p->data.key<<n;
  }
  /* p=H.elem[0]->next;
   while(p){
      cout<<" "<<p->data.key;
      p=p->next;
   }*/
  fin.close();
}

int Hash(KeyType key) {
  int n;
  n = (key[0] * 100 + FindLast(key)) % 41;
  return n;
}

void SearchHash(LHashTable H, int n, KeyType s) {
  LHptr p;
  p = H.elem[n]->next;
  while (p) {
    // if(!s.compare(p->data.key)){
    if (!strcmp(s, p->data.key)) {  // 等于则返回0
      p->data.Data++;
      break;
    }
    p = p->next;
  }
}

void CreateVectorSim(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHptr p;
  // fstream fp1("similar.c");
  //   fp1.ignore(4096,'\n');

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

char FindLast(const char *key) {
  int i = 0;
  char ch;
  while (key[i] != '\0') {
    ch = key[i];
    i++;
  }
  return ch;
}

bool ReadWord(ifstream &fin, char str[]) {
  char c;
  int counter = 0;

  while (fin.get(c)) {
    if (!isalpha(c) && (counter <= 0)) {
      // 消去非字母字符
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

// 在顺序表SST中顺序查找关键字为kval的记录。
// 若找到，则返回记录在表中的位序；否则返回0
//__attribute__((unused)) int SeqSearch(StaticSrhTable SST, KeyType kval) {
//  int i;
//  SST.elem[0].key = kval;  // 放置监视哨
//  for (i = SST.len; SST.elem[i].key != kval; i--)
//    ;        // 查找
//  return i;  // 查找结果
//}
//
//__attribute__((unused)) int BinSearch(StaticSrhTable SST, KeyType kval) {
//  int bot, top, mid;
//  bot = 1, top = SST.len;   // 置查找范围初值
//  while (bot <= top) {      // 等于解决待查值在最后的情况。
//    mid = (bot + top) / 2;  // 整型取半会向下舍！！
//    if (SST.elem[mid].key == kval)
//      return mid;  // 查找成功
//    else {
//      if (SST.elem[mid].key > kval)
//        top = mid - 1;  // 前半区
//      else
//        bot = mid + 1;  // 后半区
//    }
//  }
//  return 0;  // 未查找到
//}

// state BlkInxSearch(StaticSrhTable SST, InxTab Inx, KeyType kval){
// bot = 1, top = Inx.len, blFound = FALSE;    // 置查找范围初值
// if (kval > Inx.elem[top].key) return 0;     // 越界
// while (bot <= top && !blFound) {
//     mid = (bot + top) / 2;
//     if (Inx.elem[mid].key == kval) {         // 查找成功
//          blFound = TRUE; bot = mid;
// }
//     else {
//        if (Inx.elem[mid].key > kval) top = mid - 1; // 前半区
//        else bot = mid + 1;                                    // 后半区
//     }
// }   //退出循环时，bot所指的为所找的块
// bn = Inx.elem[bot].StartAdd;     //第bot块的数据记录起始地址
// if (bot < Inx.len) en = Inx.elem[bot + 1].StartAdd – 1;
// else en = SST.len;                 //第bot块的数据记录尾地址
// for (i = bn; (i <= en) && (SST.elem[i].key != kval); i++);
// if (i <= en) return i;
// return 0;                                          //未查找到
// }
