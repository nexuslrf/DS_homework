#include<cstdio>
#include<iostream>
using namespace std;
int matrix[6][6];
const int MAXI=2147483647;
int ans;
void dfs(int x1,int y1,int dx,int dy,int state,int cost)
{
	if(x1==dx&&y1==dy)
	{
		ans=min(cost,ans); return;
	}
	//**
	if(cost>ans) return;// 剪枝 可以提高千倍的效率！！！
	//**
	int token=matrix[x1][y1],stepCost;
	matrix[x1][y1]=0;
	if(y1-1>=0&&matrix[x1][y1-1]) //left
	{
		stepCost=state*matrix[x1][y1-1];
		dfs(x1,y1-1,dx,dy,stepCost%4+1,cost+stepCost);
	}
	if(y1+1<6&&matrix[x1][y1+1]) //right
	{
		stepCost=state*matrix[x1][y1+1];
		dfs(x1,y1+1,dx,dy,stepCost%4+1,cost+stepCost);
	}
	if(x1-1>=0&&matrix[x1-1][y1]) //up
	{
		stepCost=state*matrix[x1-1][y1];
		dfs(x1-1,y1,dx,dy,stepCost%4+1,cost+stepCost);
	}
	if(x1+1<6&&matrix[x1+1][y1])
	{
		stepCost=state*matrix[x1+1][y1];
		dfs(x1+1,y1,dx,dy,stepCost%4+1,cost+stepCost);
	}
	matrix[x1][y1]=token;
}
int main()
{
	int n,x0,y0,dx,dy;
	scanf("%d",&n);
	for(int c=0;c<n;c++)
	{
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				scanf("%d",&matrix[i][j]);
		scanf("%d%d%d%d",&x0,&y0,&dx,&dy);
		ans=MAXI;
		dfs(x0,y0,dx,dy,1,0);
		printf("%d\n", ans);
	}
	return 0;
}