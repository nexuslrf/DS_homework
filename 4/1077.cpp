#include<cstdio>
//#include<iostream>
using namespace std;
struct datas
{
	int val;
	int list[30];
};
int n;
datas note[30][30];//ij 之间的最优
int find(int *d,int s,int e)
{
	if(s>e)
	{
		//cout<<s<<" "<<e<<" "<<1<<endl;
		return 1;
	}
	if(s==e)
	{
		//cout<<s<<" "<<e<<" "<<d[s]<<endl;
		note[s][e].val=d[s];
		note[s][e].list[0]=s;
		return d[s];
	}
	if(note[s][e].val)
	{
		//cout<<s<<" "<<e<<" "<<note[s][e].val<<endl;
		return note[s][e].val;
	}
	int max=0;
	for(int i=s;i<=e;i++)
	{
		int temp=find(d,s,i-1)*find(d,i+1,e)+d[i];
		if(temp>max)
		{
			max=temp;
			note[s][e].list[0]=i;
			for(int j=0;j<=i-s-1;j++)
			{
				note[s][e].list[j+1]=note[s][i-1].list[j];
			}
			for(int j=0;j<=e-i-1;j++)
			{
				note[s][e].list[i-s+1+j]=note[i+1][e].list[j];
			}
		}
	}
	note[s][e].val=max;
	//cout<<s<<" "<<e<<" "<<max<<endl;
	return max;
}
int main()
{
	scanf("%d",&n);
	int *d=new int[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	printf("%d\n", find(d,1,n));
	for(int i=0;i<n;i++)
		printf("%d ",note[1][n].list[i]);
	delete[] d;
	return 0;
}