#include<cstdio>
using namespace std;
int sumdg(int x)
{
	int sum=x%10;
	while(x)
	{
		x/=10;
		sum+=x%10;
	}
	return sum;
}
int power(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)
			ans*=x;
		y>>=1;
		x*=x;
		//printf("%d %d %d\n",ans,x,y);
	}
	return ans;
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int k,p,q,l,r;
	int ans[10000];
	scanf("%d %d %d",&k,&p,&q);
	scanf("%d %d",&l,&r);
	int cnt=0,x,t;
	for(int i=1;i<81;i++)
	{
		x=power(i,k)*p+q;
		if(x>=l&&x<=r&&sumdg(x)==i)
			ans[cnt++]=x;
	}
	printf("%d\n", cnt);
	if(cnt)
	{
		for(int i=0;i<cnt;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	else
		printf("-1");
	return 0;

}

