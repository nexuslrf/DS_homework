#include<cstdio>
using namespace std;
int n;
void preorder(int *p,int *q,int *v,int root)
{
	printf("%d ", v[root]);
	if(p[root])
	{
		preorder(p,q,v,p[root]);
		int t=p[root];
		while(q[t])
		{
			preorder(p,q,v,q[t]);
			t=q[t];
		}
	}
}
void postorder(int *p,int *q,int *v,int root)
{
	if(p[root])
	{
		postorder(p,q,v,p[root]);
		int t=p[root];
		while(q[t])
		{
			postorder(p,q,v,q[t]);
			t=q[t];
		}
	}
	printf("%d ", v[root]);
}
void seqorder(int *p,int *q,int *v,int root)
{
	int *temp=new int[n+1];
	temp[1]=root;
	int tail=2,head=1,t;
	while(head!=tail)
	{
		t=p[temp[head]];
		if(t)
		{
			temp[tail++]=t;
			while(q[t])
			{
				t=q[t];
				temp[tail++]=t;
			}
		}
		head++;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ", v[temp[i]]);
	}
}
int main()
{
	scanf("%d",&n);
	int *p=new int[n+1],*q=new int[n+1],*v=new int[n+1],*flag=new int[n+1];
	for(int i=1;i<=n;i++)
		flag[i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&p[i],&q[i],&v[i]);
		flag[p[i]]=1;
		flag[q[i]]=1;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			root=i;
			break;
		}
	preorder(p,q,v,root);
	printf("\n");
	postorder(p,q,v,root);
	printf("\n");
	seqorder(p,q,v,root);
}