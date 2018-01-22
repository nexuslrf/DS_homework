#include<cstdio>
#include<iostream>
using namespace std;
struct Node
{
	int val,size,multi;
	Node *chd[2];
	Node(int x)
	{
		chd[0]=chd[1]=NULL;
		val=x; size=1;
		multi=1;
	}
};
struct SplayTree
{
	Node *root;
	Node *L_tree,*R_tree;
	SplayTree() 
	{root=NULL;
	 L_tree=R_tree=NULL;
	}
	void transplant(Node *&t,Node *s)
	{
		if(!s) return;
		if(!t) t=s;
		else if(s->val<t->val) transplant(t->chd[0],s);
		else transplant(t->chd[1],s);
	}
	void join()
	{
		if(!root)
		{
			if(L_tree)
			{
				Node *p=L_tree,*q=NULL;
				while(p->chd[1]) {q=p;p=p->chd[1];}
				if(!q){ root=p; L_tree=p->chd[0];}
				else{q->chd[1]=NULL;root=p;}
			}
			else if(R_tree)
			{
				Node *p=R_tree,*q=NULL;
				while(p->chd[0]) {q=p;p=p->chd[0];}
				if(!q){ root=p; R_tree=p->chd[1];}
				else{q->chd[0]=NULL;root=p;}
			}
			else return;

		}
		if(L_tree)
		{
			Node *p=L_tree;
			while(p->chd[1]) p=p->chd[1];
			p->chd[1]=root->chd[0];
			root->chd[0]=L_tree;
			L_tree=NULL;
		}
		if(R_tree)
		{
			Node *p=R_tree;
			while(p->chd[0]) p=p->chd[0];
			p->chd[0]=root->chd[1];
			root->chd[1]=R_tree;
			R_tree=NULL;
		}
	}
	void zig(Node *&x,int dir)
	{
		if(!dir)
		{
			Node *temp=x->chd[0];
			x->chd[0]=NULL;
			transplant(R_tree,x);
			x=temp;
		}
		else
		{
			Node *temp=x->chd[1];
			x->chd[1]=NULL;
			transplant(L_tree,x);
			x=temp;
		}
	}
	void zig_zig(Node *&x,int dir)
	{
		if(!dir)
		{
			Node *temp=x->chd[0];
			x->chd[0]=temp->chd[1];
			temp->chd[1]=x;
			x=temp;
			zig(x,0);
		}
		else
		{
			Node *temp=x->chd[1];
			x->chd[1]=temp->chd[0];
			temp->chd[0]=x;
			x=temp;
			zig(x,1);
		}
	}
	void zig_zag(Node *&x,int dir)
	{
		if(!dir)
		{
			zig(x,0);
			zig(x,1);
		}
		else
		{
			zig(x,1);
			zig(x,0);
		}
	}
	void insert(int x)
	{
		int idx1,idx2;
		while(root)
		{
			if(x==root->val)
			{
				root->multi++; break;
			}
			else 
			{
				idx1=(x<root->val)?0:1;
				if(root->chd[idx1])
				{
					if(x==root->chd[idx1]->val)
					{
						zig(root,idx1);
					}
					else
					{
						idx2=(x<root->chd[idx1]->val)?0:1;
						if(!(idx1^idx2))
							zig_zig(root,idx1);
						else 
							zig_zag(root,idx1);
					}

				}
				else
				{
					//cout<<"233\n";
					zig(root,idx1);
				}
			}
		}
		if(!root)
			root=new Node(x);
		join();
	}
	void remove(int x)
	{
		int idx1,idx2;
		while(root)
		{
			if(x==root->val)
			{
				Node *temp=root;
				if(root->chd[0])
				{
					transplant(R_tree,root->chd[1]);root=root->chd[0];
				}
				else
				{
					root=root->chd[1];
				}
				delete temp;
				break;
			}
			else 
			{
				idx1=(x<root->val)?0:1;
				if(root->chd[idx1])
				{
					if(x==root->chd[idx1]->val)
					{
						zig(root,idx1);
					}
					else
					{
						idx2=(x<root->chd[idx1]->val)?0:1;
						if(!(idx1^idx2))
							zig_zig(root,idx1);
						else 
							zig_zag(root,idx1);
					}

				}
				else
				{
					zig(root,idx1);
				}
			}
		}
		join();
	}
	bool find(int x)
	{
		int idx1,idx2;
		bool flag=false;
		while(root)
		{
			if(x==root->val)
			{
				flag=true; break;
			}
			else 
			{
				idx1=(x<root->val)?0:1;
				if(root->chd[idx1])
				{
					if(x==root->chd[idx1]->val)
					{
						zig(root,idx1);
					}
					else
					{
						idx2=(x<root->chd[idx1]->val)?0:1;
						if(!(idx1^idx2))
							zig_zig(root,idx1);
						else 
							zig_zag(root,idx1);
					}

				}
				else
				{
					zig(root,idx1);
				}
			}
		}
		join();
		return flag;
	}
};
int main()
{
	SplayTree tree;
	int c,x;
	for(int i=0;i<15;i++)
	{
		cin>>x;
		tree.insert(x);
	}
	for(int i=0;i<30;i++)
	{
		cin>>c>>x;
		if(c)
		{
			tree.remove(x);
		}
		else
		{
			if(tree.find(x)) 
				cout<<"Y\n";
			else
				cout<<"N\n";
		}
	}
}