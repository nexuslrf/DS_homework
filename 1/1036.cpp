#include<iostream>
using namespace std;
int a[100000];
int maxi(int x[],int n)
{
	int t=0;
	for(int i=0;i<n;i++)
		if(t<x[i])
			t=x[i];
	return t;
}
long long maxi(long long x[],int n)
{
	long long t=0;
	for(int i=0;i<n;i++)
		if(t<x[i])
			t=x[i];
	return t;
}
long long mini(long long x[],int n)
{
	long long t=x[0];
	for(int i=0;i<n;i++)
		if(t>x[i])
			t=x[i];
	return t;
}
int main()
{
	int n;
	long long w1=0,w2=0,t1=0,t2=0;
	long long counter[3]={0,0,0};
	long long w[3]={0,0,0};
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n<=3)
	{
		int t=maxi(a,n);
		cout<<0<<' '<<t<<endl;
		cout<<0<<' '<<t<<endl;
		return 0;
	}
	for(int i=3;i<n;i++)
	{
		w[i%3]=a[i-3]+counter[i%3];
		counter[i%3]=w[i%3];
		w1+=w[i%3];
		w[i%3]+=a[i];
	}
	for(int i=0;i<3;i++)
	{
		counter[i]=a[i];
	}
	t1=maxi(w,3);
	cout<<w1<<" "<<t1<<endl;
	int cnt=3;
	long long ti=0,cut,tempt;
	t2=maxi(a,3);
	while(cnt<n)
	{
		cut=mini(counter,3);
		ti+=cut;
		for(int i=0;i<3;i++)
		{
			counter[i]-=cut;
			if(counter[i]==0&&cnt<n)
			{
				counter[i]=a[cnt];
				w2+=ti;
				tempt=ti+a[cnt++];
				if(tempt>t2)
					t2=tempt;
			}
		}
	} 
	cout<<w2<<" "<<t2;
	return 0;
	
} 
