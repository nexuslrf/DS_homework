#include<iostream>
#include<cstdio>
using namespace std;
const long long range=0x7FFFFFFF;
long long gcd(long long a,long long b)
{    //辗转相除法，老哥！！！orz
    return b?gcd(b,a%b):a;    
}   
class Rational   //z x/y
{
	long long x,y,z;
	void fix()
	{
		long long m=min(x,y);
		long long i=m;
		if(x>=y)
		{
			z+=(x/y);
			x=x%y;
		}
		long long gcdnum=gcd(x,y);
		x/=gcdnum;
		y/=gcdnum;
	}
	int getlen(long long tt)
	{
		int len=0;
		while(tt)
		{
			tt/=10; len++;
		}
		return len;
	}
public:
	Rational(long long a=0,long long b=1,long long c=0)
	{
		x=a;y=b;z=c; fix();
	}
	void multi(long long num)
	{
		z*=num;
		x*=num;
		fix();
	}
	void add(Rational &other)
	{
		long long gcdnum=gcd(y,other.y);
		z+=other.z;
		x=other.y/gcdnum*x+y/gcdnum*other.x;	// 两个顺序不能
		y=y/gcdnum*other.y;            //颠倒啊。
	//	if(x>range||y>range)
		fix();
	}
	friend ostream &operator<<(ostream &out,Rational &num)
	{
		if(num.x==0)
			out<<num.z;
		else
		{
			int len1=num.getlen(num.z),len2=num.getlen(num.y);
			for(int i=0;i<len1+1;i++)
				out<<' ';
			out<<num.x<<'\n'<<num.z<<' ';
			for(int i=0;i<len2;i++)
				out<<'-';
			out<<'\n';
			for(int i=0;i<len1+1;i++)
				out<<' ';
			out<<num.y;
		}
		return out;
	}
};
Rational H(int s,int e)
{
	if(s==e)
		return Rational(1,s,0);
	int mid=(s+e)/2;
	Rational a=H(s,mid),b=H(mid+1,e);
	a.add(b);
	return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	Rational ans,p;
	ans=H(1,n);
	ans.multi(n);
	cout<<ans<<endl;
	return 0;
}