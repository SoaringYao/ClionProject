#include "BinaryTree.h"

/*先序创建二叉树*/
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

/*先序遍历*/
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

/*中序遍历*/
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

/*后序遍历*/
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

/*统计二叉树中结点的个数*/
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

/*求树的深度*/
int Depth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int i = Depth(T->lchild);
        int j = Depth(T->rchild);
        return i > j ? i + 1 : j + 1;
    }
}

/*复制二叉树*/
void Copy(BiTree T, BiTree &NewT)
{
    if (T = NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

/*统计二叉树中叶子结点的个数*/
int LeafCount(BiTree T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    /*如果二叉树左子树和右子树皆为空，说明该二叉树根节点为叶子结点，结果为1*/
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}

/*二叉树中从每个叶子结点到跟结点的路径*/
void PrintAllPath(BiTree T, char path[], int pathlen)
{
    int i;
    if (T != NULL)
    {
        path[pathlen] = T->data; /*将当前结点放入路径中*/
        if (T->lchild == NULL && T->rchild == NULL)
        {
            /*若这个节点是叶子结点*/
            for (i = pathlen; i >= 0; i--)
                cout << path[i] << " ";
            cout << "\n";
        }
        else
        {
            PrintAllPath(T->lchild, path, pathlen + 1);
            PrintAllPath(T->rchild, path, pathlen + 1);
        }
    }
}

/*判断二叉树是否为空*/
int BiTree_empty(BiTree T)
{
    if (T)
        return 1;
    else
        return 0;
}

//递归,交换左右子树 
void exchage(BiTree &T)
{
	//递归出口 
	if(T == NULL)
	{
		return;
	}

	//递归 左右子树 
	exchage(T->lchild);
	exchage(T->rchild);

	//交换当前左右子树
	BiTree temp = NULL;

	temp = T->lchild; 
	T->lchild = T->rchild;
	T->rchild = temp;
	
	return;
}

int getNodeNumKthLevel(Node* tree, int k) {
        if (tree == NULL || k < 1) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        return getNodeNumKthLevel(tree->lchild, k - 1) + getNodeNumKthLevel(tree->rchild, k - 1);
}

//释放二叉树 
void FreeTree(BiTree &T)
{
	if(T)
	{
		FreeTree(T->lchild);            //递归释放其左子树 
		FreeTree(T->rchild);           //递归释放其右子树 
		
		free(T);                      //释放根节点 
		T = NULL;                     //释放指向根节点的指针 
	}
	return;          
}