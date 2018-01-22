//NOiP 2015 跳石子 a tricky solu
//我在最初考虑的时候是按线段长度来分析的，打算用贪心来解决
//可是在处理到所找到的最短段要删那一边的端点的时候普，发现了一个无法解决的bug
//EX： {7，5，3，4，6}（表示len）在m=1和m=2时的不同的处理方式
//Orz
//
//标程的思想：它既不针对点也不针对每一段的长度来处理！
//它通过二分的方式来寻找满足条件的最优解，判断二分的长度能否在删除量<m的情况下解决问题
//impressive ORZ!!!
#include<cstdio>
#include<iostream>
using namespace std;
int L,m,n;
int a[50010];
bool check(int x)
{
	int pre=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-pre<x)
			cnt++;
		else pre=a[i];
	}
	if(L-pre<x) cnt++;
	if(cnt>m) return 0;
	else return 1;
}
int main()
{
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int ls=0,rs=L,mid,ans;
	while(ls<=rs)
	{
		mid=(ls+rs)>>1;
		if(check(mid))
		{ls=mid+1;ans=mid;}
		else rs=mid-1;
	}
	printf("%d\n", ans);
}