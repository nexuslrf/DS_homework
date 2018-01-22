#include<iostream>
#include<cstdio>
using namespace std;
int mat[501][501];
struct point
{
	point *prev,*next;
	int x,y;
	point(int i=0,int j=0,point *p=NULL,point *n=NULL):x(i),y(j),prev(p),next(n){}
};
point* head=new point;
point* tail=new point;
point* link[501][501];
int n,m;
int ans=0;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void delink(point *t)
{
	t->prev->next=t->next;
	t->next->prev=t->prev;
}
void dfs(int x,int y,int c)
{
	if(!mat[x][y])
	{	
		mat[x][y]=c;
		delink(link[x][y]);
		for(int i=0;i<4;i++)
		{
			if(!mat[x+dx[i]][y+dy[i]])
			{
				dfs(x+dx[i],y+dy[i],c);
			}
		}
	}
}
int main()
{
	head->next=tail;
	tail->prev=head;
	scanf("%d%d",&n,&m);
	int idx=0;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1) {mat[i][j]=-1;continue;}
			scanf("%d",&mat[i][j]);
			if(!mat[i][j])
			{
				point *temp=new point(i,j,head,head->next);
				head->next->prev=temp;
				head->next=temp;
				link[i][j]=temp;
			}
		}
	// point *zz=head->next;
	// while(zz!=tail)
	// {
	// 	cout<<zz->x<<" "<<zz->y<<endl;
	// 	zz=zz->next;
	// }
	while(head->next!=tail)
	{
		point *temp=head->next;
		//cout<<temp->x<<" "<<temp->y<<endl;
		ans++;
		dfs(temp->x,temp->y,ans);
	}
	printf("%d\n", ans);
}