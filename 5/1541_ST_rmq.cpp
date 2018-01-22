#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int rmq[200000][20];
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&rmq[i][0]);
	}
	int i=1;
	while(1<<i<=n)
	{
		for(int j=0;j<(n-(1<<i)+1);j++)
		{
			rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
		}
		i++;
	}
	int j=0;
	while(k>(1<<j)) j++;
		j--;
	for(i=k-1;i<n;i++)
	{
		printf("%d ", max(rmq[i-k+1][j],rmq[i-(1<<j)+1][j]));
	}
	return 0;
}