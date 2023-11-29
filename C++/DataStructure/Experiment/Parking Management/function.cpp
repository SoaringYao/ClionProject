#include "function.h"

int Splace, Qplace;
int Snum = 0, Qnum = 0;
int price;

void Initstack(sqstack &s) // 栈的初始化
{
    s.base = new car[Splace]; // 为顺序栈动态分为一个最大容量为n的数组空间
    s.top = s.base;           // top初始值为base,空栈
}

bool StackEmpty(sqstack s)
{ // 判断栈是否为空
    if (s.base == s.top)
        return false;
    else
        return true;
}

void PushStack(sqstack &s, car p) // 入栈
{
    *s.top = p;
    s.top++;
}

car Pop_s(sqstack &s) // 出栈
{
    s.top--;
    return *s.top;
}

void InitQueue(SqQueue &Q, int Qplace)
{
    Q.front = Q.rear = new car[Qplace];
}

void PushQueue(SqQueue &Q, car p) // 入队
{
    *Q.rear = p;
    Q.rear++;
}

car Pop_q(SqQueue &Q) // 出队
{
    return *Q.front++;
}

void Push(sqstack &s, SqQueue &Q, car p) // 停车（入栈或入队列）
{
    if (s.top - s.base >= Splace)
    {
        Qnum++;
        if (Qnum > Qplace)
        {
            cout << "QUEUE FULL" << endl;
            exit(EXIT_FAILURE);
        }
        PushQueue(Q, p);
        cout << "车牌号" << p.num << ":便道第" << Qnum << "位" << endl;
    }
    else
    {
        Snum++;
        PushStack(s, p);
        cout << "车牌号" << p.num << ":停车场第" << Snum << "位" << endl;
    }
}

void arrive(sqstack &s1, SqQueue &Q)
{
    car v;
    cin >> v.num >> v.atime;
    Push(s1, Q, v);
}

void leave(sqstack &s1, sqstack &s2, SqQueue &Q)
{
    car *p;
    p = new car;
    cin >> p->num >> p->ltime;
    car *q;
    q = new car;
    q = s1.base;
    int i = 1;
    for (i; i <= Snum; i++) // 找到要出库的车
    {
        if (strcmp(p->num, q->num) == 0)
            break;
        q++; // 从底向顶遍历
    }
    if (i <= Snum)
    {
        while (1)
        {
            car d;
            d = Pop_s(s1);
            Snum--;
            cout << "车牌号" << d.num << ": 离开停车场" << endl;
            if (strcmp(q->num, s1.top->num) == 0)
                break;
            PushStack(s2, d);
        }
        int a = (p->ltime) - (s1.top->atime);
        cout << endl
             << "车牌号:" << p->num << endl
             << "到达时间 " << s1.top->atime << " 离开时间 " << p->ltime << "  收费 " << a * price << endl
             << endl;

        while (StackEmpty(s2))
        {
            *s1.top = Pop_s(s2);
            Snum++;
            cout << "车牌号" << s1.top->num << ": 停车场第" << Snum << "位" << endl;
            s1.top++;
        }
        if (Q.front != Q.rear)
        {
            *s1.top = Pop_q(Q);
            Snum++;
            s1.top->atime = p->ltime;
            cout << "车牌号" << s1.top->num << ": 停车场第" << Snum << "位" << endl
                 << endl;
            s1.top++;
            Qnum--;
        }
    }
    else if (strcmp(Q.front->num, p->num) == 0)
    {
        cout << "车牌号:" << p->num << endl
             << "到达时间 " << Q.front->atime << " 离开时间 " << p->ltime << "  收费 " << 0 << endl;
        Qnum--;
        Q.front++;
    }
    else
    {
        cout << "ERROR:can't find OR can't be moved in the sidewalk" << endl;
    }
}

void traverse_S(sqstack s)
{
    int n = Snum;
    car *q;
    q = new car;
    q = s.base;
    for (int i = 1; i <= Snum; i++)
    {
        cout << "车牌号" << q->num << ": 停车场第" << i << "位" << endl;
        q++;
    }
}

void traverse_Q(SqQueue Q)
{
    car *q;
    q = Q.front;
    for (int i = 1; i <= Qnum; i++)
    {
        cout << "车牌号" << q->num << ": 便道第" << i << "位" << endl;
        q++;
    }
}