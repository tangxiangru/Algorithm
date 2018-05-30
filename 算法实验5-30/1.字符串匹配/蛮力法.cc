#include <iostream>
#include <cstring>
using namespace std;
int  BruteStringMatch(char *,char * );
int main()
{
	char s[40];
	char t[10];
	int location;
	cout<<"enter s:\n";
	cin.getline(s,39);
	cout<<"enter t:\n";
	cin.getline(t,9);
	location=BruteStringMatch(s,t);
	if (location!=-1)
	cout<<"t is in"<<location<<"of s.\n";
	else
	cout<<"can not match t from s.\n";


	return 0;

}
int BruteStringMatch(char *s,char* t)
{
	int i=0,j=0;
	int slen=strlen(s);
	int tlen=strlen(t);
	while (i<slen&&j<tlen)
	{
		if (s[i++]!=t[j++])
		j=0;
		else
		{
		 i++;
		 j++;
	    }
	}
	if (i==slen)
	return -1;
	else
	return (i-j)+1;
}
