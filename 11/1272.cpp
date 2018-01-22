#include<iostream>
#include<cstdio>
using namespace std;
int n;
int note[200];
int arr[200];
int divs(int x,int y)
{
	int a,b;
	if(x<y){a=y;b=x;}
	else{a=x;b=y;}
	return a/b;
}
void update(int x)
{
	//cout<<"+"<<x<<'\n';
	int temp=n,p;
	arr[n++]=x;
	note[x]++;
	for(int i=0;i<temp;i++)
	{
		p=divs(x,arr[i]);
		if(!note[p])
		{
			update(p);
		}
	}
}
int main()
{
	int p,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		note[arr[i]]++;
	}
	temp=n;
	for(int i=0;i<temp;i++)
	{
		for(int j=i+1;j<temp;j++)
		{
			p=divs(arr[i],arr[j]);
			if(!note[p]) update(p);
		}
	}
	printf("%d\n", n);
} 