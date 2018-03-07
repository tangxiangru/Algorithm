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

