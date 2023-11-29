#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <iostream>
#include <string>

/*定义二叉树的结构*/
typedef struct Node
{
    char data; /*数据域*/
    struct Node *lchild, *rchild; /*左子树和右子树*/
} * BiTree, BiNode;
/*整棵树和结点名称*/

using namespace std;

/*先序创建二叉树*/
void CreateBiTree(BiTree &T);

/*遍历二叉树*/
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);

/*统计二叉树中结点的个数*/
int NodeCount(BiTree T);

/*求树的深度*/
int Depth(BiTree T);

/*复制二叉树*/
void Copy(BiTree T, BiTree &NewT);

/*统计二叉树中叶子结点的个数*/
int LeafCount(BiTree T);

/*二叉树中从每个叶子结点到跟结点的路径*/
void PrintAllPath(BiTree T, char path[], int pathlen);

/*判断二叉树是否为空*/
int BiTree_empty(BiTree T);

//递归交换左右子树 
void exchage(BiTree &T);

//求k层结点数
int getNodeNumKthLevel(Node* tree, int k);

//释放二叉树 
void FreeTree(BiTree &T);

#endif

/*TestMain

int main()
{
    BiTree T;
    //测试数据AB#CD##E##F#GH###
    cout << "先序遍历输入(以#结束):";
    CreateBiTree(T);
    cout << "中序遍历输出：";
    InOrderTraverse(T);
    cout << endl
         << "先序遍历输出:";
    PreOrderTraverse(T);
    cout << endl
         << "后序遍历输出:";
    PostOrderTraverse(T);
    cout << endl
         << "树的深度:" << Depth(T);
    cout << endl
         << "结点的个数:" << NodeCount(T);
    cout << endl
         << "二叉树中从每个叶子结点到根结点的所有路径：" << endl;
    char path[256];
    int pathlen = 0;
    PrintAllPath(T, path, pathlen);
    return 0;
}

*/