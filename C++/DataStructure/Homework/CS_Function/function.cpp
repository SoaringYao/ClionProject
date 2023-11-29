#include "function.h"

// 初始化
void InitTree_CS(CSTree &T)
{
    T = NULL;
}

// 接受前序扩展序列建树
int CreateTree_CS(CSTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (CSTree)malloc(sizeof(CSNode));
        if (!T)
            exit(0);
        T->data = ch;
        CreateTree_CS(T->firstchild);
        CreateTree_CS(T->nextsibling);
    }
    return OK;
}

// 树的度
int Algo_1(CSTree T)
{
    int i, j, max, tmp;
    CSTree Q[100]; // 临时存放各结点
    i = j = 0;
    max = -1;
    if (T)
    {
        max = 0;
        Q[j++] = T->firstchild;

        while (i < j) // 按层序遍历
        {
            tmp = 0;
            while (Q[i])
            {
                tmp++;
                // 存储有孩子的结点
                if (Q[i]->firstchild)
                    Q[j++] = Q[i]->firstchild;
                Q[i] = Q[i]->nextsibling; // 统计本层结点数
            }
            if (tmp > max)
                max = tmp;
            i++;
        }
    }
    return max;
}

// 树的深度
int Algo_2(CSTree T)
{
    int row, max;
    SqStack S;
    InitStack_sq(S);
    CSTree tmp, del;
    row = 0;
    if (T)
    {
        Push_sq(S, T);
        row = max = 1;

        while (!StackEmpty(S))
        {
            GetTop_sq(S, tmp);
            while (tmp->firstchild)
            {
                Push_sq(S, tmp->firstchild);
                ++max;
                if (row < max)
                    row = max;
                GetTop_sq(S, tmp);
            }
            GetTop_sq(S, tmp);
            Pop_sq(S, del);
            if (tmp->nextsibling)
                Push_sq(S, tmp->nextsibling);
            else
            {
                while (!StackEmpty(S))
                {
                    GetTop_sq(S, tmp);
                    Pop_sq(S, del);
                    --max;

                    if (tmp->nextsibling)
                    {
                        Push_sq(S, tmp->nextsibling);
                        break;
                    }
                }
            }
        }
    }
    DestroyStack_sq(S);
    return row;
}

// 树的叶子
int Algo_3(CSTree T)
{
    if (T)
    {
        if (!T->firstchild)
        {
            cout << T->data << ' '; // 输出叶子结点
            return 1 + Algo_3(T->nextsibling);
        }
        else
            return Algo_3(T->firstchild) + Algo_3(T->nextsibling);
    }
    else
        return 0;
}

// 树的边
void Algo_4(CSTree T)
{
    CSTree p, q;
    if (T)
    {
        p = T;
        q = T->firstchild;
        int i = 0; // 打印计数器
        while (q)
        {
            printf("(%c,%c) ", p->data, q->data);
            q = q->nextsibling;
            i++;
        }
        if (i > 0)
            cout << endl;
        Algo_4(T->firstchild);
        Algo_4(T->nextsibling);
    }
}
