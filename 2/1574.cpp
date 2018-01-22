#include<cstdio>
#include<cmath>
using namespace std;
int Mod(int n,int k)
{
	int temp=10%n,a=temp;
	if(k==0)
		return 1;
	if(temp==0)
		return 0;
	int i=1;
	if(k%2==0)
		return (Mod(n,k/2)*Mod(n,k/2))%n;
	else
		return (Mod(n,k-1)*temp)%n;
/*	
	while(2*i<=k)
	{
		temp=(temp*temp)%n;
		i*=2;
	}
	for(i;i<k;i++)
	{
		temp=(a*temp)%n;
	}
	return temp;
*/
}
int main()
{
	int n,m,k,x;
	scanf("%d %d %d %d",&n,&m,&k,&x);
	int temp=((Mod(n,k)%n)*(m%n))%n;
	temp=(x%n+temp)%n;
	printf("%d",temp);
	return 0;
}
