#include "CSTree.h"
 
void InitQueue (SqQueue &Q) {
    // 构造一个空队列Q
    Q.base = new CSTree[MAXQSIZE];
    if(!Q.base) exit(0);             // 存储分配失败
    Q.front = Q.rear = 0;
}
 
bool EmptyQueue(SqQueue Q){
    //判断队列是否空
    return Q.front == Q.rear;
}
 
int  QueueLength (SqQueue Q) {
    //返回Q的元素个数，即队列的长度
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}
 
CSTree GetHead(SqQueue Q) {
    //返回队列Q的队头元素，不修改队头指针
    if ( Q.front != Q.rear )
        return Q.base[Q.front];
    else
        return 0;
}
 
void EnQueue(SqQueue&Q,CSTree e) {
    // 插入元素e为Q的新的队尾元素
    if((Q.rear+1) %MAXQSIZE ==Q.front){
        cout<<"队列满";
        exit(0); //队列满
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
}
 
void DeQueue (SqQueue&Q) {
    //若队列不空，则删除Q的队头元素，
    //否则退出程序报错
    if (Q.front==Q.rear)  exit(0);
    Q.front = (Q.front+1) % MAXQSIZE;
}
 
CSTree GetTreeNode(char ch){//创建结点
    CSTree CST = new CSNode;
    CST->data = ch;
    CST->firstchild = NULL;
    CST->nextsibling = NULL;
    return CST;
}
 
void CreatTree(CSTree &T){//创建树
    CSTree P,s,r;
    T = NULL;
    SqQueue Q;InitQueue(Q);//队列创建及初始化
    char fa,ch;
    for(cin>>fa,cin>>ch;ch!='^';cin>>fa,cin>>ch){
        P = GetTreeNode(ch);//创建结点
        EnQueue(Q,P);//指针入队
        if(fa == '^') T=P;//fa == ^表示没有父结点，即创建结点为根结点
        else{//不为根结点时
            s = GetHead(Q);//取队列头元素(指针值)
            while (s->data != fa){//查询双亲结点
                DeQueue(Q);s = GetHead(Q);
            }
            if(!(s->firstchild)){
                s->firstchild = P;//链接第一个孩子结点
                r = P;//r指向尾端
            }else{
                r->nextsibling = P;//链接兄弟结点
                r = P;//r指向尾端
            }
        }
    }
}
 
void printTree(CSTree T,int n){//打印树，n表示深度
    if(T){
        for(int i = 0;i<n;i++){
            cout<<"\t";//按深度打印制表符
        }
        cout<<T->data;//打印数据
        cout<<endl;//换行打印孩子
        printTree(T->firstchild,n+1);//递归打印孩子，深度加1
        printTree(T->nextsibling,n);//递归打印兄弟
    }
}
 
int CountLeaf(CSTree T){//统计树的叶子结点个数
    int static num=0;
    if(T){
        if(!T->firstchild)//没有孩子即为叶子结点，计数+1
          num++;
        CountLeaf(T->firstchild);//遍历孩子
        CountLeaf(T->nextsibling);//遍历兄弟
    }
    return num;
}
 
int TreeDepth(CSTree T){//计算树的高度
    if(T == NULL) return 0;//空树时返回0
    else{
        int h1 = TreeDepth(T->firstchild);//孩子高度
        int h2 = TreeDepth(T->nextsibling);//兄弟高度
        return (h1+1>h2)?(h1+1):h2;//返回大的值
    }
}
 
void PreOrderTraverse(CSTree T) {//先根遍历
    if(T) {
        cout<<T->data<<" ";
        PreOrderTraverse(T->firstchild);
        PreOrderTraverse(T->nextsibling);
    }
}
 
void InOrderTraverse(CSTree T) {//后根遍历
    if(T) {
        InOrderTraverse(T->firstchild);
        cout<<T->data<<" ";
        InOrderTraverse(T->nextsibling);
    }
}
 
void LevelOrderTraverse(CSTree T){//层次遍历
    SqQueue Q;
    InitQueue(Q);//队列初始化
    if(T==NULL) return;
    CSTree p = T;
    EnQueue(Q,p);//根结点入队
        while (!EmptyQueue(Q)) {
            int width = QueueLength(Q);//队列长度
            for(int i = 0;i<width;i++){
                p = GetHead(Q);
                cout<<p->data<<" ";//输出结点
                DeQueue(Q);//出队
                p = p->firstchild;//指向下一个孩子结点
                while (p) {//p非空时继续遍历
                    EnQueue(Q,p);//入队
                    p = p->nextsibling;//指向兄弟结点
                }
            }
        }
}
 
void AllPath(CSTree T,SqQueue Q){//输出根结点到叶子结点的路径
    if(T){
        EnQueue(Q,T);//根结点入队
        if(!T->firstchild){//没有孩子时输出路径
            for(;QueueLength(Q)>1;DeQueue(Q)){
                cout<<GetHead(Q)->data<<" ";
            }
            cout<<GetHead(Q)->data<<endl;
        }else {
            T = T->firstchild;//否则指向孩子
            while (T) {
                AllPath(T,Q);//递归孩子，即递归该路径
                T = T->nextsibling;//指向兄弟
            }
        }
    }
}
