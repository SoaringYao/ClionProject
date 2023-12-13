#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef int Datatype;
typedef char *KeyType;

typedef struct {
  Datatype Data;  // 记录关键字出现的次数
  KeyType key;
} ElemType;  // 包含关键字和数据

typedef struct LHNode {  // 哈希表结点
  ElemType data;         // 查找表单元
  LHNode *next;          // 后继
} *LHptr;

typedef struct {
  LHptr *elem;
  int count;   // 记录数
  int size;    // 哈希表容量
} LHashTable;  // 链地址存储法

__attribute__((unused)) typedef struct {
  ElemType *elem;  // 查找表单元元素
  int count;       // 记录数
  int size;        // 哈希表容量
} OHashTable;      // 开放定址法

// typedef struct {
//   ElemType *elem;  // 约定从下标1开始!!!!
//   int len;         // 表的元素个数
// } StaticSrhTable;

//__attribute__((unused)) int SeqSearch(StaticSrhTable SST, KeyType kval);
//__attribute__((unused)) int BinSearch(StaticSrhTable SST, KeyType kval);
// 索引查找

void CreateHash(LHashTable &H);
int Hash(KeyType key);
void SearchHash(LHashTable H, int n, KeyType s);
void CreateVectorSim(LHashTable H, int vector[]);
void CreateVectorDif(LHashTable H, int vector[]);
void CreateVectorMain(LHashTable H, int vector[]);
double X1(const int vector1[], const int vector2[]);
double X2(const int vector1[], const int vector2[]);
char FindLast(const char *key);

// 文件操作函数
bool ReadWord(ifstream &fin, char str[]);