#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node* left,*right;
	Node(int x,Node* ll=NULL,Node* rr=NULL):left(ll),right(rr),val(x){}
};
class BinarySearchTree
{
	Node *head;
	int currentNum;
	int aux;
	void clear(Node* &root)
	{
		if(!root)
			return;
		clear(root->left);
		clear(root->right);
		delete root;
		currentNum--;
	}
	bool find(int x,Node *root)
	{
		if(!root)
			return false;
		if(x==root->val)
			return true;
		else if(x<root->val)
			return find(x,root->left);
		else
			return find(x,root->right);
	}
	void find_ith(int index,Node* root,int &x)
	{
		if(aux>index)
			return;
		if(root->left)
			find_ith(index,root->left,x);
		if(index==++aux)
		{
			x=root->val;
			return;
		}
		if(root->right)
			find_ith(index,root->right,x);
	}
	void del_less(int x,Node *&root)
	{
		if(!root) return;
		while(root&&x>root->val)
		{
			clear(root->left);
			Node* temp=root->right;
			delete root;
			root=temp; currentNum--;
		}
		if(root&&x<=root->val)
			del_less(x,root->left);
	}
	void del_greater(int x,Node *&root)
	{
		if(!root) return;
		while(root&&root->val>x)
		{
			clear(root->right);
			Node *temp=root->left;
			delete root;
			root=temp; currentNum--;
		}
		if(root&&x>=root->val)
			del_greater(x,root->right);
	}
	void del_interval(int a,int b,Node *&root)
	{
		if(a>=b||!root) return;
		while(root&&root->val>a&&root->val<b)
		{
			del_singular(root->val,root);
		}
		//inOrder();printf("\n");
		if(root&&root->val>=b)
			del_interval(a,b,root->left);
		if(root&&root->val<=a)
			del_interval(a,b,root->right);
	}
	void del_singular(int x,Node *&p)
	{
		if(!p) return;
		if(x<p->val) del_singular(x,p->left);
		else if(x>p->val) del_singular(x,p->right);
		else if(p->left&&p->right)
		{
			Node *q=p->right;
			while(q->left) q=q->left;
			p->val=q->val;
			del_singular(p->val,p->right);
		}
		else
		{
			Node *temp=p;
			p=(p->left)?p->left:p->right;
			delete temp;
			currentNum--;
		}
	}
	void insert(int x,Node *&root)
	{
		if(root==NULL)
		{
		 	root=new Node(x);currentNum++;
		}
		else if(x<=root->val)
			insert(x,root->left);
		else
			insert(x,root->right);
	}
	void inOrder(Node *root)
	{
		if(!root)
			return;
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
public:
	BinarySearchTree():currentNum(0),head(NULL){}
	~BinarySearchTree()
	{
		clear(head);
	}
	bool find(int x)
	{
		return find(x,head);
	}
	bool find_ith(int index,int &x)
	{
		if(index>currentNum)
			return false;
		aux=0;
		find_ith(index,head,x);
		return true;
	}
	void inOrder()
	{
		inOrder(head);
		printf("%d",currentNum);
	}
	void insert(int x)
	{
		insert(x,head);
	}
	void del_singular(int x)
	{
		del_singular(x,head);
	}
	void del_less(int x)
	{
		del_less(x,head);
		if(currentNum==0) head=NULL;
	}
	void del_greater(int x)
	{
		del_greater(x,head);
		if(currentNum==0) head=NULL;
	}
	void del_interval(int a,int b)
	{
		del_interval(a,b,head);
		if(currentNum==0) head=NULL;
	}
};
int main()
{
	int n,x,y;
	scanf("%d",&n);
	BinarySearchTree tree;
	char commd[21];
	for(int i=0;i<n;i++)
	{
		scanf("%s",commd);
		if(commd[0]=='i')
		{
			scanf("%d",&x);
			tree.insert(x);
		}
		else if(commd[0]=='f'&&commd[4]=='_')
		{
			scanf("%d",&x);
			if(tree.find_ith(x,y)) printf("%d\n",y);
			else printf("N\n");
		}
		else if(commd[0]=='f'&&commd[4]=='\0')
		{
			scanf("%d",&x);
			if(tree.find(x)) printf("Y\n");
			else printf("N\n");
		}
		else if(commd[0]=='d')
		{
			if(commd[6]=='\0')
			{
				scanf("%d",&x);
				tree.del_singular(x);
			}
			else if(commd[7]=='l')
			{
				scanf("%d",&x);
				tree.del_less(x);
			}
			else if(commd[7]=='g')
			{
				scanf("%d",&x);
				tree.del_greater(x);
			}
			else if(commd[7]=='i')
			{
				scanf("%d%d",&x,&y);
				tree.del_interval(x,y);
			}
		}
		// tree.inOrder();
		// printf("\n");
	}
	return 0;
}