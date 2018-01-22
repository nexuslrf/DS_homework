#include<cstdio>
#include<iostream>
using namespace std;
int p[100001];
int main()
{
	char a[1000001],b[100001];
	scanf("%s%s",a,b);
	int i=1,j=0,len;
	p[0]=-1;
	int k;
	while(b[i])
	{
		k=p[i-1];
		while(k!=-1&&b[k+1]!=b[i])
		{
			k=p[k];
		}
		if(b[k+1]==b[i])
			p[i]=k+1;
		else
			p[i]=-1;
		i++;
	}
	len=i;
	i=-1; j=-1;
	int pos=0;
	while(a[i+1]&&b[j+1])
	{
		if(a[i+1]==b[j+1])
		{
			i++;j++;
		}
		else
		{
			j=p[j];
			if(j==-1) i++;
			pos=i-j;
		}
		//cout<<i<<" "<<j<<" "<<pos<<endl;
	}
	printf("%d\n", pos);
	return 0;
}