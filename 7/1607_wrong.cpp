#include<cstdio>
using namespace std;
class Queue
{
	struct Node
	{
		int id;
		Node *next,*prev;
		Node(int x,Node *nn=NULL,Node *pp=NULL):id(x),next(nn),prev(pp){}
	};
	Node *head,*tail;
public:
	Queue():head(NULL),tail(NULL){}
	~Queue()
	{
		Node *p=head,*q;
		while(p)
		{
			q=p;
			p=p->next;
			delete q;
		}
	}
	void push(int x)
	{
		if(!head)
		{
			head=new Node(x);
			tail=head;
		}
		else
		{
			tail->next=new Node(x);
			tail=tail->next;
		}
	}
	void pop()
	{
		Node *p=head;
		head=head->next;
		if(head) head->prev=NULL;
		else tail=NULL;
		delete p;
	}
	int front(){return head->id;}
	bool isEmpty() {return head==NULL;}
};
class BinarySearchTree
{
	struct Node
	{
		int id,times;
		Node *left,*right;
		Node(int x,Node *ll=NULL,Node *rr=NULL):id(x),left(ll),right(rr),times(1){}
	};
	Node *root;
	void clear(Node *t)
	{
		if(!t) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	bool insert(int x,Node *&t)
	{
		if(!t)
	 	{
			t=new Node(x);return false;//Not exist;
	 	}
	 	else if(x==t->id) {t->times++;return true;}
		else if(x<t->id) insert(x,t->left);
		else if(x>t->id) insert(x,t->right);
	}
	bool del(int x,Node *&t)
	{
		if(x==t->id)
		{
			if(t->times>1){t->times--;return true;}
			else
			{
				if(!(t->left&&t->right))
				{
					Node *p=t;
					t=(t->left)?t->left:t->right;
					delete p; return false;
				}
				else
				{
					Node *p=t->right;
					while(p->left) p=p->left;
					t->id=p->id;t->times=p->times;
					p->times=0;
					del(t->id,t->right);
				}
			}
		}
		else if(x<t->id) del(x,t->left);
		else del(x,t->right);
	}
public:
	BinarySearchTree():root(NULL){}
	~BinarySearchTree(){clear(root);}
	bool insert(int x){return insert(x,root);}
	bool del(int x){return del(x,root);}
};
int main()
{
	int n,m,op;
	BinarySearchTree check;
	Queue queue;
	scanf("%d",&n);
	int *a=new int[n];
	for(int i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	int idx=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&op);
		if(op)
		{
			if(queue.isEmpty()) {printf("-1\n"); continue;}
			printf("%d\n", queue.front());
			if(!check.del(queue.front())) queue.pop();
		}
		else
		{
			if(idx>=n) continue;
			if(!check.insert(a[idx])) queue.push(a[idx]);
			idx++;
		}
	}
	delete[] a;
	return 0;
}