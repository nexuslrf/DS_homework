#include<cstdio>
using namespace std;
int dp[1000][1000];
int n,m;
int maxi(int a,int b)
{
	return a>b?a:b;
}
int find(char *s1,char *s2,int x,int y)
{
	if(x<0||y<0)
		return 0;
	if(dp[x][y])
		return dp[x][y];
	if(s1[x]==s2[y])
		dp[x][y]=find(s1,s2,x-1,y-1)+1;
	else
		dp[x][y]=maxi(find(s1,s2,x-1,y),find(s1,s2,x,y-1));
	return dp[x][y];
}
int main()
{
	scanf("%d%d",&n,&m);
	char *s1=new char[n+1],*s2=new char[m+1];
	scanf("%s%s",s1,s2);
	printf("%d", find(s1,s2,n-1,m-1));
	delete[] s1,s2;
	return 0;
}
