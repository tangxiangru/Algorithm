#include<iostream>
#include<math.h>
using namespace std;

//物品
typedef struct obj
{
	int w;
	int v;
};

//生成子集
void subset(int s[][10],int n)
{
    int i,j,m,k;
	for(i=0;i<pow(2,n);i++)
	{
		k=i;
		for(j=n-1;j>=0;j--)
		{
			m=k%2;
			s[i][j]=m;
			k=k/2;
		}
	}
}

//判断子集可行性
void judge(int s[][10], obj obj[],int mark[],int n,int c)
{
   int i,j,v,w;
   for(i=0;i<pow(2,n);i++)
   {
        w=0;
        v=0; 
      for(j=0;j<n;j++)
	  { 
         w+=obj[j].w*s[i][j]; 
         v+=obj[j].v*s[i][j];  
	  }  
      if(w<=c) 
        mark[i]=v; 
      else
	    mark[i]=0;
  }
}

//求问题的最优解
int getmax(int mark[],int n,int &flag)
{
	int i,max;
	max=0;
	for(i=0;i<pow(2,n);i++)
	{
		if(mark[i]>max)
		{
			max=mark[i];
			flag=i;
		}
	}
    return max;
}
//输出选择物品的情况
void outputObj(int flag,int s[][10],int n)
{
	cout<<"装入背包物品的编号为： ";
	for(int i=0;i<n;i++)
	{
		if(s[flag][i]==1)
			cout<<i+1<<" ";
	}
	cout<<endl;
}

int main()
{
   int s[1024][10],mark[1024],n,max,c,flag;
   obj obj[10];
   cout<<"请输入背包的容量：";
   cin>>c;
   cout<<"请输入物品的个数：";
   cin>>n;
   cout<<"请分别输入物品的重量：";
   for(int i=0;i<n;i++)
   {
	   cin>>obj[i].w;
   }
   cout<<"请分别输入物品的价值：";
   for(int i=0;i<n;i++)
   {
	   cin>>obj[i].v;
   }
   subset(s,n);
   judge(s,obj,mark,n,c);
   max=getmax(mark,n,flag);
   outputObj(flag,s,n);
   cout<<"背包可容纳的最大价值为： "<<max<<endl;
   return 0;
}

