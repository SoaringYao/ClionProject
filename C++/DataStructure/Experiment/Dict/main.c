#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void sort(int i,int num,char a[][20])
{
    char b[20];
    for(int y=i; y+1<num; y++)
    {
        strcpy(b,a[y]);
        strcpy(a[y],a[y+1]);
        strcpy(a[y+1],b);
    }
}

void sortAlpha(char a[][20],int num)
{
    char b[20];
    int i,j;
    for(i=0; i<num; i++)
    {
        for(j=0; j+1<num; j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                strcpy(b,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],b);
            }
        }
    }
}

int isSameword(char a[][20],int num,int snum[])
{
    int wnum=1;
    for(int i=0; i<num; i++)
    {
        if(strcmp(a[i],a[i+1])==0)
        {
            wnum++;
            if(strcmp(a[i+1],a[i+2])!=0)
            {
                for(int k=0; k<wnum-1; k++)
                {
                    sort(i-wnum+3,num,a);
                }
                num=num-wnum+1;
                snum[i-wnum+2]=wnum;
                i=i-wnum+2;
                wnum=1;
            }
        }
        else
        {
            snum[i]=1;
        }
    }
    return num;
}

void process_1(char a[][20],int num)
{
    for(int i=0,j=0; i<600; j++)
    {
        if(isalpha(a[i][j])==1)
        {
            a[i][j]=a[i][j]+32;
        }
        if(j==19)
        {
            i++;
            j=-1;
        }
    }
}

void process_2(char a[][20],int num)
{
    for(int i=0,j=0; i<600; j++)
    {
        if(isalpha(a[i][j])==0&&j!=0)
        {
            a[i][j]='\0';
        }
        if(j==19)
        {
            i++;
            j=-1;
        }
    }
}
void process_3(char a[][20],int num)
{
    for(int i=0,j=0; i<600; j++)
    {
        if((isalpha(a[i][0])==0)&&(isalpha(a[i][1])==2))
        {
            for(int y=0; y+1<20; y++)
            {
                a[i][y]=a[i][y+1];
            }

        }
        if(j==19)
        {
            i++;
            j=-1;
        }
    }
}

int process_4(char a[][20],int num)
{
    for(int i=0; i<600; i++)
    {
        if(isdigit(a[i][0])!=0)
        {
            sort(i,num,a);
            num--;
        }
    }
    return num;
}
int main()
{
    FILE* fp;
    char a[600][20];
    memset(a,0,sizeof(a));
    int snum[600];
    if((fp=fopen("article.txt","r"))==NULL)
    {
        printf("未找到文件！\n");
        exit(-1);
    }
    int num=516;
    for(int i=0; i<600; i++)
    {
        fscanf(fp,"%s",a[i]);
    }
    if(fp!=NULL)
    {
        fclose(fp);
    }
    process_1(a,num);
    process_2(a,num);
    process_3(a,num);
    sortAlpha(a,num);
    for(int k=0; k<5; k++)
    {
        num=process_4(a,num);
    }
    num=isSameword(a,num,snum);
    if((fp=fopen("dictionary.txt","w+"))==NULL)
    {
        printf("单词本创建失败！\n");
        exit(-1);
    }

    for(int i=0; i<num; i++)
    {
        fprintf(fp,"%s,%d\n",a[i],snum[i]);
    }
    if(fp!=NULL)
    {
        fclose(fp);
        printf("单词本创建成功");
    }
    return 0;
}
