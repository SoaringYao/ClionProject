#include "huffman.h"

int main() {
    //def
    HuffTree HT;
    char a[1000];
    word *head = nullptr;
    int m[1000] = {0}, Length = 0;

    //统计
    Count(head);
    print(head);

    //将频度存入数组
    load(head, m);
    Length = getlength(m);

    //并构建哈夫曼树
    HuffmanTree(HT, m, Length);
    printHT(HT, Length);


    //编码
    char **HC;
    HuffmanCoding(HT, HC, Length);
    printHC(HC, Length, head);

    DestroyHC(HC, Length);
    DestroyWord(head);

    return 0;
}