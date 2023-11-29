#include "function.h"
#include "stack.h"

void getsuffix(char exp[],char suffix[])
{ // 将串exp表示的原表达式（#结束）转换为后缀表达式suffix
    SqStack S;
    char *p = exp;
    int k = 0; // 初始化后缀表达式下标
    char ch,c;

    InitStack_sq(S);
    Push_sq(S, '#'); // 初始化栈S

    while (!StackEmpty(S))
    {
        ch = *p++; // 处理原表达式一个字符
        if (!isoperator(ch))
        {
            suffix[k++] = ch;
            continue; // 非运算符直接发送
        }
        switch (ch)
        {
        case '(':
            Push_sq(S, ch);
            break;
        case ')':
            while (Pop_sq(S, c) && c != '(')
                suffix[k++] = c;
            break;
        default:
            while (GetTop_sq(S, c) && preop(c, ch))
            {
                suffix[k++] = c;
                Pop_sq(S, c);
            }
            if (ch != '#')
            {
                Push_sq(S, ch);
            }
            break; //'#'除外当前字符入栈
        }// switch
    }// while
    suffix[k] = '\0';
    DestroyStack_sq(S);
} // end getsuffix

bool preop(char c,char ch)
{
    return (getlevel(c)>=getlevel(ch))?true:false;
}

int getlevel(char ch)
{//获取符号优先级
    int a;
    switch(ch)
    {
        case '#':
            a=-1;
            break;
        case '(':
            a=0;
            break;
        case '+':
        case '-':
            a=1;
            break;
        case '*':
        case '/':
            a=2;
            break;
    }
    return a;
}

bool isoperator(char ch)
{
    return ((ch=='#')||(ch=='(')||(ch==')')||(ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))?true:false;
}