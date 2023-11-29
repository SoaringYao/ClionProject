# homework_caculate RPN

```cpp
bool isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#') return 1;
    else return 0;
};

int calculate(char* suffix){
    sqstack s;
    Initstack_sq(s);
    char* p;
    char ch;
    char a,b;
    p=suffix;
    ch=*p++;
    while(ch!='#'){
        if(!isoperator(ch)) Push_sq(s,ch);
        Pop_sq(s,b);
        Pop_sq(s,a);
        Push_sq(s,operate(a,ch,b));
        ch=*p++;
    };
    Pop_sq(s,ch);
    return (int)ch;
};
int operate(int m,char op,int n){
    if(op=='+') return m+n;
    if(op=='-') return m-n;
    if(op=='*') return m*n;
    if(op=='/') return m/n;
    else return 0;
}
```
