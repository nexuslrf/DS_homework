#include<cstdio>
#include<iostream>
using namespace std;
#define N (1000)
int Capacity=100000000;
class Bigint
{
	int bits[N];
public:
	Bigint(int x=0)
	{
		bits[0]=x;
		for(int i=1;i<N;i++) bits[i]=0;
	}
	Bigint &operator=(const Bigint &num)
	{
		for(int i=0;i<N;i++) bits[i]=num.bits[i];
		return *this;
	}
	friend ostream &operator<<(ostream &out,const Bigint &num)
	{	
		int i=N-1;
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
		while(i<N&&(up||num.bits[i]||bits[i]))
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
		for(int i=N-1;i>=0;i--)
		{
			if(bits[i]) return false;
		}
		return true;
	}
};
int main()
{
	int  m;
	cin>>m;
	Bigint a(2),b(4),c(7),ans;
	for(int i=0;i<m-3;i++)
	{
		ans=a+b+c;
		a=b;
		b=c;
		c=ans;
	}
	cout<<ans;
}