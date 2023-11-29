#include "CSTree.h"

int main()
{
    CSTree CST;
    SqQueue Q;
    CreatTree(CST);
    InitQueue(Q);
    printTree(CST, 0);
    cout << "树的叶子个数为:" << CountLeaf(CST) << endl;
    cout << "树的高度为:" << TreeDepth(CST) << endl;
    cout << "树的先根遍历为:";
    PreOrderTraverse(CST);
    cout << endl;
    cout << "树的后根遍历为:";
    InOrderTraverse(CST);
    cout << endl;
    cout << "树的层次遍历为:";
    LevelOrderTraverse(CST);
    cout << endl;
    cout << "树从根结点到所有叶子结点的路径:" << endl;
    AllPath(CST, Q);
    return 0;
}