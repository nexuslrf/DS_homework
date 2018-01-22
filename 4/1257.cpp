#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node *parent;
	Node *left;
	Node *right;
};
Node* slot[100001];
class Tree
{
	Node *root;
	void clear(Node *p)
	{
		slot[p->val]=0;
		if(p->left)
			clear(p->left);
		if(p->right)
			clear(p->right);
		delete p;
	}
public:
	Tree()
	{
		root=new Node;
		root->val=1;
		root->parent=root->left=root->right=NULL;
		slot[1]=root;
	}
	~Tree()
	{
		clear(root);
	}
	void add(int n,int a,int b)
	{
		if(!slot[n]||slot[a]||slot[b])
		{
			printf("Error!\n");
			return;
		}
		Node* temp=slot[n];
		if(temp->left||temp->right)
		{
			printf("Error!\n");
			return;
		}	
		Node* lc=new Node;
		Node* rc=new Node;
		lc->val=a;
		rc->val=b;
		lc->parent=temp;
		rc->parent=temp;
		lc->left=rc->left=NULL;
		lc->right=rc->right=NULL;
		temp->left=lc;
		temp->right=rc;
		slot[a]=lc;
		slot[b]=rc;
		printf("Ok!\n");
	}
	void query(int a)
	{
		if(!slot[a])
		{
			printf("Error!\n");
			return;
		}
		Node *temp=slot[a];
		if(temp->parent)
			printf("%d ", temp->parent->val);
		else
			printf("0 ");
		if(temp->left)
			printf("%d ", temp->left->val);
		else
			printf("0 ");
		if(temp->right)
			printf("%d\n", temp->right->val);
		else
			printf("0\n");
	}
	void swap(int a)
	{
		Node* t=slot[a];
		if (!t||a==1)
		{
			printf("Error!\n");
			return;
		}
		Node* p=t->parent;
		if(p->left==t)
		{
			p->left=p->right;
			p->right=t;
			if(p->left)
				printf("%d\n", p->left->val);
			else
				printf("0\n");
		}
		else if(p->right==t)
		{
			p->right=p->left;
			p->left=t;
			if(p->right)
				printf("%d\n", p->right->val);
			else
				printf("0\n");
		}
	}
	void preOrder()
	{
		preOrder_in(root);
	}
	void preOrder_in(Node *p)
	{
		if(!p)
			return;
		printf("%d ", p->val);
		preOrder_in(p->left);
		preOrder_in(p->right);
	}
};
int main()
{
	int m;
	scanf("%d",&m);
	int mod,a,b,c;
	Tree tree;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&mod);
		switch(mod)
		{
			case 1:scanf("%d%d%d",&a,&b,&c);tree.add(a,b,c);break;
			case 2:scanf("%d",&a);tree.query(a);break;
			case 3:scanf("%d",&a);tree.swap(a);break;
		}
	}
	tree.preOrder();	
	return 0;
}