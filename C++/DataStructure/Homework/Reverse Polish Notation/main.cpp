#include "function.h"

int main()
{
    char exp[100],RPN[100];
    cout<<"请输入表达式："<<endl;
    cin>>exp;
    getsuffix(exp,RPN);
    cout<<RPN;
    return 0;
}