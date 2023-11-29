#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <iostream>

using namespace std;

int getlevel(char ch);
bool preop(char c1,char c2);
void getsuffix(char exp[],char suffix[]);
bool isoperator(char ch);

#endif