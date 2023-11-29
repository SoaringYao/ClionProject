#include "huffman.h"

// 根据权值创建哈夫曼树
void HuffmanTree(HuffTree &HT, const WeightType *w, int n) {
  int m;  // 哈夫曼树总结点数
  int s1, s2;
  m = n * 2 - 1;
  HT = new HTNode[m + 1];
  for (int i = 1; i <= m; i++) {
    HT[i].weight = (i <= n) ? w[i - 1] : 0;
    HT[i].lchild = HT[i].rchild = HT[i].parent = 0;
  }
  for (int i = n + 1; i <= m; i++) {
    Select(HT, i, s1, s2);
    HT[i].lchild = s1;
    HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;
    HT[s1].parent = i;
    HT[s2].parent = i;
  }
}

// 从哈夫曼树HT上求n个叶子结点的哈夫曼编码并存入HC
void HuffmanCoding(HuffTree HT, HuffCode &HC, int n) {
  SqStack S;  // 顺序栈, 用于记录遍历路径
  InitStack_sq(S);
  HC = new char *[n + 1];
  Coding(HT, 2 * n - 1, HC, S);
}

void printHT(HuffTree HT, int n) {
  int i, m;
  m = 2 * n - 1;
  cout << "Huffman Tree:" << endl;
  for (i = 1; i <= m; i++) {
    cout << std::left << setw(2) << i << ": " << std::left << setw(2)
         << HT[i].weight << " " << std::left << setw(2) << HT[i].parent << " "
         << std::left << setw(2) << HT[i].lchild << " " << std::left << setw(2)
         << HT[i].rchild << endl;
  }
  cout << endl;
}

// 打印编码二维数组
void printHC(char **HC, int n, word *phead) {
  word *p = phead->next;
  cout << "Huffman Code:" << endl;
  for (int i = 1; i < n + 1; i++) {
    cout << p->ch << ": ";
    for (int j = 0; HC[i][j] != 0; j++) {
      cout << HC[i][j];
    }
    p = p->next;
    cout << endl;
  }
}

//
void DestroyHC(char **HC, int n) {
  for (int i = 1; i < n + 1; i++) {
    free(HC[i]);
  }
}

// 辅助函数实现

// 将权值存入数组
void load(word *phead, int *a) {
  int i = 0;
  word *p = phead->next;
  while (p) {
    a[i] = p->num;
    i++;
    p = p->next;
  }
}

int getlength(const int *a) {
  int i = 0, count = 0;
  while (a[i] != 0) {
    count++;
    i++;
  }
  return count;
}

void Select(HuffTree &HT, int i, int &s1, int &s2) {
  int temp;
  s1 = Min(HT, i);
  s2 = Min(HT, i);
  if (HT[s1].weight > HT[s2].weight) {
    temp = s1;
    s1 = s2;
    s2 = temp;
  }
}

int Min(HuffTree HT, int n) {
  int i, flag;
  int f = MAX_WEIGHT;
  for (i = 1; i < n; i++) {
    if (HT[i].weight < f && HT[i].parent == 0) {
      f = HT[i].weight, flag = i;
    }
  }
  HT[flag].parent = 1;
  return flag;
}

void Coding(HuffTree HT, int root, HuffCode &HC, SqStack &S) {
  // root是哈夫曼树组HT的根节点位置下标
  ElemType ch;
  if (root != 0) {
    if (HT[root].lchild == 0) {
      Push_sq(S, '\0');
      HC[root] = new char[S.stacksize + 1];
      strcpy(HC[root], S.elem);
      Pop_sq(S, ch);
    }
    Push_sq(S, '0');
    Coding(HT, HT[root].lchild, HC, S);
    Pop_sq(S, ch);
    Push_sq(S, '1');
    Coding(HT, HT[root].rchild, HC, S);
    Pop_sq(S, ch);
  }
}
