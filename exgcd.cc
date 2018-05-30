    //求最大公约数的线性组合（扩展欧几里得）
    #include<stdio.h>  
    int x,y;  
    int gcd(int a,int b)  
    {                   //欧几里得算法求最大公约数  
        if(b==0)  
            return a;  
        return  
            gcd(b,a%b);  
    }  
    int exgcd(int a,int b)  
    {                       //扩展欧几里得算法  
        if(b==0)  
        {  
            x=1;  
            y=0;  
            return a;  
        }  
        int r=exgcd(b,a%b);  
        int t=x;  
        x=y;  
        y=t-a/b*y;  
        return r;  
    }  
    int main()  
    {  
        int a,b;  
        scanf("%d%d",&a,&b);  
        int d=exgcd(a,b);  
        int c=gcd(a,b);  
        int k=c/d;  
        if(y*k>0)  
        printf("%d*%d+%d*%d=%d\n",a,x*k,b,y*k,c);  
        else  
            printf("%d*%d%d*%d=%d\n",a,x*k,y*k,b,c);  
        return 0;  
    }  