#include<iostream>
#include<cstdio>
using namespace std;
struct Trie
{
	Trie *One,*Zero;
	//bool flag;
	Trie()
	{
		One=NULL;
		Zero=NULL;
		//flag=false;
	}
};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Trie *root=new Trie;
	Trie *p;
	int x,ans=0,temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		p=root;
		for(int i=30;i>=0;i--)
		{
			if((1<<i)&x)
			{
				if(!p->One)
					p->One=new Trie;
				p=p->One;
			}
			else
			{
				if(!p->Zero)
					p->Zero=new Trie;
				p=p->Zero;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		p=root;
		temp=0;
		for(int i=30;i>=0;i--)
		{
			if((1<<i)&x)
			{
				if(p->Zero)
				{
					p=p->Zero;
					temp+=(1<<i);
				}
				else
					p=p->One;
			}
			else
			{
				if(p->One)
				{
					p=p->One;
					temp+=(1<<i);
				}
				else
					p=p->Zero;
			}
		}
		ans=max(ans,temp);
	}
	printf("%d\n", ans);
	return 0;
}