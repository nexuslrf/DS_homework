#include<cstdio>
#include<iostream>
using namespace std;
int dp[2000][2000];
int partition(int *a,int s,int e)
{
	int k=a[s];
	int i=s;
	for(int j=s+1;j<=e;j++)
	{
		if(a[j]<=k)
		{
			i++;
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	a[s]=a[i];
	a[i]=k;
	return i;
}
void quicksort(int *a,int s,int e)
{
	if(s>=e)
		return;
	int mid=partition(a,s,e);
	quicksort(a,s,mid-1);
	quicksort(a,mid+1,e);
}
int abs(int x)
{
	if(x<0)
		x*=-1;
	return x;
}
int main()
{
	int n,ans=2147483647;
	scanf("%d",&n);
	int *a=new int[n],*s=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=a[i];
	}
	quicksort(s,0,n-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				if(!j)
					dp[i][j]=abs(s[j]-a[i]);
				else
					dp[i][j]=min(abs(s[j]-a[i]),dp[i][j-1]);
			}
			else if(j==0)
				dp[i][j]=dp[i-1][j]+abs(s[j]-a[i]);
			else
				dp[i][j]=min(dp[i-1][j]+abs(s[j]-a[i]),dp[i][j-1]);
			if(i==n-1)
				ans=min(ans,dp[i][j]);
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(i==n-1)
			{
				if(!j)
					dp[i][j]=abs(s[j]-a[i]);
				else
					dp[i][j]=min(abs(s[j]-a[i]),dp[i][j-1]);
			}
			else if(j==0)
				dp[i][j]=dp[i+1][j]+abs(s[j]-a[i]);
			else
				dp[i][j]=min(dp[i+1][j]+abs(s[j]-a[i]),dp[i][j-1]);
			if(i==0)
				ans=min(ans,dp[i][j]);
			//printf("%d ", dp[i][j]);
		}
		//printf("\n");
	}
	printf("%d\n", ans);
	delete[] a,s;
}