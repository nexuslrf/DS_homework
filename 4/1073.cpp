#include<cstdio>
using namespace std;
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
			temp[k++]=a[j++];
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
		temp[k++]=a[j++];
	for(int i=0;i<k;i++)
	{
		a[s+i]=temp[i];
	}
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
int main()
{
	int n;
	scanf("%d",&n);
	Node *v=new Node[n];
	int *w=new int[n];
	bool *alive=new bool[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
		v[i].val=w[i];
		v[i].pos=i;
		alive[i]=true;
	}
	mergesort(v,0,n-1);
	int ans=0;
	int m,t;
	for(int i=0;i<n-1;i++)
	{
		int p=v[i].pos;
		alive[p]=false;
		m=(n+p-1)%n;t=(p+1)%n;
		while(!alive[m])
		{

			m=(m-1+n)%n;
		}
		while(!alive[t])
			t=(t+1)%n;
		ans+=w[p]*w[m]*w[t];
		printf("%d\n", w[p]*w[m]*w[t]);
	}
	printf("%d", ans);
	delete[] v,w,alive;
}