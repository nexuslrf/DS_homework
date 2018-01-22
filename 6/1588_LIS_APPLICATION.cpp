#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,ans1=0,ans2=0;
	scanf("%d",&n);
	int *dp1=new int[n],*dp2=new int[n],*a=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i); dp1[i]=dp2[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[i]) dp1[i]=max(dp1[i],dp1[j]+1);
			if(a[j]<=a[i]) dp2[i]=max(dp2[i],dp2[j]+1); 
		}
		ans1=max(ans1,dp1[i]);
		ans2=max(ans2,dp2[i]);
	}
	printf("%d\n%d", ans1,ans2);
	delete[] dp1,dp2;
	return 0;
}