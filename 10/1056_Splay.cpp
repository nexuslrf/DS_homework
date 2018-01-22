#include<cstdio>
#include<iostream>
using namespace std;
struct Node
{
	int val,size,multi;
	Node *chd[2];
	Node(int x)
	{
		val=x; size=1;
		multi=1;
	}
};
struct SplayTree
{
	Node *root,*nil;
	Node *L_tree,*R_tree;
	void maintain(Node *x)
	{
		if(x!=nil)
		x->size=x->chd[0]->size+x->chd[1]->size+x->multi;
	}
	SplayTree() 
	{
		nil=new Node(0);
		nil->size=nil->multi=0;
		root=nil;
	 	L_tree=R_tree=nil;
	}
	void transplant(Node *&t,Node *s)
	{
		if(s==nil) return;
		if(t==nil) t=s;
		else if(s->val<t->val)
		{ 
			transplant(t->chd[0],s);maintain(t);
		}
		else transplant(t->chd[1],s);maintain(t);
	}
	void join()
	{
		if(root==nil)
		{
			if(L_tree!=nil)
			{
				Node *p=L_tree,*q=nil;
				while(p->chd[1]!=nil) {q=p;p=p->chd[1];}
				if(q==nil){ root=p; L_tree=nil;}
				else{q->chd[1]=nil;maintain(q);root=p;}
			}
			else if(R_tree!=nil)
			{
				Node *p=R_tree,*q=nil;
				while(p->chd[0]!=nil) {q=p;p=p->chd[0];}
				if(q==nil){ root=p; R_tree=nil;}
				else{q->chd[0]=nil;maintain(q);root=p;}
			}
			else return;

		}
		if(L_tree!=nil)
		{
			Node *p=L_tree;
			while(p->chd[1]!=nil)
			{
				p->size+=root->chd[0]->size;
				p=p->chd[1];
			}
			p->size+=root->chd[0]->size;
			p->chd[1]=root->chd[0];
			root->chd[0]=L_tree;
			L_tree=nil;
		}
		if(R_tree!=nil)
		{
			Node *p=R_tree;
			while(p->chd[0]!=nil)
			{
				p->size+=root->chd[1]->size;
				p=p->chd[0];
			}
			p->size+=root->chd[1]->size;
			p->chd[0]=root->chd[1];
			root->chd[1]=R_tree;
			R_tree=nil;
		}
		maintain(root);
	}
	void zig(Node *&x,int dir)
	{
		if(!dir)
		{
			Node *temp=x->chd[0];
			x->chd[0]=nil;
			x->size-=temp->size;
			transplant(R_tree,x);
			x=temp;
		}
		else
		{
			Node *temp=x->chd[1];
			x->chd[1]=nil;
			x->size-=temp->size;
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
			maintain(x);
			temp->chd[1]=x;
			maintain(temp);
			x=temp;
			zig(x,0);
		}
		else
		{
			Node *temp=x->chd[1];
			x->chd[1]=temp->chd[0];
			maintain(x);
			temp->chd[0]=x;
			maintain(temp);
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
		while(root!=nil)
		{
			if(x==root->val)
			{
				root->multi++; break;
			}
			else 
			{
				idx1=(x<root->val)?0:1;
				if(root->chd[idx1]!=nil)
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
		if(root==nil)
		{
			root=new Node(x);
			root->chd[0]=root->chd[1]=nil;
		}
		join();
	}
	void remove(int x)
	{
		//cout<<"remove: "<<x<<endl;
		int idx1,idx2;
		while(root!=nil)
		{
			if(x==root->val)
			{
				if(root->multi>1)
				{
					root->multi--; break;
				}
				else
				{
					Node *temp=root;
					if(root->chd[0]!=nil)
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
			}
			else 
			{
				idx1=(x<root->val)?0:1;
				if(root->chd[idx1]!=nil)
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
	int  find_kth(int x)
	{
		if(root==nil||x>root->size) return 0;
		int idx1,idx2,s,ans=0;
		s=root->chd[1]->size;
		while(root!=nil)
		{
			if(x<=s)
			{
				zig(root,1);
			}
			else if(x>s+root->multi)
			{
				x-=(s+root->multi);
				zig(root,0);
			}
			else {ans=root->val;break;}
			s=root->chd[1]->size;
		}
		join();
		return ans;
	}
	int find(Node *t,int k)
	{
		int s;
		if(t==nil||k<=0||k>t->size)
		{
			return 0;
		}
		if(t->chd[1]!=nil)
			s=t->chd[1]->size;
		else s=0;
		if(k<=s)
			return find(t->chd[1],k);
		else if(k>s+t->multi)
			return find(t->chd[0],k-s-t->multi);
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
	// freopen("1056.in","r",stdin);
	SplayTree tree;
	int n,m;
	scanf("%d%d",&n,&m);
	tree.insert(1);
	tree.root->multi=n;
	tree.root->size=n;
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
				tree.remove(note[suger[x]]);
				tree.remove(note[suger[y]]);
				note[suger[x]]+=note[suger[y]];
				tree.insert(note[suger[x]]);
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
				tree.remove(note[suger[x]]);
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
			printf("%d\n", tree.find_kth(x));
		}
	}
}