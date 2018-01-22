#include<cstdio>
using namespace std;
/*
class BiTree
{
	struct Node
	{
		int val;
		Node *lch;
		Node *rch;
	};
	Node *root;
	public:
		BiTree()
		{root=NULL;}
		BiTree(Node *p)
		{
			root=p;
		}
		~BiTree()
		{
			clear();
		}
		int getRoot()
		{
			return root->val;
		}
		int getLeft()
		{
			return root->lch->val;
		}
		int getRight()
		{
			return root->rch->val;
		}
		void delLeft()
		{
			BiTree tmp=root->lch;
			root->lch=NULL;
			tmp->clear();
		}
		void delRight()
		{
			BiTree tmp=root->rch;
			root->rch=NULL;
			tmp->clear();
		}
		bool isEmpty()
		{
			return (root==NULL)
		}
		void clear()
		{
			if(root)
				clear(root);
			root=NULL:
		}
		void clear(Node *tmp)
		{
			if(tmp->lch)
				clear(tmp->lch);
			if(tmp->rch)
				clear(tmp->rch);
			delete tmp;
		}
		void createT()
		{
			
		}	
 };*/
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	int *p=new int[n+1];
 	int *q=new int[n+1];
 	int *v=new int[n+1];
 	int *flag=new int[n+1];
 //	BiTree tree;
 	for(int i=0;i<=n;i++)
 		flag[i]=0;
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d %d %d",&p[i],&q[i],&v[i]);
 		flag[p[i]]=1;
 		flag[q[i]]=1;
	}
	int root;
	for(int i=1;i<=n;i++)
	{
 		if(!flag[i])
 		{
 			root=i;
 			break;
		 }
 	}
 	int cnt=1,i=2,prev=1;
 	flag[1]=root;
 	while(i<=n)
 	{
 		int t=i;
 		for(int j=prev;j<t;j++)
 		{
 			if(p[flag[j]])
 				flag[i++]=p[flag[j]];
 			if(q[flag[j]])
 				flag[i++]=q[flag[j]];
		 }
		prev=t;
		
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	printf("%d ",v[flag[i]]);
	 }
 	delete p,q,v;
} 
 
