#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct slot
{
	int pos;
	slot *next;
	slot(int x):pos(x){next=NULL;}
};
struct Node
{
	int val,prio,cnt;
	slot *id;
	Node *left,*right;
	Node(int x,int p,Node *ll,Node *rr):val(x),left(ll),right(rr)
	{
		prio=rand(); id=new slot(p);cnt=1;
	}
	void add(int p)
	{
		//cout<<"add:"<<p<<" val"<<val<<'\n';
		slot *temp=new slot(p);
		temp->next=id;
		id=temp;cnt++;
	}
	void pop(int p)
	{
		slot *temp=id,*q=NULL;cnt--;
		while(temp->pos!=p){q=temp;temp=temp->next;}
		//if(!temp) return;
		if(q){q->next=temp->next;delete temp;}
		else{id=temp->next;delete temp;}
	}
};
struct Treap
{
	Node *root,*nil;
	Treap()
	{
		nil=new Node(0,-1,NULL,NULL);
		root=nil;
	}
	void LL(Node *&t)
	{
		Node *temp=t->left;
		t->left=temp->right;
		temp->right=t;
		t=temp;
	}
	void RR(Node *&t)
	{
		Node *temp=t->right;
		t->right=temp->left;
		temp->left=t;
		t=temp;
	}
	void insert(Node *&t,int x,int pt)
	{
		if(t==nil)
		{
			t=new Node(x,pt,nil,nil);
		}
		else
		{
			if(x==t->val)
			{
				t->add(pt);
			}
			else if(x<t->val)
			{
				insert(t->left,x,pt);
				if(t->prio<t->left->prio)
					LL(t);
			}
			else// if(x>t->val)
			{
				insert(t->right,x,pt);
				if(t->prio<t->right->prio)
					RR(t);
			}
		}
	}
	void clear(Node *t)
	{
		if(t==nil) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	void remove(Node *&t,int x,int pt)
	{
		if(t==nil) return;
		if(x==t->val)
		{
			//cout<<"remove:"<<t->val<<" at:"<<pt<<'\n';
			if(t->cnt)	{t->pop(pt);}
			if(!t->cnt)
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
					t->val=p->val; t->id=p->id; t->cnt=p->cnt;p->cnt=0;
					remove(t->right,t->val,0);
				}
			}
		}
		else if(x<t->val)
		{
			remove(t->left,x,pt);
		}
		else
		{
			remove(t->right,x,pt);
		}
	}
	int find_min()
	{
		Node *p=root;
		while(p->left!=nil)
		{
			//cout<<"p->val:"<<p->val<<endl;
			p=p->left;
		}
		//cout<<"p->val:"<<p->val<<endl;
		return p->id->pos;
	}
};
int a[2000001];
int main()
{
	freopen("1990.in","r",stdin);
	int n,m;
	Treap tree;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		tree.insert(tree.root,a[i],i);
	}
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		tree.remove(tree.root,a[x],x);
		a[x]+=y;
		tree.insert(tree.root,a[x],x);
		printf("%d\n", tree.find_min());
	}
	return 0;
}