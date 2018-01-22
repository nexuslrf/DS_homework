#include<cstdio>
#include<iostream>
using namespace std;
const int INT_MAXI=10000000;
int dpA[100001]={};
int dpS[100001]={};
struct skill
{
	int mp;
	int damage;
};
void compeleteKnapsack(int *a,skill *list,int n,int mhp)
{
	for(int i=1;i<=mhp;i++) a[i]=INT_MAXI;
	a[0]=0;
	for(int i=0;i<n;i++)
	{
		int k=1;
		for(int j=1;j<=mhp;j++)
		{
			if(i==0)
			{
				if(j<k*list[i].damage) a[j]=k*list[i].mp;
				if(j==k*list[i].damage) a[j]=k++*list[i].mp;
			}
			else
			{
				if(j<=list[i].damage) a[j]=min(a[j],list[i].mp);
				else
					a[j]=min(a[j],a[j-list[i].damage]+list[i].mp);
			}
		}
	}
}
int main()
{
	freopen("233.in","w",stdin);
	int n,m,mhp=0;
	scanf("%d",&n);
	int *Hps=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",Hps+i);
		mhp=max(mhp,Hps[i]);
	}
	scanf("%d",&m);
	skill *listA=new skill[m],*listS=new skill[m];
	char name[31],tag[10];
	int mps,d,na=0,ns=0;
	for(int i=0;i<m;i++) 
	{
		scanf("%s%d%s%d",name,&mps,tag,&d);
		if(d==0) continue;
		if(tag[0]=='A')
		{
			listA[na].mp=mps;
			listA[na++].damage=d;
		}
		else
		{
			listS[ns].mp=mps;
			listS[ns++].damage=d;
		}
	}
	compeleteKnapsack(dpA,listA,na,mhp);
	compeleteKnapsack(dpS,listS,ns,mhp);
	// for(int i=0;i<=mhp;i++) cout<<dpA[i]<<" ";
	// 	cout<<endl;
	// for(int i=0;i<=mhp;i++) cout<<dpS[i]<<" ";
	// 	cout<<endl;
	int ans=INT_MAXI;
	if(na)
		for(int i=0;i<=mhp;i++)
		{
			int sum=dpA[i];
			for(int j=0;j<n;j++)
			{	
				if(Hps[j]>i)
					sum+=dpS[Hps[j]-i];
			}
			ans=min(ans,sum);
		}
	else 
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=dpS[Hps[j]];
		}
		ans=sum;
	}
	printf("%d", ans);
	delete[] Hps;
	return 0;
}
