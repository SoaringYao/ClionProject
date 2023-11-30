// Code file created by C Code Develop

#include "stdio.h"
#include "stdlib.h"
#include "function.h"

void mark(int i,int j, int flag)
{//在R[i,j]放入或取走皇后，flag=1放入，flag=0取走
    A[j] = B[i+j] = C[i-j+7] = flag;
}
//end mark

int place(int i,int j)
{//检查R[i,j]是否可以放皇后
    return (A[j] == 0 && B[i+j] == 0&& C[i-j+7] == 0);
}//end place

void queen(int i)
{//从第i行开始放第i个皇后，调用queen（0）得到全部的解。
    for(int j = 0; j < N; j++)
    {//逐列尝试
        if(place(i, j))
        {//R[i,j]是否可放置
            X[i] = j; //第i个皇后放在j列
            mark(i, j, 1); //标记R（ij）已放置皇后
            if (i == N-1)
            {
                for(int k = 0; k < N; k++)printf("%d\n", X[k]); 
            }//最后一个皇后已放入，输出解向量。
            else queen(i+1); //接着试下一行的皇后
            mark(i, j, 0); //回溯，取走最后放置的皇后尝试下一个i
        }//if
    }//for
}//end queen
