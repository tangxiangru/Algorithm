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
