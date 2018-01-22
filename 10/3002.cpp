#include<cstdio>
#include<iostream>
using namespace std;
int note[1001];
int maxi=0,mini=1001;
int main()
{
	int n,x,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x<mini) mini=x;
		if(x>maxi) maxi=x;
		if(!note[x])
		{
			cnt++;
			note[x]=1;
		}
	}
	printf("%d\n", cnt);
	for(int i=mini;i<=maxi;i++)
		if(note[i])
			printf("%d ", i);
}