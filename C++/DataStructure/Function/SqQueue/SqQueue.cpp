#include "SqQueue.h"

/***************************基本操作函数**************************/

// 初始化函数
Status InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    return 1;
}

// 判断队空函数
bool QueueEmpty(SqQueue Q)
{
    if (Q.front != Q.rear)
        return false;
    else
        return true;
}

// 入队函数
bool EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MaxQSize == Q.front)
        return false; // 队列满 牺牲一个以判断
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxQSize; // 指针加1 取模
    return true;
}

// 出队函数
bool DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false; // 队空 其实可以调用QueueEmpty 不然要它干啥呢
                      // 严蔚敏版 给了判空函数，但在其他基本操作函数中也没用
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxQSize; // 指针加1 取模
    return true;
}

// 取队头
bool GetHead(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false; // 队空 其实可以调用QueueEmpty 不然要它干啥呢
                      // 严蔚敏版 给了判空函数，但在其他基本操作函数中也没用
    e = Q.data[Q.front];
    return true;
}

/**************************功能实现函数****************************/
// 入队功能函数 调用EnQueue函数
void EnterToQueue(SqQueue &Q)
{
    int n;
    QElemType e;
    int flag;
    cout << "请输入入队元素个数(>=1):" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i + 1 << "个元素的值:";
        cin >> e;
        flag = EnQueue(Q, e);
        if (flag)
            cout << e << "已入队" << endl;
        else
        {
            cout << "队已慢！！!" << endl;
            break;
        }
    }
}

// 出队函数 调用DeQueue函数
void DeleteFromQueue(SqQueue &Q)
{
    int n;
    QElemType e;
    int flag;
    cout << "请输入出队元素个数(>=1):" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        flag = DeQueue(Q, e);
        if (flag)
            cout << e << "已出队" << endl;
        else
        {
            cout << "队已空！！！" << endl;
            break;
        }
    }
}

// 获得队头元素 调用GetHead函数
void GetHeadOfQueue(SqQueue Q)
{
    QElemType e;
    bool flag;
    flag = GetHead(Q, e);
    if (flag)
        cout << "队头元素为:" << e << endl;
    else
        cout << "队已空！！!" << endl;
}

// 菜单
void menu()
{
    cout << "********1.入队          2.出队*********" << endl;
    cout << "********3.取队头元素    4.退出*********" << endl;
}