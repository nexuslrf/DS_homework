#include<iostream>
#include<cstring>
using namespace std;
struct bignum
{
	int val[302];	
	int len;
};
bool judge(int p,bignum &a,bignum &b)
{
	if(a.len-p>b.len)
		return true;
	if(a.len-p<b.len)
		return false;
	for(int i=a.len-1;i>=p;i--)
	{
		if(a.val[i]>b.val[i-p])
			return true;
		else if(a.val[i]<b.val[i-p])
			return false;
	}
	if(a.val[p]==b.val[0])
		return true;
	else
		return false; 
}
void Minus(int p,bignum &a,bignum &b)
{
	int down=0;
	for(int i=0;i<b.len;i++)
	{
		a.val[i+p]=a.val[i+p]-b.val[i]-down;
		if(a.val[i+p]<0)
		{
			a.val[i+p]+=10;
			down=1;
		}
		else
			down=0;
	}
	if(down)
		a.val[b.len+p]-=1;
	while(!a.val[a.len-1]&&a.len>1)
		a.len--; 
}
int main()
{
	char ac[303];
	char bc[303];
	cin>>ac>>bc;
	bignum a,b,c;
	a.len=strlen(ac);
	for(int i=0;i<a.len;i++)
		a.val[i]=ac[a.len-1-i]-'0';
	b.len=strlen(bc);
	for(int i=0;i<b.len;i++)
		b.val[i]=bc[b.len-1-i]-'0';
	c.len=a.len-b.len+1;
	if(c.len<=0)
	{
		cout<<0;
		return 0;
	}
	int i=c.len-1;
	while(i>=0)
	{
		int cnt=0;
		while(judge(i,a,b))
		{
			Minus(i,a,b);
			cnt++; 
		}
		c.val[i]=cnt; 
		i--;
	}
	while(c.val[c.len-1]==0&&c.len>1)
		c.len--;
	for(int i=c.len-1;i>=0;i--)
		cout<<c.val[i];
	return 0;
}
