#include<iostream>
#include<cstring>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;
#define eps 1e-8
#define MAXN 10000000
#define N 5000
struct Point{
	double x,y;
};
Point S[N*2],S1[N],S2[N],P1[N],P2[N];

double Distance(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp1(Point a, Point b){
	return a.x<b.x;
}
int cmp2(Point a, Point b){
	return a.y<b.y;
}
double min(double a,double b){
	return a>b?b:a;
}
//分治法求最近对问题
double ClosestPoints1(Point S[],int n){
	int i,j,m;
	if (n<2)
		return MAXN;
	else{
		double d0=10000000;
		double d,d1,d2;
		int k1=0;
		int k2=0;
		int j1=0;
		int j2=0;
		sort(S,S+n,cmp1);
		Point p=S[n/2];
		m=p.x;		//m=S中各点x坐标的中位数
		for(i=0;i<(n+1)/2;i++){
			S1[j1].x=S[i].x;
			S1[j1].y=S[i].y;
			j1++;
		}		//构造S1中点的坐标小于m
		for(i=(n+1)/2;i<n;i++){
			S2[j2].x=S[i].x;
			S2[j2].y=S[i].y;
			j2++;
		}		//构造S2中点的坐标大于m
		d1=ClosestPoints1(S1,j1);
		d2=ClosestPoints1(S2,j2);
		d=min(d1,d2);
		for (i=0;i<j1;i++)
			if (m-S1[i].x<d){
				P1[k1].x=S1[i].x;
				P1[k1].y=S1[i].y;
				k1++;
			}		//构造P1为S1中点的坐标与m的距离小于d的点集
		for (i=0;i<j1;i++)
			if (S2[i].x-m<d){
				P2[k2].x=S2[i].x;
				P2[k2].y=S2[i].y;
				k2++;
			}		//构造P2为S2中点的坐标与m的距离小于d的点集
		sort(P1,P1+k1,cmp2);	//将P1中的点按y坐标升序排列
		sort(P2,P2+k2,cmp2);	//将P2中的点按y坐标升序排列
		for(i=0;i<k1;i++){
			for(j=0;j<k2;j++){
				double ans=Distance(P1[i],P2[j]);

			d0=min(d0,ans);	//求最小距离
			}
		}
		return d0;
	}
}
//蛮力法求最近对问题
double ClosestPoints2(Point S[],int n)
{
    double d0=MAXN;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
			double d=Distance(S[i],S[j]);
			if(d<d0)
			{
				d0=d;
			}
        }
    }
    return d0;
}
//测试两种算法
int main()
{
	int n=5000;
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		S[i].x=rand()/(double)(RAND_MAX/100000);
		S[i].y=rand()/(double)(RAND_MAX/100000);
	}  //产生随机点集
	clock_t start1,end1,start2,end2;
	start1=clock();
	double d1=ClosestPoints1(S,n);
	end1=clock();
	start2=clock();
	double d2=ClosestPoints2(S,n);
	end2=clock();
	cout<<"分治法求最近对问题运行时间："<<double(end1-start1)/CLOCKS_PER_SEC<<endl;
	cout<<"结果为"<<"  "<<d2<<endl;
	cout<<"蛮力法求最近对问题运行时间："<<double(end2-start2)/CLOCKS_PER_SEC<<endl;
	cout<<"结果为"<<"  "<<d2<<endl;
	return 0;
}
