#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

typedef int Datatype;
typedef char* KeyType; 
typedef struct{
    Datatype Data;
    KeyType key;
}Elemtype;                                      //包含关键字和数据

typedef struct{
    Elemtype *elem;                     //          !!!!约定从下标1开始
    int len;                                //      表的元素个数
}StaticSrhTable;

typedef struct{
    Elemtype *elem;                             //查找表单元元素
    int count;                                  //记录数
    int sizeindex;                              //哈希表容量
}HashTable;                                         //开放定址法

typedef struct LHNode{                      //哈希表结点
    Elemtype data;                          //查找表单元
    LHNode *next;                                           //后继
} *LHNodeptr;

typedef struct{
    LHNodeptr *elem;                        //指针的指针
    int count;
    int sizeindex;
}LHashTable;                                //链地址存储法

__attribute__((unused)) int SeqSearch(StaticSrhTable SST, KeyType kval);
__attribute__((unused)) int BinSearch(StaticSrhTable SST, const KeyType kval);
//索引查找

void CreateHash(LHashTable &H);
int Hash(KeyType key);
void SearchHash(LHashTable H,int n);
void CreateVectorSim(LHashTable H,int vector[]);
void CreateVectorDif(LHashTable H,int vector[]);
void CreateVectorMain(LHashTable H,int vector[]);
double X1(const int vector1[],const int vector2[]);
double X2(const int vector1[],const int vector2[]);
char FindLast(const char* key);


//文件操作函数
int ReadWord(FILE *&fp,char str []);
int isChar(char c);


