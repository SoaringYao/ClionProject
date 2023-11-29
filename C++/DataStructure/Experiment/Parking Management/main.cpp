#include "function.h"

using namespace std;

int main()
{
    cout << "停车场车位数:";
    cin >> Splace;
    cout << "便道容纳量:";
    cin >> Qplace;
    cout << "收费单价:";
    cin >> price;
    cout<<endl<<"————————停车管理————————"<<endl;
    sqstack s1, s2;
    SqQueue Q;
    Initstack(s1);
    Initstack(s2);
    InitQueue(Q, Qplace);
    char x1;
    cin >> x1;
    while (x1 != 'E')
    {
        switch(x1){
        case 'A':
            arrive(s1, Q);
            break;
        case 'D':
            leave(s1, s2, Q);
            break;
        case 'P':
            traverse_S(s1);
            break;
        case 'W':
            traverse_Q(Q);
            break;
        default:
            break;
        }
        cin >> x1;
    }
    return 0;
}
