#include "function.h"

int main()
{
    char exp[100];
    cout<<"请输入表达式:";
    cin>>exp;
    if(match(exp))
    {
        cout<<"匹配成功"<<endl;
    }
    else
    {
        cout<<"括号不匹配"<<endl;
    }
    return 0;
}