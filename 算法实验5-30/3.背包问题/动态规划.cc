#include<iostream>
using namespace std;
//比较并返回两个数中的较大值
int max(int i,int j)
{
	if(i<j)
		return j;
	else
		return i;
}

int KnapSack (int w[],int v[],int x[],int n,int c)
{
	int i,j,V[105][1005]={0};
	for(i=0;i<=n;i++)
		V[i][0]=0;
	for(j=0;j<=c;j++)
		V[0][j]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(j<w[i])
				V[i][j]=V[i-1][j];
			else
				V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
		}
	}
	for(j=c,i=n;i>0;i--)                
	{
		if(V[i][j]>V[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		else x[i]=0;
	}
     return V[n][c];
}
int main()
{
	int c,n,w[105],v[105],x[105],max;//x[]记录物品的选择情况
	cout<<"请输入背包的重量：";
		cin>>c;
	cout<<"请输入物品的个数：";
		cin>>n;
    cout<<"请分别输入物品的重量：";
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cout<<"请分别输入物品的价值：";
	for(int i=1;i<=n;i++)
		cin>>v[i];
	max=KnapSack(w,v,x,n,c);
		cout<<"装入背包的物品编号为：";
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1)
			cout<<i<<" ";
	}
	cout<<endl;
	cout<<"背包可容纳的最大价值为："<<max<<endl;
	return 0;
}
