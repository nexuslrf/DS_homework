#include<cstdio>
#include<iostream>
using namespace std;
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
int good[10001],bad[10001];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",good+i);
	for(int i=0;i<m;i++)
		scanf("%d",bad+i);
	Qsort(good,0,n-1);
	Qsort(bad,0,m-1);
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(good[i]>bad[j])
		{
			j++;
			ans++;
		}
		i++;
	}
	printf("%d\n", ans+n);
}