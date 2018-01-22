#include<cstdio>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
	int bound=sqrt(n);
	if(n%2==0&&n!=2)
		return false;
	for(int i=3;i<=bound;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	int n,pri[25];
	scanf("%d",&n);
	int maxi=sqrt(n),inp=0;
	if(n%2==0)
		pri[inp++]=2;
	for(int i=3;i<=maxi;i+=2)
	{
		if(n%i==0&&isPrime(i))
			pri[inp++]=i;
	}
	printf("%d=",n);
	for(int i=0;i<inp;i++)
	{
		int Pow=0;
		while(n%pri[i]==0&&n!=0)
		{
			Pow++;
			n/=pri[i];
		}
		printf("%d(%d)",pri[i],Pow);
	}
	if(n!=1)
	printf("%d(%d)",n,1);
	return 0;
}
