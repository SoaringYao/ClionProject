#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    LNode *s;
    LinkList H;
    int x;
    H = Creat_CircularList();
    scanf("%d",&x);
    s=SetPointerS(H,x);
    DelPrior(s);
    PrintCircularList(s);
}
