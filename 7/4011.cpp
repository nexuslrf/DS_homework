#include<cstdio>
#include<iostream>
using namespace std;
int Capacity=100000000;
class Bigint
{
	int bits[10];
public:
	Bigint(int x=0)
	{
		bits[0]=x;
		for(int i=1;i<10;i++) bits[i]=0;
	}
	Bigint &operator=(const Bigint &num)
	{
		for(int i=0;i<10;i++) bits[i]=num.bits[i];
		return *this;
	}
	friend ostream &operator<<(ostream &out,const Bigint &num)
	{	
		int i=9;
		while(i&&!num.bits[i]) i--;
		out<<num.bits[i--];
		for(;i>=0;i--)
		{
			int p=Capacity/10;
			while(!(num.bits[i]/p))
			{
				out<<0;p/=10;
			}
			out<<num.bits[i];
		}
		return out;
	}
	Bigint operator+(const Bigint &num)
	{
		Bigint p(0);
		int temp;
		int i=0,up=0;
		while(i<10&&(up||num.bits[i]||bits[i]))
		{
			temp=num.bits[i]+bits[i]+up;
			p.bits[i]=temp%Capacity;
			up=temp/Capacity;
			i++;
		}
		return p;
	}
	bool isEmpty()
	{
		for(int i=9;i>=0;i--)
		{
			if(bits[i]) return false;
		}
		return true;
	}
};
Bigint dp[51][51];
Bigint get(int x,int y,int k)
{
	if(!dp[x][y].isEmpty()) return dp[x][y];
	if(y==2)
	{
		dp[x][y]=Bigint(x);
		return dp[x][y];
	}
	for(int i=0;i<x;i++)
		dp[x][y]=dp[x][y]+get(k-i,y-1,k);
	return dp[x][y];
}

int main()
{
	int k,h;
	scanf("%d%d",&k,&h);
	cout<<get(k,h,k);
	return 0;
}