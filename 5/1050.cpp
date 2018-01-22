#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node *son;
	Node *bro;
	Node(int x)
	{
		val=x;
		son=NULL;
		bro=NULL;
	}                                                                                                           
};
class BernoliTree
{
	Node **roots;
	int maxSize;
	int currentSize;
	void clear(Node *root)
	{
		if(!root)
			return;
		clear(root->son);
		clear(root->bro);
		delete root;
	}
	Node* merge(Node *a,Node *b,int r)
	{
		Node *root,*p,*q;
		if(a->val<b->val)
		{
			root=a;
			p=b;
		}
		else
		{
			root=b;
			p=a;
		}
		if(r==0)
		{
			root->son=p;
		}
		else
		{
			q=root->son;
			for(int i=0;i<r-1;i++)
				q=q->bro;
			q->bro=p;
		}
		return root;
	}
public:
	BernoliTree(int n=20)
	{
		maxSize=n;
		currentSize=0;
		roots=new Node*[n];
		for(int i=0;i<n;i++)
			roots[i]=NULL;
	}
	~BernoliTree()
	{
		for(int i=0;i<maxSize;i++)
		{
			if(roots[i])
				clear(roots[i]);
		}
		delete[] roots;
	}
	void push(int x)
	{
		Node *temp=new Node(x);
		int i=0;
		if(!roots[0])
			roots[0]=temp;
		else
		{
			do
			{
				temp=merge(temp,roots[i],i);
				roots[i]=NULL;
				i++;
			}while(roots[i]);
			roots[i]=temp;
		}
		currentSize++;
		//printf("%d\n", currentSize);
	}
	int getMin()
	{
		int c=currentSize,i=0,mini=2147483647;
		int ans;
		while(c)
		{
			if(roots[i])
			{
				if(roots[i]->val<mini)
				{
					mini=roots[i]->val;
					ans=i;
				}
				c-=(1<<i);
			}
			i++;
		}
		//printf("%d\n", ans);
		return ans;
	}
	int Min()
	{
		if(!currentSize)
			return -1;
		int i=getMin();
		return roots[i]->val;
	}
	int pop()
	{
		if(!currentSize)
			return -1;
		int pos=getMin();
		int ans=roots[pos]->val;
		currentSize--;
		if(pos==0)
		{
			delete roots[0];
			roots[0]=NULL;
			return ans;
		}
		Node **temp=new Node*[pos];
		Node *p;
		temp[0]=roots[pos]->son;
		for(int i=1;i<pos;i++)
		{
			temp[i]=temp[i-1]->bro;
			temp[i-1]->bro=NULL;
		}
		delete roots[pos];
		roots[pos]=NULL;
		for(int i=0;i<pos;i++)
		{
			p=temp[i];
			int j=i;
			while(roots[j])
			{
				p=merge(p,roots[j],j);
				roots[j]=NULL;
				j++;
			}
			roots[j]=p;
		}
		delete[] temp;
		return ans;
	}
	void combine(BernoliTree &x)
	{
		int c=x.currentSize,i=0;
		while(c)
		{
			if(x.roots[i])
			{
				int j=i;
				Node *p=x.roots[i];
				while(roots[j])
				{
					p=merge(p,roots[j],j);
					roots[j]=NULL;
					j++;
				}
				roots[j]=p;
				c-=(1<<i);
			}
			i++;
		}
		currentSize+=x.currentSize;
		x.currentSize=0;
	}
	int getLen(){return currentSize;}
};
int main()
{
	int n,m,p;
	scanf("%d%d",&n,&m);
	BernoliTree *trees=new BernoliTree[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p);
		trees[i].push(p);
	}
	int c,a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&c);
		switch(c)
		{
			case 0:scanf("%d%d",&a,&b);trees[a].combine(trees[b]);break;
			case 1: scanf("%d",&a);printf("%d\n", trees[a].pop());break;
			case 2:scanf("%d%d",&a,&b);trees[a].push(b);break;
		}
	}
	return 0;
}