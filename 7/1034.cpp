#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node *next,*prev;
	Node(int x,Node *nn=NULL,Node *pp=NULL):val(x),next(nn),prev(pp){}
};
class queue
{
	Node *head,*tail;
public:
	queue():head(NULL),tail(NULL){}
	~queue()
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
			tail->next=new Node(x,NULL,tail);
			tail=tail->next;
		}
	}
	void pop_front()
	{
		Node *p=head;
		head=head->next;
		if(head) head->prev=NULL;
		else tail=NULL;
		delete p;
	}
	void pop_back()
	{
		Node *p=tail;
		tail=tail->prev;
		if(tail) tail->next=NULL;
		else head=NULL;
		delete p;
	}
	int front(){return head->val;}
	int back(){return tail->val;}
	bool isEmpty(){return head==NULL;}
};
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int *a=new int[n];
	queue list;
	for(int i=0;i<n;i++) scanf("%d",a+i);
	list.push(0);
	for(int i=1;i<k;i++)
	{
		if(a[list.back()]>a[i]){list.push(i); continue;}
		while(!list.isEmpty()&&a[list.back()]<=a[i]) list.pop_back();
		list.push(i);
	}
	int ans=a[list.front()],t;
	for(int i=1;i<n;i++)
	{
		t=(i+k-1)%n;
		if(i-1==list.front()) list.pop_front();
		if(list.isEmpty()) list.push(t);
		else if(a[list.back()]>a[t]) list.push(t);
		else
		{
			while(!list.isEmpty()&&a[list.back()]<=a[t]) list.pop_back();
			list.push(t);
		}
		if(ans>a[list.front()]) ans=a[list.front()];
	}
	printf("%d\n", ans);
	return 0;
}