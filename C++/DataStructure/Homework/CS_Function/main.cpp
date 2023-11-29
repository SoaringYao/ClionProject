#include "function.h"

int main()
{
    CSTree T;
    InitTree_CS(T);
    cout << "请录入先序序列(扩展法):" << endl; // 例如:RAD#E##B#CFG#H#K#####
    CreateTree_CS(T);

    cout << "****深度****" << endl;
    cout << "树的深度为:" << Algo_2(T) << endl;

    return 0;
}