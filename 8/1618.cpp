#include<iostream>
#include<cstdio>
using namespace std;
class Queue
{
	struct Node
	{
		int val;
		Node *next,*prev;
		Node(int x,Node *p=NULL,Node *q=NULL)
		{
			val=x;next=p;prev=q;
		}
	};
	Node *head,*tail;
public:
	Queue()
	{
		head=NULL;
		tail=NULL;
	}
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
			head=tail=new Node(x);
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
		if(head)
			head->prev=NULL;
		else
			tail=NULL;     //Don't forget this!!!
		delete p;
	}
	void pop_back()
	{
		Node *p=tail;
		tail=tail->prev;
		if(tail)
			tail->next=NULL;
		else
			head=NULL;
		delete p;
	}
	int front(){return head->val;}
	int back(){return tail->val;}
	bool empty(){return head==NULL;}
};
int main()
{
	int n,k,x;
	Queue mini,maxi;
	scanf("%d%d",&n,&k);
	int *a=new int[n-k+1],*b=new int[n-k+1],*num=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",num+i);
	mini.push(0);
	maxi.push(0);
	int idx=0;
	for(int i=1;i<n;i++)
	{
		if(i>=k)
		{
			a[idx]=num[mini.front()];
			b[idx++]=num[maxi.front()];
			if(mini.front()==i-k) mini.pop_front();
			if(maxi.front()==i-k) maxi.pop_front();
		}
		if(mini.empty()||num[mini.back()]<num[i])
			mini.push(i);
		else
		{
			while(!mini.empty()&&num[mini.back()]>=num[i])
			{
				mini.pop_back();
			}
			mini.push(i);
		}
		if(maxi.empty()||num[maxi.back()]>num[i])
			maxi.push(i);
		else
		{
			while(!maxi.empty()&&num[maxi.back()]<=num[i])
				maxi.pop_back();
			maxi.push(i);
		}
	}
	a[idx]=num[mini.front()];
	b[idx++]=num[maxi.front()];
	for(int i=0;i<idx;i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i=0;i<idx;i++)
		printf("%d ", b[i]);
	delete[] a,b;
	return 0;
}
