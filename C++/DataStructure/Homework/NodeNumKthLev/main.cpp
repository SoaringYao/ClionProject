#include "BinaryTree.h"

int main()
{
	BiTree T;
	//构建二叉树
	cout<<"请输入结点值(#表示空结点):"<<endl;
	CreateBiTree(T);
	InOrderTraverse(T);//查看构建结果
	cout<<endl;
	int num,k;
	cout<<"请输入要查看的层数:"<<endl;
	cin>>k;
	num=getNodeNumKthLevel(T,k);
	cout<<"第"<<k<<"层有"<<num<<"个结点"<<endl;
	//释放二叉树 
	FreeTree(T);
	return 0;
}

/*Test
输入abc##d##ef##g## 
				    	a
				    b       e
				c     d   f    g
*/