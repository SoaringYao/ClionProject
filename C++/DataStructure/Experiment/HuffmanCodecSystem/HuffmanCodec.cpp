//
// Created by admin on 2023/11/19.
//
#include "HuffmanCodec.h"

HTNode *InitHTNode(int n) {
  HTNode *ht;
  int m = 2 * n - 1;
  ht = new HTNode[m + 1];
  return ht;
}

void Select(HuffmanTree &HT, int i, int &s1, int &s2) {
  int temp;
  s1 = Min(HT, i);
  s2 = Min(HT, i);
  if (HT.node[s1].weight > HT.node[s2].weight) {
    temp = s1;
    s1 = s2;
    s2 = temp;
  }
}

int Min(HuffmanTree HT, int n) {
  int i, flag;
  int f = MAX_WEIGHT;
  for (i = 0; i < n; i++) {
    if (HT.node[i].weight < f && HT.node[i].parent == -1) {
      f = HT.node[i].weight, flag = i;
    }
  }
  HT.node[flag].parent = 0;
  return flag;
}

bool CreateHuffmanTree(HuffmanTree &HT, int n, const int *w) {
  int m = 2 * n - 1, i;
  for (i = 0; i < m; i++) {
    HT.node[i].weight = (i < n) ? w[i] : 0;
    HT.node[i].parent = -1;
    HT.node[i].lchild = -1;
    HT.node[i].rchild = -1;
  }
  int s1 = 0, s2 = 0;
  for (i = n; i < m; i++) {
    Select(HT, i, s1, s2);
    HT.node[i].weight = HT.node[s1].weight + HT.node[s2].weight;
    HT.node[i].lchild = s1;
    HT.node[i].rchild = s2;
    HT.node[s1].parent = i;
    HT.node[s2].parent = i;
  }
  for (i = HT.nodeNum - 1; i >= 0; i--) {
    if (HT.node[i].parent == -1) {
      HT.root = i;
    }
  }
  return OK;
}

bool CountTreeByToBeTran(Number &num, HuffmanTree &HT) {
  // 统计文件中每种字母的个数与种类，个数作为其权值保存，种类作为结点数
  string str;
  ifstream infile;
  infile.open("../ToBeTran.txt");
  getline(infile, str);
  int i, j;
  num.length = 0;
  for (i = 0; i < str.length(); i++) {
    int count = 0;
    num.data[i].num = 0;
    for (j = 0; j < num.length; j++) {
      if (str[i] != num.data[j].ch)
        count++;
      else
        num.data[j].num++;
    }
    // 最开始先做一次++,放入第一个元素
    // count一旦与length相同,length++,直到再次有相同元素使count++
    if (count == num.length) {
      num.data[num.length].ch = str[i];
      num.data[j].num++;
      num.length++;
    }
  }
  HT.leafNum = num.length;
  HT.nodeNum = HT.leafNum * 2 - 1;
  HT.node = InitHTNode(HT.leafNum);
  infile.close();
  return OK;
}

bool CountTreeByInput(Number &num, HuffmanTree &HT) {
  int n;
  ifstream fin("../hfmTree.txt", ios::in);
  // 无论是cin还是fin,in指的是进入缓冲区,即从键盘进缓冲区和从硬盘进缓冲区
  // 故此处为读操作
  if (fin.fail())  // 若不存在此文件，则从终端读入
  {
    cout << "请输入字符个数n：";
    cin >> n;
    cout << "请输入字符及相应权值：" << endl;
    for (int i = 0; i < n; i++) {
      getchar();  // 取消换行符
      num.data[i].ch = char(getchar());
      cin >> num.data[i].num;
    }
    num.length = n;
    HT.leafNum = num.length;
    HT.nodeNum = HT.leafNum * 2 - 1;
    HT.node = InitHTNode(HT.leafNum);
  } else {
    CountTreeByHuffTree(num, HT);
  }
  fin.close();
  return OK;
}

bool CountTreeByHuffTree(Number &num, HuffmanTree &HT) {
  char c;
  int n;
  ifstream fin("../hfmTree.txt", ios::in);
  if (!fin.fail()) {
    // 如果文件存在
    fin >> n;
    num.length = n;
    HT.leafNum = num.length;
    HT.nodeNum = HT.leafNum * 2 - 1;
    HT.node = InitHTNode(HT.leafNum);
    fin.get(c);
    for (int i = 0; i < 2 * n - 1; i++) {
      fin.get(num.data[i].ch);
      fin.get(c);
      fin >> HT.node[i].weight;
      fin.get(c);
      fin >> HT.node[i].parent;
      fin.get(c);
      fin >> HT.node[i].lchild;
      fin.get(c);
      fin >> HT.node[i].rchild;
      fin.get(c);
      num.data[i].num = HT.node[i].weight;
    }
  } else {
    cerr << "Can't Find hfmTree.txt" << endl;
    return false;
  }
  // 未经过CreateTree,故需要认为确定root位置
  for (int i = HT.nodeNum - 1; i >= 0; i--) {
    if (HT.node[i].parent == -1) {
      HT.root = i;
    }
  }
  fin.close();
  return OK;
}

bool outPut_CodeFile(Sqlist &CD) {
  // 将字符转化为各自的编码
  string str, results;
  ifstream infile;
  ofstream outfile;
  infile.open("../ToBeTran.txt");
  getline(infile, str);
  infile.close();
  outfile.open("../CodeFile.txt");
  for (char i : str) {
    for (int j = 0; j < CD.length; j++) {
      if (i == CD.chars[j].data) results += CD.chars[j].code;
    }
  }
  // 实现压缩
  // CodeHuffman();
  outfile << results;
  outfile.close();
  return OK;
}

