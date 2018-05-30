#include<iostream>
#include<stdio.h>
using namespace std;

//物品结构体
struct _Object
{
 int Value;
 int Weight;
 double AveValue;
 double Num;
 int key;
};

int Partition(_Object r[],int first,int end){
	int i=first,j=end;
	while(i<j)
	{
		while(i<j&&r[i].AveValue>r[j].AveValue)
			j--;
		if(i<j)
		{
		   _Object temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			i++;
		}
		while(i<j &&r[i].AveValue>r[j].AveValue)
			i++;
		if(i<j)
		{
			_Object temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			j--;
		}
	}
	return i;
}

//快速排序
void QuickSort(_Object r[],int first,int end){
	int pivot;
	if(first<end){
	pivot=Partition(r,first,end);
	QuickSort(r,first,pivot-1);
	QuickSort(r,pivot+1,end);
	}
}
double knaspsack(int n,int M,_Object object[]) //n为物品个数，M为背包容量
{
    int i;
    int C=M;
    double maxValue=0;
    for(i=0;object[i].Weight<C;i++)
    {
        object[i].Num=1;
        maxValue+=object[i].Value;
        C=C-object[i].Weight;
    }
    object[i].Num=(double)C/object[i].Weight;
    maxValue+=object[i].Num*object[i].Value;
    return maxValue;

}
int main()
{
	   int n,c;
  	_Object pro[1001];
    cout<<"背包的容量： ";
    cin>>c;
    cout<<"请输入物品的个数：";
    cin>>n;
    cout<<"请分别输入物品的重量和价值：";
for(int i=0;i<n;i++)
  {
		    cin>>pro[i].Weight>>pro[i].Value;
		    pro[i].AveValue=(double)pro[i].Value/pro[i].Weight;
		    pro[i].Num=0;
		    pro[i].key=i;
	 }
    QuickSort(pro,0,n-1);
    double maxValue=knaspsack(n,c,pro);
    cout<<"背包的可容纳的最大价值为：";
    printf("%.2f",maxValue);
    cout<<endl;
    int k;
    cout<<"各个物品装入背包的重量分别为：";
    for(k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
	       {
		       if(pro[j].key==k)       //找到原来顺序的物品编号
			   cout<<pro[j].Weight*pro[j].Num<<" ";
	       }
    }
   cout<<endl;
   return 0;
}
