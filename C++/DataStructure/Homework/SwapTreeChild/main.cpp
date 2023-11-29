#include "BinaryTree.h"

int main()
{
	BiTree T;
	//构建二叉树
	cout<<"请输入结点值(#表示空结点):"<<endl;
	CreateBiTree(T);
	InOrderTraverse(T);//查看构建结果
	cout<<endl;
	//交换左右子树 
	exchage(T);
	//查看交换后结果
	InOrderTraverse(T); 
	cout<<endl;
	//释放二叉树 
	FreeTree(T);
	return 0;
}

/*Test
输入abc##d##ef##g## 
    
				    	a         -->交换后       a 
				    b       e                  e     b
				c     d   f    g             g   f  d  c
*/