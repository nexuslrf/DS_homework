#include<iostream>
#include<cstdio>
using namespace std;
const int inf=100000000;
char mat[102][102];
int tempX[10000];
int tempY[10000];
char mark[10000];
int n,m,x1,y1,x2,y2;
int ans=inf;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void dfs(int xs,int ys,int xe,int ye,int step)
{
	if(xs==xe&&ys==ye)
	{
		if(step<ans) ans=step;
		return;
 	}
 	if(step>=ans) return;
 	char temp=mat[xs][ys];
 	mat[xs][ys]='*';
 	if(temp=='.')
 	{
 		for(int i=0;i<2;i++)
 		{
 			if(mat[xs+dx[i]][ys]=='.'||mat[xs+dx[i]][ys]=='|')
 				dfs(xs+dx[i],ys,xe,ye,step+1);
 		}
 		for(int i=2;i<4;i++)
 		{
 			if(mat[xs][ys+dy[i]]=='.'||mat[xs][ys+dy[i]]=='-')
 				dfs(xs,ys+dy[i],xe,ye,step+1);
 		}
 	}
 	else if(temp=='|')
 	{
 		for(int i=0;i<2;i++)
 		{
 			if(mat[xs+dx[i]][ys]=='.'||mat[xs+dx[i]][ys]=='|')
 				dfs(xs+dx[i],ys,xe,ye,step+1);
 		}
 	}
 	else if(temp=='-')
 	{
 		for(int i=2;i<4;i++)
 		{
 			if(mat[xs][ys+dy[i]]=='.'||mat[xs][ys+dy[i]]=='-')
 				dfs(xs,ys+dy[i],xe,ye,step+1);
 		}
 	}
 	mat[xs][ys]=temp;
}
void getin(int x,int y,int& idx,bool &flag)
{
	if(x==x2&&y==y2) {flag=1; }
	mark[idx]=mat[x][y];
	mat[x][y]='*';
	tempX[idx]=x;
	tempY[idx]=y;
	idx++;
}
void bfs(int xs,int ys,int xe,int ye,int step)
{
	int idx=0,cnt=0;
	char temp;
	bool flag=0;
	getin(xs,ys,idx,flag);
	for(int k=0;k<idx;k++)
	{
		temp=mark[k];
		xs=tempX[k];ys=tempY[k];
	 	if(temp=='.')
	 	{
	 		for(int i=0;i<2;i++)
	 		{
	 			if(mat[xs+dx[i]][ys]=='.'||mat[xs+dx[i]][ys]=='|')
	 				getin(xs+dx[i],ys,idx,flag);
	 		}
	 		for(int i=2;i<4;i++)
	 		{
	 			if(mat[xs][ys+dy[i]]=='.'||mat[xs][ys+dy[i]]=='-')
	 				getin(xs,ys+dy[i],idx,flag);
	 		}
	 	}
	 	else if(temp=='|')
	 	{
	 		for(int i=0;i<2;i++)
	 		{
	 			if(mat[xs+dx[i]][ys]=='.'||mat[xs+dx[i]][ys]=='|')
	 				getin(xs+dx[i],ys,idx,flag);
	 		}
	 	}
	 	else if(temp=='-')
	 	{
	 		for(int i=2;i<4;i++)
	 		{
	 			if(mat[xs][ys+dy[i]]=='.'||mat[xs][ys+dy[i]]=='-')
	 				getin(xs,ys+dy[i],idx,flag);
	 		}
	 	}
	 	if(flag){ans=step+1; return;}
	 	if(k==cnt)
	 	{
	 		cnt=idx-1;step++;
	 	}
	 }
}
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
	for(int i=0;i<=n+1;i++)
	{
		if(i<=n) scanf("\n");
		for(int j=0;j<=m+1;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1) {mat[i][j]='*';continue;}
			scanf("%c",&mat[i][j]);
		}
	}
	bfs(x1,y1,x2,y2,0);
	if(ans==inf) printf("-1\n");
	else printf("%d\n", ans);
}