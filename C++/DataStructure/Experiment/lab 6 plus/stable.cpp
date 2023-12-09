#include "stable.h"

__attribute__((unused)) int SeqSearch(StaticSrhTable SST, KeyType kval) {
  /* 在顺序表SST中顺序查找关键字为kval的记录。
     若找到，则返回记录在表中的位序；否则，返回0 */
  int i;
  SST.elem[0].key = kval;  // 放置监视哨
  for (i = SST.len; SST.elem[i].key != kval; i--)
    ;        // 查找
  return i;  // 查找结果
}

__attribute__((unused)) int BinSearch(StaticSrhTable SST,  KeyType kval) {
  int bot, top, mid;
  bot = 1, top = SST.len;   // 置查找范围初值
  while (bot <= top) {      // 等于解决待查值在最后的情况。
    mid = (bot + top) / 2;  // 整型取半会向下舍！！
    if (SST.elem[mid].key == kval)
      return mid;  // 查找成功
    else {
      if (SST.elem[mid].key > kval)
        top = mid - 1;  // 前半区
      else
        bot = mid + 1;  // 后半区
    }
  }
  return 0;  // 未查找到
}

/*state BlkInxSearch(StaticSrhTable SST, InxTab Inx, KeyType kval){
bot = 1, top = Inx.len, blFound = FALSE;    // 置查找范围初值
if (kval > Inx.elem[top].key) return 0;     // 越界
while (bot <= top && !blFound) {
    mid = (bot + top) / 2;
    if (Inx.elem[mid].key == kval) {         // 查找成功
         blFound = TRUE; bot = mid;
}
    else {
       if (Inx.elem[mid].key > kval) top = mid - 1; // 前半区
       else bot = mid + 1;                                    // 后半区
    }
}   //退出循环时，bot所指的为所找的块
bn = Inx.elem[bot].StartAdd;     //第bot块的数据记录起始地址
if (bot < Inx.len) en = Inx.elem[bot + 1].StartAdd – 1;
else en = SST.len;                 //第bot块的数据记录尾地址
for (i = bn; (i <= en) && (SST.elem[i].key != kval); i++);
if (i <= en) return i;
return 0;                                          //未查找到

} */

void CreateHash(LHashTable &H) {
  KeyType keyword[23];  // 此处是指针的指针
  FILE *fp;
  LHNodeptr p;
  char ch;
  int n;
  int i, j;
  fp = fopen("../file/keywords.txt", "r");

  keyword[0] = new char[30];

  for (i = 1; i < 23; i++) {
    keyword[i] = new char[10];
  }

  // fp.ignore(1024,'=');

  fgets(keyword[0], 26, fp);  // 同时第零位置空

  i = 1;
  j = 0;
  while (!feof(fp)) {  // 关键字输入
    ch = char(fgetc(fp));

    if (ch >= 97 && ch <= 122) {
      keyword[i][j] = ch;
      j++;

    } else {
      keyword[i][j] = '\0';
      j = 0;
      i++;
    }
  }

  H.sizeindex = 43;
  H.count = 0;
  H.elem = new LHNodeptr[H.sizeindex];  // 初始化为所有结点指针的头指针
  for (i = 0; i < H.sizeindex; i++) {
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
  fclose(fp);
}

int Hash(KeyType key) {
  int n;
  n = (key[0] * 100 + FindLast(key)) % 41;
  return n;
}

void SearchHash(LHashTable H, int n, KeyType s) {
  LHNodeptr p;
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
  LHNodeptr p;
  // fstream fp1("similar.c");
  //   fp1.ignore(4096,'\n');
  FILE *fp;

  s = new char[10];
  fp = fopen("../file/similar.c", "r");
  while (!feof(fp)) {
    ReadWord(fp, s);
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
  cout << "vector";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fclose(fp);
}

void CreateVectorDif(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHNodeptr p;
  FILE *fp;

  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  s = new char[10];
  // fstream fp1("different.c");
  fp = fopen("../file/different.c", "r");

  //   fp1.ignore(4096,'\n');
  while (!feof(fp)) {
    ReadWord(fp, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      //   cout<<" "<<p->data.key;
      vector[j++] = p->data.Data;
      p = p->next;
      //   cout<<" "<<vector[j-1];
    }
  }
  cout << "vector";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fclose(fp);
}

void CreateVectorMain(LHashTable H, int vector[]) {
  KeyType s;
  int n;
  int i;
  int j = 0;
  LHNodeptr p;
  FILE *fp;

  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      p->data.Data = 0;
      p = p->next;
    }
  }

  s = new char[10];
  fp = fopen("../file/main.c", "r");

  while (!feof(fp)) {
    ReadWord(fp, s);
    n = Hash(s);
    SearchHash(H, n, s);
  }
  for (i = 0; i < 43; i++) {
    p = H.elem[i]->next;
    while (p) {
      //   cout<<" "<<p->data.key;
      vector[j++] = p->data.Data;
      p = p->next;
      //   cout<<" "<<vector[j-1];
    }
  }
  cout << "vector";
  for (i = 0; i < 17; i++) {
    cout << " " << vector[i];
  }
  cout << endl;

  fclose(fp);
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

int ReadWord(FILE *&fp, char str[]) {
  char c;

  int counter = 0;

  while ((c = char(fgetc(fp))) != EOF) {
    if (isChar(c) && (counter <= 0)) {
      // 消去非字母字符
      continue;
    }

    else if (isChar(c) && (counter > 0)) {
      // 一个单词读取完毕
      break;
    }

    str[counter++] = c;
  }

  str[counter] = '\0';

  // 成功返回SUCCESS 否则返回FAIL

  if (counter > 0)
    return 1;

  else
    return 0;
}

int isChar(char c) {
  return !(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
}
// 是字母则返回0，否则返回1
