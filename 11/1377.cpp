#include<iostream>
#include<cstdio>
using namespace std;
int a[100001];
int t[200010];
int *delta=t+100000; //delta=high-low LOL +_+
int n,b;
int main()
{
	int pos,ans=0;
	int hcnt=0,lcnt=0;
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]==b) pos=i;
	}
	delta[0]=1;
	for(int i=pos-1;i;i--)
	{
		if(a[i]<b) lcnt++;
		else hcnt++;
		delta[hcnt-lcnt]++;
	}
	int temp=delta[0];
	ans+=temp;
	lcnt=hcnt=0;
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]<b) lcnt++;
		else hcnt++;
		ans+=delta[lcnt-hcnt];
	}
	printf("%d\n", ans);
}