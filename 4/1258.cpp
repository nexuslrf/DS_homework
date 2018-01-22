#include<cstdio>
using namespace std;
int slot[100001];
struct Node
{
	int val;
	int idx;
	Node* next;
};
Node *link[100001];
int* radixsort(Node *a,int size)
{
	int maxi=0,mini=100001;
	int* pos=new int[size+1];
	for(int i=1;i<=size;i++)
	{
		slot[a[i].val]++;
		if(link[a[i].val])
		{
			(a+i)->next=link[a[i].val]->next;
			link[a[i].val]->next=a+i;
		}
		else
			link[a[i].val]=a+i;
		if(maxi<a[i].val)
			maxi=a[i].val;
		if(mini>a[i].val)
			mini=a[i].val;
	}
	int k=1;
	for(int i=mini;i<=maxi;i++)
	{
		if(slot[i])
		{
			for(int j=0;j<slot[i];j++)
			{
				pos[link[i]->idx]=k;
				link[i]=link[i]->next;
			}
			k++;
		}
	}
	pos[0]=k-1;
	return pos;
}
int lowbit(int x)
{
	return x&-x;
}
void update(int *a,int pos,int x,int size)
{
	while(pos<=size)
	{
		a[pos]+=x;
		pos+=lowbit(pos);
	}
}
int Nsum(int *a,int pos)
{
	int sum=0;
	while(pos)
	{
		sum+=a[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	Node *p=new Node[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].val);
		p[i].idx=i;
	}
	int *q=radixsort(p,n);
	// for(int i=1;i<=n;i++)
	// 	printf("%d", q[i]);
	int c=q[0];
	long long ans=0;
	int *tree=new int[c+1];
	for(int i=0;i<=c;i++) tree[i]=0;
	for(int i=1;i<=n;i++)
	{
		update(tree,q[i],1,c);
		ans+=i-Nsum(tree,q[i]);
	}
	printf("%lld", ans);
	delete[] p,q,tree;
	return 0;
}
