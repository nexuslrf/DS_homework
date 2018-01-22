#include<cstdio>
using namespace std;
int n; 
struct Node
{
	int val;
	int pos;
};
void merge(Node *a,int s,int e,int mid)
{
	Node *temp=new Node[e-s+1];
	int i=s,j=mid+1,k=0;
	while(i<=mid&&j<=e)
	{
		if(a[i].val<a[j].val)
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			//ans+=mid+1-i;
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=e)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[s+i]=temp[i];
	delete[] temp;
}
void mergesort(Node *a,int s,int e)
{
	if(s==e)
		return;
	int mid=(s+e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	merge(a,s,e,mid);
}
int lowbit(int x)
{
	return x&-x;
}
void update(int *a,int pos,int x)
{
	while(pos<=n)
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
	scanf("%d",&n);
	Node *a=new Node[n];
	int *note=new int[n];
	int *tree=new int[n+1];
	tree[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i].pos=i;
		tree[i+1]=0;
	}
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		note[a[i].pos]=i+1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		update(tree,note[i],1);
		ans+=i-Nsum(tree,note[i])+1;
	}
	printf("%d\n", ans);
	return 0;
}