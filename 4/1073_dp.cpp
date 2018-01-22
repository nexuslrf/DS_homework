#include<cstdio>
//#include<iostream>
using namespace std;
int note[100][100];
int n,maxi;
int find(int *d,int s,int e,int p)
{
	if(s==e)
		return 0;
	if(note[(s+p)%n][(e+p)%n])
		return note[(s+p)%n][(e+p)%n];
	int mx=0;
	for(int i=s;i<e;i++)
	{
		int temp=find(d,s,i,p)+find(d,i+1,e,p)+d[(s+p)%n]*d[(i+1+p)%n]*d[(e+p+1)%n];
		if(temp>mx)
			mx=temp;
	}
	note[(s+p)%n][(e+p)%n]=mx;
	return mx;
}
int main()
{
	scanf("%d",&n);
	int *v=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	maxi=0;
	for(int i=0;i<n;i++)
		if(maxi<find(v,0,n-1,i))
			maxi=find(v,0,n-1,i);
	printf("%d", maxi);
	delete[] v;
	return 0;
}