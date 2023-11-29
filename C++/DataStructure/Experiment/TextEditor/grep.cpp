#include "grep.h"

int lineNumber=0;
string line;

// 函数用于查找子串在主串中的位置
int findSubstring(const string& mainStr, const string& subStr) {
    size_t found = mainStr.find(subStr);
    if (found != string::npos) {
        return found;
    }
    return -1;
}

//反馈行号
bool feedback(string fileName,string keyword)
{
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "无法打开文件 " << fileName << endl;
        return false;
    }

    while (getline(file, line))
    {
        lineNumber++;
        int position = findSubstring(line, keyword);
        if (position != -1)
        {
            cout << "行号 " << lineNumber << ": " << line << endl;
        }
    }

    file.close();
    
    return true;
}