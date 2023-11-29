#ifndef __GREP_H__
#define __GREP_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern int lineNumber;
extern string line;

int findSubstring(const string& mainStr, const string& subStr);
bool feedback(string file, string keyword);

#endif