#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
	int val,prio,amount;
	int num;
	Node *left,*right;
	Node(int x,Node *ll,Node *rr):val(x),left(ll),right(rr)
	{
		prio=rand(); amount=1; num=1;
	}
	void maintain(){amount=left->amount+right->amount+1;}
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
			else// if(x>t->val)
			{
				insert(t->right,x);
				if(t->prio<t->right->prio)
					RR(t);
			}
			// else
			// 	t->num++;
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
	int del(Node *&t,int x)
	{
		if(t==nil) return 0;
		if(x<=t->val)
		{
			int temp=del(t->left,x);
			t->amount-=temp;
			return temp;
		}
		else
		{
			int temp=t->left->amount+1;
			// clear(t->left);
			// Node *p=t;
			// delete p;
			t=t->right;
			return temp+del(t,x);
		}
	}
	int find(Node *t,int k)
	{
		int s;
		if(t==nil||k<=0||k>t->amount)
		{
			return -1;
		}
		if(t->right!=nil)
			s=t->right->amount;
		else s=0;
		if(s+1==k) return t->val;
		else if(k<=s)
			return find(t->right,k);
		else 
			return find(t->left,k-s-1);
	}
};
int main()
{
	//freopen("1054_treap2.txt","w",stdout);
	int n,m,z;
	int leave=0,delta=0,x;
	char c;
	scanf("%d%d",&n,&m);
	Treap treap;
	for(int i=0;i<n;i++)
	{
		scanf("\n%c%d",&c,&x);
		switch(c)
		{
			case 'I':
				if(x>=m)
					treap.insert(treap.root,x-delta);
				//else leave++;
				break;
			case 'A':
				delta+=x; break;
			case 'S':
				delta-=x;
				leave+=treap.del(treap.root,m-delta); 
				//cout<<leave<<endl;
				break;
			case 'F':
				//A wrong approach
				// z=treap.find(treap.root,x);
				// printf("%d ", z);
				// if(z>=0)
				// 	printf("%d\n", z+delta);
				// else 
				// 	printf("-1\n");
				if(x> treap.root->amount) printf("-1\n");
				else
				printf("%d\n",treap.find(treap.root,x)+delta);
				break;
		}
	}
	printf("%d\n", leave);
}