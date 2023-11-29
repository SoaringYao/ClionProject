#include "SqQueue.h"

int main()
{
    SqQueue Q;
    int choice;
    InitQueue(Q);
    while (1)
    {
        menu();
        cout << "请输入菜单序号:" << endl;
        cin >> choice;
        if (choice == 4)
            break;
        switch (choice)
        {
        case 1:
            EnterToQueue(Q);
            break;
        case 2:
            DeleteFromQueue(Q);
            break;
        case 3:
            GetHeadOfQueue(Q);
            break;
        default:
            cout << "error" << endl;
        }
    }
    return 0;
}