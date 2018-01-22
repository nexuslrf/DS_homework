#include<cstdio>
#include<iostream>
using namespace std;
struct Point
{
	int *X,*Y;
	int val;
	Point(int *a,int *b,int c):X(a),Y(b),val(c){}
};
struct Node
{
	Point *p;
	Node *next;
};
Point *points[10000];
Node *xs[100000], *ys[100000];
int xt[100000],yt[100000];
int main()
{
	int n;
	int x,y,z;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		xt[x]=x;
		yt[y]=y;
		points[i]=new Point(xt+x,yt+y,z);
		if(!xs[x])
		{
			xs[x]=new Node;
			xs[x]->p=points[i];
			xs[x]->next=NULL;
		}
		else
		{
			Node *temp=new Node;
			temp->p=points[i];
			temp->next=xs[x];
			xs[x]=temp;
		}
		if(!ys[y])
		{
			ys[y]=new Node;
			ys[y]->p=points[i];
			ys[y]->next=NULL;
		}
		else
		{
			Node *temp=new Node;
			temp->p=points[i];
			temp->next=ys[y];
			ys[y]=temp;
		}
	}
	//cout<<233<<endl;
	int m;
	Node *temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		switch(z)
		{
			case 0:
				temp=xs[x];
				xs[x]=xs[y];
				xs[y]=temp; 
				if(xs[x])
					*(xs[x]->p->X)=x;
				if(xs[y])
					*(xs[y]->p->X)=y;
				break;
			case 1:
				temp=ys[x];
				ys[x]=ys[y];
				ys[y]=temp; 
				if(ys[x])
					*(ys[x]->p->Y)=x;
				if(ys[y])
					*(ys[y]->p->Y)=y;
				break;
			case 2:
				if(!xs[x]||!ys[y])
				{
					printf("0\n"); break;
				}
				temp=xs[x];
				while(temp&&*(temp->p->Y)!=y)
				{
					temp=temp->next;
				}
				if(temp)
					printf("%d\n", temp->p->val);
				else
					printf("0\n");
				break;
		}
	}
}