#include<cstdio>
using namespace std;
int maxi(int a,int b)
{
	return a>b?a:b;
}
int search(int *b,int s,int e,int x)
{
	int mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(b[mid]<x) s=mid+1;
		else e=mid-1;
	}
	if(b[s]<x)
		return s;
	else return s-1;
}//二分 DP;
int main()
{
	int n,idx=1;
	scanf("%d",&n);
	int *note=new int[n],*a=new int[n],*b=new int[n],max=0;
	b[0]=10000000;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		int j=search(b,0,idx-1,a[i]);
		//printf("%d\n", j);
		if(j==idx-1&&b[j]<a[i])
		{
			b[idx++]=a[i];
		}
		else if(b[j+1]>a[i])
			b[j+1]=a[i];
	}

	/*	int j=idx-1;
		note[idx]=1;
		while(j>=0)
		{
			if(a[j]<a[idx])
				note[idx]=maxi(1+note[j],note[idx]);
			else if(a[j]==a[idx])
			{
				idx--;
				break;
			}
			j--;
		}
		if(note[idx]>max)
			max=note[idx];
		printf("%d\n", note[idx]);
		idx++;*/  //O(n^2) dp;
	printf("%d", idx);
	delete[] a,note,b;
	return 0;
}