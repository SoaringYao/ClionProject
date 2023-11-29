#include"function.h"
#include <iostream>

using namespace std;

int main() {
    //环的长度
    int len;
    cout << "输入约瑟夫环的长度：";
    cin >> len;
    int array[len];
    cout << "请输入m的初始值 m:";
    int m;
    cin >> m;
    for (int i = 0; i < len; ++i) {
		cout << "请输入第"<<i+1<<"个人的密码: ";
        cin >> array[i];
    }
    //创建约瑟夫环
    Node *head = init(len, array);
	cout<<endl;
    function(head, len, m);
    return 0;
}