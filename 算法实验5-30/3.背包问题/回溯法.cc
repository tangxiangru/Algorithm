#include<stdio.h>

int c=30;    //背包容量
int n=3;    //对象数目
int w[]={20,15,15};  //重量数组
int v[]={40,25,25};  //收益数组
int cw;
int cv;
int bestv;
int X[3];

void getBest(int i)
{
    if(i>=n)
    {
        if(cv>bestv)
            bestv=cv;

        return;
    }
    if(cw+w[i]<=c)
    {
        X[i]=1;
        cw+=w[i];
        cv+=v[i];
        getBest(i+1);
        cw-=w[i];//此处回溯
        cv-=v[i];
    }

    X[i]=0;
    getBest(i+1);
}

int main()
{

    getBest(0);
    printf("%d",bestv);

    return 0;
}
