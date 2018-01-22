#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int a[2000001],heap[2000001][3],n,m;//heap 1 val 2 pos 3 modify date
void percolateDown(int hole) //attention to map & d_copy
{
	int temp=heap[hole][0],pos=heap[hole][1],date=heap[hole][2];
	int child;
	while(hole<<1<=n)
	{
		child=hole<<1;
		if(child<n)
			if(heap[child+1][0]<heap[child][0])	child+=1;
			else if(heap[child+1][0]==heap[child][0]&&heap[child+1][2]>heap[child][2]) child+=1;
		if(temp>heap[child][0]||(temp==heap[child][0]&&date<heap[child][2]))
		{
			heap[hole][0]=heap[child][0];
			heap[hole][1]=heap[child][1];
			heap[hole][2]=heap[child][2];
			a[heap[hole][1]]=hole;
			hole=child;
		}
		else break;

	}
	heap[hole][0]=temp;
	heap[hole][1]=pos;
	heap[hole][2]=date;
	a[pos]=hole;
}
void percolateUp(int hole)
{
	int temp=heap[hole][0],pos=heap[hole][1],date=heap[hole][2];
	int parent;
	while(hole>>1)
	{
		parent=hole>>1;
		if(temp<=heap[parent][0])
		{
			heap[hole][0]=heap[parent][0];
			heap[hole][1]=heap[parent][1];
			heap[hole][2]=heap[parent][2];
			a[heap[hole][1]]=hole;
			hole=parent;
		}
		else break;
	}
	heap[hole][0]=temp;
	heap[hole][1]=pos;
	heap[hole][2]=date;
	a[pos]=hole;
}
void build_heap()
{
	for(int i=n/2;i>0;i--)
		percolateDown(i);
}
int main()
{
	freopen("1990.in","r",stdin);
	scanf("%d%d",&n,&m);
	int date=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&heap[i][0]);
		heap[i][1]=i;
		heap[i][2]=date++;
		a[i]=i;
	}
	build_heap();
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		heap[a[x]][0]+=y;
		heap[a[x]][2]=date++;
		if(y>0) percolateDown(a[x]);
		if(y<0) percolateUp(a[x]);
		printf("%d\n", heap[1][1]);
	}
	return 0;
}