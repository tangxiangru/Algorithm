#include <iostream>
#include"实验一_版本一.h"
#include"实验一_版本二.h"
#include"实验一_版本三.h"
#include <stdlib.h>
#include <time.h>
/*
        int a[1000];
        int i;
        srand(time(0)); /*初始化种子*/
//        for( i = 0; i < 1000; i++ ) a[i]=rand();   



int main()
{
	int a, b, c;
	printf("Please input two integer numbers(a, b):");
	scanf("%d%d", &a, &b);
	
	
	c = CommFactor1(a, b);
	//c = CommFactor2(a, b);	
	// 穷举法
    //c = CommFactor3(a, b);
	
	printf("The greatest common divisor bewteen(%d, %d) is %d\n", a, b, c);
	return 0;
}

