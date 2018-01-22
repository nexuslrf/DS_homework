#include<cstdio>
#include<iostream>
//A tricky thought: From LIS to LCS;
using namespace std;
//BInary search
int maps[100001];
int *a,*b;
int lower_bound(int *lst,int x,int len)
{
	int s=0,e=len-1;
	int mid=(s+e)>>1;
	while(s<e)
	{
		if(x==lst[mid])
			break;
		else if(x<lst[mid])
			e=mid;
		else
			s=mid+1;
		mid=(s+e)>>1;
	}
	if(x>lst[mid]) mid++;
	return mid;
}
int LIS(int *lst,int *note,int n)
{
	int len=1,p;
	note[0]=lst[0];
	for(int i=1;i<n;i++)
	{
		p=lower_bound(note,lst[i],len);
		if(p==len)
			note[len++]=lst[i];
		else
			note[p]=lst[i];
	}
	return len;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	a=new int[n+1];
	b=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		maps[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=maps[x];
	}
	printf("%d\n", LIS(a+1,b,n));
	delete[] a,b;
	return 0;
}