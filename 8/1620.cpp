#include<iostream>
#include<cstdio>
//#include<cstring>
using namespace std;
const long long MOD=1000000007;
int treeArray[31][60001]={0};
int *a;
int N;
int lowbit(int x)
{
	return x&-x;
}
void update(int pos,int bit,int dx)
{
	while(pos<=N)
	{
		treeArray[bit][pos]+=dx;
		pos+=lowbit(pos);
	}
}
void exchange(int pos,int x)
{
	int temp=a[pos];
	a[pos]=x;
	bool b1,b2;
	for(int i=30;i>=0;i--)
	{
		b1=(1<<i)&x;b2=(1<<i)&temp;
		if((!b2)&&b1)
		{
			update(pos,i,1);
		}
		if(b2&&(!b1))
		{
			update(pos,i,-1);
		}
	}

}
void push(int x,int pos)
{
	for(int i=30;i>=0;i--)
	{
		if((1<<i)&x)
			update(pos,i,1);
	}
}
int sum(int pos,int bit)
{
	int ans=0;
	while(pos)
	{
		ans+=treeArray[bit][pos];
		pos-=lowbit(pos);
	}
	return ans;
}
long long getxor(int x,int y)
{
	long long ans=0;
	long long len=y-x+1;
	for(int i=30;i>=0;i--)
	{
		long long ones=sum(y,i)-sum(x-1,i);
		ans+=(1<<i)*(len-ones)*ones;
		ans=ans%MOD;
	}
	return ans;
}
int main()
{
	scanf("%d",&N);
	a=new int[N+1];
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		push(a[i],i);
	}
	int q;
	scanf("%d",&q);
	int op,x,y;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op)
			exchange(x,y);
		else
			printf("%d\n", getxor(x,y));
	}
	// cout<<endl;
	// for(int i=1;i<=N;i++)
	// {
	// 	int ans=0;
	// 	for(int j=0;j<31;j++)
	// 	{
	// 		if(sum(i,j)-sum(i-1,j))
	// 			ans+=1<<j;
	// 	}
	// 	cout<<"#"<<i<<" "<<ans<<"vs"<<a[i]<<" "<<ans-a[i]<<endl;
	// }
	return 0;
}