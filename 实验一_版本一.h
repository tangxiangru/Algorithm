//蛮力法
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
