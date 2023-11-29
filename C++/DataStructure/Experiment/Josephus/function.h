#ifndef __FUNCTION_H__
#define ___FUNCTION_H__

#include<iostream>
using namespace std;

struct Joseph {
    //约瑟夫环中某个人的序号
    int number;
    //约瑟夫环中某个人的密码
    int password;
    //约瑟夫环的下一个节点
    struct Joseph *next;
};

typedef Joseph Node;

Node *init(int n, int array[]);

void function(Node *head, int len, int password);

#endif