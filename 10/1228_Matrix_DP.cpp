#include<iostream>
#include<cstdio>
using namespace std;
int A[400][400],F[401][401],n;
long long note[405];
long long *P=note+1;
long long ans=0;
void build_F()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			F[i][j]=F[i][j-1]+A[i-1][j-1];
			F[i][j]%=2;
		}
}
void build_P()
{
	int last_one;
	int temp;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//cout<<"case: "<<i<<' '<<j<<'\n';
			last_one=0;
			for(int k=1;k<=n;k++)
			{
				temp=F[k][j]-F[k][i-1];
				//cout<<temp<<' ';
				if(!temp)
					P[k]=P[k-1];
				else
				{
					P[k]=P[last_one-1]+k-last_one;
					last_one=k;
				}
				ans+=P[k];
			}
			// cout<<"\nP:\n";
			// for(int z=1;z<=n;z++) cout<<P[z]<<' ';
			// cout<<"ans: "<<ans<<'\n';
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	build_F();
	build_P();
	long long ans2=(n+1)*n/2;
	ans2=ans2*ans2-ans;
	cout<<ans<<" "<<ans2;
	return 0;
}