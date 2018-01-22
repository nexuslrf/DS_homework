#include<iostream>
#include<cstdio>
using namespace std;
const int factor=100007;
struct slot
{
	int val;
	int cnt;
	slot *next;
	slot(int x)
	{
		val=x;
		cnt=1;
		next=NULL;
	}
};
int func(int x){return x%factor;}
int a[100000];
slot *note[100007];
int insert(int x)
{
	int idx=func(x);
	if(!note[idx])
	{
		note[idx]=new slot(x);
		return 1;
	}
	else
	{
		slot *p=note[idx];
		while(p&&p->val!=x)
			p=p->next;
		if(p)
			p->cnt++;
		else
		{
			p=new slot(x);
			p->next=note[idx];
			note[idx]=p;
		}
		return p->cnt;
	}
}
int query(int x)
{
	int idx=func(x);
	if(!note[idx])
	{
		return 0;
	}
	else
	{
		slot *p=note[idx];
		while(p&&p->val!=x)
			p=p->next;
		if(p)
			return p->cnt;
		else
			return 0;
	}
}
int del(int x)
{
	int idx=func(x);
	if(!note[idx])
	{
		return 0;
	}
	else
	{
		slot *p=note[idx];
		while(p&&p->val!=x)
			p=p->next;
		if(p)
			return --p->cnt;
		else
			return 0;
	}
}
int main()
{
	int n,k,ans=0;
	int start=0,cnt=0;
	//Queue list;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		int temp=insert(a[i]); //insert 返回该位置有多少个id 
		if(ans<temp) ans=temp;
		if(temp==1)
		{
			//list.enQueue(a[i]);
			cnt++;
		}
		if(cnt>k+1)
		{
			int i;
			for(i=start;;i++)
			{
				if(del(a[i])==0) //del 返回删除后还剩几个id
					break;
			}
			start=i+1;
			cnt--;
		}
	}
	printf("%d\n", ans);
}