void Coding(HuffmanTree &HT, int root, Sqlist &CD, Number &num, SqStack &S) {
  // root是哈夫曼树组HT的根节点位置下标
  char ch;
  if (root != -1) {
    if (HT.node[root].lchild == -1) {
      Push_sq(S, '\0');
      CD.chars[root].code = S.elem;
      CD.chars[root].data = num.data[root].ch;
      Pop_sq(S, ch);
    }
    Push_sq(S, '0');
    Coding(HT, HT.node[root].lchild, CD, num, S);
    Pop_sq(S, ch);
    Push_sq(S, '1');
    Coding(HT, HT.node[root].rchild, CD, num, S);
    Pop_sq(S, ch);
  }
}

void HuffmanCoding(HuffmanTree &HT, Sqlist &CD, Number &num) {
  SqStack S;  // 顺序栈, 用于记录遍历路径
  InitStack_sq(S);
  CD.chars = new ElemType_2[2 * HT.leafNum];
  CD.length = HT.leafNum;
  Coding(HT, HT.root, CD, num, S);
}

bool outPut_hfmTree(HuffmanTree HT, Number num) {
  ofstream huffmanTree;
  huffmanTree.open("../hfmTree.txt");
  huffmanTree << HT.leafNum << endl;
  for (int i = 0; i < HT.nodeNum; i++) {
    if (i < HT.leafNum) {
      huffmanTree << num.data[i].ch << "\t";
    } else {
      huffmanTree << i << "\t";
    }
    huffmanTree << HT.node[i].weight << "\t\t";
    huffmanTree << HT.node[i].parent << "\t\t";
    huffmanTree << HT.node[i].lchild << "\t\t";
    huffmanTree << HT.node[i].rchild << endl;
  }
  huffmanTree.close();
  return OK;
}

bool DeCoding(HuffmanTree HT, Number num) {
  // 获取编码文件
  string code;
  ifstream infile;
  infile.open("../CodeFile.txt");
  infile >> code;
  infile.close();
  //   cout << code;
  ofstream outfile;
  outfile.open("../TextFile.txt");
  // 从树根开始，0向左走，1向右走，到达叶子结点为止，获取叶子结点的值
  int j = 0;
  while (j < code.length()) {
    int i = HT.root;
    while (HT.node[i].lchild != -1 && HT.node[i].rchild != -1) {
      if (code[j] == '0') {
        i = HT.node[i].lchild;
        j++;
      } else {
        i = HT.node[i].rchild;
        j++;
      }
    }
    outfile << num.data[i].ch;
  }
  outfile.close();
  return OK;
}

bool Check() {
  string str_ToBeTran;
  string str_TextFile;
  ifstream ToBeTran;
  ifstream TextFile;
  ToBeTran.open("../ToBeTran.txt");
  ToBeTran >> str_ToBeTran;
  // cout<<str_ToBeTran<<endl;
  TextFile.open("../TextFile.txt");
  TextFile >> str_TextFile;
  // cout<<str_TextFile;
  int count = 0;
  for (int i = 0; i < str_ToBeTran.length(); i++) {
    if (str_ToBeTran[i] == str_TextFile[i]) count++;
  }
  if (str_ToBeTran.length() == str_TextFile.length() &&
      count == str_ToBeTran.length()) {
    cout << "Verify Correct" << endl;
  } else {
    cout << "Verify Wrong" << endl;
  }
  ToBeTran.close();
  TextFile.close();
  return OK;
}

bool CodePrint() {
  string str;
  ifstream infile;
  infile.open("../CodeFile.txt");
  getline(infile, str);
  infile.close();
  ofstream outfile;
  outfile.open("../CodePrint.txt");
  for (int i = 0; i < str.length(); i++) {
    if (i % 50 == 0 && i != 0) {
      cout << endl;
      outfile << endl;
    }
    cout << str[i];
    outfile << str[i];
  }
  cout << endl;
  outfile.close();
  return OK;
}

// 打印编码二维数组
void printHC(Sqlist &CD) {
  cout << "Huffman Code:" << endl;
  for (int i = 0; i < CD.length; i++) {
    cout << CD.chars[i].data << ": " << CD.chars[i].code << endl;
  }
}

/*打印二叉树*/
void TreePrint(HuffmanTree HT, Sqlist &CD, int i, int n) {
  ofstream outfile;
  outfile.open("../TreePrint.txt");
  Print(HT, CD, i, n, outfile);
  outfile.close();
}

void Print(HuffmanTree HT, Sqlist &CD, int i, int n, ofstream &outfile) {
  if (i != -1) {
    Print(HT, CD, HT.node[i].rchild, n + 1, outfile);
    for (int j = 0; j < n; j++) {
      cout << '\t';
      outfile << '\t';
    }
    if (i < HT.leafNum) {
      if (CD.chars[i].data == ' ') {
        cout << '#' << endl;
        outfile << '#' << endl;
      } else {
        cout << CD.chars[i].data << endl;
        outfile << CD.chars[i].data << endl;
      }
    } else {
      cout << HT.node[i].weight << endl;
      outfile << HT.node[i].weight << endl;
    }
    Print(HT, CD, HT.node[i].lchild, n + 1, outfile);
  }
}
