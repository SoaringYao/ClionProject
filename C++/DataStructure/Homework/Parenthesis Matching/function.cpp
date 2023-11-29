#include "function.h"
#include "stack.h"

bool match(char exp[])
{ // 检查表达式exp中的括号是否嵌套正确，是则返回TRUE， 否则返回FALSE
    int matchstat = 1;
    char ch;
    SqStack S;
    ElemType e;

    InitStack_sq(S); // 初始化栈S
    ch = *exp++;
    while (ch !='#'&& matchstat)
    { // exp没有处理完
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            Push_sq(S, ch);
            break;
        case ')':
            if (!Pop_sq(S, e) || e != '(')
                matchstat = 0;
            break; // 栈空或栈顶不是“(”，则表示不匹配
        case ']':
            if (!Pop_sq(S, e) || e != '[')
                matchstat = 0;
            break;
        case '}':
            if (!Pop_sq(S, e) || e != '{')
                matchstat = 0;
            break;
        } // switch
        ch = *exp++;
    } // while
    if (matchstat && StackEmpty(S))
        return true;
    else
        return false;
} // end match
