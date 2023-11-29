#include <iostream>
using namespace std;
typedef int DataType;
struct Node{
	DataType data;
	Node *next;
};
class LinkQueue{
	public:
		LinkQueue();//初始化空的链表队列
		~LinkQueue();//释放链队列的存储空间
        void ShowQueue();
		void EnQueue(DataType x);//入队操作，将元素x出队
		DataType DeQueue();//出队操作，将队头元素出队 
        void FindQueue(DataType value);
        int Length();
		DataType GetHead();//取链队列队头元素
		int Empty();//判断队列是否为空
	private:
		Node *front,*rear;//队头和队尾指针 
		int Len;
};
//链队列基本操作的实现本质上是单链表操作的简单化，且时间复杂度均为O(1)
 
//构造函数----链队列的初始化
LinkQueue::LinkQueue(){
	Node *s=nullptr;
	s=new Node;
	s->next = nullptr;
	front=rear=s;//将队头指针和队尾指针都指向头结点s 
}
 
//析构函数----链队列的销毁
LinkQueue::~LinkQueue(){
	while(front){//释放每一个结点的存储空间 
		rear=front->next;
		delete front;
		front=rear;
	}
}
 
//入队操作----链队列的插入操作只需考虑在链表的尾部进行
void LinkQueue::EnQueue(DataType x){
	Node *s=nullptr;
	s=new Node;
	s->data=x;s->next=nullptr;
	rear->next=s;rear=s;//将结点s插入到队尾 
	Len++;
} 
 
//出队操作----链队列的删除操作只需考虑在链表的头部进行 
DataType LinkQueue::DeQueue(){
	DataType x;
	Node *p=nullptr;
	if(rear == front) throw "下溢";
	p=front->next;x=p->data;
	front->next=p->next;
	//if(!p->next)
	if(rear==p) front=rear;
	delete p;
	Len--;
	return x;
}

//显示队列
void LinkQueue::ShowQueue() 
{
    Node *p;
    p = front->next;
    if (p == NULL)  
    {
        cout << "队列为空" << endl;
    }
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//队列查询
void LinkQueue::FindQueue(DataType value) {
    Node *ptarget;
    ptarget = front;
    int n = 0;
    cout << "数据值为" << value << "的位置=";
    while (ptarget != rear) {
        if (ptarget->data == value) {
            cout << n + 1 << " ";
        }
        n = n + 1;
        ptarget = ptarget->next;
    }
    cout << endl;
}
//计算队列长度
int LinkQueue::Length() {
    int length = 0;
    Node *p1 = front;
    Node *p2 = rear;
    while (p1 != p2) {
        p1 = p1->next;
        length++;
    }
    cout << "队列长度=" << length << endl;
    return length;
}
 
//取队头元素
DataType LinkQueue::GetHead(){
	return front->next->data;
}
 
//判断队列是否为空
int LinkQueue::Empty(){
	if(front==rear) return 1;
	else return 0;
}
 
int main(){
	int x;
	LinkQueue Q{};//定义对象变量Q
	cout<<"对5和8执行入队操作,";
	Q.EnQueue(5);
	Q.EnQueue(8);
	cout<<"当前队头元素为："<<Q.GetHead()<<endl;//输出队头元素5
    Q.ShowQueue();
    Q.FindQueue(5);
    Q.Length();
	try{
		x=Q.DeQueue();
		cout<<"执行一次出队操作，出队元素是："<<x<<endl;//输出出队元素5 
	} catch(char *str){
		cout<<str<<endl;
	}
	cout<<"当前队头元素为："<<Q.GetHead()<<endl;//输出队头元素8
	try{
		cout<<"请输入入队元素：";
		cin>>x;
		Q.EnQueue(x);
	} catch(char *str){
		cout<<str<<endl;
	}
	if(Q.Empty()==1) cout<<"队列为空"<<endl;
	else cout<<"队列非空"<<endl;//队列有2个元素，输出队列非空 
    Q.~LinkQueue();
	return 0;
}