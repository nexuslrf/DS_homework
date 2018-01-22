#include<cstdio>
using namespace std;
int strlen(char s[])
{
	int len=0;
	while(s[len])
		len++;
	return len;
}
int main()
{
	char a[101],b[101];
	scanf("%s %s",a,b);
	int al=strlen(a),bl=strlen(b),up=0,temp,i;
	int n=al>bl?al:bl,loop=al<bl?al:bl;
	int pos=n;
	char *ans=new char[n+2];
	ans[n+1]=0;
	for(i=0;i<loop;i++)
	{
		temp=a[al-1-i]+b[bl-1-i]-194+up;
		ans[pos-i]=temp%26+'a';
		up=temp/26;
	}
	while(i<al)
	{
		temp=a[al-1-i]-97+up;
		ans[pos-i]=temp%26+'a';
		up=temp/26;
		i++;
	}
	while(i<bl)
	{
		temp=b[bl-1-i]-97+up;
		ans[pos-i]=temp%26+'a';
		up=temp/26;
		i++;
	}
	if(up)
		ans[pos-i++]='b';
	printf("%s\n", ans+n+1-i);
	delete[] ans;
}