#include<cstdio>
#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node *left,*right;
	Node(int x=0,Node *ll=NULL,Node *rr=NULL):val(x),left(ll),right(rr){}
};
struct BST
{
	Node *root;
	BST(){root=NULL;}
	void clear(Node *t)
	{
		if(!t) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	~BST()
	{
		clear(root);
	}
	void find(int x)
	{
		int path[100000],len=0; //0 l 1 r
		Node *p=root;
		bool flag=false;
		while(p)
		{
			if(x<p->val)
			{
				p=p->left;
				path[len++]=0;
			}
			else if(x>p->val)
			{
				p=p->right;
				path[len++]=1;
			}
			else
			{
				flag=1;break;
			}
		}
		if(flag)
		{
			printf("*");
			for(int i=0;i<len;i++)
				if(path[i]) printf("r");
				else printf("l");
			printf("\n");
		}
		else printf("Nothing.\n");
	}
	void insert(Node *&t,int x)
	{
		if(!t)
		{
			t=new Node(x);return;
		}
		//if(t->val==x) return;
		if(x<t->val) insert(t->left,x);
		else if(x>t->val) insert(t->right,x);
	}
	void remove(Node *&t,int x)
	{
		if(!t) return;
		if(t->val==x)
		{
			if(!t->right)
			{
				Node *temp=t;
				t=t->left;
				delete temp;
			}
			else
			{
				Node *p=t->right,*q=NULL;
				while(p->left)
				{
					q=p;
				 	p=p->left;
				}
				t->val=p->val;
				if(!q)
				{
					t->right=p->right;
				}
				else q->left=p->right;
				delete p;
			}
		}
		else if(x<t->val) remove(t->left,x);
		else remove(t->right,x);
	}
};
int main()
{
	int q,x;
	scanf("%d",&q);
	char c;
	BST bst;
	for(int i=0;i<q;i++)
	{
		scanf("\n%c%d",&c,&x);
		switch(c)
		{
			case '+': bst.insert(bst.root,x);break;
			case '-': bst.remove(bst.root,x);break;
			case '*': bst.find(x);break;
		}
	}
}