#include<cstdio>
using namespace std;
const int hashFactor=100007;
struct Node
{
	int val;
	Node* next;
	int times;
	Node(int x=0,Node *p=NULL)
	{
		val=x;
		next=p;
		times=1;
	}
};
int abs(int x)
{
	if(x<0)
		x=-1*x;
	return x;
}
class hashtable
{
	Node **table;
public:
	hashtable()
	{
		table=new Node*[100007];
		for(int i=0;i<hashFactor;i++)
			table[i]=NULL;
	}
	~hashtable(){delete[] table;}
	int hashFunc(int i)
	{
		return abs(i)%hashFactor;
	}
	void insert(int x)
	{
		int i=hashFunc(x);
		Node *p=table[i],*q=NULL;
		if(!table[i])
		{
			table[i]=new Node(x);
			return;
		}
		while(p&&p->val!=x) 
		{
			q=p;
			p=p->next;
		}
		if(!p) 
		{
			p=new Node(x);
			q->next=p;
		}
		else
			p->times++;
	}
	bool find(int x,int &t)
	{
		int i=hashFunc(x);
		if(!table[i])
			return false;
		Node *p=table[i];
		while(p&&p->val!=x)
			p=p->next;
		if(p)
		{
			t=p->times;
			return true;
		}
		else
			return false;
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	int *a=new int[n],*b=new int[n],*c=new int[n],*d=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	}
	hashtable check;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			check.insert(a[i]+b[j]);
		}
	//printf("\n");
	int cnt=0,t;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			t=0;
			if(check.find(-1*(c[i]+d[j]),t))
				cnt+=t;
		}
	printf("%d\n", cnt);
	delete[] a,b,c,d;
}