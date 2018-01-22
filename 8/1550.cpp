#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	char ch;
	scanf("%d",&n);
	int *a=new int[n],*pos=new int[n];
	int ans=0,temp=0,back=0,cnt=0,mm=0;
	int left=0,right=0;
	scanf("\n%c",&ch);
	//cout<<ch<<endl;
	for(int i=0;i<n;i++)
	{
		scanf("%d%c",a+i,&ch);
		scanf("%d",a+i);
		//cout<<a[i]<<" "<<ch<<endl;
		if(a[i]>mm)
		{
			mm=a[i];
			cnt=0;
			pos[cnt++]=i;
		}
		else if(a[i]==mm)
		{
			pos[cnt++]=i;
		}

	}
	scanf("%c",&ch);
	for(int i=0;i<=pos[0];i++)
		if(left<a[i])
		{
			left=a[i];
			ans+=temp;
			temp=0;
		}
		else
		{
			temp+=(left-a[i]);
		}
	temp=0;
	for(int i=n-1;i>=pos[cnt-1];i--)
		if(right<a[i])
		{
			right=a[i];
			ans+=temp;
			temp=0;
		}
		else
		{
			temp+=(right-a[i]);
		}
	for(int i=1;i<cnt;i++)
	{
		for(int j=pos[i-1];j<=pos[i];j++)
		{
			ans+=(mm-a[j]);
		}
	}
	printf("%d\n", ans);
	delete[] pos,a;
	return 0;
}