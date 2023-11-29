#include "function.h"

Node *init(int n, int array[]) {
    Node *head;//链表头结点
    Node *current;//链表当前节点
    Node *next;//链表下一个节点

	int i = 1;

    current = new Node[1];
    current->number = i;
    current->password = array[i - 1];
    head = current;

    for (i = 2; i <= n; ++i) {
        next = new Node[1];
        next->number = i;
        next->password = array[i - 1];

        current->next = next;
        current = next;
    }
    current->next = head;
    return head;
}

/**
 * 遍历约瑟夫环，报数出列
 * @param head 头结点
 * @param len 约瑟夫环长度
 * @param password 初始密码
 */

void function(Node *head, int len, int password) {
    //前一个节点
    Node *pre;
    //后一个节点
    Node *next;
    //要删除的节点
    Node *temp;
    //初始化
    next = head;
    for (int i = 1; i < len; i++) {
        pre = next->next;
        next = next->next;
    }
    //遍历所有人
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j < password; j++) {//将指针移动到出列的前一个
            pre = pre->next;
        }
        //保存要删除的节点
        temp = pre->next;
        //下一个节点
        next = temp->next;
        //修改密码
        password = temp->password;
        //输出
        cout <<"出列人的序号为"<<temp->number<<",密码为"<<temp->password<< endl;
        //连接链表，去除中间节点
        pre->next = next;
        //释放中间节点
        delete temp;
    }
}