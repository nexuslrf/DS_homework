#include<cstdio>
#include<iostream>
using namespace std;
struct EdgeNode
{
	int end;
	EdgeNode *next;
	EdgeNode(int x=0,EdgeNode *p=NULL):end(x),next(p){}
};
struct VerNode
{
	EdgeNode *head;
	VerNode()
	{
		head=NULL;
	}
};
VerNode vers[20];
int visit[20];
void addEdge(int a,int b)
{
	if(a==b) return;
	if(!vers[a].head)
		vers[a].head=new EdgeNode(b,vers[a].head);
	else
	{
		EdgeNode *p=vers[a].head;
		while(p)
		{
			if(p->end==b) return;
			if(!p->next) break;
			p=p->next;
		}
		p->next=new EdgeNode(b,NULL);
	}
}
int cnt=0,len;
void dfs(int s,int step)
{
	if(step==len)
	{
		cnt++;
		return;
	}
	EdgeNode *p=vers[s].head;
	visit[s]=1;
	while(p)
	{
		if(!visit[p->end])
			dfs(p->end,step+1);
		p=p->next;
	}
	visit[s]=0;
}
int main()
{
	int n,m,start,x,y;
	scanf("%d%d%d%d",&n,&m,&start,&len);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		addEdge(x,y);
	}
	dfs(start,0);
	printf("%d\n", cnt);
}