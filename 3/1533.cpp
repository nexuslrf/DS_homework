#include<cstdio>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	int q=x<(n+1-y)?x:(n+1-y),p=y<(n+1-x)?y:(n+1-x);
	long long t=(q<p?q:p)-1,ans=4*t*(n-t);
	if(x==t+1)
		ans+=y-t;
	else if(y==n-t)
		ans+=n-3*t-1+x;
	else if(x==n-t)
		ans+=2*(n-2*t-1)+n-y+1-t;
	else
		ans+=3*(n-2*t-1)+n-x+1-t;
	printf("%d",ans-1);
	return 0;
}