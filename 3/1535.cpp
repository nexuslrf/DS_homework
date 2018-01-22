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
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int k,p,q,l,r;
	int ans[100000];
	scanf("%d %d %d",&k,&p,&q);
	scanf("%d %d",&l,&r);
	int cnt=0,x=l,t,res;
	while(x<=r)
	{
	//	printf("%d %d\n",x,cnt);
		if(x-q<=0||(x-q)%p!=0)
		{
			x++;
			continue;
		}
		t=sumdg(x);
		res=(x-q)/p;
		int temp=k;
		if(res==1&&t==1)
			ans[cnt++]=x;
		while(t!=1&&res%t==0)
		{
			//printf("%d\n", temp);
			if(temp&1)
				res/=t;
			temp>>=1;
			if(temp==0&&res==1)
			{
				
				ans[cnt++]=x;
				break;
			}
			t*=t;
			while(!(temp&1))
			{
				t*=t;
			//	printf("%d\n", temp);
				temp>>=1;
			}
			
		}
		x++;
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
