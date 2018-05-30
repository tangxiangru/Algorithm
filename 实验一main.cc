#include <stdio.h>
//#include"实验一_版本一.h"
//#include"实验一_版本二.h"
//#include"实验一_版本三.h"
#include <stdlib.h>
#include <time.h>
//蛮力法
int CommFactor2(int a, int b);
int CommFactor3(int a, int b);
int CommFactor1(int m,int n){
        int i,factor=1;
        for(i=2;i<=m && i<=n;i++)
        {
            while(m%i==0 && n%i == 0)
            {
                while(m%i==0 && n%i==0)
                {
                    factor=factor*i;
                    m=m/i;
                    n=n/i;
                }
            }
        }
        return factor;
}
//辗转相除法(非递归)
//有两整数a和b：1 a%b得余数c;2 若c=0，则b即为两数的最大公约数;3 若c≠0，则a=b，b=c，再回去执行1.

int CommFactor2(int a, int b)
{
	int c = a%b;
	while(c != 0)
	{
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}
/* 更相减损法
有两整数a和b：
	1 若a>b，则a=a-b;
	2 若a<b，则b=b-a;
	3 若a=b，则a（或b）即为两数的最大公约数;
	4 若a≠b，则再回去执行1.
*/
int CommFactor3(int a, int b)
{
	while(a != b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main()
{
	int a[1000],b[1000];
	int c,i,j;
    srand(time(NULL)); /*初始化种子*/
    for(i=0; i < 1000; i++ ){
		a[i]=rand()%1001;
		b[i]=rand()%1001;
	}
	printf("%d %d",a[2],a[10]);
	
	for(i=0; i < 1000; i++){
		c = CommFactor2(a[i], b[i]);	
	}	
    clock_t start, finish;
    double duration;
	start = clock();
	//c = CommFactor2(a, b);	
	// 穷举法
    //c = CommFactor3(a, b);
	
	finish = clock();
    duration = 10000*(double)(finish-start) / CLOCKS_PER_SEC;
 	printf("elasped time : %f seconds\n", duration);
	//运行1000次算法，取平均运行时间
	return 0;
}
