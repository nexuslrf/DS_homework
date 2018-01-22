#include<cstdio>
#include<iostream>
using namespace std;
int cnt_Q=0,cnt_M=0,cnt_H=0;
int partition(int *array,int s,int e)
{
	int temp=array[s];
	int i=s+1;
	for(int j=s+1;j<=e;j++)
	{
		if(array[j]<=temp)
		{
			int t=array[i];
			array[i++]=array[j];
			array[j]=t;
		}
		cnt_Q++;
	}
	i--;
	array[s]=array[i];
	array[i]=temp;
	return i;
}
void Qsort(int *array,int s,int e)
{
	if(s>=e) return;
	int mid=partition(array,s,e);
	Qsort(array,s,mid-1);
	Qsort(array,mid+1,e);
}
void merge(int *array,int s,int e,int mid)
{
	int temp[10001];
	int i=s,j=mid+1,idx=0;
	while(i<=mid&&j<=e)
	{
		if(array[i]<=array[j]) temp[idx++]=array[i++];
		else temp[idx++]=array[j++];
		cnt_M++;
	}
	while(i<=mid) temp[idx++]=array[i++];
	while(j<=e) temp[idx++]=array[j++];
	for(int i=0;i<idx;i++)
		array[i+s]=temp[i];
}
void mergesort(int *array,int s,int e)
{
	if(s>=e) return;
	int mid=s-1+(e-s+1)/2;
	mergesort(array,s,mid);
	mergesort(array,mid+1,e);
	merge(array,s,e,mid);
}
void percolateDown(int *heap,int hole,int n)
{
	int child;
	int temp=heap[hole];
	while(hole*2<=n)
	{
		child=hole*2;
		if(child<n)
		{
			cnt_H++;
			if(heap[child]>heap[child+1])
			{
				child+=1;
			}
		}
		cnt_H++;
		if(temp>heap[child])
		{
			heap[hole]=heap[child];
			hole=child;
		}
		else break;
	}
	heap[hole]=temp;
}
void heapsort(int *array,int s,int e)
{
	int heap[10001],idx=0;
	heap[++idx]=array[s];
	for(int i=s+1;i<=e;i++)
	{
		int hole=++idx;
		int temp=array[i],parent;
		while(hole>>1)
		{
			parent=hole>>1;
			cnt_H++;
			if(heap[parent]>temp)
			{
				heap[hole]=heap[parent];
				hole=parent;
			}
			else break;
		}
		heap[hole]=temp;
	}
	for(int i=s;i<=e;i++)
	{
		array[i]=heap[1];
		heap[1]=heap[idx--];
		percolateDown(heap,1,idx);
	}
}
int a[10001];
int main()
{
	while(true){
	int n,k,ans;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	switch(k)
	{
		case 1:heapsort(a,0,n-1);ans=cnt_H;break;
		case 2:mergesort(a,0,n-1);ans=cnt_M;break;
		case 3:Qsort(a,0,n-1);ans=cnt_Q;break;
	}
	cnt_Q=cnt_M=cnt_H=0;
	printf("%d\n", ans);
}
}