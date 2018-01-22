#include<cstdio>
#include<iostream>
using namespace std;
typedef pair<int,int> Pairs;
#define x first
#define y second
const int INF=9999999;
int A[101][101],B[101][101];
int n,m,N,zz;
int X[3][2];
int note[101][101],visit[101][101],dist[3][3];
int ans,mm=INF;
int getid(int i,int j)
{return (i-1)*m+j;}
inline int abs(int v)
{
	if(v<0) v=-1*v;
	return v;
}
Pairs getmin()
{
	int a=1,b=1;
	int mins=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!visit[i][j]&&note[i][j]<mins)
			{
				a=i;b=j;mins=note[i][j];
			}
		}
	return Pairs(a,b);
}
void dijkstra(int a)
{
	//map<int, int> data;
	int b,c;
	b=(a+1)%3;c=(a+2)%3;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			{visit[i][j]=0;note[i][j]=INF;
				//data.insert(Pairs(getid(i,j),INF);
			}
	note[X[a][0]][X[a][1]]=0;
	//data[getid(X[a][0],X[a][1])]=0;
	int cnt=2;
	for(int z=1;z<=N;z++)
	{
		//cout<<"#"<<z<<'\n';
		Pairs v=getmin();
		if(note[v.x][v.y]==INF)
			return;
		visit[v.x][v.y]=1;
		// cout<<v.x<<" "<<v.y<<'\n';
		if(v==Pairs(X[b][0],X[b][1]))
		{
			cnt--;
			dist[a][b]=note[v.x][v.y];
			//cout<<"ggz "<<summ<<'\n';
		}
		else if(v==Pairs(X[c][0],X[c][1]))
		{
			cnt--;
			dist[a][c]=note[v.x][v.y];
			//cout<<"ggz "<<summ<<'\n';
		}
		if(!cnt) return;
		int d=A[v.x][v.y],tt=B[v.x][v.y]+note[v.x][v.y];
		for(int i=1;i<=d&&i<=zz;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if((v.y-i+j)&&(v.x-j)&&!visit[v.x-j][v.y-i+j])
					note[v.x-j][v.y-i+j]=min(note[v.x-j][v.y-i+j],tt);
				if((v.y+i-j<=m)&&(v.x-j)&&!visit[v.x-j][v.y+i-j])
					note[v.x-j][v.y+i-j]=min(note[v.x-j][v.y+i-j],tt);
				if((v.y-i+j)&&(v.x+j<=n)&&!visit[v.x+j][v.y-i+j])
					note[v.x+j][v.y-i+j]=min(note[v.x+j][v.y-i+j],tt);
				if((v.y+i-j<=m)&&(v.x+j<=n)&&!visit[v.x+j][v.y+i-j])
					note[v.x+j][v.y+i-j]=min(note[v.x+j][v.y+i-j],tt);
			}
		}
	}

}
int main()
{
	//freopen("2106.in","r",stdin);
	scanf("%d%d",&n,&m);
	N=n*m;zz=max(m,n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&B[i][j]);
	scanf("%d%d%d%d%d%d",X[0],X[0]+1,X[1],X[1]+1,X[2],X[2]+1);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++) 
		{
			if(i==j) dist[i][j]=0;
			else	dist[i][j]=INF;
		}
	for(int i=0;i<3;i++) dijkstra(i);
	for(int i=0;i<3;i++)
	{
		int temp=0;
		for(int j=0;j<3;j++)
			temp+=dist[j][i];
		if(temp<mm)
		{
			mm=temp;
			ans=i;
		}
	}
	if(mm>=INF)
		printf("NO\n");
	else
	{
		printf("%c\n", 'X'+ans);
		printf("%d\n", mm);
	}
}