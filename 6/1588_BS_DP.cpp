#include<cstdio>
using namespace std;
int search(int *b,int s,int e,int x)
{
	int mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(b[mid]>x) s=mid+1;
		else e=mid-1;
	}
	if(b[s]>x)
		return s;
	else return s-1;
}
int search2(int *b,int s,int e,int x)
{
	int mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(b[mid]<=x) s=mid+1;
		else e=mid-1;
	}
	if(b[s]<=x)
		return s;
	else return s-1;
}
int main()
{
	int n,idx=1;
	scanf("%d",&n);
	int *a=new int[n],*b=new int[n];
	b[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		int j=search(b,0,idx-1,a[i]);
		if(j==idx-1&&b[j]>a[i])
			b[idx++]=a[i];
		else if(b[j+1]<a[i])
			b[j+1]=a[i];
	}
	int idx2=1;
	b[0]=2147483647;
	for(int i=0;i<n;i++)
	{
		int j=search2(b,0,idx2-1,a[i]);
		if(j==idx2-1&&b[j]<=a[i])
			b[idx2++]=a[i];
		else if(b[j+1]>a[i])
			b[j+1]=a[i];
	}
	printf("%d\n%d", idx,idx2);
	delete[] a,b;
	return 0;
}