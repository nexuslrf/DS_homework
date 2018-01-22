#include<cstdio>
#include<iostream>
using namespace std;
int abs(int x)
{
	if(x<0) x*=-1;
	return x;
}
struct Node
{
	int val;
	Node *left,*right;
	Node(int x,Node *ll=NULL,Node *rr=NULL):val(x),left(ll),right(rr){}
};
class BinarySearchTree
{
	Node *root;
	int currentSize;
	void insert(int x,Node *&t)
	{
		if(!t)
		{
			t=new Node(x);
			return;
		}
		if(x<=t->val) insert(x,t->left);
		else insert(x,t->right);
	}
	void del(int x,Node *&t)
	{
		if(!t) return;
		if(x==t->val)
		{
			if(!(t->left&&t->right))
			{
				Node *p=t;
				t=(t->left)?t->left:t->right;
				delete p;
			}
			else
			{
				Node *p=t->right;
				while(p->left) p=p->left;
				t->val=p->val;
				del(t->val,t->right);
			}
		}
		else if(x<t->val) del(x,t->left);
		else del(x,t->right);
	}
	void clear(Node *&t)
	{
		if(!t) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
public:
	BinarySearchTree(){root=NULL;currentSize=0;}
	~BinarySearchTree() {clear(root);}
	void insert(int x){insert(x,root);}
	void del(int x) {del(x,root);}
	int func(int x)
	{
		int p,ans=2147483647;
		Node *t=root;
		while(t)
		{
			if(x<t->val)
			{
				ans=min(ans,abs(x-t->val));
				t=t->left;
			}
			else if(x>t->val)
			{
				ans=min(ans,abs(x-t->val));
				t=t->right;
			}
			else return 0;
		}
		return ans;
	}
};
int main()
{
	int n,mod,x;
	BinarySearchTree bst;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&mod,&x);
		switch(mod)
		{
			case 0: printf("%d\n", bst.func(x));break;
			case 1: bst.insert(x);break;
			case 2: bst.del(x);break;
		}
	}
	return 0;
}