#include "grep.h"

int main() {
    setbuf(stdout,nullptr);//puts到输出台上
    string fileName, keyword;
    cout << "请输入要搜索的文件名: ";
    cin >> fileName;
    cout << "请输入要查找的关键词: ";
    cin >> keyword;

    feedback(fileName,keyword);

    return 0;
}