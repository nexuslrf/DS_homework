#include<cstdio>
using namespace std;
int bs(int* &x,int s,int t,int num)
{
	if(s>=t)
	{
		return s;
	}
	int mid=(s+t)/2;
	if(x[mid]==num)
		return mid;
	else if(x[mid]>num)
		return bs(x,s,mid-1,num);
	else
		return bs(x,mid+1,t,num);
	
}
int main()
{
	int n,t,ans;
	scanf("%d",&n);
	scanf("%d",&t);
	int *x=new int[n];
	int *y=new int[t];
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(int i=0;i<t;i++)
		scanf("%d",&y[i]);
	for(int i=0;i<t;i++)
	{
		int indx=bs(x,0,n-1,y[i]);
		if(x[indx]>y[i])
			ans=n-indx;
		else
			ans=n-1-indx;
		printf("%d\n",ans);	
	}
	delete[] x;
	delete[] y;	
	return 0;
}
