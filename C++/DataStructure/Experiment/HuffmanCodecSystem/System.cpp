//
// Created by admin on 2023/11/19.
//

#include "System.h"

void system() {
  HuffmanTree HT;
  Sqlist code;
  Number num;
  char input;
  int flag = 0;
  cout << "-----Huffman Codec System-----" << endl;
  cout << "--I-----(Initialization)------" << endl;
  cout << "--E--------(Encoding)---------" << endl;
  cout << "--D--------(Decoding)---------" << endl;
  cout << "--P---------(Print)-----------" << endl;
  cout << "--T-------(TreePrint)---------" << endl;
  cout << "--Q---------(Quit)------------" << endl;
  cout << "Please Input Instruction: " << endl;
  while (true) {
    cin >> input;
    if (input == 'I') {
      flag = 1;
      CountTreeByInput(num, HT);
      int w[HT.leafNum];
      for (int i = 0; i < HT.leafNum; i++) {
        w[i] = num.data[i].num;
      }
      CreateHuffmanTree(HT, HT.leafNum, w);
      outPut_hfmTree(HT, num);  // 将生成的哈夫曼树保存到hfmTree.txt
      cout << "Process Success!" << endl;
    } else if (input == 'E') {
      if (!flag) {
        CountTreeByHuffTree(num, HT);
      }
      HuffmanCoding(HT, code, num);  // 获得每个字符的编码
      outPut_CodeFile(code);
      printHC(code);
      cout << "Process Success!" << endl;
    } else if (input == 'D') {
      DeCoding(HT, num);  // 解码并将结果写入TextFile.txt
      cout << "Process Success!" << endl;
      Check();  // 验证操作
    } else if (input == 'P') {
      CodePrint();  // 将文件CodeFile以紧凑格式显示在终端上，每行50个代码。同时将此字符形式的编码文件写入文件CodePrint中
      cout << "Process Success!" << endl;
    } else if (input == 'T') {
      TreePrint(HT, code, HT.root, 1);
    } else if (input == 'Q')
      break;
    else
      cout << "Please Re-Enter!" << endl;
  }
}