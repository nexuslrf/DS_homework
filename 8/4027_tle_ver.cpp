#include<cstdio>
#include<iostream>
using namespace std;
int dp[2][100001];
int main()
{
	int n;
	scanf("%d",&n);
	int *a=new int[n+1],*b=new int[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
				dp[i%2][j]=dp[(i-1)%2][j-1]+1;
			else
				dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
		}
	}
	printf("%d\n", dp[n%2][n]);
	delete[] a,b;
	return 0;
}