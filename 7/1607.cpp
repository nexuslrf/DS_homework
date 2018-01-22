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
	Queue &operator=(const Queue &t)
	{
		Node *p=head,*q;
		while(p)
		{
			q=p;
			p=p->next;
			delete q;
		}
		q=t.head->next;
		head=new Node(t.head->id);
		p=head;
		while(q)
		{
			p->next=new Node(q->id,NULL,p);
			q=q->next;
			p=p->next;
		}
		tail=p;
		return *this;
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
		Queue group_que;
		Node(int x,int pos,Node *ll=NULL,Node *rr=NULL):id(x),left(ll),right(rr),times(1){group_que.push(pos);}
	};
	Node *root;
	void clear(Node *t)
	{
		if(!t) return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	bool insert(int x,int pos,BinarySearchTree::Node *&t)
	{
		if(!t)
	 	{
			t=new Node(x,pos);return false;//Not exist;
	 	}
	 	else if(x==t->id) {t->times++;t->group_que.push(pos); return true;}
		else if(x<t->id) insert(x,pos,t->left);
		else if(x>t->id) insert(x,pos,t->right);
	}
	bool del(int x,BinarySearchTree::Node *&t,int &pos)
	{
		if(x==t->id)
		{
			if(t->times)
			{
				pos=t->group_que.front();
				//printf("##%d\n", pos);
				t->group_que.pop();
			}
			if(t->times>1)
			{
				t->times--;
				return true;
			}
			else
			{
				if(!(t->left&&t->right))
				{
					Node *p=t;
					t=(t->left)?t->left:t->right;
					delete p;
					return false;
				}
				else
				{
					Node *p=t->right;
					while(p->left) p=p->left;
					t->id=p->id;t->times=p->times;
					p->times=0;t->group_que=p->group_que;
					del(t->id,t->right,pos);
				}
			}
		}
		else if(x<t->id) del(x,t->left,pos);
		else del(x,t->right,pos);
	}
public:
	BinarySearchTree():root(NULL){}
	~BinarySearchTree(){clear(root);}
	bool insert(int x,int pos){return insert(x,pos,root);}
	bool del(int x,int &pos){return del(x,root,pos);}
};
int main()
{
	int n,m,op;
	BinarySearchTree check;
	Queue queue;
	scanf("%d",&n);
	int *a=new int[n+1];
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	int idx=1,pos;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&op);
		if(op)
		{
			if(queue.isEmpty()) {printf("-1\n"); continue;}
			if(!check.del(queue.front(),pos)) queue.pop();
			printf("%d\n", pos);
		}
		else
		{
			if(idx>n) continue;
			if(!check.insert(a[idx],idx)) queue.push(a[idx]);
			idx++;
		}
	}
	delete[] a;
	return 0;
}