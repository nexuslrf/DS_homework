#include<iostream>
#include<cstdio>
//#include<cstring>
using namespace std;
const int MOD=1000000007;
long long *treeArray;
int N;
int lowbit(int x)
{
	return x&-x;
}
void update(int pos,int dx)
{
	while(pos<=N)
	{
		treeArray[pos]+=dx;
		pos+=lowbit(pos);
	}
}
long long sum(int pos)
{
	long long ans=0;
	while(pos)
	{
		ans+=treeArray[pos];
		pos-=lowbit(pos);
	}
	return ans;
}
int cnt[31];
int idx;
long long getin(int x)
{
	int sum=0;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			sum+=(1<<i)*(idx-cnt[i]);
			cnt[i]++;
		}
		else
		{
			sum+=(1<<i)*cnt[i];
		}
	}
	idx++;
	return sum;
}
int main()
{
	scanf("%d",&N);
	if(N>100) return 0;
	int *a=new int[N+1];
	treeArray=new long long[N+1];
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		//update(i,getin(a[i],i));
	}
	int q;
	scanf("%d",&q);
	int op,x,y;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op)
			a[x]=y;
		else
			{
				long long ans=0;
				for(int i=0;i<31;i++) cnt[i]=0;
				idx=0;
				for(int i=x;i<=y;i++)
				{
					ans+=getin(a[i]);
				}
				printf("%d\n", ans%MOD);
			}
	}
	return 0;
}