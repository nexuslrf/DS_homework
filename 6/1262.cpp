#include<cstdio>
#include<iostream>
using namespace std;
struct interval
{
	int t1,t2;
};
int partition(interval *a,int s,int e)
{
	interval temp=a[s];
	int i=s;
	for(int j=s+1;j<=e;j++)
	{
		if(a[j].t1<=temp.t1)
		{
			i++;
			interval t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	a[s]=a[i];
	a[i]=temp;
	return i;
}
void quicksort(interval *a,int s,int e)
{
	if(s>=e) return;
	int mid=partition(a,s,e);
	quicksort(a,s,mid-1);
	quicksort(a,mid+1,e);
}
int main()
{
	int n;
	int ans1=0,ans2=0;
	scanf("%d",&n);
	interval *list=new interval[n];
	for(int i=0;i<n;i++) scanf("%d%d",&list[i].t1,&list[i].t2);
	quicksort(list,0,n-1);
	interval note;
	note=list[0];
	ans1=note.t2-note.t1;
	for(int i=1;i<n;i++)
	{
		if(list[i].t1<=note.t2)
			note.t2=max(note.t2,list[i].t2);
		else
		{
			ans2=max(ans2,list[i].t1-note.t2);
			note=list[i];
		}
		ans1=max(ans1,note.t2-note.t1);
	}
	printf("%d %d", ans1,ans2);
	return 0;
}