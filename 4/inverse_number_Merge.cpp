#include<cstdio>
using namespace std;
int ans=0;
void merge(int *a,int s,int e,int mid)
{
	int *temp=new int[e-s+1];
	int i=s,j=mid+1,k=0;
	while(i<=mid&&j<=e)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
		{
			temp[k++]=a[j++];
			ans+=mid+1-i;
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
void mergesort(int *a,int s,int e)
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
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("%d\n", ans);
	return 0;
}