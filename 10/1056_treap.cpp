#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
	int val,prio,amount,multi;
	int num;
	Node *left,*right;
	Node(int x,Node *ll,Node *rr):val(x),left(ll),right(rr)
	{
		prio=rand(); amount=1; num=1;multi=1;
	}
	void maintain(){amount=left->amount+right->amount+multi;}
};
struct Treap
{
	Node *root,*nil;
	Treap()
	{
		nil=new Node(0,NULL,NULL);
		nil->amount=0;
		root=nil;
	}
	void LL(Node *&t)
	{
		Node *temp=t->left;
		t->left=temp->right;
		temp->right=t;
		t->maintain();
		temp->maintain();
		t=temp;
	}
	void RR(Node *&t)
	{
		Node *temp=t->right;
		t->right=temp->left;
		temp->left=t;
		t->maintain();
		temp->maintain();
		t=temp;
	}
	void insert(Node *&t,int x)
	{
		if(t==nil)
		{
			t=new Node(x,nil,nil);
		}
		else
		{
			if(x<t->val)
			{
				insert(t->left,x);
				if(t->prio<t->left->prio)
					LL(t);
			}
			else if(x>t->val)
			{
				insert(t->right,x);
				if(t->prio<t->right->prio)
					RR(t);
			}
			else
				t->multi++;
		}
		t->maintain();
	}
	void clear(Node *t)
	{
		if(t==nil) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	void del(Node *&t,int x)
	{
		if(t==nil) return;
		if(x==t->val)
		{
			if(t->multi>1)
			{
				t->multi--;
			}
			else
			{
				if(t->left==nil) 
				{
					Node *temp=t;
					t=t->right;
					delete temp;
				}
				else if(t->right==nil)
				{
					Node *temp=t;
					t=t->left;
					delete temp;
				}
				else
				{
					Node *p=t->right;
					while(p->left!=nil) p=p->left;
					t->val=p->val;
					t->multi=p->multi;
					p->multi=0;
					del(t->right,t->val);
				}
			}
			if(t!=nil)
				t->maintain();
		}
		else if(x<t->val)
		{
			del(t->left,x);
			t->maintain();
		}
		else
		{
			del(t->right,x);
			t->maintain();
		}
	}
	int find(Node *t,int k)
	{
		int s;
		if(t==nil||k<=0||k>t->amount)
		{
			return 0;
		}
		if(t->right!=nil)
			s=t->right->amount;
		else s=0;
		if(k<=s)
			return find(t->right,k);
		else if(k>s+t->multi)
			return find(t->left,k-s-t->multi);
		else return t->val;
	}
};
struct slot
{
	int pos;
	slot *next;
	slot(){next=NULL;}
};
slot box[500001];
int suger[500001],note[500001];
int main()
{
	//freopen("1056.in","r",stdin);
	Treap tree;
	int n,m;
	scanf("%d%d",&n,&m);
	tree.insert(tree.root,1);
	tree.root->multi=n;
	tree.root->amount=n;
	char c[5];
	int x,y;
	for(int i=1;i<=n;i++)
	{
		box[i].pos=i;suger[i]=i;note[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",c);
		if(c[0]=='C')
		{
			scanf("%d%d",&x,&y);
			if(suger[x]&&suger[y]&&suger[x]!=suger[y])
			{
				tree.del(tree.root,note[suger[x]]);
				tree.del(tree.root,note[suger[y]]);
				note[suger[x]]+=note[suger[y]];
				tree.insert(tree.root,note[suger[x]]);
				slot *p=&box[suger[y]],*temp=p;
				while(p->next)
				{
					suger[p->pos]=suger[x];
					p=p->next;
				}
				suger[p->pos]=suger[x];
				p->next=box[suger[x]].next;
				box[suger[x]].next=temp;
			}
		}
		else if(c[0]=='D')
		{
			scanf("%d",&x);
			if(suger[x])
			{
				tree.del(tree.root,note[suger[x]]);
				slot *p=&box[suger[x]];
				while(p)
				{
					suger[p->pos]=0;
					p=p->next;
				}
			}
		}
		else if(c[0]=='Q')
		{
			scanf("%d",&x);
			printf("%d\n", tree.find(tree.root,x));
		}
	}
}
