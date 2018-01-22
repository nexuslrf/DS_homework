#include<cstdio>
using namespace std;
int getOnes(int x)
{
	int sum=0;
	while(x)
	{
		if(x&1) sum++;
		x>>=1;
	}
	return sum;
}
int main()
{
	int n,k;
	int ans,tmp;
	scanf("%d%d",&n,&k);
	ans=n;
	while(k<getOnes(n))
	{
		tmp=(n&-n);
		n+=tmp;
	}
	if(k>ans) printf("%d", k-ans);
	else printf("%d", n-ans);
	return 0;
}